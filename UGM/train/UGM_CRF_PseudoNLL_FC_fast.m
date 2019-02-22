function [NLL,g] = UGM_CRF_PseudoNLL_FC_fast(w,Xnode,Xedge,Y,nodeMap,edgeMap,edgeStruct)

[nNodes,maxState] = size(nodeMap);
nNodeFeatures = size(Xnode,2);
nEdgeFeatures = size(Xedge,2);
nEdges = edgeStruct.nEdges;
edgeEnds = edgeStruct.edgeEnds;
V = edgeStruct.V;
E = edgeStruct.E;
nStates = edgeStruct.nStates;

nInstances = size(Y,1);
NLL = 0;
g = zeros(size(w));



nodemap=nodeMap(:,2,:);
edgemap=edgeMap(2,2,:,1);
logPotMat=zeros(nNodes);
logPotMat(edgeEnds(:,1)+nNodes*(edgeEnds(:,2)-1))=w(edgemap(edgemap~=0));
logPotMat=logPotMat+logPotMat';


wtemp=zeros(nNodes,nNodeFeatures);
wtemp(nodemap~=0)=w(nodemap(nodemap~=0));

nodeBels = exp(Y*logPotMat+Xnode* wtemp');
NLL = NLL - (sum(log(nodeBels(Y==1)))-sum(sum(log(1+nodeBels))));
nodeBels = nodeBels./(nodeBels+1);

%note we assume that Xedge is an all-1 vector.
gMatCond=double(nodeBels-Y)'*Xnode; 



% gMat= repmat(sum(nodeBels,1),nNodes,1);
gMat = (nodeBels'-Y')*Y + Y'*(nodeBels-Y);


    

    g(nodemap(nodemap~=0))=gMatCond(nodemap~=0);
    edgemap=edgeMap(2,2,:,1);
    g(edgemap(edgemap~=0))=gMat(edgeEnds(:,1)+nNodes*(edgeEnds(:,2)-1));

% 
% for i = 1:nInstances
%     % Make potentials
%     if edgeStruct.useMex
%         [nodePot,edgePot] = UGM_CRF_makePotentialsC_FC(w,Xnode(i,:),Xedge(i,:),nodeMap,edgeMap,nStates,edgeEnds,int32(i));
% 		
%         % Updates in-place
%         UGM_CRF_PseudoNLLC_FC2(NLL,g,int32(i),nodePot,edgePot,edgeEnds,V,E,nStates,nodeMap,edgeMap,Xnode(i,:),Xedge(i,:),int32(Y(i,:)));
%     else
%         [nodePot,edgePot] = UGM_CRF_makePotentials_FC(w,Xnode,Xedge,nodeMap,edgeMap,edgeStruct,i);
%         
%         for n = 1:nNodes
%             % Find Neighbors
%             edges = E(V(n):V(n+1)-1);
%             
%             % Compute Probability of Each State with Neighbors Fixed
%             pot = nodePot(n,1:nStates(n));
%             for e = edges(:)'
%                 n1 = edgeEnds(e,1);
%                 n2 = edgeEnds(e,2);
%                 
%                 if n == edgeEnds(e,1)
%                     ep = edgePot(1:nStates(n),Y(i,n2)+1,e).';
%                 else
%                     ep = edgePot(Y(i,n1)+1,1:nStates(n),e);
%                 end
%                 pot = pot .* ep;
%             end
%             
%             % Update Objective
%             NLL = NLL - log(pot(Y(i,n)+1)) + log(sum(pot));
%             
%             %% Update Gradient
%             if nargout > 1
%                 nodeBel = pot/sum(pot);
%                 
%                 % Update Gradient of Node Weights
%                 for s = 1:nStates(n)
%                     for f = 1:nNodeFeatures
%                         if nodeMap(n,s,f) > 0
%                             if s == Y(i,n)+1
%                                 obs = 1;
%                             else
%                                 obs = 0;
%                             end
%                             g(nodeMap(n,s,f)) = g(nodeMap(n,s,f)) + Xnode(i,f)*(nodeBel(s) - obs);
%                         end
%                     end
%                 end
%                 
%                 % Update Gradient of Edge Weights
%                 for e = edges(:)'
%                     
%                     n1 = edgeEnds(e,1);
%                     n2 = edgeEnds(e,2);
%                     
%                     for s = 1:nStates(n)
%                         if n == n1
%                             s1 = s;
%                             neigh = n2;
%                             s2 = Y(i,neigh)+1;
%                         else
%                             s2 = s;
%                             neigh = n1;
%                             s1 = Y(i,neigh)+1;
%                         end
%                         for f = 1:nEdgeFeatures
%                             if edgeMap(s1,s2,e,f) > 0
%                                 if s == Y(i,n)+1
%                                     obs = 1;
%                                 else
%                                     obs = 0;
%                                 end
%                                 g(edgeMap(s1,s2,e,f)) = g(edgeMap(s1,s2,e,f)) + 1*(nodeBel(s) - obs);
%                             end
%                         end
%                     end
%                 end
%             end
%         end
%     end
% end
