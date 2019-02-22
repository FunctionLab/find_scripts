function [corvalue, g, currentSamples, currentClampedSamples] = UGM_CRF_NLL_FC_Hidden_sample_newpar(w,subXnode,subXedge,suby,nodeMap,edgeMap,edgeStruct,~,currentSamples,currentClampedSamples)

[nNodes,maxState,~] = size(nodeMap);
nNodeFeatures = size(subXnode,2);
nEdgeFeatures = size(subXedge,2);
nEdges = edgeStruct.nEdges;
edgeEnds = edgeStruct.edgeEnds;
nStates = edgeStruct.nStates;
nInstances = size(suby,1);

% nodePots = zeros(nNodes,maxState,nInstances);
% edgePots = zeros(maxState,maxState,nEdges,nInstances);
    nodemap=nodeMap(:,2,:);
    edgemap=edgeMap(2,2,:,1);
        
NLL = 0;
    [~,edgePots] = UGM_CRF_makePotentialsC_FC(w,subXnode(1,:),subXedge(1,:),nodeMap,edgeMap,edgeStruct.nStates,edgeStruct.edgeEnds,int32(1));
    
    nodePots = zeros(nNodes,maxState,nInstances);
    wnode=zeros(nNodes,nNodeFeatures);
    wnode(nodemap~=0)=w(nodemap(nodemap~=0));
    wnode=subXnode*wnode';
    
    wedge=zeros(nNodes,nNodes);
    wedge(edgeEnds(:,1)+nNodes*(edgeEnds(:,2)-1))= w(edgemap(edgemap~=0));
    wedge=wedge+wedge';

    
     [currentSamples,nodeBel,edgeBel] = maxent_Infer_Sample_batch_newpar(wnode,wedge,edgeStruct,currentSamples);
     [currentClampedSamples,nodeBelC,edgeBelC] =  maxent_Infer_Sample_clamp_batch_newpar(wnode,wedge,edgeStruct,currentClampedSamples,suby==0);


% Compute Clamped Potential for Latent Variables
% Make potentials

    if edgeStruct.monitor == 1
        corvalue = corr([nodeBel(:,2)' squeeze(edgeBel(2,2,:))']',[nodeBelC(:,2)' squeeze(edgeBelC(2,2,:))']');
    else
        corvalue =0;
    end
    % Updates in-place
    g = zeros(size(w));

    gMat= double(currentSamples-1)*double(currentSamples-1)' - double(currentClampedSamples-1)*double(currentClampedSamples-1)';
    gMatCond=double(currentSamples-currentClampedSamples)*subXnode; 
    

    g(nodemap(nodemap~=0))=gMatCond(nodemap~=0);
    g(edgemap(edgemap~=0))=gMat(edgeEnds(:,1)+nNodes*(edgeEnds(:,2)-1));
    
    


   