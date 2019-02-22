function [corvalue, g, currentSamples, currentClampedSamples,nodeBel,edgeBel,nodeBelC,edgeBelC] = UGM_CRF_NLL_FC_Hidden_sample(w,subXnode,subXedge,suby,nodeMap,edgeMap,edgeStruct,~,currentSamples,currentClampedSamples)

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
    
NLL = 0;
    [~,edgePots] = UGM_CRF_makePotentialsC_FC(w,subXnode(1,:),subXedge(1,:),nodeMap,edgeMap,edgeStruct.nStates,edgeStruct.edgeEnds,int32(1));
    
    nodePots = zeros(nNodes,maxState,nInstances);
    wtemp=zeros(nNodes,nNodeFeatures);
    wtemp(nodemap~=0)=w(nodemap(nodemap~=0));
    nodePots(:,2,:)=   exp(subXnode* wtemp')';
    nodePots(:,1,:)=   1;

%     [nodePots] = UGM_CRF_makePotentialsC_FC_Batch_NodePot_OpenMP(w,subXnode,subXedge,nodeMap,edgeMap,nStates,edgeEnds);

% for i = 1:nInstances
%     
% %     Make potentials
%         [nodePot,edgePot] = UGM_CRF_makePotentialsC_FC(w,subXnode(i,:),subXedge(i,:),nodeMap,edgeMap,nStates,edgeEnds,int32(i));
%         nodePots(:,:,i)=nodePot;
%         edgePots(:,:,:,i)=edgePot;
% 
% end
% Compute marginals and logZ
%[nodeBel,edgeBel,logZ] = inferFunc(nodePot,edgePot,edgeStruct,currentSamples);


if edgeStruct.monitor == 1
     [currentSamples,nodeBel,edgeBel] = maxent_Infer_Sample_batch(nodePots,edgePots,edgeStruct,currentSamples);
     [currentClampedSamples,nodeBelC,edgeBelC] =  maxent_Infer_Sample_clamp_batch(nodePots,edgePots,edgeStruct,currentClampedSamples,suby==0);
%     [currentSamples,~,~,logZ] = maxent_Infer_Sample_batch(nodePots,edgePots,edgeStruct,currentSamples);
%     [currentClampedSamples,~,~,logZC] =  maxent_Infer_Sample_clamp_batch(nodePots,edgePots,edgeStruct,currentClampedSamples,suby==0);
else
    [currentSamples] = maxent_Infer_Sample_batch(nodePots,edgePots,edgeStruct,currentSamples);
    [currentClampedSamples] =  maxent_Infer_Sample_clamp_batch(nodePots,edgePots,edgeStruct,currentClampedSamples,suby==0);
end



% Compute Clamped Potential for Latent Variables
% Make potentials

% Update NLL
% logZC
% mean(UGM_LogConfigurationPotentialC_Hidden_Batch_OpenMP(int32(suby'),nodePots,edgePots,int32(edgeEnds)))
% logZ
%     NLL = NLL - (logZC+mean(UGM_LogConfigurationPotentialC_Hidden_Batch_OpenMP(int32(suby'),nodePots,edgePots,int32(edgeEnds))) );% + logZ;
    if edgeStruct.monitor == 1
        corvalue = corr([nodeBel(:,2)' squeeze(edgeBel(2,2,:))']',[nodeBelC(:,2)' squeeze(edgeBelC(2,2,:))']');
    else
        corvalue =0;
    end
    % Updates in-place
    g = zeros(size(w));
%     for i = 1:nInstances
%         UGM_CRF_NLLC_FC_Hidden_Sample(g,int32(i),int32(currentSamples(:,i)),int32(currentClampedSamples(:,i)),edgeEnds,nStates,nodeMap,edgeMap,subXnode(i,:),subXedge(i,:),int32(suby(i,:)));
%     end
    gMat= double(currentSamples-1)*double(currentSamples-1)' - double(currentClampedSamples-1)*double(currentClampedSamples-1)';
    gMatCond=double(currentSamples-currentClampedSamples)*subXnode; 
    
%         g(nodeMap(:,2,:))=gMatCond(nodeMap(:,2,:)~=0);
%         g(edgeMap(2,2,:,1))=gMat(edgeEnds(:,1)+nNodes*(edgeEnds(:,2)-1));


    g(nodemap(nodemap~=0))=gMatCond(nodemap~=0);
    edgemap=edgeMap(2,2,:,1);
    g(edgemap(edgemap~=0))=gMat(edgeEnds(:,1)+nNodes*(edgeEnds(:,2)-1));
    
    


   