#include <math.h>
#include "mex.h"
#include "UGM_common.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Variables */
    int i,n, s, f, e, k, n1, n2, s1, s2, nInstances,nNodes, nEdges, nNodeFeatures, nEdgeFeatures,nSamples, *nStates, maxState,
            *nodeMap, *edgeMap, *edgeEnds, dims[4],dims2[3];
    
    double *w, *Xnodes, *Xedges, *nodePot, *edgePot;
        
    /* Input */
    w = mxGetPr(prhs[0]);
    Xnodes = mxGetPr(prhs[1]);
    Xedges = mxGetPr(prhs[2]);
    nodeMap = (int*)mxGetPr(prhs[3]);
    edgeMap = (int*)mxGetPr(prhs[4]);
    nStates = (int*)mxGetPr(prhs[5]);
    edgeEnds = (int*)mxGetPr(prhs[6]);

	
	if (!mxIsClass(prhs[3],"int32")||!mxIsClass(prhs[4],"int32")||!mxIsClass(prhs[5],"int32")||!mxIsClass(prhs[6],"int32"))
		mexErrMsgTxt("edgeEnds, nStates, nodeMap, edgeMap, i must be int32");
    
    /* Compute Sizes */
    nNodes = mxGetDimensions(prhs[3])[0];
    nEdges = mxGetDimensions(prhs[6])[0];
    nInstances = mxGetDimensions(prhs[1])[0];
    nNodeFeatures = mxGetDimensions(prhs[1])[1];
    nEdgeFeatures = mxGetDimensions(prhs[2])[1];
    maxState = getMaxState(nStates, nNodes);
    nSamples = mxGetDimensions(prhs[1])[0];

    /*printf("%d,%d,%d,%d,%d\n", nNodes, nEdges, nNodeFeatures, nEdgeFeatures, maxState);*/
    /*printf("%d,%d\n",nInstances,i);*/
    
    /* Make output */
    dims2[0] = nNodes;
	dims2[1] = maxState;
	dims2[2] = nSamples;
    plhs[0] = mxCreateNumericArray(3, dims2, mxDOUBLE_CLASS, mxREAL);
    nodePot = mxGetPr(plhs[0]);
    
	/*dims[0] = maxState;
	dims[1] = maxState;
	dims[2] = nEdges;
    dims[3] = nSamples;
    plhs[1] = mxCreateNumericArray(4, dims, mxDOUBLE_CLASS, mxREAL);
    edgePot = mxGetPr(plhs[1]);*/
    
    for(k = 0; k < nSamples; k++){

        for(n = 0; n < nNodes; n++) {
            for(s = 0; s < nStates[n]; s++) {
                for(f = 0; f < nNodeFeatures; f++) {
                    if(nodeMap[n + nNodes*(s + maxState*f)] > 0) {
                        nodePot[n+nNodes*(s+k*maxState)] += w[nodeMap[n+nNodes*(s+maxState*f)]-1]*Xnodes[k+(f*nSamples)];
                    }
                }
                nodePot[n+nNodes*(s+k*maxState)] = exp(nodePot[n+nNodes*(s+k*maxState)]);
            }
        }


        for(e = 0; e < nEdges; e++) {
            n1 = edgeEnds[e]-1;
            n2 = edgeEnds[e+nEdges]-1;

            for (s1 = 0; s1 < nStates[n1]; s1++) {
                for (s2 = 0; s2 < nStates[n2]; s2++) {
                    for (f = 0; f < nEdgeFeatures; f++) {
                        if (edgeMap[s1 + maxState*(s2 + maxState*(e + nEdges*f))] > 0) {
                            edgePot[s1+maxState*(s2+maxState*(e+k*nEdges))] += w[edgeMap[s1+maxState*(s2+maxState*(e+nEdges*f))]-1];
                        }
                    }
                    edgePot[s1+maxState*(s2+maxState*(e+k*nEdges))] = exp(edgePot[s1+maxState*(s2+maxState*(e+k*nEdges))]);
                }
            }
        }
    
    }
}
