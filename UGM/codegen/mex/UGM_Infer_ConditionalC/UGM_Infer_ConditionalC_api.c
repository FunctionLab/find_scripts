/*
 * UGM_Infer_ConditionalC_api.c
 *
 * Code generation for function 'UGM_Infer_ConditionalC_api'
 *
 * C source code generated on: Sun Feb 16 17:36:25 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "UGM_Infer_ConditionalC.h"
#include "UGM_Infer_ConditionalC_api.h"
#include "UGM_Infer_ConditionalC_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo c_emlrtRTEI = { 1, 1, "UGM_Infer_ConditionalC_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y);
static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u);
static void c_emlrt_marshallIn(const mxArray *clampedEB, const char_T
  *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y);
static void e_emlrt_marshallIn(const mxArray *edgeMap, const char_T *identifier,
  emxArray_int32_T *y);
static void emlrt_marshallIn(const mxArray *clampedNB, const char_T *identifier,
  emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(emxArray_real_T *u);
static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_int32_T *y);
static void g_emlrt_marshallIn(const mxArray *edgeEnds, const char_T *identifier,
  emxArray_int32_T *y);
static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_int32_T *y);
static void i_emlrt_marshallIn(const mxArray *clamped, const char_T *identifier,
  emxArray_int32_T *y);
static void j_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_int32_T *y);
static void k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret);
static void l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret);
static void m_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_int32_T *ret);
static void n_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_int32_T *ret);
static void o_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_int32_T *ret);

/* Function Definitions */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y)
{
  k_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv2[3] = { 0, 0, 0 };

  const mxArray *m2;
  y = NULL;
  m2 = mxCreateNumericArray(3, (int32_T *)&iv2, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m2, (void *)u->data);
  mxSetDimensions((mxArray *)m2, u->size, 3);
  emlrtAssign(&y, m2);
  return y;
}

static void c_emlrt_marshallIn(const mxArray *clampedEB, const char_T
  *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(emlrtAlias(clampedEB), &thisId, y);
  emlrtDestroyArray(&clampedEB);
}

static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y)
{
  l_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const mxArray *edgeMap, const char_T *identifier,
  emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  f_emlrt_marshallIn(emlrtAlias(edgeMap), &thisId, y);
  emlrtDestroyArray(&edgeMap);
}

static void emlrt_marshallIn(const mxArray *clampedNB, const char_T *identifier,
  emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(emlrtAlias(clampedNB), &thisId, y);
  emlrtDestroyArray(&clampedNB);
}

static const mxArray *emlrt_marshallOut(emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv1[2] = { 0, 0 };

  const mxArray *m1;
  y = NULL;
  m1 = mxCreateNumericArray(2, (int32_T *)&iv1, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m1, (void *)u->data);
  mxSetDimensions((mxArray *)m1, u->size, 2);
  emlrtAssign(&y, m1);
  return y;
}

static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_int32_T *y)
{
  m_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const mxArray *edgeEnds, const char_T *identifier,
  emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  h_emlrt_marshallIn(emlrtAlias(edgeEnds), &thisId, y);
  emlrtDestroyArray(&edgeEnds);
}

static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_int32_T *y)
{
  n_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const mxArray *clamped, const char_T *identifier,
  emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  j_emlrt_marshallIn(emlrtAlias(clamped), &thisId, y);
  emlrtDestroyArray(&clamped);
}

static void j_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_int32_T *y)
{
  o_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret)
{
  int32_T iv3[2];
  boolean_T bv0[2];
  int32_T i2;
  static const boolean_T bv1[2] = { TRUE, FALSE };

  int32_T iv4[2];
  for (i2 = 0; i2 < 2; i2++) {
    iv3[i2] = 3 * i2 - 1;
    bv0[i2] = bv1[i2];
  }

  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 2U,
    iv3, bv0, iv4);
  ret->size[0] = iv4[0];
  ret->size[1] = iv4[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = FALSE;
  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret)
{
  int32_T iv5[3];
  boolean_T bv2[3];
  int32_T i;
  static const int8_T iv6[3] = { 2, 2, -1 };

  static const boolean_T bv3[3] = { FALSE, FALSE, TRUE };

  int32_T iv7[3];
  for (i = 0; i < 3; i++) {
    iv5[i] = iv6[i];
    bv2[i] = bv3[i];
  }

  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 3U,
    iv5, bv2, iv7);
  ret->size[0] = iv7[0];
  ret->size[1] = iv7[1];
  ret->size[2] = iv7[2];
  ret->allocatedSize = ret->size[0] * ret->size[1] * ret->size[2];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = FALSE;
  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_int32_T *ret)
{
  int32_T iv8[1];
  boolean_T bv4[1];
  int32_T iv9[1];
  iv8[0] = -1;
  bv4[0] = TRUE;
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "int32", FALSE, 1U,
    iv8, bv4, iv9);
  ret->size[0] = iv9[0];
  ret->allocatedSize = ret->size[0];
  ret->data = (int32_T *)mxGetData(src);
  ret->canFreeData = FALSE;
  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_int32_T *ret)
{
  int32_T iv10[2];
  boolean_T bv5[2];
  int32_T i3;
  static const boolean_T bv6[2] = { TRUE, FALSE };

  int32_T iv11[2];
  for (i3 = 0; i3 < 2; i3++) {
    iv10[i3] = 3 * i3 - 1;
    bv5[i3] = bv6[i3];
  }

  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "int32", FALSE, 2U,
    iv10, bv5, iv11);
  ret->size[0] = iv11[0];
  ret->size[1] = iv11[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (int32_T *)mxGetData(src);
  ret->canFreeData = FALSE;
  emlrtDestroyArray(&src);
}

static void o_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_int32_T *ret)
{
  int32_T iv12[2];
  boolean_T bv7[2];
  int32_T i4;
  static const boolean_T bv8[2] = { FALSE, TRUE };

  int32_T iv13[2];
  for (i4 = 0; i4 < 2; i4++) {
    iv12[i4] = 1 + -2 * i4;
    bv7[i4] = bv8[i4];
  }

  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "int32", FALSE, 2U,
    iv12, bv7, iv13);
  ret->size[0] = iv13[0];
  ret->size[1] = iv13[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (int32_T *)mxGetData(src);
  ret->canFreeData = FALSE;
  emlrtDestroyArray(&src);
}

void UGM_Infer_ConditionalC_api(const mxArray * const prhs[7], const mxArray
  *plhs[2])
{
  emxArray_real_T *clampedNB;
  emxArray_real_T *clampedEB;
  emxArray_real_T *nodePot;
  emxArray_real_T *edgePot;
  emxArray_int32_T *edgeMap;
  emxArray_int32_T *edgeEnds;
  emxArray_int32_T *clamped;
  emxArray_real_T *nodeBel;
  emxArray_real_T *edgeBel;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&clampedNB, 2, &c_emlrtRTEI, TRUE);
  b_emxInit_real_T(&clampedEB, 3, &c_emlrtRTEI, TRUE);
  emxInit_real_T(&nodePot, 2, &c_emlrtRTEI, TRUE);
  b_emxInit_real_T(&edgePot, 3, &c_emlrtRTEI, TRUE);
  emxInit_int32_T(&edgeMap, 1, &c_emlrtRTEI, TRUE);
  b_emxInit_int32_T(&edgeEnds, 2, &c_emlrtRTEI, TRUE);
  b_emxInit_int32_T(&clamped, 2, &c_emlrtRTEI, TRUE);
  emxInit_real_T(&nodeBel, 2, &c_emlrtRTEI, TRUE);
  b_emxInit_real_T(&edgeBel, 3, &c_emlrtRTEI, TRUE);

  /* Marshall function inputs */
  emlrt_marshallIn(emlrtAlias(prhs[0]), "clampedNB", clampedNB);
  c_emlrt_marshallIn(emlrtAlias(prhs[1]), "clampedEB", clampedEB);
  emlrt_marshallIn(emlrtAlias(prhs[2]), "nodePot", nodePot);
  c_emlrt_marshallIn(emlrtAlias(prhs[3]), "edgePot", edgePot);
  e_emlrt_marshallIn(emlrtAlias(prhs[4]), "edgeMap", edgeMap);
  g_emlrt_marshallIn(emlrtAlias(prhs[5]), "edgeEnds", edgeEnds);
  i_emlrt_marshallIn(emlrtAlias(prhs[6]), "clamped", clamped);

  /* Invoke the target function */
  UGM_Infer_ConditionalC(clampedNB, clampedEB, nodePot, edgePot, edgeMap,
    edgeEnds, clamped, nodeBel, edgeBel);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(nodeBel);
  plhs[1] = b_emlrt_marshallOut(edgeBel);
  edgeBel->canFreeData = FALSE;
  emxFree_real_T(&edgeBel);
  nodeBel->canFreeData = FALSE;
  emxFree_real_T(&nodeBel);
  clamped->canFreeData = FALSE;
  emxFree_int32_T(&clamped);
  edgeEnds->canFreeData = FALSE;
  emxFree_int32_T(&edgeEnds);
  edgeMap->canFreeData = FALSE;
  emxFree_int32_T(&edgeMap);
  edgePot->canFreeData = FALSE;
  emxFree_real_T(&edgePot);
  nodePot->canFreeData = FALSE;
  emxFree_real_T(&nodePot);
  clampedEB->canFreeData = FALSE;
  emxFree_real_T(&clampedEB);
  clampedNB->canFreeData = FALSE;
  emxFree_real_T(&clampedNB);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  static const int32_T iv0[2] = { 0, 1 };

  const mxArray *m0;
  nameCaptureInfo = NULL;
  m0 = mxCreateNumericArray(2, (int32_T *)&iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&nameCaptureInfo, m0);
  return nameCaptureInfo;
}

/* End of code generation (UGM_Infer_ConditionalC_api.c) */
