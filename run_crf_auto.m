function [] = run_crf_auto(cvi, RegParam1, RegParam2)
    load data.mat;
    load dag_02122016.mat;
    addpath(genpath('./UGM'));
    nNodes = size(dag, 1);
    nStates = int32(2);
    adj = dag;
    edgeStruct = UGM_makeEdgeStruct(adj, nStates);
    maxState = max(nStates);
    nEdges = edgeStruct.nEdges;

    %% Training 


    nNodeFeatures = size(Xnodeall, 2);
    nodeMap = zeros(nNodes, maxState, nNodeFeatures, 'int32');
    n = 1;

    for i = 1:nNodes

        for f = 1:nNodeFeatures
            nodeMap(i, 2, f) = n;
            n = n + 1;
        end

    end

    % Make edgeMap
    edgeMap = zeros(maxState, maxState, nEdges, 'int32');
    edgeMap(2, 2, :) = n:n + nEdges - 1;

    % Initialize weights
    nParams = max([nodeMap(:); edgeMap(:)]);
    w = zeros(nParams, 1);

    rng(1);
    perm = randperm(length(Xnodeall));

    testInds1 = 1:1440;
    testInds2 = 1441:2880;
    testInds3 = 2881:4320;
    testInds4 = 4321:5760;
    testInds5 = 5761:7200;

    trainInds1 = setdiff(1:7200, testInds1);
    trainInds2 = setdiff(1:7200, testInds2);
    trainInds3 = setdiff(1:7200, testInds3);
    trainInds4 = setdiff(1:7200, testInds4);
    trainInds5 = setdiff(1:7200, testInds5);

    size(trainInds1)
    size(perm)
    size(Xnodeall)

    if cvi == 1
        Xnode = Xnodeall(perm(trainInds1), :);
        Xedge = Xedgeall(perm(trainInds1), :);
        y = yall(perm(trainInds1), :);
    elseif cvi == 2
        Xnode = Xnodeall(perm(trainInds2), :);
        Xedge = Xedgeall(perm(trainInds2), :);
        y = yall(perm(trainInds2), :);
    elseif cvi == 3
        Xnode = Xnodeall(perm(trainInds3), :);
        Xedge = Xedgeall(perm(trainInds3), :);
        y = yall(perm(trainInds3), :);
    elseif cvi == 4
        Xnode = Xnodeall(perm(trainInds4), :);
        Xedge = Xedgeall(perm(trainInds4), :);
        y = yall(perm(trainInds4), :);
    elseif cvi == 5
        Xnode = Xnodeall(perm(trainInds5), :);
        Xedge = Xedgeall(perm(trainInds5), :);
        y = yall(perm(trainInds5), :);
    end

    nTrainInstances = length(Xnode(:, 1));

    lambda = ones(size(w)) * RegParam1;
    lambda(1:nNodeFeatures) = 0;
    lambda(nNodes * nNodeFeatures + 1:end) = RegParam2;
    lambdaF = 1;

    edgeStruct.edgeEnds = int32(edgeStruct.edgeEnds);
    options.maxIter = 500;
    funobj = @(w)UGM_CRF_PseudoNLL_FC_fast(w, Xnode, Xedge, y, int32(nodeMap), int32(edgeMap), edgeStruct);
    w = L1General2_PSSgb(funobj, w, lambda .* lambdaF, options);

    %Training with MCMC
    mcmcallws = [];

    currentSamples = y' + 1;
    currentClampedSamples = y' + 1;
    regularizebaseline = zeros(size(w));

    gbak = zeros(size(w));
    momentum = 0.9;
    maxIter = 200000;
    for iter = 1:maxIter
        edgeStruct.useMex = 1;
        edgeStruct.maxIter = 1;

        if iter < 100000
            stepSize = 1e-6;
        elseif iter < 150000
            stepSize = 1e-7;
        else
            stepSize = 1e-8;
        end

        if 1
            edgeStruct.monitor = 1;
        else
            edgeStruct.monitor = 0;
        end

        [f, g, currentSamples, currentClampedSamples, nodeBel, edgeBel, nodeBelC, edgeBelC] = UGM_CRF_NLL_FC_Hidden_sample(w, Xnode, Xedge, y + 1, nodeMap, edgeMap, edgeStruct, [], currentSamples, currentClampedSamples);

        g = g * (1 - momentum) + gbak * momentum;
        gbak = g;
        w = w - stepSize * g;
        w = w - min(abs(w - regularizebaseline), stepSize * lambdaF * lambda .* (w > regularizebaseline));
        w = w + min(abs(w - regularizebaseline), stepSize * lambdaF * lambda .* (w < regularizebaseline));

        if mod(iter, 10) == 0
            fprintf('Iter = %d of %d (fsub = %f)\n', iter, maxIter, corr([nodeBelCUM(:, 2)' squeeze(edgeBelCUM(2, 2, :))']', [nodeBelCCUM(:, 2)' squeeze(edgeBelCCUM(2, 2, :))']'));
            fprintf('Iter = %d of %d (wnorm = %f)\n', iter, maxIter, norm(w));
            fprintf('Iter = %d of %d (L1penalty = %f)\n', iter, maxIter, mean(abs(w - regularizebaseline) .* lambda));
            fprintf('Iter = %d of %d (gnorm = %f)\n', iter, maxIter, norm(g));
            nodeBelCUM = nodeBel;
            edgeBelCUM = edgeBel;
            nodeBelCCUM = nodeBelC;
            edgeBelCCUM = edgeBelC;
        else

            if iter == 1
                nodeBelCUM = nodeBel;
                edgeBelCUM = edgeBel;
                nodeBelCCUM = nodeBelC;
                edgeBelCCUM = edgeBelC;
            else
                nodeBelCUM = nodeBelCUM + nodeBel;
                edgeBelCUM = edgeBelCUM + edgeBel;
                nodeBelCCUM = nodeBelCCUM + nodeBelC;
                edgeBelCCUM = edgeBelCCUM + edgeBelC;
            end

        end

        if (mod(iter, 1000) == 0)
            mcmcallws = [mcmcallws, w];
        end

    end

    save(['insitu.cvdata.final.nolnc.knowledge.reg10.cv' int2str(cvi) '.' int2str(RegParam1) '.' int2str(RegParam2) '.short.mat'], 'mcmcallws', 'w', 'edgeStruct', 'nodeMap', 'edgeMap', 'nNodes', 'nNodeFeatures');

    %evaluation

    if cvi == 1
        testInds = testInds1;
    elseif cvi == 2
        testInds = testInds2;
    elseif cvi == 3
        testInds = testInds3;
    elseif cvi == 4
        testInds = testInds4;
    elseif cvi == 5
        testInds = testInds5;
    end

    maxState = 2;
    nodemap = nodeMap(:, 2, :);
    [~, edgePots] = UGM_CRF_makePotentialsC_FC(w, Xnodeall(perm(testInds), :), Xedgeall(perm(testInds), :), int32(nodeMap), int32(edgeMap), edgeStruct.nStates, int32(edgeStruct.edgeEnds), int32(1));

    nodePots = zeros(nNodes, maxState, size(yall(perm(testInds), :), 1));
    wtemp = zeros(nNodes, nNodeFeatures);
    wtemp(nodemap ~= 0) = w(nodemap(nodemap ~= 0));
    nodePots(:, 2, :) = exp(Xnodeall(perm(testInds), :) * wtemp')';
    nodePots(:, 1, :) = 1;

    currentSamples = ones(size(yall(perm(testInds), :)'));

    e = sum(yall(perm(testInds), :), 1);

    for i = 1:10
        edgeStruct.maxIter = 10;
        [currentSamples, ~, ~] = maxent_Infer_Sample_batch(nodePots, edgePots, edgeStruct, currentSamples);
        o = sum(currentSamples == 2, 2);
        corr(e', o)
    end

    CUMcurrentSamples = currentSamples - 1;
    edgeStruct.maxIter = 1;

    for i = 1:80000
        [currentSamples, ~, ~] = maxent_Infer_Sample_batch(nodePots, edgePots, edgeStruct, currentSamples);
        CUMcurrentSamples = CUMcurrentSamples + currentSamples - 1;
    end

    save(['insitu.cvdata.final.nolnc.knowledge.reg10.cv' int2str(cvi) '.' int2str(RegParam1) '.' int2str(RegParam2) '.short.eval.mat'], 'CUMcurrentSamples');

    
    %prediction
    load data.pred.mat;
    x = Xnodeall;
    addpath(genpath('/tigress/jzthree/Code/UGM'));
    nNodes = size(y, 2);
    nStates = int32(2);
    adj = dag;
    edgeStruct = UGM_makeEdgeStruct(adj, nStates);
    maxState = max(nStates);
    nEdges = edgeStruct.nEdges;

    % Make nodeMap

    nNodeFeatures = size(Xnode, 2);
    nodeMap = zeros(nNodes, maxState, nNodeFeatures, 'int32');
    n = 1;

    for i = 1:nNodes

        for f = 1:nNodeFeatures
            nodeMap(i, 2, f) = n;
            n = n + 1;
        end

    end

    % Make edgeMap
    edgeMap = zeros(maxState, maxState, nEdges, 'int32');
    edgeMap(2, 2, :) = n:n + nEdges - 1;

    % Initialize weights

    Xnodeall = [ones(size(x, 1), 1), x];
    Xedgeall = ones(size(Xnodeall, 1), 1);

    edgeStruct.edgeEnds = int32(edgeStruct.edgeEnds);

    maxState = 2;
    nodemap = nodeMap(:, 2, :);
    [~, edgePots] = UGM_CRF_makePotentialsC_FC(w, Xnodeall, Xedgeall, int32(nodeMap), int32(edgeMap), edgeStruct.nStates, int32(edgeStruct.edgeEnds), int32(1));

    nodePots = zeros(nNodes, maxState, size(Xnodeall, 1));
    wtemp = zeros(nNodes, nNodeFeatures);
    wtemp(nodemap ~= 0) = w(nodemap(nodemap ~= 0));
    nodePots(:, 2, :) = exp(Xnodeall * wtemp')';
    nodePots(:, 1, :) = 1;

    currentSamples = ones(nNodes, size(Xnodeall, 1));

    for i = 1:10
        edgeStruct.maxIter = 10;
        [currentSamples, ~, ~] = maxent_Infer_Sample_batch(nodePots, edgePots, edgeStruct, currentSamples);
    end

    CUMcurrentSamples = currentSamples - 1;
    edgeStruct.maxIter = 1;

    for i = 1:80000
        i
        [currentSamples, ~, ~] = maxent_Infer_Sample_batch(nodePots, edgePots, edgeStruct, currentSamples);
        CUMcurrentSamples = CUMcurrentSamples + currentSamples - 1;
    end

    save(['insitu.cvdata.final.nolnc.knowledge.reg10.cv' int2str(cvi) '.' int2str(RegParam1) '.' int2str(RegParam2) '.short.pred.mat'], 'CUMcurrentSamples');
