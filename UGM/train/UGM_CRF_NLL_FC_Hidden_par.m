function [NLL,g] = UGM_CRF_NLL_FC_Hidden_par(w,Xnode,Xedge,Y,nodeMap,edgeMap,edgeStruct,inferFunc,varargin)

[nNodes,maxState] = size(nodeMap);

edgeEnds = edgeStruct.edgeEnds;
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
        if edgeStruct.useMex
            [nodePot,edgePot] = UGM_CRF_makePotentialsC_FC(w,Xnod(i,:),Xedg(i,:),nodeMap,edgeMap,nStates,edgeEnds,int32(i));
        else
            [nodePot,edgePot] = UGM_CRF_makePotentials_FC(w,Xnod,Xedg,nodeMap,edgeMap,edgeStruct,i);
        end
        
        % Compute marginals and logZ
        [nodeBel,edgeBel,logZ] = inferFunc(nodePot,edgePot,edgeStruct,varargin{:});
        
        
        
        % Compute Clamped Potential for Latent Variables
        % Make potentials
        
        [nodeBelC,edgeBelC,logZC] =  UGM_Infer_Conditional_FC(nodePot,edgePot,edgeStruct,int32(Ysub(i,:)),inferFunc,varargin{:});
        
        
        % Update NLL
        if edgeStruct.useMex
            NLL = NLL - (logZC+UGM_LogConfigurationPotentialC_Hidden(int32(Ysub(i,:)),nodePot,edgePot,edgeEnds)) + logZ;
            % Updates in-place
            UGM_CRF_NLLC_FC_Hidden(g,int32(i),nodeBel,edgeBel,edgeEnds,nStates,nodeMap,edgeMap,Xnod(i,:),Xedg(i,:),int32(Ysub(i,:)),nodeBelC,edgeBelC);
            
        else
            NLL = NLL - (logZC+UGM_LogConfigurationPotential(Ysub(i,:),nodePot,edgePot,edgeEnds)) + logZ;
            
            if nargout > 1
                for n = 1:nNodes
                    for s = 1:nStates(n)
                        for f = 1:nNodeFeatures
                            if nodeMap(n,s,f) > 0
                                if (s) == Ysub(i,n)
                                    obs = 1;
                                else
                                    obs = 0;
                                end
                                g(nodeMap(n,s,f)) = g(nodeMap(n,s,f)) + Xnod(i,f)*(nodeBel(n,s) - obs);
                            end
                        end
                    end
                end
                for e = 1:nEdges
                    n1 = edgeEnds(e,1);
                    n2 = edgeEnds(e,2);
                    for s1 = 1:nStates(n1)
                        for s2 = 1:nStates(n2)
                            for f = 1:nEdgeFeatures
                                if edgeMap(s1,s2,e,f) > 0
                                    if (s1) == Ysub(i,n1) && (s2) == Ysub(i,n2)
                                        obs = 1;
                                    else
                                        obs = 0;
                                    end
                                    g(edgeMap(s1,s2,e,f)) = g(edgeMap(s1,s2,e,f)) +(edgeBel(s1,s2,e) - obs);
                                end
                            end
                        end
                    end
                end
            end
        end
        
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