/*
 * UGM_Infer_ConditionalC.c
 *
 * Code generation for function 'UGM_Infer_ConditionalC'
 *
 * C source code generated on: Sun Feb 16 17:36:25 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "UGM_Infer_ConditionalC.h"
#include "UGM_Infer_ConditionalC_emxutil.h"
#include "UGM_Infer_ConditionalC_data.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 1, 30, "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m" };

static emlrtRTEInfo b_emlrtRTEI = { 10, 1, "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 16, 33, "clampedNB",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 25, 18, "edgeEnds",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 26, 18, "edgeEnds",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 34, 49, "clampedNB",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 39, 49, "clampedNB",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 42, 43, "clampedEB",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 16, 16, "nodeBel",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo h_emlrtBCI = { 1, 2, 34, 20, "edgeBel",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 34, 34, "edgeBel",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo j_emlrtBCI = { 1, 2, 39, 22, "edgeBel",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 39, 34, "edgeBel",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 42, 24, "edgeBel",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 28, 7, "clamped",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 37, 11, "clamped",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 42, 43, "edgeMap",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 39, 22, "clamped",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 39, 49, "regulVarMap",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 29, 11, "clamped",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 34, 20, "clamped",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 34, 49, "regulVarMap",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo u_emlrtBCI = { 1, 2, 31, 20, "edgeBel",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 31, 20, "clamped",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo w_emlrtBCI = { 1, 2, 31, 32, "edgeBel",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 31, 32, "clamped",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 31, 44, "edgeBel",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 12, 7, "clamped",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 17, 8, "regulVarMap",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 13, 16, "nodeBel",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo db_emlrtBCI = { 1, 2, 13, 18, "nodeBel",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 13, 18, "clamped",
  "UGM_Infer_ConditionalC",
  "E:/Code/Matlab Kits/UGM/infer/UGM_Infer_ConditionalC.m", 0 };

/* Function Definitions */
void UGM_Infer_ConditionalC(const emxArray_real_T *clampedNB, const
  emxArray_real_T *clampedEB, const emxArray_real_T *nodePot, const
  emxArray_real_T *edgePot, const emxArray_int32_T *edgeMap, const
  emxArray_int32_T *edgeEnds, const emxArray_int32_T *clamped, emxArray_real_T
  *nodeBel, emxArray_real_T *edgeBel)
{
  uint32_T uv0[2];
  int32_T i0;
  int32_T loop_ub;
  uint32_T regulVar;
  emxArray_real_T *regulVarMap;
  int32_T n;
  int32_T i1;
  uint32_T uv1[3];
  int32_T e;
  int32_T b_clamped;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (uint32_T)nodePot->size[i0];
  }

  i0 = nodeBel->size[0] * nodeBel->size[1];
  nodeBel->size[0] = (int32_T)uv0[0];
  nodeBel->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)nodeBel, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = (int32_T)uv0[0] << 1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    nodeBel->data[i0] = 0.0;
  }

  regulVar = 1U;
  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (uint32_T)clamped->size[i0];
  }

  emxInit_real_T(&regulVarMap, 2, &b_emlrtRTEI, TRUE);
  i0 = regulVarMap->size[0] * regulVarMap->size[1];
  regulVarMap->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)regulVarMap, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = regulVarMap->size[0] * regulVarMap->size[1];
  regulVarMap->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity((emxArray__common *)regulVarMap, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = (int32_T)uv0[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    regulVarMap->data[i0] = 0.0;
  }

  n = 1;
  while (n - 1 <= nodePot->size[0] - 1) {
    i0 = clamped->size[1];
    if (clamped->data[emlrtDynamicBoundsCheckFastR2012b(n, 1, i0, &ab_emlrtBCI,
         emlrtRootTLSGlobal) - 1] != 0) {
      i0 = nodeBel->size[0];
      i1 = clamped->size[1];
      i1 = clamped->data[emlrtDynamicBoundsCheckFastR2012b(n, 1, i1,
        &eb_emlrtBCI, emlrtRootTLSGlobal) - 1];
      nodeBel->data[(emlrtDynamicBoundsCheckFastR2012b(n, 1, i0, &cb_emlrtBCI,
        emlrtRootTLSGlobal) + nodeBel->size[0] *
                     (emlrtDynamicBoundsCheckFastR2012b(i1, 1, 2, &db_emlrtBCI,
        emlrtRootTLSGlobal) - 1)) - 1] = 1.0;
    } else {
      loop_ub = nodeBel->size[0];
      emlrtDynamicBoundsCheckFastR2012b(n, 1, loop_ub, &g_emlrtBCI,
        emlrtRootTLSGlobal);
      i0 = clampedNB->size[0];
      i1 = (int32_T)regulVar;
      loop_ub = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &emlrtBCI,
        emlrtRootTLSGlobal);
      for (i0 = 0; i0 < 2; i0++) {
        nodeBel->data[(n + nodeBel->size[0] * i0) - 1] = clampedNB->data
          [(loop_ub + clampedNB->size[0] * i0) - 1];
      }

      i0 = regulVarMap->size[1];
      regulVarMap->data[emlrtDynamicBoundsCheckFastR2012b(n, 1, i0, &bb_emlrtBCI,
        emlrtRootTLSGlobal) - 1] = regulVar;
      regulVar++;
    }

    n++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
  }

  /*  Construct edge beliefs */
  for (i0 = 0; i0 < 3; i0++) {
    uv1[i0] = (uint32_T)edgePot->size[i0];
  }

  i0 = edgeBel->size[0] * edgeBel->size[1] * edgeBel->size[2];
  edgeBel->size[0] = 2;
  edgeBel->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)edgeBel, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = edgeBel->size[0] * edgeBel->size[1] * edgeBel->size[2];
  edgeBel->size[2] = (int32_T)uv1[2];
  emxEnsureCapacity((emxArray__common *)edgeBel, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = 4 * (int32_T)uv1[2];
  for (i0 = 0; i0 < loop_ub; i0++) {
    edgeBel->data[i0] = 0.0;
  }

  e = 0;
  while (e <= edgePot->size[2] - 1) {
    i0 = edgeEnds->size[0];
    i1 = (int32_T)(1.0 + (real_T)e);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &b_emlrtBCI, emlrtRootTLSGlobal);
    i0 = edgeEnds->size[0];
    i1 = (int32_T)(1.0 + (real_T)e);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &c_emlrtBCI, emlrtRootTLSGlobal);
    i0 = clamped->size[1];
    i1 = edgeEnds->data[e];
    if (clamped->data[emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &m_emlrtBCI,
         emlrtRootTLSGlobal) - 1] != 0) {
      i0 = clamped->size[1];
      i1 = edgeEnds->data[e + edgeEnds->size[0]];
      if (clamped->data[emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &r_emlrtBCI,
           emlrtRootTLSGlobal) - 1] != 0) {
        /*  This edge is between clamped variables */
        i0 = clamped->size[1];
        i1 = edgeEnds->data[e];
        i0 = clamped->data[emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
          &v_emlrtBCI, emlrtRootTLSGlobal) - 1];
        i1 = clamped->size[1];
        n = edgeEnds->data[e + edgeEnds->size[0]];
        i1 = clamped->data[emlrtDynamicBoundsCheckFastR2012b(n, 1, i1,
          &x_emlrtBCI, emlrtRootTLSGlobal) - 1];
        n = edgeBel->size[2];
        loop_ub = 1 + e;
        edgeBel->data[((emlrtDynamicBoundsCheckFastR2012b(i0, 1, 2, &u_emlrtBCI,
          emlrtRootTLSGlobal) + edgeBel->size[0] *
                        (emlrtDynamicBoundsCheckFastR2012b(i1, 1, 2, &w_emlrtBCI,
          emlrtRootTLSGlobal) - 1)) + edgeBel->size[0] * edgeBel->size[1] *
                       (emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, n,
          &y_emlrtBCI, emlrtRootTLSGlobal) - 1)) - 1] = 1.0;
      } else {
        /*  n1 is a clamped variable, n2 is a regular variable */
        loop_ub = edgeBel->size[2];
        i0 = 1 + e;
        emlrtDynamicBoundsCheckFastR2012b(i0, 1, loop_ub, &i_emlrtBCI,
          emlrtRootTLSGlobal);
        i0 = clamped->size[1];
        i1 = edgeEnds->data[e];
        i0 = clamped->data[emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
          &s_emlrtBCI, emlrtRootTLSGlobal) - 1];
        b_clamped = emlrtDynamicBoundsCheckFastR2012b(i0, 1, 2, &h_emlrtBCI,
          emlrtRootTLSGlobal);
        i0 = clampedNB->size[0];
        i1 = regulVarMap->size[1];
        n = edgeEnds->data[e + edgeEnds->size[0]];
        i1 = (int32_T)regulVarMap->data[emlrtDynamicBoundsCheckFastR2012b(n, 1,
          i1, &t_emlrtBCI, emlrtRootTLSGlobal) - 1];
        loop_ub = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &d_emlrtBCI,
          emlrtRootTLSGlobal);
        for (i0 = 0; i0 < 2; i0++) {
          edgeBel->data[((b_clamped + edgeBel->size[0] * i0) + edgeBel->size[0] *
                         edgeBel->size[1] * e) - 1] = clampedNB->data[(loop_ub +
            clampedNB->size[0] * i0) - 1];
        }
      }
    } else {
      i0 = clamped->size[1];
      i1 = edgeEnds->data[e + edgeEnds->size[0]];
      if (clamped->data[emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &n_emlrtBCI,
           emlrtRootTLSGlobal) - 1] != 0) {
        /*  n2 is a clamped variable, n1 is a regular variable */
        loop_ub = edgeBel->size[2];
        i0 = 1 + e;
        emlrtDynamicBoundsCheckFastR2012b(i0, 1, loop_ub, &k_emlrtBCI,
          emlrtRootTLSGlobal);
        i0 = clamped->size[1];
        i1 = edgeEnds->data[e + edgeEnds->size[0]];
        i0 = clamped->data[emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0,
          &p_emlrtBCI, emlrtRootTLSGlobal) - 1];
        b_clamped = emlrtDynamicBoundsCheckFastR2012b(i0, 1, 2, &j_emlrtBCI,
          emlrtRootTLSGlobal);
        i0 = clampedNB->size[0];
        i1 = regulVarMap->size[1];
        n = edgeEnds->data[e];
        i1 = (int32_T)regulVarMap->data[emlrtDynamicBoundsCheckFastR2012b(n, 1,
          i1, &q_emlrtBCI, emlrtRootTLSGlobal) - 1];
        loop_ub = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &e_emlrtBCI,
          emlrtRootTLSGlobal);
        for (i0 = 0; i0 < 2; i0++) {
          edgeBel->data[(i0 + edgeBel->size[0] * (b_clamped - 1)) +
            edgeBel->size[0] * edgeBel->size[1] * e] = clampedNB->data[(loop_ub
            + clampedNB->size[0] * i0) - 1];
        }
      } else {
        /*  This edge was present in the clamped graph */
        loop_ub = edgeBel->size[2];
        i0 = 1 + e;
        emlrtDynamicBoundsCheckFastR2012b(i0, 1, loop_ub, &l_emlrtBCI,
          emlrtRootTLSGlobal);
        i0 = clampedEB->size[2];
        i1 = edgeMap->size[0];
        n = 1 + e;
        i1 = edgeMap->data[emlrtDynamicBoundsCheckFastR2012b(n, 1, i1,
          &o_emlrtBCI, emlrtRootTLSGlobal) - 1];
        loop_ub = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &f_emlrtBCI,
          emlrtRootTLSGlobal);
        for (i0 = 0; i0 < 2; i0++) {
          for (i1 = 0; i1 < 2; i1++) {
            edgeBel->data[(i1 + edgeBel->size[0] * i0) + edgeBel->size[0] *
              edgeBel->size[1] * e] = clampedEB->data[(i1 + clampedEB->size[0] *
              i0) + clampedEB->size[0] * clampedEB->size[1] * (loop_ub - 1)];
          }
        }
      }
    }

    e++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
  }

  emxFree_real_T(&regulVarMap);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (UGM_Infer_ConditionalC.c) */
