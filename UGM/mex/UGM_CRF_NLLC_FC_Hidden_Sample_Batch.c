#include <math.h>
#include "mex.h"
#include "UGM_common.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /* Variables */
    
    int n, s, f, n1, n2, s1, s2, i,e,k, nSamples,
             nNodes, nNodeFeatures, nEdges, maxState, nEdgeFeatures,
            *edgeEnds, *nStates, *nodeMap, *edgeMap, *Y,*sampleBel,*sampleBelc;
    double obs, *g,  *Xnode, *Xedge;
    
    /* Input */
    g = mxGetPr(prhs[0]);
    i = (int)mxGetScalar(prhs[1])-1;
    sampleBel = (int*)mxGetPr(prhs[2]);
    sampleBelc = (int*)mxGetPr(prhs[3]);
    edgeEnds = (int*)mxGetPr(prhs[4]);
    nStates = (int*)mxGetPr(prhs[5]);
    nodeMap = (int*)mxGetPr(prhs[6]);
    edgeMap = (int*)mxGetPr(prhs[7]);
    Xnode = mxGetPr(prhs[8]);
    Xedge = mxGetPr(prhs[9]);
    Y = (int*)mxGetPr(prhs[10]);

	
	if (!mxIsClass(prhs[1],"int32")||!mxIsClass(prhs[2],"int32")||!mxIsClass(prhs[3],"int32")||!mxIsClass(prhs[4],"int32")||!mxIsClass(prhs[5],"int32")||!mxIsClass(prhs[6],"int32")||!mxIsClass(prhs[7],"int32")||!mxIsClass(prhs[10],"int32"))
		mexErrMsgTxt("edgeEnds, nStates, nodeMap, edgeMap, i, Y must be int32");
    
    /* Compute Sizes */
    nSamples = mxGetDimensions(prhs[10])[0];
    nNodeFeatures = mxGetDimensions(prhs[8])[1];
    nNodes = mxGetDimensions(prhs[6])[0];
    nEdgeFeatures = 1;
    nEdges = mxGetDimensions(prhs[4])[0];
    maxState = getMaxState(nStates, nNodes);

    for(k = 0; k < nSamples; k++){
    for(n = 0; n < nNodes; n++) {
        for(s = 0; s < nStates[n]; s++) {
            for(f = 0; f < nNodeFeatures; f++) {
                if(nodeMap[n + nNodes*(s + maxState*f)] > 0) {
                    if (Y[k+n*nSamples] == 0){
                        obs = (sampleBelc[n+k*nNodes]-1) == s;
                    }else if(s == Y[k+n*nSamples]-1) {
                        obs = 1;
                    }
                    else {
                        obs = 0;
                    }
                    g[nodeMap[n + nNodes*(s + maxState*f)]-1] += Xnode[k+f*nSamples]*( (sampleBel[n+k*nNodes]-1 == s) - obs);
                }
            }
        }
    }
     
   
    for(e = 0; e < nEdges; e++) {
        n1 = edgeEnds[e]-1;
        n2 = edgeEnds[e+nEdges]-1;
        
        for (s1 = 0; s1 < nStates[n1]; s1++) {
            for (s2 = 0; s2 < nStates[n2]; s2++) {
                for (f = 0; f < nEdgeFeatures; f++) {
                    if (edgeMap[s1 + maxState*(s2 + maxState*(e + nEdges*f))] > 0) {
                        if (Y[k+n1*nSamples] == 0 && Y[k+n2*nSamples] == 0)
                            obs = sampleBelc[n1+k*nNodes]-1 ==s1 && sampleBelc[n2+k*nNodes]-1 == s2;
                        else if (Y[k+n1*nSamples] == 0 && Y[k+n2*nSamples]-1 == s2)
                            obs = sampleBelc[n1+k*nNodes]-1 ==s1 && sampleBelc[n2+k*nNodes] == Y[k+n2*nSamples];
                        else if (Y[k+n1*nSamples]-1 == s1 && Y[k+n2*nSamples] == 0)
                            obs = sampleBelc[n1+k*nNodes] ==Y[k+n1*nSamples] && sampleBelc[n2+k*nNodes]-1 == s2;
                        else if (s1 == Y[k+n1*nSamples]-1 && s2 == Y[k+n2*nSamples]-1) {
                            obs = 1;
                        }
                        else { 
                            obs = 0;
                        }
                        g[edgeMap[s1 + maxState*(s2 + maxState*(e + nEdges*f))]-1] += (( sampleBel[n1+k*nNodes]-1 ==s1 && sampleBel[n2+k*nNodes]-1 == s2) - obs);
                    }
                }
            }
        }
    }
}    
}
