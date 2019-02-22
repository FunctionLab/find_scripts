#include <math.h>
#include "mex.h"
#include "UGM_common.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
   /* Variables */
    int n, s,e,emap,n1,n2,neigh,Vind,s1,s2,
    nNodes,nNodesClamped, nEdges, maxState, dims[3],
    iter,maxIter,clampVar,edgeVar,
    *edgeEnds, *nStates, *V, *E,*y, *clamped,*regulVarMap, *edgeMap;
    
    double *nodePot, *edgePot, *nodeBel, *edgeBel,*clampedNB, *clampedEB;
    
   /* Input */
    
    clampedNB = mxGetPr(prhs[0]);
    clampedEB = mxGetPr(prhs[1]);
    nodePot = mxGetPr(prhs[2]);
    edgePot = mxGetPr(prhs[3]);
    edgeMap = (int*)mxGetPr(prhs[4]);
    edgeEnds = (int*)mxGetPr(prhs[5]);
    clamped = (int*)mxGetPr(prhs[6]);
    regulVarMap = (int*)mxGetPr(prhs[7]);
    
	if (!mxIsClass(prhs[4],"int32")||!mxIsClass(prhs[5],"int32")||!mxIsClass(prhs[6],"int32")||!mxIsClass(prhs[7],"int32"))
		mexErrMsgTxt("edgeMap, edgeEnds, clamped, regularVar must be int32");
	
   /* Compute Sizes */
    
    nNodes = mxGetDimensions(prhs[2])[0];
    nNodesClamped = mxGetDimensions(prhs[0])[0];
    maxState = mxGetDimensions(prhs[2])[1];
    nEdges = mxGetDimensions(prhs[3])[2];
    
   /* Output */
    plhs[0] = mxCreateDoubleMatrix(nNodes,maxState,mxREAL);
    dims[0] = maxState;
    dims[1] = maxState;
    dims[2] = nEdges;
    plhs[1] = mxCreateNumericArray(3,dims,mxDOUBLE_CLASS,mxREAL);
    nodeBel = mxGetPr(plhs[0]);
    edgeBel = mxGetPr(plhs[1]);
    
    /* Initialize */
    for(n = 0; n < nNodes; n++)
    {
        /* Initialize nodeBel to nodePot */
        if(clamped[n]!=0)
            nodeBel[n + nNodes*(clamped[n]-1)] = 1;
        else{
            nodeBel[n + nNodes*(0)] =clampedNB[regulVarMap[n]-1+ nNodesClamped*0];
            nodeBel[n + nNodes*(1)] =clampedNB[regulVarMap[n]-1+ nNodesClamped*1];
        }
            
    }
    
      
    /* Compute edgeBel */
    for(e = 0; e < nEdges; e++)
    {
        n1 = edgeEnds[e]-1;
        n2 = edgeEnds[e+nEdges]-1;
        
        if (clamped[n1]!=0){
            if (clamped[n2]!=0)
                edgeBel[clamped[n1]-1+maxState*(clamped[n2]-1+maxState*e)] = 1;
            else{
                edgeBel[clamped[n1]-1+maxState*(0+maxState*e)] = clampedNB[regulVarMap[n2]-1+ nNodesClamped*0];
                edgeBel[clamped[n1]-1+maxState*(1+maxState*e)] = clampedNB[regulVarMap[n2]-1+ nNodesClamped*1];
            }
        }else{
            if (clamped[n2]!=0){
                edgeBel[0+maxState*(clamped[n2]-1+maxState*e)] = clampedNB[regulVarMap[n1]-1+ nNodesClamped*0];
                edgeBel[1+maxState*(clamped[n2]-1+maxState*e)] = clampedNB[regulVarMap[n1]-1+ nNodesClamped*1];
            }
            else{
                emap = edgeMap[e]-1;
                edgeBel[0+maxState*(0+maxState*e)] = clampedEB[0+maxState*(0+maxState*emap)];
                edgeBel[0+maxState*(1+maxState*e)] = clampedEB[0+maxState*(1+maxState*emap)];
                edgeBel[1+maxState*(0+maxState*e)] = clampedEB[1+maxState*(0+maxState*emap)];
                edgeBel[1+maxState*(1+maxState*e)] = clampedEB[1+maxState*(1+maxState*emap)];
            }
        }

    }
    

}
