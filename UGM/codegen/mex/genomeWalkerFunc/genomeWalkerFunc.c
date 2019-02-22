/*
 * genomeWalkerFunc.c
 *
 * Code generation for function 'genomeWalkerFunc'
 *
 * C source code generated on: Mon Sep 10 17:00:55 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "genomeWalkerFunc.h"
#include "UGM_ConfigurationPotential.h"
#include "genomeWalkerFunc_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 18, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m" };
static emlrtRSInfo b_emlrtRSI = { 20, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m" };
static emlrtRSInfo c_emlrtRSI = { 22, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m" };
static emlrtRSInfo d_emlrtRSI = { 34, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m" };
static emlrtRSInfo e_emlrtRSI = { 44, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m" };
static emlrtRSInfo f_emlrtRSI = { 54, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m" };
static emlrtRSInfo g_emlrtRSI = { 15, "max", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/datafun/max.m" };
static emlrtRSInfo h_emlrtRSI = { 27, "eml_min_or_max", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo i_emlrtRSI = { 62, "eml_min_or_max", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo j_emlrtRSI = { 77, "eml_min_or_max", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo k_emlrtRSI = { 17, "sum", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtRSInfo l_emlrtRSI = { 20, "sum", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtRSInfo m_emlrtRSI = { 56, "eml_isequal_core", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };
static emlrtMCInfo emlrtMCI = { 30, 9, "eml_min_or_max", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo b_emlrtMCI = { 27, 19, "eml_min_or_max", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo c_emlrtMCI = { 63, 9, "eml_min_or_max", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo d_emlrtMCI = { 62, 19, "eml_min_or_max", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo e_emlrtMCI = { 18, 9, "sum", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtMCInfo f_emlrtMCI = { 17, 19, "sum", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtMCInfo g_emlrtMCI = { 23, 9, "sum", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtMCInfo h_emlrtMCI = { 20, 19, "sum", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtRTEInfo emlrtRTEI = { 1, 54, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m" };
static emlrtRTEInfo b_emlrtRTEI = { 10, 5, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m" };
static emlrtRTEInfo c_emlrtRTEI = { 14, 9, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m" };
static emlrtRTEInfo d_emlrtRTEI = { 16, 13, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m" };
static emlrtBCInfo emlrtBCI = { -1, -1, 6, 43, "chrom_data", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo b_emlrtBCI = { -1, -1, 10, 24, "chrom_data", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo c_emlrtBCI = { -1, -1, 17, 27, "y", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo d_emlrtBCI = { -1, -1, 29, 24, "y", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo e_emlrtBCI = { 1, 20000, 34, 41, "Maximas", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtECInfo emlrtECI = { 2, 34, 22, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m" };
static emlrtBCInfo f_emlrtBCI = { 1, 20000, 42, 21, "Maximas", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtECInfo b_emlrtECI = { -1, 42, 13, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m" };
static emlrtECInfo c_emlrtECI = { -1, 53, 9, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m" };
static emlrtBCInfo g_emlrtBCI = { -1, -1, 22, 9, "", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo h_emlrtBCI = { -1, -1, 22, 9, "", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtDCInfo emlrtDCI = { 3, 21, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 1 };
static emlrtDCInfo b_emlrtDCI = { 3, 21, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 4 };
static emlrtDCInfo c_emlrtDCI = { 3, 21, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 1 };
static emlrtDCInfo d_emlrtDCI = { 3, 21, "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 4 };
static emlrtBCInfo i_emlrtBCI = { -1, -1, 20, 9, "potNei", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo j_emlrtBCI = { -1, -1, 22, 9, "", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo k_emlrtBCI = { -1, -1, 22, 9, "", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo l_emlrtBCI = { -1, -1, 22, 9, "", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo m_emlrtBCI = { -1, -1, 29, 9, "y_new", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo n_emlrtBCI = { -1, -1, 55, 9, "Chrom_maxima", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo o_emlrtBCI = { -1, -1, 34, 17, "", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo p_emlrtBCI = { -1, -1, 48, 13, "Chrom_maxima", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo q_emlrtBCI = { -1, -1, 45, 13, "Chrom_maxima", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo r_emlrtBCI = { -1, -1, 17, 13, "ynei", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };
static emlrtBCInfo s_emlrtBCI = { -1, -1, 18, 13, "potNei", "genomeWalkerFunc", "E:/Data/Projects/Chromating/Finalize/Exploring/genomeWalkerFunc.m", 0 };

/* Function Declarations */
static void error(const mxArray *b, emlrtMCInfo *location);
static const mxArray *message(const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */

static void error(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    pArray = b;
    emlrtCallMATLAB(0, NULL, 1, &pArray, "error", TRUE, location);
}

static const mxArray *message(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    const mxArray *m5;
    pArray = b;
    return emlrtCallMATLAB(1, &m5, 1, &pArray, "message", TRUE, location);
}

/*
 * function [Chrom_maxima, Maximas,Mcount,Mpot nMaxima]=genomeWalkerFunc(chrom_data, nodePot,edgePot,edgeEnds, nNodes, maxRounds)
 */
void genomeWalkerFunc(const emxArray_boolean_T *chrom_data, const emxArray_real_T *nodePot, const emxArray_real_T *edgePot, const emxArray_int32_T *edgeEnds, real_T nNodes, real_T maxRounds, emxArray_real_T *Chrom_maxima, emxArray_real_T *Maximas, real_T Mcount[20000], real_T Mpot[20000], real_T *nMaxima)
{
    int32_T i0;
    int32_T loop_ub;
    int32_T i;
    emxArray_int32_T *r0;
    int32_T n;
    emxArray_int32_T *r1;
    emxArray_int32_T *r2;
    uint32_T t;
    emxArray_real_T *y_new;
    emxArray_real_T *potNei;
    emxArray_real_T *ynei;
    emxArray_int32_T *r3;
    emxArray_boolean_T *x;
    emxArray_real_T *b_Maximas;
    int32_T ix;
    int32_T exitg3;
    uint32_T b_i;
    boolean_T searchingForNonNaN;
    const mxArray *y;
    static const int32_T iv0[2] = { 1, 36 };
    const mxArray *m0;
    static const char_T cv0[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };
    const mxArray *b_y;
    static const int32_T iv1[2] = { 1, 39 };
    static const char_T cv1[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };
    real_T mtmp;
    boolean_T guard1 = FALSE;
    int32_T k;
    boolean_T exitg4;
    int32_T j;
    boolean_T exitg1;
    int32_T c_Maximas[2];
    boolean_T p;
    int32_T exitg2;
    const mxArray *c_y;
    static const int32_T iv2[2] = { 1, 30 };
    static const char_T cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 's', 'u', 'm', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p', 't', 'y' };
    const mxArray *d_y;
    static const int32_T iv3[2] = { 1, 36 };
    emlrtHeapReferenceStackEnterFcn();
    /* 'genomeWalkerFunc:2' nMaxima=0; */
    *nMaxima = 0.0;
    /* 'genomeWalkerFunc:3' Maximas=zeros(20000,nNodes)-1; */
    i0 = Maximas->size[0] * Maximas->size[1];
    Maximas->size[0] = 20000;
    Maximas->size[1] = (int32_T)emlrtIntegerCheckR2011a(emlrtNonNegativeCheckR2011a(nNodes, &b_emlrtDCI, &emlrtContextGlobal), &emlrtDCI, &emlrtContextGlobal);
    emxEnsureCapacity((emxArray__common *)Maximas, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
    loop_ub = 20000 * (int32_T)emlrtIntegerCheckR2011a(emlrtNonNegativeCheckR2011a(nNodes, &d_emlrtDCI, &emlrtContextGlobal), &c_emlrtDCI, &emlrtContextGlobal) - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        Maximas->data[i0] = -1.0;
    }
    /* 'genomeWalkerFunc:4' Mcount=zeros(20000,1); */
    for (i = 0; i < 20000; i++) {
        Mcount[i] = 0.0;
    }
    /* 'genomeWalkerFunc:5' Mpot=zeros(20000,1); */
    for (i = 0; i < 20000; i++) {
        Mpot[i] = 0.0;
    }
    emxInit_int32_T(&r0, 1, &emlrtRTEI, TRUE);
    /* 'genomeWalkerFunc:6' Chrom_maxima=zeros(1, length(chrom_data(:,1))); */
    emlrtDynamicBoundsCheckR2011a(1, 1, chrom_data->size[1], &emlrtBCI, &emlrtContextGlobal);
    i0 = r0->size[0];
    r0->size[0] = chrom_data->size[0];
    emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(int32_T), &emlrtRTEI);
    loop_ub = chrom_data->size[0] - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        r0->data[i0] = 1 + i0;
    }
    if (r0->size[0] == 0) {
        n = 0;
    } else {
        emxInit_int32_T(&r1, 1, &emlrtRTEI, TRUE);
        i0 = r1->size[0];
        r1->size[0] = chrom_data->size[0];
        emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(int32_T), &emlrtRTEI);
        loop_ub = chrom_data->size[0] - 1;
        for (i0 = 0; i0 <= loop_ub; i0++) {
            r1->data[i0] = 1 + i0;
        }
        if (r1->size[0] > 1) {
            emxInit_int32_T(&r2, 1, &emlrtRTEI, TRUE);
            i0 = r2->size[0];
            r2->size[0] = chrom_data->size[0];
            emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(int32_T), &emlrtRTEI);
            loop_ub = chrom_data->size[0] - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                r2->data[i0] = 1 + i0;
            }
            n = r2->size[0];
            emxFree_int32_T(&r2);
        } else {
            n = 1;
        }
        emxFree_int32_T(&r1);
    }
    emxFree_int32_T(&r0);
    i0 = Chrom_maxima->size[0] * Chrom_maxima->size[1];
    Chrom_maxima->size[0] = 1;
    Chrom_maxima->size[1] = n;
    emxEnsureCapacity((emxArray__common *)Chrom_maxima, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
    loop_ub = n - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        Chrom_maxima->data[i0] = 0.0;
    }
    /* 'genomeWalkerFunc:7' for t= 1: maxRounds */
    t = 1U;
    emxInit_real_T(&y_new, 2, &b_emlrtRTEI, TRUE);
    emxInit_real_T(&potNei, 2, &c_emlrtRTEI, TRUE);
    emxInit_real_T(&ynei, 2, &d_emlrtRTEI, TRUE);
    emxInit_int32_T(&r3, 1, &emlrtRTEI, TRUE);
    emxInit_boolean_T(&x, 2, &emlrtRTEI, TRUE);
    emxInit_real_T(&b_Maximas, 2, &emlrtRTEI, TRUE);
    while ((real_T)t <= maxRounds) {
        /* 'genomeWalkerFunc:9' y = ones(1,nNodes); */
        /* 'genomeWalkerFunc:10' y_new = chrom_data(t,:)+1; */
        ix = emlrtDynamicBoundsCheckR2011a((int32_T)t, 1, chrom_data->size[0], &b_emlrtBCI, &emlrtContextGlobal);
        i0 = y_new->size[0] * y_new->size[1];
        y_new->size[0] = 1;
        y_new->size[1] = chrom_data->size[1];
        emxEnsureCapacity((emxArray__common *)y_new, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
        loop_ub = chrom_data->size[1] - 1;
        for (i0 = 0; i0 <= loop_ub; i0++) {
            y_new->data[y_new->size[0] * i0] = (real_T)chrom_data->data[(ix + chrom_data->size[0] * i0) - 1] + 1.0;
        }
        /* 'genomeWalkerFunc:11' while ( 1 ) */
        do {
            exitg3 = 0U;
            /* Try all neighbours (move one step) */
            /* 'genomeWalkerFunc:13' y=y_new; */
            /* 'genomeWalkerFunc:14' potNei = ones(1,nNodes+1); */
            i0 = potNei->size[0] * potNei->size[1];
            potNei->size[0] = 1;
            potNei->size[1] = (int32_T)(nNodes + 1.0);
            emxEnsureCapacity((emxArray__common *)potNei, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
            loop_ub = (int32_T)(nNodes + 1.0) - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                potNei->data[i0] = 1.0;
            }
            /* 'genomeWalkerFunc:15' for i = 1:nNodes */
            b_i = 1U;
            while ((real_T)b_i <= nNodes) {
                /* 'genomeWalkerFunc:16' ynei = y; */
                i0 = ynei->size[0] * ynei->size[1];
                ynei->size[0] = 1;
                ynei->size[1] = y_new->size[1];
                emxEnsureCapacity((emxArray__common *)ynei, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = y_new->size[0] * y_new->size[1] - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    ynei->data[i0] = y_new->data[i0];
                }
                /* 'genomeWalkerFunc:17' ynei(i)= swap(y(i)); */
                emlrtDynamicBoundsCheckR2011a((int32_T)b_i, 1, y_new->size[1], &c_emlrtBCI, &emlrtContextGlobal);
                /* 'swap:2' if (x==1) */
                if (y_new->data[(int32_T)b_i - 1] == 1.0) {
                    /* 'swap:3' m=2; */
                    ix = 2;
                } else {
                    /* 'swap:4' else */
                    /* 'swap:5' m=1; */
                    ix = 1;
                }
                ynei->data[emlrtDynamicBoundsCheckR2011a((int32_T)b_i, 1, y_new->size[1], &r_emlrtBCI, &emlrtContextGlobal) - 1] = (real_T)ix;
                /* 'genomeWalkerFunc:18' potNei(i) = UGM_ConfigurationPotential(ynei,nodePot,edgePot,edgeEnds); */
                EMLRTPUSHRTSTACK(&emlrtRSI);
                potNei->data[emlrtDynamicBoundsCheckR2011a((int32_T)b_i, 1, potNei->size[1], &s_emlrtBCI, &emlrtContextGlobal) - 1] = UGM_ConfigurationPotential(ynei, nodePot, edgePot, edgeEnds);
                EMLRTPOPRTSTACK(&emlrtRSI);
                b_i++;
                emlrtBreakCheck();
            }
            /* 'genomeWalkerFunc:20' potNei(nNodes+1)= UGM_ConfigurationPotential(y,nodePot,edgePot,edgeEnds); */
            EMLRTPUSHRTSTACK(&b_emlrtRSI);
            potNei->data[emlrtDynamicBoundsCheckR2011a((int32_T)((uint32_T)nNodes + 1U), 1, potNei->size[1], &i_emlrtBCI, &emlrtContextGlobal) - 1] = UGM_ConfigurationPotential(y_new, nodePot, edgePot, edgeEnds);
            EMLRTPOPRTSTACK(&b_emlrtRSI);
            /* 'genomeWalkerFunc:22' [junk i]= max(potNei); */
            EMLRTPUSHRTSTACK(&c_emlrtRSI);
            EMLRTPUSHRTSTACK(&g_emlrtRSI);
            if ((potNei->size[1] == 1) || (potNei->size[1] != 1)) {
                searchingForNonNaN = TRUE;
            } else {
                searchingForNonNaN = FALSE;
            }
            if (searchingForNonNaN) {
            } else {
                EMLRTPUSHRTSTACK(&h_emlrtRSI);
                y = NULL;
                m0 = mxCreateCharArray(2, iv0);
                emlrtInitCharArray(36, m0, cv0);
                emlrtAssign(&y, m0);
                error(message(y, &emlrtMCI), &b_emlrtMCI);
                EMLRTPOPRTSTACK(&h_emlrtRSI);
            }
            if (potNei->size[1] > 0) {
            } else {
                EMLRTPUSHRTSTACK(&i_emlrtRSI);
                b_y = NULL;
                m0 = mxCreateCharArray(2, iv1);
                emlrtInitCharArray(39, m0, cv1);
                emlrtAssign(&b_y, m0);
                error(message(b_y, &c_emlrtMCI), &d_emlrtMCI);
                EMLRTPOPRTSTACK(&i_emlrtRSI);
            }
            EMLRTPUSHRTSTACK(&j_emlrtRSI);
            n = potNei->size[1];
            emlrtDynamicBoundsCheckR2011a(1, 1, potNei->size[1], &g_emlrtBCI, &emlrtContextGlobal);
            mtmp = potNei->data[0];
            loop_ub = 1;
            if (n == 1) {
            } else {
                ix = 1;
                guard1 = FALSE;
                if (muDoubleScalarIsNaN(potNei->data[0])) {
                    searchingForNonNaN = TRUE;
                    k = 2;
                    exitg4 = 0U;
                    while ((exitg4 == 0U) && (k <= n)) {
                        ix++;
                        emlrtDynamicBoundsCheckR2011a(ix, 1, potNei->size[1], &h_emlrtBCI, &emlrtContextGlobal);
                        if (!muDoubleScalarIsNaN(potNei->data[ix - 1])) {
                            mtmp = potNei->data[emlrtDynamicBoundsCheckR2011a(ix, 1, potNei->size[1], &j_emlrtBCI, &emlrtContextGlobal) - 1];
                            loop_ub = k;
                            searchingForNonNaN = FALSE;
                            exitg4 = 1U;
                        } else {
                            k++;
                        }
                    }
                    if (searchingForNonNaN) {
                    } else {
                        guard1 = TRUE;
                    }
                } else {
                    guard1 = TRUE;
                }
                if (guard1 == TRUE) {
                    for (ix = loop_ub + 1; ix <= n; ix++) {
                        if (potNei->data[emlrtDynamicBoundsCheckR2011a(ix, 1, potNei->size[1], &k_emlrtBCI, &emlrtContextGlobal) - 1] > mtmp) {
                            mtmp = potNei->data[emlrtDynamicBoundsCheckR2011a(ix, 1, potNei->size[1], &l_emlrtBCI, &emlrtContextGlobal) - 1];
                            loop_ub = ix;
                        }
                    }
                }
            }
            EMLRTPOPRTSTACK(&j_emlrtRSI);
            EMLRTPOPRTSTACK(&g_emlrtRSI);
            EMLRTPOPRTSTACK(&c_emlrtRSI);
            /* 'genomeWalkerFunc:24' if(i==nNodes+1) */
            if ((real_T)loop_ub == nNodes + 1.0) {
                exitg3 = 1U;
            } else {
                /* 'genomeWalkerFunc:28' y_new=y; */
                /* 'genomeWalkerFunc:29' y_new(i)= swap(y(i)); */
                emlrtDynamicBoundsCheckR2011a(loop_ub, 1, y_new->size[1], &d_emlrtBCI, &emlrtContextGlobal);
                /* 'swap:2' if (x==1) */
                if (y_new->data[loop_ub - 1] == 1.0) {
                    /* 'swap:3' m=2; */
                    ix = 2;
                } else {
                    /* 'swap:4' else */
                    /* 'swap:5' m=1; */
                    ix = 1;
                }
                y_new->data[emlrtDynamicBoundsCheckR2011a(loop_ub, 1, y_new->size[1], &m_emlrtBCI, &emlrtContextGlobal) - 1] = (real_T)ix;
                emlrtBreakCheck();
            }
        } while (exitg3 == 0U);
        /* 'genomeWalkerFunc:31' if( nMaxima~=0) */
        if (*nMaxima != 0.0) {
            /* 'genomeWalkerFunc:32' i=0; */
            i = 0;
            /* 'genomeWalkerFunc:33' for j=1:nMaxima */
            j = 1;
            exitg1 = 0U;
            while ((exitg1 == 0U) && ((real_T)j <= *nMaxima)) {
                /* 'genomeWalkerFunc:34' if( sum( (y_new-1)==Maximas(j,:) ) == length(y_new)) */
                emlrtBoundsCheckR2011a(j, &e_emlrtBCI, &emlrtContextGlobal);
                i0 = b_Maximas->size[0] * b_Maximas->size[1];
                b_Maximas->size[0] = 1;
                b_Maximas->size[1] = Maximas->size[1];
                emxEnsureCapacity((emxArray__common *)b_Maximas, i0, (int32_T)sizeof(real_T), &emlrtRTEI);
                loop_ub = Maximas->size[1] - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    b_Maximas->data[b_Maximas->size[0] * i0] = Maximas->data[(j + Maximas->size[0] * i0) - 1];
                }
                for (i0 = 0; i0 < 2; i0++) {
                    c_Maximas[i0] = b_Maximas->size[i0];
                }
                emlrtSizeEqCheckNDR2011a(*(int32_T (*)[2])y_new->size, c_Maximas, &emlrtECI, &emlrtContextGlobal);
                EMLRTPUSHRTSTACK(&d_emlrtRSI);
                i0 = x->size[0] * x->size[1];
                x->size[0] = 1;
                x->size[1] = y_new->size[1];
                emxEnsureCapacity((emxArray__common *)x, i0, (int32_T)sizeof(boolean_T), &emlrtRTEI);
                loop_ub = y_new->size[1] - 1;
                for (i0 = 0; i0 <= loop_ub; i0++) {
                    x->data[x->size[0] * i0] = (y_new->data[y_new->size[0] * i0] - 1.0 == Maximas->data[(j + Maximas->size[0] * i0) - 1]);
                }
                p = FALSE;
                EMLRTPUSHRTSTACK(&m_emlrtRSI);
                searchingForNonNaN = FALSE;
                k = 1;
                do {
                    exitg2 = 0U;
                    if (k <= 2) {
                        i0 = x->size[k - 1];
                        if (i0 != 0) {
                            exitg2 = 1U;
                        } else {
                            k++;
                        }
                    } else {
                        searchingForNonNaN = TRUE;
                        exitg2 = 1U;
                    }
                } while (exitg2 == 0U);
                EMLRTPOPRTSTACK(&m_emlrtRSI);
                if (searchingForNonNaN) {
                    searchingForNonNaN = TRUE;
                } else {
                    searchingForNonNaN = FALSE;
                }
                if (!searchingForNonNaN) {
                } else {
                    p = TRUE;
                }
                if (!p) {
                    searchingForNonNaN = TRUE;
                } else {
                    searchingForNonNaN = FALSE;
                }
                if (searchingForNonNaN) {
                } else {
                    EMLRTPUSHRTSTACK(&k_emlrtRSI);
                    c_y = NULL;
                    m0 = mxCreateCharArray(2, iv2);
                    emlrtInitCharArray(30, m0, cv2);
                    emlrtAssign(&c_y, m0);
                    error(message(c_y, &e_emlrtMCI), &f_emlrtMCI);
                    EMLRTPOPRTSTACK(&k_emlrtRSI);
                }
                if ((x->size[1] == 1) || (x->size[1] != 1)) {
                    searchingForNonNaN = TRUE;
                } else {
                    searchingForNonNaN = FALSE;
                }
                if (searchingForNonNaN) {
                } else {
                    EMLRTPUSHRTSTACK(&l_emlrtRSI);
                    d_y = NULL;
                    m0 = mxCreateCharArray(2, iv3);
                    emlrtInitCharArray(36, m0, cv0);
                    emlrtAssign(&d_y, m0);
                    error(message(d_y, &g_emlrtMCI), &h_emlrtMCI);
                    EMLRTPOPRTSTACK(&l_emlrtRSI);
                }
                if (x->size[1] == 0) {
                    mtmp = 0.0;
                } else {
                    ix = x->size[1];
                    mtmp = (real_T)x->data[0];
                    for (k = 2; k <= ix; k++) {
                        mtmp += (real_T)x->data[emlrtDynamicBoundsCheckR2011a(k, 1, x->size[1], &o_emlrtBCI, &emlrtContextGlobal) - 1];
                    }
                }
                if (y_new->size[1] == 0) {
                    n = 0;
                } else {
                    n = y_new->size[1];
                }
                EMLRTPOPRTSTACK(&d_emlrtRSI);
                if (mtmp == (real_T)n) {
                    /* 'genomeWalkerFunc:35' i=j; */
                    i = j;
                    exitg1 = 1U;
                } else {
                    j++;
                    emlrtBreakCheck();
                }
            }
            /* 'genomeWalkerFunc:40' if (i==0) */
            if (i == 0) {
                /* 'genomeWalkerFunc:41' nMaxima=nMaxima+1; */
                (*nMaxima)++;
                /* 'genomeWalkerFunc:42' Maximas(nMaxima,:) = (y_new-1); */
                i0 = emlrtBoundsCheckR2011a((int32_T)*nMaxima, &f_emlrtBCI, &emlrtContextGlobal) - 1;
                ix = r3->size[0];
                r3->size[0] = Maximas->size[1];
                emxEnsureCapacity((emxArray__common *)r3, ix, (int32_T)sizeof(int32_T), &emlrtRTEI);
                loop_ub = Maximas->size[1] - 1;
                for (ix = 0; ix <= loop_ub; ix++) {
                    r3->data[ix] = ix;
                }
                c_Maximas[0] = 1;
                c_Maximas[1] = r3->size[0];
                emlrtSubAssignSizeCheckR2011a(c_Maximas, 2, *(int32_T (*)[2])y_new->size, 2, &b_emlrtECI, &emlrtContextGlobal);
                loop_ub = y_new->size[1] - 1;
                for (ix = 0; ix <= loop_ub; ix++) {
                    Maximas->data[i0 + Maximas->size[0] * r3->data[ix]] = y_new->data[y_new->size[0] * ix] - 1.0;
                }
                /* 'genomeWalkerFunc:43' Mcount(nMaxima)=1; */
                Mcount[(int32_T)*nMaxima - 1] = 1.0;
                /* 'genomeWalkerFunc:44' Mpot(nMaxima)=UGM_ConfigurationPotential(y_new,nodePot,edgePot,edgeEnds); */
                EMLRTPUSHRTSTACK(&e_emlrtRSI);
                Mpot[(int32_T)*nMaxima - 1] = UGM_ConfigurationPotential(y_new, nodePot, edgePot, edgeEnds);
                EMLRTPOPRTSTACK(&e_emlrtRSI);
                /* 'genomeWalkerFunc:45' Chrom_maxima(t)=nMaxima; */
                Chrom_maxima->data[emlrtDynamicBoundsCheckR2011a((int32_T)t, 1, Chrom_maxima->size[1], &q_emlrtBCI, &emlrtContextGlobal) - 1] = *nMaxima;
            } else {
                /* 'genomeWalkerFunc:46' else */
                /* 'genomeWalkerFunc:47' Mcount(i)=Mcount(i)+1; */
                Mcount[i - 1]++;
                /* 'genomeWalkerFunc:48' Chrom_maxima(t)=i; */
                Chrom_maxima->data[emlrtDynamicBoundsCheckR2011a((int32_T)t, 1, Chrom_maxima->size[1], &p_emlrtBCI, &emlrtContextGlobal) - 1] = (real_T)i;
            }
        } else {
            /* 'genomeWalkerFunc:51' else */
            /* 'genomeWalkerFunc:52' nMaxima=nMaxima+1; */
            *nMaxima = 1.0;
            /* 'genomeWalkerFunc:53' Maximas(nMaxima,:) = (y_new-1); */
            i0 = r3->size[0];
            r3->size[0] = Maximas->size[1];
            emxEnsureCapacity((emxArray__common *)r3, i0, (int32_T)sizeof(int32_T), &emlrtRTEI);
            loop_ub = Maximas->size[1] - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                r3->data[i0] = i0;
            }
            c_Maximas[0] = 1;
            c_Maximas[1] = r3->size[0];
            emlrtSubAssignSizeCheckR2011a(c_Maximas, 2, *(int32_T (*)[2])y_new->size, 2, &c_emlrtECI, &emlrtContextGlobal);
            loop_ub = y_new->size[1] - 1;
            for (i0 = 0; i0 <= loop_ub; i0++) {
                Maximas->data[Maximas->size[0] * r3->data[i0]] = y_new->data[y_new->size[0] * i0] - 1.0;
            }
            /* 'genomeWalkerFunc:54' Mpot(nMaxima)=UGM_ConfigurationPotential(y_new,nodePot,edgePot,edgeEnds); */
            EMLRTPUSHRTSTACK(&f_emlrtRSI);
            Mpot[0] = UGM_ConfigurationPotential(y_new, nodePot, edgePot, edgeEnds);
            EMLRTPOPRTSTACK(&f_emlrtRSI);
            /* 'genomeWalkerFunc:55' Chrom_maxima(t)=1; */
            Chrom_maxima->data[emlrtDynamicBoundsCheckR2011a((int32_T)t, 1, Chrom_maxima->size[1], &n_emlrtBCI, &emlrtContextGlobal) - 1] = 1.0;
        }
        /* n(t)=nMaxima; */
        t++;
        emlrtBreakCheck();
    }
    emxFree_real_T(&b_Maximas);
    emxFree_boolean_T(&x);
    emxFree_int32_T(&r3);
    emxFree_real_T(&ynei);
    emxFree_real_T(&potNei);
    emxFree_real_T(&y_new);
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (genomeWalkerFunc.c) */
