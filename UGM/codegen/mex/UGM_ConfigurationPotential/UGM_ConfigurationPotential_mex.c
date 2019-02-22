/*
 * UGM_ConfigurationPotential_mex.c
 *
 * Code generation for function 'UGM_ConfigurationPotential'
 *
 * C source code generated on: Mon Sep 10 15:47:03 2012
 *
 */

/* Include files */
#include "mex.h"
#include "UGM_ConfigurationPotential_api.h"
#include "UGM_ConfigurationPotential_initialize.h"
#include "UGM_ConfigurationPotential_terminate.h"

/* Type Definitions */

/* Function Declarations */
static void UGM_ConfigurationPotential_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "UGM_ConfigurationPotential", NULL, false, NULL };

/* Function Definitions */
static void UGM_ConfigurationPotential_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Temporary copy for mex outputs. */
  mxArray *outputs[1];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  /* Check for proper number of arguments. */
  if(nrhs != 4) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:WrongNumberOfInputs","4 inputs required for entry-point 'UGM_ConfigurationPotential'.");
  } else if(nlhs > 1) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:TooManyOutputArguments","Too many output arguments for entry-point 'UGM_ConfigurationPotential'.");
  }
  /* Module initialization. */
  UGM_ConfigurationPotential_initialize(&emlrtContextGlobal);
  /* Call the function. */
  UGM_ConfigurationPotential_api(prhs,(const mxArray**)outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  UGM_ConfigurationPotential_terminate();
}
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(UGM_ConfigurationPotential_atexit);
  emlrtClearAllocCount(&emlrtContextGlobal, 0, 0, NULL);
  /* Dispatch the entry-point. */
  UGM_ConfigurationPotential_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (UGM_ConfigurationPotential_mex.c) */
