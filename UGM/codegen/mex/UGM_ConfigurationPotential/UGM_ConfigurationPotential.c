/*
 * UGM_ConfigurationPotential.c
 *
 * Code generation for function 'UGM_ConfigurationPotential'
 *
 * C source code generated on: Mon Sep 10 15:47:03 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "UGM_ConfigurationPotential.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtBCInfo emlrtBCI = { -1, -1, 10, 22, "nodePot", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtDCInfo emlrtDCI = { 10, 24, "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 1 };
static emlrtBCInfo b_emlrtBCI = { 1, 2, 10, 24, "nodePot", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtBCInfo c_emlrtBCI = { -1, -1, 15, 18, "edgeEnds", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtBCInfo d_emlrtBCI = { -1, -1, 16, 18, "edgeEnds", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtDCInfo b_emlrtDCI = { 17, 22, "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 1 };
static emlrtBCInfo e_emlrtBCI = { 1, 2, 17, 22, "edgePot", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtDCInfo c_emlrtDCI = { 17, 28, "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 1 };
static emlrtBCInfo f_emlrtBCI = { 1, 2, 17, 28, "edgePot", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtBCInfo g_emlrtBCI = { -1, -1, 17, 34, "edgePot", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtBCInfo h_emlrtBCI = { -1, -1, 17, 22, "y", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtBCInfo i_emlrtBCI = { -1, -1, 17, 28, "y", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtBCInfo j_emlrtBCI = { -1, -1, 10, 24, "y", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * function [pot] = UGM_ConfigurationPotential(y,nodePot,edgePot,edgeEnds)
 */
real_T UGM_ConfigurationPotential(const real_T y_data[72], const int32_T y_sizes[2], const real_T nodePot_data[144], const int32_T nodePot_sizes[2], const real_T edgePot_data[10224], const int32_T edgePot_sizes[3], const int32_T edgeEnds_data[5112], const int32_T edgeEnds_sizes[2])
{
    real_T pot;
    int32_T n;
    /*  [pot] = UGM_ConfigurationPotential(y,nodePot,edgePot,edgeEnds) */
    /* 'UGM_ConfigurationPotential:3' nNodes = size(nodePot,1); */
    /* 'UGM_ConfigurationPotential:4' nEdges = size(edgeEnds,1); */
    /* 'UGM_ConfigurationPotential:6' pot = 1; */
    pot = 1.0;
    /*  Nodes */
    /* 'UGM_ConfigurationPotential:9' for n = 1:nNodes */
    n = 1;
    while (n <= nodePot_sizes[0]) {
        /* 'UGM_ConfigurationPotential:10' pot = pot*nodePot(n,y(n)); */
        emlrtDynamicBoundsCheckR2011a(n, 1, nodePot_sizes[0], &emlrtBCI, &emlrtContextGlobal);
        emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(y_data[emlrtDynamicBoundsCheckR2011a(n, 1, y_sizes[1], &j_emlrtBCI, &emlrtContextGlobal) - 1], &emlrtDCI, &emlrtContextGlobal), &b_emlrtBCI, &emlrtContextGlobal);
        pot *= nodePot_data[(n + nodePot_sizes[0] * ((int32_T)y_data[n - 1] - 1)) - 1];
        n++;
        emlrtBreakCheck();
    }
    /*  Edges */
    /* 'UGM_ConfigurationPotential:14' for e = 1:nEdges */
    n = 0;
    while (n + 1 <= edgeEnds_sizes[0]) {
        /* 'UGM_ConfigurationPotential:15' n1 = edgeEnds(e,1); */
        emlrtDynamicBoundsCheckR2011a(n + 1, 1, edgeEnds_sizes[0], &c_emlrtBCI, &emlrtContextGlobal);
        /* 'UGM_ConfigurationPotential:16' n2 = edgeEnds(e,2); */
        emlrtDynamicBoundsCheckR2011a(n + 1, 1, edgeEnds_sizes[0], &d_emlrtBCI, &emlrtContextGlobal);
        /* 'UGM_ConfigurationPotential:17' pot = pot*edgePot(y(n1),y(n2),e); */
        emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(y_data[emlrtDynamicBoundsCheckR2011a(edgeEnds_data[n], 1, y_sizes[1], &h_emlrtBCI, &emlrtContextGlobal) - 1], &b_emlrtDCI, &emlrtContextGlobal), &e_emlrtBCI, &emlrtContextGlobal);
        emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(y_data[emlrtDynamicBoundsCheckR2011a(edgeEnds_data[n + edgeEnds_sizes[0]], 1, y_sizes[1], &i_emlrtBCI, &emlrtContextGlobal) - 1], &c_emlrtDCI, &emlrtContextGlobal), &f_emlrtBCI, &emlrtContextGlobal);
        emlrtDynamicBoundsCheckR2011a(n + 1, 1, edgePot_sizes[2], &g_emlrtBCI, &emlrtContextGlobal);
        pot *= edgePot_data[(((int32_T)y_data[edgeEnds_data[n] - 1] + edgePot_sizes[0] * ((int32_T)y_data[edgeEnds_data[n + edgeEnds_sizes[0]] - 1] - 1)) + edgePot_sizes[0] * edgePot_sizes[1] * n) - 1];
        n++;
        emlrtBreakCheck();
    }
    return pot;
}
/* End of code generation (UGM_ConfigurationPotential.c) */
