#include <math.h>
#include "mex.h"
#include "UGM_common.h"
#include <omp.h>


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Variables */
    
    int n, n1, n2, e, k,
            nNodes, nEdges, nSamples, maxState,dims[2],
            *edgeEnds, *y;
    double *nodePot, *edgePot, *logPot;
    
    /* Input */
    y = (int*)mxGetPr(prhs[0]);
    nodePot = mxGetPr(prhs[1]);
    edgePot = mxGetPr(prhs[2]);
    edgeEnds = (int*)mxGetPr(prhs[3]);
	
	if (!mxIsClass(prhs[0],"int32")||!mxIsClass(prhs[3],"int32"))
		mexErrMsgTxt("y, edgeEnds must be int32");
    
    /* Compute Sizes */
    nNodes = mxGetDimensions(prhs[1])[0];
    maxState = mxGetDimensions(prhs[1])[1];
    nEdges = mxGetDimensions(prhs[3])[0];
    nSamples = mxGetDimensions(prhs[0])[1];

    /* Output */
    dims[0] = 1;
    dims[1] = nSamples;
    plhs[0] = mxCreateNumericArray(2,dims,mxDOUBLE_CLASS,mxREAL);
    
    logPot = mxGetData(plhs[0]);
    
#pragma omp parallel for schedule(dynamic) default(shared) private(k,n,e,n1,n2)
    for(k = 0; k < nSamples; k++){
        logPot[k] = 0;
        for(n = 0; n < nNodes; n++) {
            if(y[n+ nNodes*k]!=0)
                logPot[k] += log(nodePot[n + nNodes*(y[n+ nNodes*k]-1+ k*maxState )]);
        }
        for(e = 0; e < nEdges; e++) {
            n1 = edgeEnds[e]-1;
            n2 = edgeEnds[e+nEdges]-1;
            if(y[n1+ nNodes*k]!=0 && y[n2+ nNodes*k]!=0)
                logPot[k] += log(edgePot[y[n1+ nNodes*k]-1 + maxState*(y[n2+ nNodes*k]-1 + maxState*e)]);
        }
    
    }
}
