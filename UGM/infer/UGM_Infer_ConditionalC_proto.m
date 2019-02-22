function [nodeBel,edgeBel] = UGM_Infer_ConditionalC(clampedNB,clampedEB,nodePot,edgePot,edgeMap,edgeEnds,clamped,regulVarMap)

[nNodes,~] = size(nodePot);
nEdges = size(edgePot,3);


nodeBel = zeros(size(nodePot));

for n = 1:nNodes
    if clamped(n)~=0
        nodeBel(n,clamped(n)) = 1;
    else
       nodeBel(n,:) = clampedNB(regulVarMap(n),:);
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