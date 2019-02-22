#include <math.h>
#include "mex.h"
#include "UGM_common.h"
#include <omp.h>


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Variables */
    int i,n, s, f, e, k, n1, n2, s1, s2, nInstances,nNodes, nEdges, nNodeFeatures, nEdgeFeatures,nSamples, *nStates, maxState,
            *nodeMap, *edgeMap, *edgeEnds, dims[4],dims2[3];
    
    double *w, *Xnodes, *Xedges, *nodePot, *edgePot, pot;
        
    /* Input */
    w = (double*)mxGetPr(prhs[0]);
    Xnodes = (double*)mxGetPr(prhs[1]);
    Xedges = (double*)mxGetPr(prhs[2]);
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
    nodePot = (double*)mxGetPr(plhs[0]);
    

    
#pragma omp parallel for  schedule(static) default(shared) private(k,n,s,f,s1,s2,e,n1,n2,pot) 
    for(k = 0; k < nSamples; k++){
        for(n = 0; n < nNodes; n++) {
            for(s = 0; s < nStates[n]; s++) {
                pot=0;
                for(f = 0; f < nNodeFeatures; f++) {
                    if(nodeMap[n + nNodes*(s + maxState*f)] > 0) {
                        pot += w[nodeMap[n+nNodes*(s+maxState*f)]-1]*Xnodes[k+(f*nSamples)];
                    }
                }
                nodePot[n+nNodes*(s+k*maxState)] = exp(pot);
            }
        }
    
    }
}
