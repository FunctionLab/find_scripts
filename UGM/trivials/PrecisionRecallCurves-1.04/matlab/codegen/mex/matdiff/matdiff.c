/*
 * matdiff.c
 *
 * Code generation for function 'matdiff'
 *
 * C source code generated on: Sun Sep 09 23:00:54 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "matdiff.h"
#include "find.h"
#include "intersect.h"
#include "length.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 8, "matdiff", "E:/Data/Projects/Chromating/Finalize/lib/matdiff.m" };
static emlrtRSInfo b_emlrtRSI = { 9, "matdiff", "E:/Data/Projects/Chromating/Finalize/lib/matdiff.m" };
static emlrtRSInfo c_emlrtRSI = { 13, "matdiff", "E:/Data/Projects/Chromating/Finalize/lib/matdiff.m" };
static emlrtBCInfo emlrtBCI = { -1, -1, 5, 27, "all", "matdiff", "E:/Data/Projects/Chromating/Finalize/lib/matdiff.m", 0 };
static emlrtBCInfo b_emlrtBCI = { -1, -1, 7, 24, "train", "matdiff", "E:/Data/Projects/Chromating/Finalize/lib/matdiff.m", 0 };
static emlrtBCInfo c_emlrtBCI = { -1, -1, 9, 40, "train", "matdiff", "E:/Data/Projects/Chromating/Finalize/lib/matdiff.m", 0 };
static emlrtBCInfo d_emlrtBCI = { -1, -1, 9, 50, "all", "matdiff", "E:/Data/Projects/Chromating/Finalize/lib/matdiff.m", 0 };
static emlrtBCInfo e_emlrtBCI = { -1, -1, 10, 5, "isTest", "matdiff", "E:/Data/Projects/Chromating/Finalize/lib/matdiff.m", 0 };
static emlrtBCInfo f_emlrtBCI = { -1, -1, 10, 13, "temp", "matdiff", "E:/Data/Projects/Chromating/Finalize/lib/matdiff.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * function [TestInd] =   matdiff(all,train)
 */
void matdiff(matdiffStackData *SD, const boolean_T all_data[15978598], const int32_T all_sizes[2], const boolean_T train_data[7989336], const int32_T train_sizes[2], real_T TestInd_data[215927], int32_T TestInd_sizes[1])
{
    int32_T b_all_sizes[2];
    int32_T loop_ub;
    int32_T i0;
    real_T b_loop_ub;
    int32_T isTest_sizes;
    int32_T b_train_sizes[2];
    int32_T i;
    int32_T temp_sizes;
    int32_T b_i;
    int32_T c_train_sizes[2];
    boolean_T b_train_data[74];
    int32_T c_all_sizes[2];
    int32_T ind_sizes;
    real_T ind_data[1];
    real_T junk_data[1];
    boolean_T b_junk_data[74];
    int32_T tmp_data[1];
    /* 'matdiff:5' isTest = zeros(length(all(1,:)),1); */
    emlrtDynamicBoundsCheckR2011a(1, 1, all_sizes[0], &emlrtBCI, &emlrtContextGlobal);
    b_all_sizes[0] = 1;
    b_all_sizes[1] = all_sizes[1];
    loop_ub = all_sizes[1] - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        SD->f1.b_all_data[i0] = all_data[all_sizes[0] * i0];
    }
    b_loop_ub = length(SD->f1.b_all_data, b_all_sizes);
    isTest_sizes = (int32_T)b_loop_ub;
    loop_ub = (int32_T)b_loop_ub - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        SD->f1.isTest_data[i0] = 0;
    }
    /* 'matdiff:7' for i = 1:length(train(1,:)) */
    emlrtDynamicBoundsCheckR2011a(1, 1, train_sizes[0], &b_emlrtBCI, &emlrtContextGlobal);
    b_train_sizes[0] = 1;
    b_train_sizes[1] = train_sizes[1];
    loop_ub = train_sizes[1] - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        SD->f1.b_all_data[i0] = train_data[train_sizes[0] * i0];
    }
    b_loop_ub = length(SD->f1.b_all_data, b_train_sizes);
    i = 1;
    while ((real_T)i <= b_loop_ub) {
        /* 'matdiff:8' temp = find(isTest~=1); */
        EMLRTPUSHRTSTACK(&emlrtRSI);
        loop_ub = isTest_sizes - 1;
        for (i0 = 0; i0 <= loop_ub; i0++) {
            SD->f1.b_all_data[i0] = (SD->f1.isTest_data[i0] != 1);
        }
        find(SD, SD->f1.b_all_data, *(int32_T (*)[1])&isTest_sizes, SD->f1.temp_data, &temp_sizes);
        EMLRTPOPRTSTACK(&emlrtRSI);
        /* 'matdiff:9' [junk,junk,ind] =intersect(train(:,i)',all(:,temp)','rows'); */
        EMLRTPUSHRTSTACK(&b_emlrtRSI);
        b_i = emlrtDynamicBoundsCheckR2011a(i, 1, train_sizes[1], &c_emlrtBCI, &emlrtContextGlobal);
        c_train_sizes[0] = 1;
        c_train_sizes[1] = train_sizes[0];
        loop_ub = train_sizes[0] - 1;
        for (i0 = 0; i0 <= loop_ub; i0++) {
            b_train_data[i0] = train_data[i0 + train_sizes[0] * (b_i - 1)];
        }
        c_all_sizes[0] = temp_sizes;
        c_all_sizes[1] = all_sizes[0];
        loop_ub = all_sizes[0] - 1;
        for (i0 = 0; i0 <= loop_ub; i0++) {
            b_i = temp_sizes - 1;
            for (ind_sizes = 0; ind_sizes <= b_i; ind_sizes++) {
                SD->f1.all_data[ind_sizes + c_all_sizes[0] * i0] = all_data[i0 + all_sizes[0] * (emlrtDynamicBoundsCheckR2011a((int32_T)SD->f1.temp_data[ind_sizes], 1, all_sizes[1], &d_emlrtBCI, &emlrtContextGlobal) - 1)];
            }
        }
        intersect(b_train_data, c_train_sizes, SD->f1.all_data, c_all_sizes, b_junk_data, b_all_sizes, junk_data, &b_i, ind_data, &ind_sizes);
        EMLRTPOPRTSTACK(&b_emlrtRSI);
        /* 'matdiff:10' isTest( temp (ind)  ) =1; */
        b_i = ind_sizes - 1;
        loop_ub = ind_sizes - 1;
        for (i0 = 0; i0 <= loop_ub; i0++) {
            tmp_data[i0] = emlrtDynamicBoundsCheckR2011a((int32_T)SD->f1.temp_data[emlrtDynamicBoundsCheckR2011a((int32_T)ind_data[i0], 1, temp_sizes, &f_emlrtBCI, &emlrtContextGlobal) - 1], 1, isTest_sizes, &e_emlrtBCI, &emlrtContextGlobal);
        }
        for (i0 = 0; i0 <= b_i; i0++) {
            SD->f1.isTest_data[tmp_data[i0] - 1] = 1;
        }
        i++;
        emlrtBreakCheck();
    }
    /* 'matdiff:13' TestInd= find(isTest~=1); */
    EMLRTPUSHRTSTACK(&c_emlrtRSI);
    loop_ub = isTest_sizes - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
        SD->f1.b_all_data[i0] = (SD->f1.isTest_data[i0] != 1);
    }
    find(SD, SD->f1.b_all_data, *(int32_T (*)[1])&isTest_sizes, TestInd_data, TestInd_sizes);
    EMLRTPOPRTSTACK(&c_emlrtRSI);
}
/* End of code generation (matdiff.c) */
