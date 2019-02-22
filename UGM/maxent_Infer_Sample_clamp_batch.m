function  [currentSamples,nodeBel,edgeBel,logZ] = maxent_Infer_Sample_clamp_batch(nodePot, edgePot, edgeStruct,currentSamples,clamp)
% [nodeBel,edgeBel,logZ] = UGM_Infer_Sample(nodePot, edgePot, edgeStruct,
% sampleFunc,varargin)
% INPUT
% nodePot(node,class)
% edgePot(class,class,edge) where e is referenced by V,E (must be the same
% between feature engine and inference engine)
%
% OUTPUT
% nodeLabel(node)
%
% Inference using samples from a Gibbs/MH/Exact sampler
% currentSamples = batch_Sample_Gibbs(nodePot,edgePot,edgeStruct,0,currentSamples,clamp);

nSamples = size(currentSamples,2);
edgeEnds = int32(edgeStruct.edgeEnds);
nStates = int32(edgeStruct.nStates);
V = int32(edgeStruct.V);
E = int32(edgeStruct.E);
maxIter= int32(edgeStruct.maxIter);
%   for i = 1:nSamples
%       currentSamples(:,i) = UGM_Sample_GibbsC_Clamp_Single(nodePot(:,:,i),edgePot(:,:,:,i),edgeEnds,nStates,V,E,maxIter,int32(0),int32(currentSamples(:,i)),int32(clamp(i,:)));
%   end
currentSamples = UGM_Sample_GibbsC_Clamp_Single_Batch_edgePot(nodePot,edgePot,edgeEnds,nStates,V,E,maxIter,int32(0),int32(currentSamples),int32(clamp),int32(75));
if nargout>1

[nNodes,maxStates,~] = size(nodePot);
nEdges = size(edgePot,3);
edgeEnds = edgeStruct.edgeEnds;


    nodeBel = zeros(nNodes,maxStates);
edgeBel = zeros(size(edgePot));
Z = 0;


wCount= double(currentSamples-1)*double(currentSamples-1)';


nodeBel(:,2) =  diag(wCount);
temp = size(wCount,1);
edgeBel(2,2,1:nEdges) =  wCount(edgeEnds(1:nEdges,1)+ (edgeEnds(1:nEdges,2)-1) *temp );

if nargout > 3
    [uA,~,uIdx] = unique(currentSamples','rows');
    modeIdx = mode(uIdx);
    modes = uA(modeIdx,:);
    whereIdx = find(uIdx==modeIdx); %# the second output argument

%         modes=mode(double(currentSamples'));
%         count=0;
%         modei=0;
%         modes
%         for i=1:nSamples
%             if(all(double(currentSamples(:,i))==modes'))
%                 count=count+1;
%                 modei=i;
%             end
%         end
        count = length(whereIdx);
        modei = whereIdx(1);
        Z = UGM_ConfigurationPotential(modes,nodePot(:,:,modei),edgePot,edgeEnds) * nSamples/count;
end


nodeBel = nodeBel./nSamples; 
edgeBel = edgeBel./nSamples;
logZ = log(Z);
end
