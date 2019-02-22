/*
 * genomeWalkerFunc_api.c
 *
 * Code generation for function 'genomeWalkerFunc_api'
 *
 * C source code generated on: Mon Sep 10 17:00:55 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "genomeWalkerFunc.h"
#include "genomeWalkerFunc_api.h"
#include "genomeWalkerFunc_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRTEInfo e_emlrtRTEI = { 1, 1, "genomeWalkerFunc_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_boolean_T *y);
static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u);
static void c_emlrt_marshallIn(const mxArray *nodePot, const char_T *identifier, emxArray_real_T *y);
static const mxArray *c_emlrt_marshallOut(const real_T u[20000]);
static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *d_emlrt_marshallOut(real_T u);
static void e_emlrt_marshallIn(const mxArray *edgePot, const char_T *identifier, emxArray_real_T *y);
static void emlrt_marshallIn(const mxArray *chrom_data, const char_T *identifier, emxArray_boolean_T *y);
static const mxArray *emlrt_marshallOut(emxArray_real_T *u);
static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void g_emlrt_marshallIn(const mxArray *edgeEnds, const char_T *identifier, emxArray_int32_T *y);
static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static real_T i_emlrt_marshallIn(const mxArray *nNodes, const char_T *identifier);
static real_T j_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId);
static void k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_boolean_T *ret);
static void l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void m_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void n_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static real_T o_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId);

/* Function Definitions */

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_boolean_T *y)
{
    k_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u)
{
    const mxArray *y;
    const mxArray *m2;
    real_T (*pData)[];
    int32_T i2;
    int32_T i;
    int32_T b_i;
    y = NULL;
    m2 = mxCreateNumericArray(2, u->size, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T (*)[])mxGetPr(m2);
    i2 = 0;
    for (i = 0; i < u->size[1]; i++) {
        for (b_i = 0; b_i < 20000; b_i++) {
            (*pData)[i2] = u->data[b_i + u->size[0] * i];
            i2++;
        }
    }
    emlrtAssign(&y, m2);
    return y;
}

static void c_emlrt_marshallIn(const mxArray *nodePot, const char_T *identifier, emxArray_real_T *y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    d_emlrt_marshallIn(emlrtAlias(nodePot), &thisId, y);
    emlrtDestroyArray(&nodePot);
}

static const mxArray *c_emlrt_marshallOut(const real_T u[20000])
{
    const mxArray *y;
    static const int32_T iv4[1] = { 20000 };
    const mxArray *m3;
    real_T (*pData)[];
    int32_T i;
    y = NULL;
    m3 = mxCreateNumericArray(1, (int32_T *)&iv4, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T (*)[])mxGetPr(m3);
    for (i = 0; i < 20000; i++) {
        (*pData)[i] = u[i];
    }
    emlrtAssign(&y, m3);
    return y;
}

static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
    l_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static const mxArray *d_emlrt_marshallOut(real_T u)
{
    const mxArray *y;
    const mxArray *m4;
    y = NULL;
    m4 = mxCreateDoubleScalar(u);
    emlrtAssign(&y, m4);
    return y;
}

static void e_emlrt_marshallIn(const mxArray *edgePot, const char_T *identifier, emxArray_real_T *y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    f_emlrt_marshallIn(emlrtAlias(edgePot), &thisId, y);
    emlrtDestroyArray(&edgePot);
}

static void emlrt_marshallIn(const mxArray *chrom_data, const char_T *identifier, emxArray_boolean_T *y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    b_emlrt_marshallIn(emlrtAlias(chrom_data), &thisId, y);
    emlrtDestroyArray(&chrom_data);
}

static const mxArray *emlrt_marshallOut(emxArray_real_T *u)
{
    const mxArray *y;
    const mxArray *m1;
    real_T (*pData)[];
    int32_T i1;
    int32_T i;
    y = NULL;
    m1 = mxCreateNumericArray(2, u->size, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T (*)[])mxGetPr(m1);
    i1 = 0;
    for (i = 0; i < u->size[1]; i++) {
        (*pData)[i1] = u->data[u->size[0] * i];
        i1++;
    }
    emlrtAssign(&y, m1);
    return y;
}

static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
    m_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const mxArray *edgeEnds, const char_T *identifier, emxArray_int32_T *y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    h_emlrt_marshallIn(emlrtAlias(edgeEnds), &thisId, y);
    emlrtDestroyArray(&edgeEnds);
}

static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
    n_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static real_T i_emlrt_marshallIn(const mxArray *nNodes, const char_T *identifier)
{
    real_T y;
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    y = j_emlrt_marshallIn(emlrtAlias(nNodes), &thisId);
    emlrtDestroyArray(&nNodes);
    return y;
}

static real_T j_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId)
{
    real_T y;
    y = o_emlrt_marshallIn(emlrtAlias(u), parentId);
    emlrtDestroyArray(&u);
    return y;
}

static void k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_boolean_T *ret)
{
    int32_T i;
    int32_T iv5[2];
    boolean_T bv0[2];
    for (i = 0; i < 2; i++) {
        iv5[i] = -1;
        bv0[i] = TRUE;
    }
    emlrtCheckVsBuiltInR2011a(msgId, src, "logical", FALSE, 2U, iv5, bv0, ret->size);
    i = ret->size[0] * ret->size[1];
    emxEnsureCapacity((emxArray__common *)ret, i, (int32_T)sizeof(boolean_T), (emlrtRTEInfo *)NULL);
    emlrtImportArrayR2008b(src, ret->data, 1);
    emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
    int32_T i3;
    int32_T iv6[2];
    static const boolean_T bv1[2] = { TRUE, FALSE };
    boolean_T bv2[2];
    for (i3 = 0; i3 < 2; i3++) {
        iv6[i3] = 72 + -70 * i3;
        bv2[i3] = bv1[i3];
    }
    emlrtCheckVsBuiltInR2011a(msgId, src, "double", FALSE, 2U, iv6, bv2, ret->size);
    i3 = ret->size[0] * ret->size[1];
    ret->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)ret, i3, (int32_T)sizeof(real_T), (emlrtRTEInfo *)NULL);
    emlrtImportArrayR2008b(src, ret->data, 8);
    emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
    int32_T i;
    static const int16_T iv7[3] = { 2, 2, 2556 };
    int32_T iv8[3];
    static const boolean_T bv3[3] = { FALSE, FALSE, TRUE };
    boolean_T bv4[3];
    for (i = 0; i < 3; i++) {
        iv8[i] = iv7[i];
        bv4[i] = bv3[i];
    }
    emlrtCheckVsBuiltInR2011a(msgId, src, "double", FALSE, 3U, iv8, bv4, ret->size);
    i = ret->size[0] * ret->size[1] * ret->size[2];
    ret->size[0] = 2;
    ret->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)ret, i, (int32_T)sizeof(real_T), (emlrtRTEInfo *)NULL);
    emlrtImportArrayR2008b(src, ret->data, 8);
    emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
    int32_T i4;
    int32_T iv9[2];
    static const boolean_T bv5[2] = { TRUE, FALSE };
    boolean_T bv6[2];
    for (i4 = 0; i4 < 2; i4++) {
        iv9[i4] = 2556 + -2554 * i4;
        bv6[i4] = bv5[i4];
    }
    emlrtCheckVsBuiltInR2011a(msgId, src, "int32", FALSE, 2U, iv9, bv6, ret->size);
    i4 = ret->size[0] * ret->size[1];
    ret->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)ret, i4, (int32_T)sizeof(int32_T), (emlrtRTEInfo *)NULL);
    emlrtImportArrayR2008b(src, ret->data, 4);
    emlrtDestroyArray(&src);
}

static real_T o_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId)
{
    real_T ret;
    emlrtCheckBuiltInR2011a(msgId, src, "double", FALSE, 0U, 0);
    ret = *(real_T *)mxGetData(src);
    emlrtDestroyArray(&src);
    return ret;
}

void genomeWalkerFunc_api(genomeWalkerFuncStackData *SD, const mxArray * const prhs[6], const mxArray *plhs[5])
{
    emxArray_boolean_T *chrom_data;
    emxArray_real_T *nodePot;
    emxArray_real_T *edgePot;
    emxArray_int32_T *edgeEnds;
    emxArray_real_T *Chrom_maxima;
    emxArray_real_T *Maximas;
    real_T nNodes;
    real_T maxRounds;
    real_T nMaxima;
    real_T Mcount[20000];
    emlrtHeapReferenceStackEnterFcn();
    emxInit_boolean_T(&chrom_data, 2, &e_emlrtRTEI, TRUE);
    emxInit_real_T(&nodePot, 2, &e_emlrtRTEI, TRUE);
    b_emxInit_real_T(&edgePot, 3, &e_emlrtRTEI, TRUE);
    b_emxInit_int32_T(&edgeEnds, 2, &e_emlrtRTEI, TRUE);
    emxInit_real_T(&Chrom_maxima, 2, &e_emlrtRTEI, TRUE);
    emxInit_real_T(&Maximas, 2, &e_emlrtRTEI, TRUE);
    /* Marshall function inputs */
    emlrt_marshallIn(emlrtAliasP(prhs[0]), "chrom_data", chrom_data);
    c_emlrt_marshallIn(emlrtAliasP(prhs[1]), "nodePot", nodePot);
    e_emlrt_marshallIn(emlrtAliasP(prhs[2]), "edgePot", edgePot);
    g_emlrt_marshallIn(emlrtAliasP(prhs[3]), "edgeEnds", edgeEnds);
    nNodes = i_emlrt_marshallIn(emlrtAliasP(prhs[4]), "nNodes");
    maxRounds = i_emlrt_marshallIn(emlrtAliasP(prhs[5]), "maxRounds");
    /* Invoke the target function */
    genomeWalkerFunc(chrom_data, nodePot, edgePot, edgeEnds, nNodes, maxRounds, Chrom_maxima, Maximas, Mcount, SD->f0.Mpot, &nMaxima);
    /* Marshall function outputs */
    plhs[0] = emlrt_marshallOut(Chrom_maxima);
    plhs[1] = b_emlrt_marshallOut(Maximas);
    plhs[2] = c_emlrt_marshallOut(Mcount);
    plhs[3] = c_emlrt_marshallOut(SD->f0.Mpot);
    plhs[4] = d_emlrt_marshallOut(nMaxima);
    emxFree_real_T(&Maximas);
    emxFree_real_T(&Chrom_maxima);
    emxFree_int32_T(&edgeEnds);
    emxFree_real_T(&edgePot);
    emxFree_real_T(&nodePot);
    emxFree_boolean_T(&chrom_data);
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (genomeWalkerFunc_api.c) */
