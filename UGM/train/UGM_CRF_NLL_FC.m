function [NLL,g] = UGM_CRF_NLL_FC(w,subXnode,subXedge,suby,nodeMap,edgeMap,edgeStruct,inferFunc,varargin)

[nNodes,maxState] = size(nodeMap);
nNodeFeatures = size(subXnode,2);
nEdgeFeatures = size(subXedge,2);
nEdges = edgeStruct.nEdges;
edgeEnds = edgeStruct.edgeEnds;
nStates = edgeStruct.nStates;

nInstances = size(suby,1);
NLL = 0;
g = zeros(size(w));

for i = 1:nInstances

    % Make potentials
     if edgeStruct.useMex
         [nodePot,edgePot] = UGM_CRF_makePotentialsC_FC(w,subXnode(i,:),subXedge(i,:),nodeMap,edgeMap,nStates,edgeEnds,int32(i));
     else
        [nodePot,edgePot] = UGM_CRF_makePotentials_FC(w,subXnode,subXedge,nodeMap,edgeMap,edgeStruct,i);
     end
    
    % Compute marginals and logZ
    [nodeBel,edgeBel,logZ] = inferFunc(nodePot,edgePot,edgeStruct,varargin{:});
    
    % Update NLL
    if edgeStruct.useMex
        NLL = NLL - UGM_LogConfigurationPotentialC(int32(suby(i,:)+1),nodePot,edgePot,edgeEnds) + logZ;
        % Updates in-place
        UGM_CRF_NLLC_FC(g,int32(i),nodeBel,edgeBel,edgeEnds,nStates,nodeMap,edgeMap,subXnode(i,:),subXedge(i,:),int32(suby(i,:)));

    else
        NLL = NLL - UGM_LogConfigurationPotential(suby(i,:)+1,nodePot,edgePot,edgeEnds) + logZ;
        
        if nargout > 1
            for n = 1:nNodes
                for s = 1:nStates(n)
                    for f = 1:nNodeFeatures
                        if nodeMap(n,s,f) > 0
                            if (s-1) == suby(i,n)
                                obs = 1;
                            else
                                obs = 0;
                            end
                            g(nodeMap(n,s,f)) = g(nodeMap(n,s,f)) + subXnode(i,f)*(nodeBel(n,s) - obs);
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
                                if (s1-1) == suby(i,n1) && (s2-1) == suby(i,n2)
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