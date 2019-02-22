/*
 * intersect.c
 *
 * Code generation for function 'intersect'
 *
 * C source code generated on: Sun Sep 09 23:00:54 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "matdiff.h"
#include "intersect.h"
#include "find.h"
#include "matdiff_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo f_emlrtRSI = { 28, "intersect", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/intersect.m" };
static emlrtRSInfo g_emlrtRSI = { 63, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtRSInfo h_emlrtRSI = { 516, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtRSInfo i_emlrtRSI = { 513, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtRSInfo j_emlrtRSI = { 492, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtRSInfo k_emlrtRSI = { 401, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtRSInfo l_emlrtRSI = { 394, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtRSInfo m_emlrtRSI = { 378, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtRSInfo n_emlrtRSI = { 377, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtRSInfo o_emlrtRSI = { 374, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtRSInfo p_emlrtRSI = { 328, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtRSInfo q_emlrtRSI = { 32, "issorted", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/datafun/issorted.m" };
static emlrtRSInfo r_emlrtRSI = { 21, "colon", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo t_emlrtRSI = { 75, "colon", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo u_emlrtRSI = { 98, "colon", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/colon.m" };
static emlrtRSInfo w_emlrtRSI = { 32, "issorted", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/datafun/issorted.m" };
static emlrtRSInfo x_emlrtRSI = { 35, "issorted", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/datafun/issorted.m" };
static emlrtRSInfo y_emlrtRSI = { 15, "eml_error", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo c_emlrtMCI = { 329, 5, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtMCInfo d_emlrtMCI = { 328, 15, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtMCInfo e_emlrtMCI = { 492, 1, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtMCInfo f_emlrtMCI = { 513, 1, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtMCInfo g_emlrtMCI = { 516, 5, "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m" };
static emlrtMCInfo l_emlrtMCI = { 15, 19, "eml_error", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo m_emlrtMCI = { 15, 5, "eml_error", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtBCInfo k_emlrtBCI = { -1, -1, 517, 13, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo l_emlrtBCI = { -1, -1, 517, 13, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo m_emlrtBCI = { -1, -1, 514, 9, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo n_emlrtBCI = { -1, -1, 514, 9, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo o_emlrtBCI = { -1, -1, 507, 11, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo p_emlrtBCI = { -1, -1, 507, 11, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo q_emlrtBCI = { -1, -1, 30, 14, "", "eml_sort_le", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo r_emlrtBCI = { -1, -1, 29, 14, "", "eml_sort_le", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo s_emlrtBCI = { -1, -1, 26, 16, "", "eml_sort_le", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/eml/eml_sort_le.m", 0 };
static emlrtBCInfo t_emlrtBCI = { -1, -1, 304, 26, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo u_emlrtBCI = { -1, -1, 304, 31, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo v_emlrtBCI = { -1, -1, 304, 36, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo w_emlrtBCI = { -1, -1, 304, 41, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo x_emlrtBCI = { -1, -1, 305, 30, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo y_emlrtBCI = { -1, -1, 305, 35, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo ab_emlrtBCI = { -1, -1, 305, 40, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo bb_emlrtBCI = { -1, -1, 305, 45, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo cb_emlrtBCI = { -1, -1, 408, 13, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo db_emlrtBCI = { -1, -1, 409, 13, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo eb_emlrtBCI = { -1, -1, 406, 19, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo fb_emlrtBCI = { -1, -1, 406, 22, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo gb_emlrtBCI = { -1, -1, 406, 34, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo hb_emlrtBCI = { -1, -1, 304, 31, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo ib_emlrtBCI = { -1, -1, 304, 36, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo jb_emlrtBCI = { -1, -1, 304, 41, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo kb_emlrtBCI = { -1, -1, 305, 35, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo lb_emlrtBCI = { -1, -1, 305, 40, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };
static emlrtBCInfo mb_emlrtBCI = { -1, -1, 305, 45, "", "eml_setop", "D:/Program Files/MATLAB/R2011a/toolbox/eml/lib/matlab/ops/eml_setop.m", 0 };

/* Function Declarations */
static void eml_error(void);
static const mxArray *message(const mxArray *b, emlrtMCInfo *location);
static uint8_T relop_rows(const boolean_T a_data[74], const int32_T a_sizes[2], int32_T arow, const boolean_T b_data[15978598], const int32_T b_sizes[2], int32_T brow);

/* Function Definitions */

/*
 * 
 */
static void eml_error(void)
{
    const mxArray *y;
    static const int32_T iv1[2] = { 1, 37 };
    const mxArray *m1;
    static const char_T cv1[37] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 's', 'e', 't', 'o', 'p', '_', 'u', 'n', 's', 'o', 'r', 't', 'e', 'd', 'R', 'o', 'w', 's', 'B' };
    EMLRTPUSHRTSTACK(&y_emlrtRSI);
    y = NULL;
    m1 = mxCreateCharArray(2, iv1);
    emlrtInitCharArray(37, m1, cv1);
    emlrtAssign(&y, m1);
    error(message(y, &l_emlrtMCI), &m_emlrtMCI);
    EMLRTPOPRTSTACK(&y_emlrtRSI);
}

static const mxArray *message(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    const mxArray *m4;
    pArray = b;
    return emlrtCallMATLAB(1, &m4, 1, &pArray, "message", TRUE, location);
}

/*
 * 
 */
static uint8_T relop_rows(const boolean_T a_data[74], const int32_T a_sizes[2], int32_T arow, const boolean_T b_data[15978598], const int32_T b_sizes[2], int32_T brow)
{
    uint8_T p;
    int32_T k;
    int32_T exitg1;
    boolean_T b_p;
    k = 1;
    do {
        exitg1 = 0U;
        if (k <= a_sizes[1]) {
            emlrtDynamicBoundsCheckR2011a(k, 1, a_sizes[1], &hb_emlrtBCI, &emlrtContextGlobal);
            emlrtDynamicBoundsCheckR2011a(brow, 1, b_sizes[0], &ib_emlrtBCI, &emlrtContextGlobal);
            emlrtDynamicBoundsCheckR2011a(k, 1, b_sizes[1], &jb_emlrtBCI, &emlrtContextGlobal);
            if (a_data[a_sizes[0] * (k - 1)] == b_data[(brow + b_sizes[0] * (k - 1)) - 1]) {
                k++;
            } else {
                emlrtDynamicBoundsCheckR2011a(k, 1, a_sizes[1], &kb_emlrtBCI, &emlrtContextGlobal);
                emlrtDynamicBoundsCheckR2011a(brow, 1, b_sizes[0], &lb_emlrtBCI, &emlrtContextGlobal);
                emlrtDynamicBoundsCheckR2011a(k, 1, b_sizes[1], &mb_emlrtBCI, &emlrtContextGlobal);
                if (a_data[a_sizes[0] * (k - 1)] < b_data[(brow + b_sizes[0] * (k - 1)) - 1]) {
                    b_p = TRUE;
                } else {
                    b_p = FALSE;
                }
                if (b_p) {
                    p = 1;
                } else {
                    p = 2;
                }
                exitg1 = 1U;
            }
        } else {
            p = 0;
            exitg1 = 1U;
        }
    } while (exitg1 == 0U);
    return p;
}

/*
 * 
 */
void intersect(const boolean_T varargin_1_data[74], const int32_T varargin_1_sizes[2], const boolean_T varargin_2_data[15978598], const int32_T varargin_2_sizes[2], boolean_T c_data[74], int32_T c_sizes[2], real_T ia_data[1], int32_T ia_sizes[1], real_T ib_data[1], int32_T ib_sizes[1])
{
    boolean_T b0;
    const mxArray *y;
    static const int32_T iv0[2] = { 1, 36 };
    const mxArray *m0;
    static const char_T cv0[36] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'e', 't', 'x', 'o', 'r', '_', 'A', 'a', 'n', 'd', 'B', 'C', 'o', 'l', 'n', 'u', 'm', 'A', 'g', 'r', 'e', 'e' };
    int32_T ncmax;
    int32_T nc;
    boolean_T b_y;
    int32_T coloffset;
    int32_T k;
    int32_T tmp_data[74];
    int32_T col_data[74];
    int32_T nm1;
    boolean_T exitg3;
    boolean_T p;
    int32_T i2;
    boolean_T exitg4;
    int32_T c;
    int32_T b_c;
    boolean_T exitg1;
    int32_T exitg2;
    uint8_T r;
    const mxArray *c_y;
    boolean_T b_c_data[74];
    const mxArray *d_y;
    const mxArray *e_y;
    int32_T b_ib_data[1];
    EMLRTPUSHRTSTACK(&f_emlrtRSI);
    EMLRTPUSHRTSTACK(&g_emlrtRSI);
    if (varargin_1_sizes[1] == varargin_2_sizes[1]) {
        b0 = TRUE;
    } else {
        b0 = FALSE;
    }
    if (b0) {
    } else {
        EMLRTPUSHRTSTACK(&p_emlrtRSI);
        y = NULL;
        m0 = mxCreateCharArray(2, iv0);
        emlrtInitCharArray(36, m0, cv0);
        emlrtAssign(&y, m0);
        error(message(y, &c_emlrtMCI), &d_emlrtMCI);
        EMLRTPOPRTSTACK(&p_emlrtRSI);
    }
    ncmax = muIntScalarMin_sint32(1, varargin_2_sizes[0]);
    c_sizes[0] = (int32_T)(int8_T)ncmax;
    c_sizes[1] = (int32_T)(int8_T)muIntScalarMin_sint32(varargin_1_sizes[1], varargin_2_sizes[1]);
    nc = 0;
    ia_sizes[0] = ncmax;
    ib_sizes[0] = ncmax;
    EMLRTPUSHRTSTACK(&o_emlrtRSI);
    if (varargin_1_sizes[1] == 0) {
    } else {
        EMLRTPUSHRTSTACK(&q_emlrtRSI);
        EMLRTPUSHRTSTACK(&r_emlrtRSI);
        EMLRTPUSHRTSTACK(&t_emlrtRSI);
        EMLRTPUSHRTSTACK(&u_emlrtRSI);
        EMLRTPOPRTSTACK(&u_emlrtRSI);
        EMLRTPOPRTSTACK(&t_emlrtRSI);
        EMLRTPOPRTSTACK(&r_emlrtRSI);
        EMLRTPOPRTSTACK(&q_emlrtRSI);
    }
    EMLRTPOPRTSTACK(&o_emlrtRSI);
    EMLRTPUSHRTSTACK(&n_emlrtRSI);
    b_y = TRUE;
    if ((varargin_2_sizes[0] == 0) || (varargin_2_sizes[1] == 0)) {
    } else {
        EMLRTPUSHRTSTACK(&w_emlrtRSI);
        EMLRTPUSHRTSTACK(&r_emlrtRSI);
        EMLRTPUSHRTSTACK(&t_emlrtRSI);
        EMLRTPUSHRTSTACK(&u_emlrtRSI);
        EMLRTPOPRTSTACK(&u_emlrtRSI);
        coloffset = varargin_2_sizes[1] - 1;
        for (k = 0; k <= coloffset; k++) {
            tmp_data[k] = 1 + k;
        }
        coloffset = varargin_2_sizes[1] - 1;
        for (k = 0; k <= coloffset; k++) {
            col_data[k] = tmp_data[k];
        }
        EMLRTPOPRTSTACK(&t_emlrtRSI);
        EMLRTPOPRTSTACK(&r_emlrtRSI);
        EMLRTPOPRTSTACK(&w_emlrtRSI);
        nm1 = varargin_2_sizes[0] - 1;
        k = 1;
        exitg3 = 0U;
        while ((exitg3 == 0U) && (k <= nm1)) {
            EMLRTPUSHRTSTACK(&x_emlrtRSI);
            p = TRUE;
            i2 = 1;
            exitg4 = 0U;
            while ((exitg4 == 0U) && (i2 <= varargin_2_sizes[1])) {
                emlrtDynamicBoundsCheckR2011a(i2, 1, varargin_2_sizes[1], &s_emlrtBCI, &emlrtContextGlobal);
                coloffset = (col_data[i2 - 1] - 1) * varargin_2_sizes[0];
                c = (coloffset + k) - 1;
                emlrtDynamicBoundsCheckR2011a(coloffset + k, 1, varargin_2_sizes[0] * varargin_2_sizes[1], &r_emlrtBCI, &emlrtContextGlobal);
                b_c = coloffset + k;
                emlrtDynamicBoundsCheckR2011a((coloffset + k) + 1, 1, varargin_2_sizes[0] * varargin_2_sizes[1], &q_emlrtBCI, &emlrtContextGlobal);
                if (varargin_2_data[c] == varargin_2_data[b_c]) {
                    b0 = TRUE;
                } else {
                    b0 = FALSE;
                }
                if (!b0) {
                    if (varargin_2_data[c] <= varargin_2_data[b_c]) {
                        p = TRUE;
                    } else {
                        p = FALSE;
                    }
                    exitg4 = 1U;
                } else {
                    i2++;
                }
            }
            EMLRTPOPRTSTACK(&x_emlrtRSI);
            if (!p) {
                b_y = FALSE;
                exitg3 = 1U;
            } else {
                k++;
            }
        }
    }
    EMLRTPOPRTSTACK(&n_emlrtRSI);
    if (!b_y) {
        EMLRTPUSHRTSTACK(&m_emlrtRSI);
        eml_error();
        EMLRTPOPRTSTACK(&m_emlrtRSI);
    }
    nm1 = 1;
    i2 = 1;
    while ((nm1 <= 1) && (i2 <= varargin_2_sizes[0])) {
        exitg1 = 0U;
        while ((exitg1 == 0U) && (i2 < varargin_2_sizes[0])) {
            EMLRTPUSHRTSTACK(&l_emlrtRSI);
            k = 1;
            do {
                exitg2 = 0U;
                if (k <= varargin_2_sizes[1]) {
                    emlrtDynamicBoundsCheckR2011a(k, 1, varargin_2_sizes[1], &u_emlrtBCI, &emlrtContextGlobal);
                    emlrtDynamicBoundsCheckR2011a(i2 + 1, 1, varargin_2_sizes[0], &t_emlrtBCI, &emlrtContextGlobal);
                    emlrtDynamicBoundsCheckR2011a(k, 1, varargin_2_sizes[1], &w_emlrtBCI, &emlrtContextGlobal);
                    emlrtDynamicBoundsCheckR2011a(i2, 1, varargin_2_sizes[0], &v_emlrtBCI, &emlrtContextGlobal);
                    if (varargin_2_data[i2 + varargin_2_sizes[0] * (k - 1)] == varargin_2_data[(i2 + varargin_2_sizes[0] * (k - 1)) - 1]) {
                        k++;
                    } else {
                        emlrtDynamicBoundsCheckR2011a(k, 1, varargin_2_sizes[1], &y_emlrtBCI, &emlrtContextGlobal);
                        emlrtDynamicBoundsCheckR2011a(i2 + 1, 1, varargin_2_sizes[0], &x_emlrtBCI, &emlrtContextGlobal);
                        emlrtDynamicBoundsCheckR2011a(k, 1, varargin_2_sizes[1], &bb_emlrtBCI, &emlrtContextGlobal);
                        emlrtDynamicBoundsCheckR2011a(i2, 1, varargin_2_sizes[0], &ab_emlrtBCI, &emlrtContextGlobal);
                        if (varargin_2_data[i2 + varargin_2_sizes[0] * (k - 1)] < varargin_2_data[(i2 + varargin_2_sizes[0] * (k - 1)) - 1]) {
                            p = TRUE;
                        } else {
                            p = FALSE;
                        }
                        if (p) {
                            r = 1;
                        } else {
                            r = 2;
                        }
                        exitg2 = 1U;
                    }
                } else {
                    r = 0;
                    exitg2 = 1U;
                }
            } while (exitg2 == 0U);
            EMLRTPOPRTSTACK(&l_emlrtRSI);
            if (r == 0) {
                i2++;
            } else {
                exitg1 = 1U;
            }
        }
        EMLRTPUSHRTSTACK(&k_emlrtRSI);
        r = relop_rows(varargin_1_data, varargin_1_sizes, 1, varargin_2_data, varargin_2_sizes, i2);
        EMLRTPOPRTSTACK(&k_emlrtRSI);
        if (r == 0) {
            nc++;
            for (k = 1; k <= varargin_1_sizes[1]; k++) {
                c_data[(emlrtDynamicBoundsCheckR2011a(nc, 1, c_sizes[0], &eb_emlrtBCI, &emlrtContextGlobal) + c_sizes[0] * (emlrtDynamicBoundsCheckR2011a(k, 1, c_sizes[1], &fb_emlrtBCI, &emlrtContextGlobal) - 1)) - 1] = varargin_1_data[varargin_1_sizes[0] * (emlrtDynamicBoundsCheckR2011a(k, 1, varargin_1_sizes[1], &gb_emlrtBCI, &emlrtContextGlobal) - 1)];
            }
            ia_data[emlrtDynamicBoundsCheckR2011a(nc, 1, ia_sizes[0], &cb_emlrtBCI, &emlrtContextGlobal) - 1] = 1.0;
            ib_data[emlrtDynamicBoundsCheckR2011a(nc, 1, ib_sizes[0], &db_emlrtBCI, &emlrtContextGlobal) - 1] = (real_T)i2;
            nm1 = 2;
            i2++;
        } else if (r == 1) {
            nm1 = 2;
        } else {
            i2++;
        }
    }
    if (nc <= ncmax) {
    } else {
        EMLRTPUSHRTSTACK(&j_emlrtRSI);
        c_y = NULL;
        m0 = mxCreateString("Assertion failed.");
        emlrtAssign(&c_y, m0);
        error(c_y, &e_emlrtMCI);
        EMLRTPOPRTSTACK(&j_emlrtRSI);
    }
    if (1 > nc) {
        k = -1;
    } else {
        emlrtDynamicBoundsCheckR2011a(1, 1, c_sizes[0], &p_emlrtBCI, &emlrtContextGlobal);
        emlrtDynamicBoundsCheckR2011a(1, 1, c_sizes[0], &o_emlrtBCI, &emlrtContextGlobal);
        k = 0;
    }
    c = k + 1;
    i2 = c_sizes[1];
    coloffset = c_sizes[1] - 1;
    for (b_c = 0; b_c <= coloffset; b_c++) {
        nm1 = 0;
        while (nm1 <= k) {
            b_c_data[c * b_c] = c_data[c_sizes[0] * b_c];
            nm1 = 1;
        }
    }
    c_sizes[0] = c;
    c_sizes[1] = i2;
    coloffset = i2 - 1;
    for (k = 0; k <= coloffset; k++) {
        nm1 = c - 1;
        b_c = 0;
        while (b_c <= nm1) {
            c_data[c_sizes[0] * k] = b_c_data[c * k];
            b_c = 1;
        }
    }
    if (nc <= ncmax) {
    } else {
        EMLRTPUSHRTSTACK(&i_emlrtRSI);
        d_y = NULL;
        m0 = mxCreateString("Assertion failed.");
        emlrtAssign(&d_y, m0);
        error(d_y, &f_emlrtMCI);
        EMLRTPOPRTSTACK(&i_emlrtRSI);
    }
    if (1 > nc) {
        nm1 = -1;
    } else {
        emlrtDynamicBoundsCheckR2011a(1, 1, ia_sizes[0], &n_emlrtBCI, &emlrtContextGlobal);
        emlrtDynamicBoundsCheckR2011a(1, 1, ia_sizes[0], &m_emlrtBCI, &emlrtContextGlobal);
        nm1 = 0;
    }
    ia_sizes[0] = nm1 + 1;
    k = 0;
    while (k <= nm1) {
        ia_data[0] = 1.0;
        k = 1;
    }
    if (nc <= ncmax) {
    } else {
        EMLRTPUSHRTSTACK(&h_emlrtRSI);
        e_y = NULL;
        m0 = mxCreateString("Assertion failed.");
        emlrtAssign(&e_y, m0);
        error(e_y, &g_emlrtMCI);
        EMLRTPOPRTSTACK(&h_emlrtRSI);
    }
    if (1 > nc) {
        nm1 = -1;
    } else {
        emlrtDynamicBoundsCheckR2011a(1, 1, ib_sizes[0], &l_emlrtBCI, &emlrtContextGlobal);
        emlrtDynamicBoundsCheckR2011a(1, 1, ib_sizes[0], &k_emlrtBCI, &emlrtContextGlobal);
        nm1 = 0;
    }
    k = 0;
    while (k <= nm1) {
        b_ib_data[0] = (int32_T)ib_data[0];
        k = 1;
    }
    ib_sizes[0] = nm1 + 1;
    k = 0;
    while (k <= nm1) {
        ib_data[0] = (real_T)b_ib_data[0];
        k = 1;
    }
    EMLRTPOPRTSTACK(&g_emlrtRSI);
    EMLRTPOPRTSTACK(&f_emlrtRSI);
}
/* End of code generation (intersect.c) */
