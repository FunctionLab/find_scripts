function [corvalue, g, currentSamples, currentClampedSamples,newweight] = UGM_CRF_NLL_FC_Hidden_sample_weight(w,subXnode,subXedge,suby,nodeMap,edgeMap,edgeStruct,~,currentSamples,currentClampedSamples,weight,normfactor)

[nNodes,maxState,~] = size(nodeMap);
nNodeFeatures = size(subXnode,2);
nEdgeFeatures = size(subXedge,2);
nEdges = edgeStruct.nEdges;
edgeEnds = edgeStruct.edgeEnds;
nStates = edgeStruct.nStates;
nInstances = size(suby,1);

    nodemap=nodeMap(:,2,:);
    
NLL = 0;
    [~,edgePots] = UGM_CRF_makePotentialsC_FC(w,subXnode(1,:),subXedge(1,:),nodeMap,edgeMap,edgeStruct.nStates,edgeStruct.edgeEnds,int32(1));
    
    nodePots = zeros(nNodes,maxState,nInstances);
    wtemp=zeros(nNodes,nNodeFeatures);
    wtemp(nodemap~=0)=w(nodemap(nodemap~=0));
    nodePots(:,2,:)=   exp(subXnode* wtemp')';
    nodePots(:,1,:)=   1;

if edgeStruct.monitor == 1
     [currentSamples,nodeBel,edgeBel] = maxent_Infer_Sample_batch(nodePots,edgePots,edgeStruct,currentSamples);
     [currentClampedSamples,nodeBelC,edgeBelC] =  maxent_Infer_Sample_clamp_batch(nodePots,edgePots,edgeStruct,currentClampedSamples,suby==0);
else
    [currentSamples] = maxent_Infer_Sample_batch(nodePots,edgePots,edgeStruct,currentSamples);
    [currentClampedSamples] =  maxent_Infer_Sample_clamp_batch(nodePots,edgePots,edgeStruct,currentClampedSamples,suby==0);
end


    if edgeStruct.monitor == 1
        corvalue = corr([nodeBel(:,2)' squeeze(edgeBel(2,2,:))']',[nodeBelC(:,2)' squeeze(edgeBelC(2,2,:))']');
    else
        corvalue =0;
    end
    g = zeros(size(w));

    gMat= double(currentSamples-1)*spdiags(normfactor./weight,0,nInstances,nInstances)*double(currentSamples-1)' - double(currentClampedSamples-1)*spdiags(normfactor./weight,0,nInstances,nInstances)*double(currentClampedSamples-1)';
    gMatCond=double(currentSamples-currentClampedSamples)*spdiags(normfactor./weight,0,nInstances,nInstances)*subXnode; 
    

    g(nodemap(nodemap~=0))=gMatCond(nodemap~=0);
    edgemap=edgeMap(2,2,:,1);
    g(edgemap(edgemap~=0))=gMat(edgeEnds(:,1)+nNodes*(edgeEnds(:,2)-1));
    
    
    %no memory
    newweight=mean(currentSamples~=currentClampedSamples,1)';
    newweight= max(sqrt(newweight.*(1-newweight)),0.01);%choice 1 Variance reduction weight ;
%    newweight=newweight./mean(newweight);
%     newweight= newweight./(1-newweight);%choice 2 Ada weight
%     newweight= log(newweight./(1-newweight));%choice 3 Ada weight

    


   