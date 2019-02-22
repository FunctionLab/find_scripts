function [NLL,g] = UGM_CRF_PseudoNLL_FC_par(w,Xnode,Xedge,Y,nodeMap,edgeMap,edgeStruct)

[nNodes,maxState] = size(nodeMap);

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
    for i = 1:nInstances
        
        % Make potentials
        [nodePot,edgePot] = UGM_CRF_makePotentialsC_FC(w,Xnod(i,:),Xedg(i,:),nodeMap,edgeMap,nStates,edgeEnds,int32(i));
        
        % Updates in-place
        UGM_CRF_PseudoNLLC_FC2(NLL,g,int32(i),nodePot,edgePot,edgeEnds,V,E,nStates,nodeMap,edgeMap,Xnod(i,:),Xedg(i,:),int32(Ysub(i,:)));
        
    end
    gs{p}=g;
    NLLs{p}=NLL;
end

NLL = 0;
g = zeros(size(w));

for p = 1:nPar
    NLL=NLL+NLLs{p};
    g = g + gs{p};
end

