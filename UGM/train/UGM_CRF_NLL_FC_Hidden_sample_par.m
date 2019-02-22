function [corvalue, g, currentSamples, currentClampedSamples] = UGM_CRF_NLL_FC_Hidden_sample_par(w,subXnode,subXedge,suby,nodeMap,edgeMap,edgeStruct,~,currentSamples,currentClampedSamples)

[nNodes,maxState,~] = size(nodeMap);

nEdges = edgeStruct.nEdges;
edgeEnds = edgeStruct.edgeEnds;
nStates = edgeStruct.nStates;

nInstances = size(suby{1},1);

monitor=edgeStruct.monitor;

nPar=length(subXnode);


corvalues = cell(nPar,1);
gs = cell(nPar,1);




parfor p = 1:nPar
    g = zeros(size(w));
    
    Xnod=subXnode{p};
    Xedg=subXedge{p};
    Ysub=suby{p};
    nodePots = zeros(nNodes,maxState,nInstances);
    edgePots = zeros(maxState,maxState,nEdges,nInstances);
    
    for i = 1:nInstances
        % Make potentials
        [nodePot,edgePot] = UGM_CRF_makePotentialsC_FC(w,Xnod(i,:),Xedg(i,:),nodeMap,edgeMap,nStates,edgeEnds,int32(i));
        nodePots(:,:,i)=nodePot;
        edgePots(:,:,:,i)=edgePot;

    end
    % Compute marginals and logZ
    if monitor == 1
        [currentSamples{p},nodeBel,edgeBel] = maxent_Infer_Sample_batch_nopar(nodePots,edgePots,edgeStruct,currentSamples{p});
        [currentClampedSamples{p},nodeBelC,edgeBelC] =  maxent_Infer_Sample_clamp_batch_nopar(nodePots,edgePots,edgeStruct,currentClampedSamples{p},Ysub==0);
        corvalues{p} = corr([nodeBel(2,:) squeeze(edgeBel(2,2,:))']',[nodeBelC(2,:) squeeze(edgeBelC(2,2,:))']');
    else
        [currentSamples{p}] = maxent_Infer_Sample_batch_nopar(nodePots,edgePots,edgeStruct,currentSamples{p});
        [currentClampedSamples{p}] =  maxent_Infer_Sample_clamp_batch_nopar(nodePots,edgePots,edgeStruct,currentClampedSamples{p},Ysub==0);
        corvalues{p} = 0;
    end
    % Updates in-place
    for i = 1:nInstances
        UGM_CRF_NLLC_FC_Hidden_Sample(g,int32(i),currentSamples{p}(:,i),currentSamples{p}(:,i),edgeEnds,nStates,nodeMap,edgeMap,Xnod(i,:),Xedg(i,:),int32(Ysub(i,:)));
    end
    gs{p}=g;
end


corvalue = 0;
g = zeros(size(w));

for p = 1:nPar
    corvalue=corvalue+corvalues{p};
    g = g + gs{p};
end

corvalue=corvalue/nPar;



