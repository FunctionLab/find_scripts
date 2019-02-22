/*
 * UGM_Infer_ConditionalC_initialize.c
 *
 * Code generation for function 'UGM_Infer_ConditionalC_initialize'
 *
 * C source code generated on: Sun Feb 16 17:36:25 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "UGM_Infer_ConditionalC.h"
#include "UGM_Infer_ConditionalC_initialize.h"
#include "UGM_Infer_ConditionalC_data.h"

/* Function Definitions */
void UGM_Infer_ConditionalC_initialize(emlrtContext *aContext)
{
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, FALSE, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (UGM_Infer_ConditionalC_initialize.c) */
