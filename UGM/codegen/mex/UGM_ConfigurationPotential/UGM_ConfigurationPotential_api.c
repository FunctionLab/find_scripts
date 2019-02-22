/*
 * UGM_ConfigurationPotential_api.c
 *
 * Code generation for function 'UGM_ConfigurationPotential_api'
 *
 * C source code generated on: Mon Sep 10 15:47:03 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "UGM_ConfigurationPotential.h"
#include "UGM_ConfigurationPotential_api.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y_data[72], int32_T y_sizes[2]);
static void c_emlrt_marshallIn(const mxArray *nodePot, const char_T *identifier, real_T y_data[144], int32_T y_sizes[2]);
static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y_data[144], int32_T y_sizes[2]);
static void e_emlrt_marshallIn(const mxArray *edgePot, const char_T *identifier, real_T y_data[10224], int32_T y_sizes[3]);
static void emlrt_marshallIn(const mxArray *y, const char_T *identifier, real_T y_data[72], int32_T y_sizes[2]);
static const mxArray *emlrt_marshallOut(real_T u);
static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y_data[10224], int32_T y_sizes[3]);
static void g_emlrt_marshallIn(const mxArray *edgeEnds, const char_T *identifier, int32_T y_data[5112], int32_T y_sizes[2]);
static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, int32_T y_data[5112], int32_T y_sizes[2]);
static void i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret_data[72], int32_T ret_sizes[2]);
static void j_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret_data[144], int32_T ret_sizes[2]);
static void k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret_data[10224], int32_T ret_sizes[3]);
static void l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, int32_T ret_data[5112], int32_T ret_sizes[2]);

/* Function Definitions */

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y_data[72], int32_T y_sizes[2])
{
    i_emlrt_marshallIn(emlrtAlias(u), parentId, y_data, y_sizes);
    emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const mxArray *nodePot, const char_T *identifier, real_T y_data[144], int32_T y_sizes[2])
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    d_emlrt_marshallIn(emlrtAlias(nodePot), &thisId, y_data, y_sizes);
    emlrtDestroyArray(&nodePot);
}

static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y_data[144], int32_T y_sizes[2])
{
    j_emlrt_marshallIn(emlrtAlias(u), parentId, y_data, y_sizes);
    emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const mxArray *edgePot, const char_T *identifier, real_T y_data[10224], int32_T y_sizes[3])
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    f_emlrt_marshallIn(emlrtAlias(edgePot), &thisId, y_data, y_sizes);
    emlrtDestroyArray(&edgePot);
}

static void emlrt_marshallIn(const mxArray *y, const char_T *identifier, real_T y_data[72], int32_T y_sizes[2])
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    b_emlrt_marshallIn(emlrtAlias(y), &thisId, y_data, y_sizes);
    emlrtDestroyArray(&y);
}

static const mxArray *emlrt_marshallOut(real_T u)
{
    const mxArray *y;
    const mxArray *m0;
    y = NULL;
    m0 = mxCreateDoubleScalar(u);
    emlrtAssign(&y, m0);
    return y;
}

static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y_data[10224], int32_T y_sizes[3])
{
    k_emlrt_marshallIn(emlrtAlias(u), parentId, y_data, y_sizes);
    emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const mxArray *edgeEnds, const char_T *identifier, int32_T y_data[5112], int32_T y_sizes[2])
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    h_emlrt_marshallIn(emlrtAlias(edgeEnds), &thisId, y_data, y_sizes);
    emlrtDestroyArray(&edgeEnds);
}

static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, int32_T y_data[5112], int32_T y_sizes[2])
{
    l_emlrt_marshallIn(emlrtAlias(u), parentId, y_data, y_sizes);
    emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret_data[72], int32_T ret_sizes[2])
{
    int32_T i0;
    int32_T iv0[2];
    static const boolean_T bv0[2] = { FALSE, TRUE };
    boolean_T bv1[2];
    for (i0 = 0; i0 < 2; i0++) {
        iv0[i0] = 1 + 71 * i0;
        bv1[i0] = bv0[i0];
    }
    emlrtCheckVsBuiltInR2011a(msgId, src, "double", FALSE, 2U, iv0, bv1, ret_sizes);
    ret_sizes[0] = 1;
    emlrtImportArrayR2008b(src, ret_data, 8);
    emlrtDestroyArray(&src);
}

static void j_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret_data[144], int32_T ret_sizes[2])
{
    int32_T i1;
    int32_T iv1[2];
    static const boolean_T bv2[2] = { TRUE, FALSE };
    boolean_T bv3[2];
    for (i1 = 0; i1 < 2; i1++) {
        iv1[i1] = 72 + -70 * i1;
        bv3[i1] = bv2[i1];
    }
    emlrtCheckVsBuiltInR2011a(msgId, src, "double", FALSE, 2U, iv1, bv3, ret_sizes);
    ret_sizes[1] = 2;
    emlrtImportArrayR2008b(src, ret_data, 8);
    emlrtDestroyArray(&src);
}

static void k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret_data[10224], int32_T ret_sizes[3])
{
    int32_T i;
    static const int16_T iv2[3] = { 2, 2, 2556 };
    int32_T iv3[3];
    static const boolean_T bv4[3] = { FALSE, FALSE, TRUE };
    boolean_T bv5[3];
    for (i = 0; i < 3; i++) {
        iv3[i] = iv2[i];
        bv5[i] = bv4[i];
    }
    emlrtCheckVsBuiltInR2011a(msgId, src, "double", FALSE, 3U, iv3, bv5, ret_sizes);
    ret_sizes[0] = 2;
    ret_sizes[1] = 2;
    emlrtImportArrayR2008b(src, ret_data, 8);
    emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, int32_T ret_data[5112], int32_T ret_sizes[2])
{
    int32_T i2;
    int32_T iv4[2];
    static const boolean_T bv6[2] = { TRUE, FALSE };
    boolean_T bv7[2];
    for (i2 = 0; i2 < 2; i2++) {
        iv4[i2] = 2556 + -2554 * i2;
        bv7[i2] = bv6[i2];
    }
    emlrtCheckVsBuiltInR2011a(msgId, src, "int32", FALSE, 2U, iv4, bv7, ret_sizes);
    ret_sizes[1] = 2;
    emlrtImportArrayR2008b(src, ret_data, 4);
    emlrtDestroyArray(&src);
}

void UGM_ConfigurationPotential_api(const mxArray * const prhs[4], const mxArray *plhs[1])
{
    int32_T y_sizes[2];
    real_T y_data[72];
    int32_T nodePot_sizes[2];
    real_T nodePot_data[144];
    int32_T edgePot_sizes[3];
    real_T edgePot_data[10224];
    int32_T edgeEnds_sizes[2];
    int32_T edgeEnds_data[5112];
    real_T pot;
    /* Marshall function inputs */
    emlrt_marshallIn(emlrtAliasP(prhs[0]), "y", y_data, y_sizes);
    c_emlrt_marshallIn(emlrtAliasP(prhs[1]), "nodePot", nodePot_data, nodePot_sizes);
    e_emlrt_marshallIn(emlrtAliasP(prhs[2]), "edgePot", edgePot_data, edgePot_sizes);
    g_emlrt_marshallIn(emlrtAliasP(prhs[3]), "edgeEnds", edgeEnds_data, edgeEnds_sizes);
    /* Invoke the target function */
    pot = UGM_ConfigurationPotential(y_data, y_sizes, nodePot_data, nodePot_sizes, edgePot_data, edgePot_sizes, edgeEnds_data, edgeEnds_sizes);
    /* Marshall function outputs */
    plhs[0] = emlrt_marshallOut(pot);
}
/* End of code generation (UGM_ConfigurationPotential_api.c) */
