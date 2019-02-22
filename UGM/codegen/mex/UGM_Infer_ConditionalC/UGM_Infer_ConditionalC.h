/*
 * UGM_Infer_ConditionalC.h
 *
 * Code generation for function 'UGM_Infer_ConditionalC'
 *
 * C source code generated on: Sun Feb 16 17:36:25 2014
 *
 */

#ifndef __UGM_INFER_CONDITIONALC_H__
#define __UGM_INFER_CONDITIONALC_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "UGM_Infer_ConditionalC_types.h"

/* Function Declarations */
extern void UGM_Infer_ConditionalC(const emxArray_real_T *clampedNB, const emxArray_real_T *clampedEB, const emxArray_real_T *nodePot, const emxArray_real_T *edgePot, const emxArray_int32_T *edgeMap, const emxArray_int32_T *edgeEnds, const emxArray_int32_T *clamped, emxArray_real_T *nodeBel, emxArray_real_T *edgeBel);
#endif
/* End of code generation (UGM_Infer_ConditionalC.h) */
