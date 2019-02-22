/*
 * UGM_Infer_ConditionalC_emxutil.h
 *
 * Code generation for function 'UGM_Infer_ConditionalC_emxutil'
 *
 * C source code generated on: Sun Feb 16 17:36:25 2014
 *
 */

#ifndef __UGM_INFER_CONDITIONALC_EMXUTIL_H__
#define __UGM_INFER_CONDITIONALC_EMXUTIL_H__
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
extern void b_emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel, int32_T elementSize, const emlrtRTEInfo *srcLocation);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
#endif
/* End of code generation (UGM_Infer_ConditionalC_emxutil.h) */
