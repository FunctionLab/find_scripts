#include <math.h>
#include "mex.h"
#include "UGM_common.h"
#include <omp.h>
#include <time.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    /* Variables */
    int i,n,s,e,k,n1,n2,Vind,maxIter,burnIn,
            nNodes, nEdges, nSamples, maxState, dims[2],
            *edgeEnds, *nStates, *V, *E,*y,*S,*tempy;
    
    double *pot,z,U,u,
            *nodePot, *edgePot;
    
    /* Input */
    
    nodePot = mxGetPr(prhs[0]);
    edgePot = mxGetPr(prhs[1]);
    edgeEnds = (int*)mxGetPr(prhs[2]);
    nStates = (int*)mxGetPr(prhs[3]);
    V = (int*)mxGetPr(prhs[4]);
    E = (int*)mxGetPr(prhs[5]);
    maxIter = ((int*)mxGetPr(prhs[6]))[0];
    burnIn = ((int*)mxGetPr(prhs[7]))[0];
    y = (int*)mxGetPr(prhs[8]);
    
    if (!mxIsClass(prhs[2],"int32")||!mxIsClass(prhs[3],"int32")||!mxIsClass(prhs[4],"int32")||!mxIsClass(prhs[5],"int32")||!mxIsClass(prhs[6],"int32")||!mxIsClass(prhs[7],"int32")||!mxIsClass(prhs[8],"int32"))
        mexErrMsgTxt("edgeEnds, nStates, V, E, maxIter, burnIn, y must be int32");
    
    /* Compute Sizes */
    
    nNodes = mxGetDimensions(prhs[0])[0];
    maxState = mxGetDimensions(prhs[0])[1];
    nEdges = mxGetDimensions(prhs[2])[0];
    nSamples = mxGetDimensions(prhs[8])[1];
    
    /* Output */
    
    dims[0] = nNodes;
    dims[1] = nSamples;
    plhs[0] = mxCreateNumericArray(2,dims,mxINT32_CLASS,mxREAL);
    S = mxGetData(plhs[0]);
    
    /* Initialize to States with highest node potentials*/
    /* for(n = 0; n < nNodes; n++)
     * {
     * u = -1;
     * U = 0;
     * for(s = 0; s < nStates[n]; s++)
     * {
     * if(nodePot[n+nNodes*s] > u)
     * {
     * u = nodePot[n+nNodes*s];
     * U = s;
     * }
     * }
     * y[n] = U;
     * }
     */
    /*omp_set_num_threads(4);*/
#pragma omp parallel  default(shared) private(k,i,n,s,e,z,U,u,n1,n2,Vind,pot,tempy)
{
    srand( ((int)time(NULL))^omp_get_thread_num());
#pragma omp for schedule(dynamic)
    for(k = 0; k < nSamples; k++){
        /*pot = mxCalloc(maxState,sizeof(double));*/
        
        pot = calloc(2,sizeof(double));
        tempy = (int*)calloc(nNodes,sizeof(int));
        for(n = 0; n < nNodes; n++)
            tempy[n]=y[n+ nNodes*k]-1;
        
        for(i = 0; i < burnIn+maxIter; i++)
        {
            
            for(n = 0; n < nNodes; n++)
            {
                /* Compute Node Potential */
                for(s = 0; s < nStates[n]; s++)
                {
                    pot[s] = nodePot[n + nNodes*(s + k*maxState )];
                }
                
                /* Iterate over Neighbors */
                for(Vind = V[n]-1; Vind < V[n+1]-1; Vind++)
                {
                    e = E[Vind]-1;
                    n1 = edgeEnds[e]-1;
                    n2 = edgeEnds[e+nEdges]-1;
                    
                    /* Multiply Edge Potentials */
                    if(n == n1)
                    {
                        for(s = 0; s < nStates[n]; s++)
                        {
                            pot[s] *= edgePot[s+maxState*(tempy[n2] + maxState*(e + k*nEdges))];
                        }
                        
                    }
                    else
                    {
                        for(s = 0; s < nStates[n]; s++)
                        {
                            pot[s] *= edgePot[tempy[n1]+maxState*(s + maxState*(e + k*nEdges))];
                        }
                    }
                    
                }
                
                /* Normalize */
                z = 0;
                for(s = 0; s < nStates[n]; s++)
                    z = z + pot[s];
                for(s = 0; s < nStates[n]; s++)
                    pot[s] /= z;
                
                /* Display */
                for(s = 0; s < nStates[n]; s++)
                    
                    /* Sample Discrete State */
                    U = rand()/((double)RAND_MAX + 1);
                u = 0;
                for(s = 0; s < nStates[n]; s++)
                {
                    u += pot[s];
                    if(u > U)
                    {
                        break;
                    }
                }
                tempy[n] = s;
            }
            
            
        }
        /* Record Sample */
        for(n = 0; n < nNodes; n++)
        {
            S[n + nNodes*k] = tempy[n]+1;
        }
        /* Free memory */
        /*mxFree(pot);*/
        free(pot);
        free(tempy);
    }
}


}
