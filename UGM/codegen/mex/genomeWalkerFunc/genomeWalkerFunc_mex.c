/*
 * genomeWalkerFunc_mex.c
 *
 * Code generation for function 'genomeWalkerFunc'
 *
 * C source code generated on: Mon Sep 10 17:00:55 2012
 *
 */

/* Include files */
#include "mex.h"
#include "genomeWalkerFunc_api.h"
#include "genomeWalkerFunc_initialize.h"
#include "genomeWalkerFunc_terminate.h"

/* Type Definitions */

/* Function Declarations */
static void genomeWalkerFunc_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "genomeWalkerFunc", NULL, false, NULL };

/* Function Definitions */
static void genomeWalkerFunc_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Temporary copy for mex outputs. */
  mxArray *outputs[5];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  genomeWalkerFuncStackData* genomeWalkerFuncStackDataLocal = (genomeWalkerFuncStackData*)mxCalloc(1,sizeof(genomeWalkerFuncStackData));
  /* Check for proper number of arguments. */
  if(nrhs != 6) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:WrongNumberOfInputs","6 inputs required for entry-point 'genomeWalkerFunc'.");
  } else if(nlhs > 5) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:TooManyOutputArguments","Too many output arguments for entry-point 'genomeWalkerFunc'.");
  }
  /* Module initialization. */
  genomeWalkerFunc_initialize(&emlrtContextGlobal);
  /* Call the function. */
  genomeWalkerFunc_api(genomeWalkerFuncStackDataLocal, prhs,(const mxArray**)outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  genomeWalkerFunc_terminate();
  mxFree(genomeWalkerFuncStackDataLocal);
}
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(genomeWalkerFunc_atexit);
  emlrtClearAllocCount(&emlrtContextGlobal, 0, 0, NULL);
  /* Dispatch the entry-point. */
  genomeWalkerFunc_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (genomeWalkerFunc_mex.c) */
