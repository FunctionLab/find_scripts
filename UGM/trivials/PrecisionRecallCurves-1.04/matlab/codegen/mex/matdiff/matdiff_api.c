/*
 * matdiff_api.c
 *
 * Code generation for function 'matdiff_api'
 *
 * C source code generated on: Sun Sep 09 23:00:54 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "matdiff.h"
#include "matdiff_api.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, boolean_T y_data[15978598], int32_T y_sizes[2]);
static const mxArray *b_emlrt_marshallOut(real_T u_data[215927], int32_T u_sizes[1]);
static void c_emlrt_marshallIn(const mxArray *train, const char_T *identifier, boolean_T y_data[7989336], int32_T y_sizes[2]);
static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, boolean_T y_data[7989336], int32_T y_sizes[2]);
static void e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, boolean_T ret_data[15978598], int32_T ret_sizes[2]);
static void emlrt_marshallIn(const mxArray *all, const char_T *identifier, boolean_T y_data[15978598], int32_T y_sizes[2]);
static void f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, boolean_T ret_data[7989336], int32_T ret_sizes[2]);

/* Function Definitions */

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, boolean_T y_data[15978598], int32_T y_sizes[2])
{
    e_emlrt_marshallIn(emlrtAlias(u), parentId, y_data, y_sizes);
    emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(real_T u_data[215927], int32_T u_sizes[1])
{
    const mxArray *y;
    const mxArray *m3;
    real_T (*pData)[];
    int32_T i2;
    int32_T i;
    y = NULL;
    m3 = mxCreateNumericArray(1, (int32_T *)u_sizes, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T (*)[])mxGetPr(m3);
    i2 = 0;
    for (i = 0; i < u_sizes[0]; i++) {
        (*pData)[i2] = u_data[i];
        i2++;
    }
    emlrtAssign(&y, m3);
    return y;
}

static void c_emlrt_marshallIn(const mxArray *train, const char_T *identifier, boolean_T y_data[7989336], int32_T y_sizes[2])
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    d_emlrt_marshallIn(emlrtAlias(train), &thisId, y_data, y_sizes);
    emlrtDestroyArray(&train);
}

static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, boolean_T y_data[7989336], int32_T y_sizes[2])
{
    f_emlrt_marshallIn(emlrtAlias(u), parentId, y_data, y_sizes);
    emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, boolean_T ret_data[15978598], int32_T ret_sizes[2])
{
    int32_T i3;
    int32_T iv2[2];
    boolean_T bv0[2];
    for (i3 = 0; i3 < 2; i3++) {
        iv2[i3] = 74 + 215853 * i3;
        bv0[i3] = TRUE;
    }
    emlrtCheckVsBuiltInR2011a(msgId, src, "logical", FALSE, 2U, iv2, bv0, ret_sizes);
    emlrtImportArrayR2008b(src, ret_data, 1);
    emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const mxArray *all, const char_T *identifier, boolean_T y_data[15978598], int32_T y_sizes[2])
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    b_emlrt_marshallIn(emlrtAlias(all), &thisId, y_data, y_sizes);
    emlrtDestroyArray(&all);
}

static void f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, boolean_T ret_data[7989336], int32_T ret_sizes[2])
{
    int32_T i4;
    int32_T iv3[2];
    boolean_T bv1[2];
    for (i4 = 0; i4 < 2; i4++) {
        iv3[i4] = 74 + 107890 * i4;
        bv1[i4] = TRUE;
    }
    emlrtCheckVsBuiltInR2011a(msgId, src, "logical", FALSE, 2U, iv3, bv1, ret_sizes);
    emlrtImportArrayR2008b(src, ret_data, 1);
    emlrtDestroyArray(&src);
}

void matdiff_api(matdiffStackData *SD, const mxArray * const prhs[2], const mxArray *plhs[1])
{
    int32_T all_sizes[2];
    int32_T train_sizes[2];
    int32_T TestInd_sizes;
    /* Marshall function inputs */
    emlrt_marshallIn(emlrtAliasP(prhs[0]), "all", SD->f2.all_data, all_sizes);
    c_emlrt_marshallIn(emlrtAliasP(prhs[1]), "train", SD->f2.train_data, train_sizes);
    /* Invoke the target function */
    matdiff(SD, SD->f2.all_data, all_sizes, SD->f2.train_data, train_sizes, SD->f2.TestInd_data, &TestInd_sizes);
    /* Marshall function outputs */
    plhs[0] = b_emlrt_marshallOut(SD->f2.TestInd_data, *(int32_T (*)[1])&TestInd_sizes);
}
/* End of code generation (matdiff_api.c) */
