function [nodeBel, edgeBel, logZ] = UGM_Infer_Conditional_FC(nodePot,edgePot,edgeStruct,clamped,inferFunc,varargin)
% Do inference with observed values

[nNodes,maxState] = size(nodePot);
nEdges = size(edgePot,3);
edgeEnds = edgeStruct.edgeEnds;

[clampedNP,clampedEP,clampedES,edgeMap] = UGM_makeClampedPotentials(nodePot,edgePot,edgeStruct,clamped);

[clampedNB,clampedEB,logZ] = inferFunc(clampedNP,clampedEP,clampedES,varargin{:});

% Construct node beliefs

 if edgeStruct.useMex
     regularVar=zeros(size(clamped));
	 regularVar(clamped==0)=1:sum(clamped==0);
     [nodeBel,edgeBel] = UGM_Infer_ConditionalC(clampedNB,clampedEB,nodePot,edgePot,int32(edgeMap),edgeEnds,int32(clamped),int32(regularVar));
 else
    nodeBel = zeros(size(nodePot));

    clampVar = 1;
    regulVar = 1;
    regulVarMap = zeros(size(clamped));
    for n = 1:nNodes
       if clamped(n)~=0
           nodeBel(n,clamped(n)) = 1;
           clampVar = clampVar+1;
       else
           nodeBel(n,:) = clampedNB(regulVar,:);
           regulVarMap(n) = regulVar;
           regulVar = regulVar + 1;
       end
    end

    % Construct edge beliefs
    edgeBel = zeros(size(edgePot));
    for e = 1:nEdges
       n1 = edgeEnds(e,1);
       n2 = edgeEnds(e,2);

       if clamped(n1)~=0
           if clamped(n2)~=0
               % This edge is between clamped variables
               edgeBel(clamped(n1),clamped(n2),e) = 1;
           else
               % n1 is a clamped variable, n2 is a regular variable
               edgeBel(clamped(n1),:,e) = clampedNB(regulVarMap(n2),:);
           end
       else
           if clamped(n2)~=0
               % n2 is a clamped variable, n1 is a regular variable
               edgeBel(:,clamped(n2),e) = clampedNB(regulVarMap(n1),:)';
           else
               % This edge was present in the clamped graph
               edgeBel(:,:,e) = clampedEB(:,:,edgeMap(e));
           end
       end
    end
end