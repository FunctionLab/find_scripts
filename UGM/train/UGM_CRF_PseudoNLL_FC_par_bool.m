function [NLL,g] = UGM_CRF_PseudoNLL_FC_par_bool(w,Xnode,Xedge,Y,nodeMap,edgeMap,edgeStruct)

[nNodes,maxState] = size(nodeMap);
nNodeFeatures = size(Xnode,2);
nEdgeFeatures = size(Xedge,2);
nEdges = edgeStruct.nEdges;
edgeEnds = edgeStruct.edgeEnds;
V = edgeStruct.V;
E = edgeStruct.E;
nStates = edgeStruct.nStates;

nInstances = size(Y{1},1);
nPar=length(Xnode);
NLLs = cell(nPar,1);
gs = cell(nPar,1);



parfor p = 1:nPar
    NLL = 0;
    g = zeros(size(w));
    Xnod=Xnode{p};
    Xedg=Xedge{p};
    Ysub=Y{p};
%     for i = 1:nInstances
%         
%         % Make potentials
%         [nodePot,edgePot] = UGM_CRF_makePotentialsC_FC(w,double(Xnod(i,:)),double(Xedg(i,:)),nodeMap,edgeMap,nStates,edgeEnds,int32(i));
%         
%         % Updates in-place
%         UGM_CRF_PseudoNLLC_FC(NLL,g,int32(i),nodePot,edgePot,edgeEnds,int32(V),int32(E),int32(nStates),int32(nodeMap),int32(edgeMap),double(Xnod(i,:)),double(Xedg(i,:)),int32(Ysub(i,:)));
%         
%     end
[NLL,g]=UGM_CRF_PseudoNLL_FC_fast(w,Xnod,Xedg,Ysub,int32(nodeMap),int32(edgeMap),edgeStruct);
    gs{p}=g;
    NLLs{p}=NLL;
end

NLL = 0;
g = zeros(size(w));

for p = 1:nPar
    NLL=NLL+NLLs{p};
    g = g + gs{p};
end


