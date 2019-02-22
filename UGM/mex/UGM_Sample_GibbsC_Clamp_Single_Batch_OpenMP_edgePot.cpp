#include <math.h>
#include "mex.h"
#include "UGM_common.h"
#include <omp.h>
#include <trng/yarn2.hpp>
#include <trng/uniform01_dist.hpp>


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    /* Variables */
    int i,n,k,s,e,n1,n2,Vind,maxIter,burnIn,
            nNodes, nEdges,nSamples, maxState, dims[2],
            *edgeEnds, *nStates, *V, *E,*y,*S,*notclamp;
    
    double *pot,z,U,u,
            *nodePot, *edgePot;
    
    int max=omp_get_max_threads();
    omp_set_num_threads(max);
    int rank;
    trng::yarn2 * gen;
    gen=new trng::yarn2[max];
    trng::uniform01_dist<> uu;
    
    unsigned long myseed = (unsigned long)time(NULL);
    for (int i = 0; i < max; i++)
    {
        gen[i].seed(myseed);
        gen[i].split(max,i);
    }
    
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
    notclamp = (int*)mxGetPr(prhs[9]);
    
    if (!mxIsClass(prhs[2],"int32")||!mxIsClass(prhs[9],"int32")||!mxIsClass(prhs[3],"int32")||!mxIsClass(prhs[4],"int32")||!mxIsClass(prhs[5],"int32")||!mxIsClass(prhs[6],"int32")||!mxIsClass(prhs[7],"int32")||!mxIsClass(prhs[8],"int32"))
        mexErrMsgTxt("edgeEnds, nStates, V, E, maxIter, burnIn, y, clamp must be int32");
    
    /* Compute Sizes */
    
    nNodes = mxGetDimensions(prhs[0])[0];
    maxState = mxGetDimensions(prhs[0])[1];
    nEdges = mxGetDimensions(prhs[2])[0];
    nSamples = mxGetDimensions(prhs[8])[1];
    /* Output */
    /* pot = mxCalloc(maxState,sizeof(double));*/
    dims[0] = nNodes;
    dims[1] = nSamples;
    plhs[0] = mxCreateNumericArray(2,dims,mxINT32_CLASS,mxREAL);
    S = (int*)mxGetData(plhs[0]);
    
    /* Initialize to States with highest node potentials
     * //      for(n = 0; n < nNodes; n++)
     * //     {
     * //          if(y[n]==0){
     * //             u = -1;
     * //             U = 0;
     * //             for(s = 0; s < nStates[n]; s++)
     * //             {
     * //                 if(nodePot[n+nNodes*s] > u)
     * //                 {
     * //                     u = nodePot[n+nNodes*s];
     * //                     U = s;
     * //                 }
     * //             }
     * //             y[n] = U+1;
     * //          }
     * //     }
     * //     */
#pragma omp parallel for schedule(dynamic) default(shared) private(k,i,n,s,e,z,U,u,n1,n2,Vind,pot,rank)
    for(k = 0; k < nSamples; k++){
        rank=omp_get_thread_num();
        pot = (double*)calloc(2,sizeof(double));
        for(n = 0; n < nNodes; n++)
            y[n+ nNodes*k]--;
        
        for(i = 0; i < burnIn+maxIter; i++)
        {
            
            for(n = 0; n < nNodes; n++)
            {
                if(notclamp[k + n*nSamples]==1){
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
                                pot[s] *= edgePot[s+maxState*(y[n2+ nNodes*k] + maxState*(e ))];
                            }
                            
                        }
                        else
                        {
                            for(s = 0; s < nStates[n]; s++)
                            {
                                pot[s] *= edgePot[y[n1+ nNodes*k]+maxState*(s + maxState*(e ))];
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
                        U =  uu(gen[rank]);
                    u = 0;
                    for(s = 0; s < nStates[n]; s++)
                    {
                        u += pot[s];
                        if(u > U)
                        {
                            break;
                        }
                    }
                    y[n+ nNodes*k] = s;
                }
            }
            
            
        }
        /* Record Sample */
        for(n = 0; n < nNodes; n++)
        {
            S[n + nNodes*k] = y[n+ nNodes*k]+1;
        }
        /* Free memory */
        free(pot);
    }
    /*mxFree(pot);*/
}
