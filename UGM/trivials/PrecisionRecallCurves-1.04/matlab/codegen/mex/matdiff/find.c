/*
 * find.c
 *
 * Code generation for function 'find'
 *
 * C source code generated on: Sun Sep 09 23:00:54 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "matdiff.h"
#include "find.h"
#include "matdiff_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo e_emlrtRSI = { 211, "find", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtMCInfo b_emlrtMCI = { 211, 9, "find", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtBCInfo g_emlrtBCI = { -1, -1, 221, 17, "", "find", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/elmat/find.m", 0 };
static emlrtBCInfo h_emlrtBCI = { -1, -1, 221, 17, "", "find", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/elmat/find.m", 0 };
static emlrtECInfo emlrtECI = { -1, 221, 17, "find", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/elmat/find.m" };
static emlrtBCInfo i_emlrtBCI = { -1, -1, 203, 33, "", "find", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/elmat/find.m", 0 };
static emlrtBCInfo j_emlrtBCI = { -1, -1, 205, 17, "", "find", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/elmat/find.m", 0 };

/* Function Declarations */
static const mxArray *emlrt_marshallOut(char * u);

/* Function Definitions */

static const mxArray *emlrt_marshallOut(char * u)
{
    const mxArray *y;
    const mxArray *m2;
    y = NULL;
    m2 = mxCreateString(u);
    emlrtAssign(&y, m2);
    return y;
}

/*
 * 
 */
void find(matdiffStackData *SD, const boolean_T x_data[215927], const int32_T x_sizes[1], real_T i_data[215927], int32_T i_sizes[1])
{
    int32_T idx;
    int32_T ii;
    boolean_T exitg1;
    boolean_T guard1 = FALSE;
    int32_T i1;
    idx = 0;
    i_sizes[0] = x_sizes[0];
    ii = 1;
    exitg1 = 0U;
    while ((exitg1 == 0U) && (ii <= x_sizes[0])) {
        guard1 = FALSE;
        if (x_data[emlrtDynamicBoundsCheckR2011a(ii, 1, x_sizes[0], &i_emlrtBCI, &emlrtContextGlobal) - 1]) {
            idx++;
            i_data[emlrtDynamicBoundsCheckR2011a(idx, 1, i_sizes[0], &j_emlrtBCI, &emlrtContextGlobal) - 1] = (real_T)ii;
            if (idx >= x_sizes[0]) {
                exitg1 = 1U;
            } else {
                guard1 = TRUE;
            }
        } else {
            guard1 = TRUE;
        }
        if (guard1 == TRUE) {
            ii++;
        }
    }
    if (idx <= x_sizes[0]) {
    } else {
        EMLRTPUSHRTSTACK(&e_emlrtRSI);
        error(emlrt_marshallOut("Assertion failed."), &b_emlrtMCI);
        EMLRTPOPRTSTACK(&e_emlrtRSI);
    }
    if (x_sizes[0] == 1) {
        if (idx == 0) {
            i_sizes[0] = 0;
        }
    } else {
        if (1 > idx) {
            idx = 0;
        } else {
            emlrtDynamicBoundsCheckR2011a(1, 1, i_sizes[0], &g_emlrtBCI, &emlrtContextGlobal);
            idx = emlrtDynamicBoundsCheckR2011a(idx, 1, i_sizes[0], &h_emlrtBCI, &emlrtContextGlobal);
        }
        ii = idx - 1;
        for (i1 = 0; i1 <= ii; i1++) {
            SD->f0.tmp_data[i1] = 1 + i1;
        }
        ii = idx - 1;
        for (i1 = 0; i1 <= ii; i1++) {
            SD->f0.b_tmp_data[i1] = SD->f0.tmp_data[i1];
        }
        emlrtVectorVectorIndexCheckR2011a(i_sizes[0], 1, 1, idx, &emlrtECI, &emlrtContextGlobal);
        ii = idx - 1;
        for (i1 = 0; i1 <= ii; i1++) {
            SD->f0.tmp_data[i1] = (int32_T)i_data[SD->f0.b_tmp_data[i1] - 1];
        }
        i_sizes[0] = idx;
        ii = idx - 1;
        for (i1 = 0; i1 <= ii; i1++) {
            i_data[i1] = (real_T)SD->f0.tmp_data[i1];
        }
    }
}
/* End of code generation (find.c) */
