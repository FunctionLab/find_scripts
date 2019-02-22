/*
 * matdiff_mex.c
 *
 * Code generation for function 'matdiff'
 *
 * C source code generated on: Sun Sep 09 23:00:54 2012
 *
 */

/* Include files */
#include "mex.h"
#include "matdiff_api.h"
#include "matdiff_initialize.h"
#include "matdiff_terminate.h"

/* Type Definitions */

/* Function Declarations */
static void matdiff_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "matdiff", NULL, false, NULL };

/* Function Definitions */
static void matdiff_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Temporary copy for mex outputs. */
  mxArray *outputs[1];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  matdiffStackData* matdiffStackDataLocal = (matdiffStackData*)mxCalloc(1,sizeof(matdiffStackData));
  /* Check for proper number of arguments. */
  if(nrhs != 2) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:WrongNumberOfInputs","2 inputs required for entry-point 'matdiff'.");
  } else if(nlhs > 1) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:TooManyOutputArguments","Too many output arguments for entry-point 'matdiff'.");
  }
  /* Module initialization. */
  matdiff_initialize(&emlrtContextGlobal);
  /* Call the function. */
  matdiff_api(matdiffStackDataLocal, prhs,(const mxArray**)outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  matdiff_terminate();
  mxFree(matdiffStackDataLocal);
}
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(matdiff_atexit);
  emlrtClearAllocCount(&emlrtContextGlobal, 0, 0, NULL);
  /* Dispatch the entry-point. */
  matdiff_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (matdiff_mex.c) */
