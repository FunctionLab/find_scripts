/*
 * UGM_ConfigurationPotential.c
 *
 * Code generation for function 'UGM_ConfigurationPotential'
 *
 * C source code generated on: Mon Sep 10 17:00:55 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "genomeWalkerFunc.h"
#include "UGM_ConfigurationPotential.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtBCInfo t_emlrtBCI = { -1, -1, 10, 22, "nodePot", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtDCInfo e_emlrtDCI = { 10, 24, "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 1 };
static emlrtBCInfo u_emlrtBCI = { 1, 2, 10, 24, "nodePot", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtBCInfo v_emlrtBCI = { -1, -1, 15, 18, "edgeEnds", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtBCInfo w_emlrtBCI = { -1, -1, 16, 18, "edgeEnds", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtDCInfo f_emlrtDCI = { 17, 22, "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 1 };
static emlrtBCInfo x_emlrtBCI = { 1, 2, 17, 22, "edgePot", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtDCInfo g_emlrtDCI = { 17, 28, "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 1 };
static emlrtBCInfo y_emlrtBCI = { 1, 2, 17, 28, "edgePot", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtBCInfo ab_emlrtBCI = { -1, -1, 17, 34, "edgePot", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtBCInfo bb_emlrtBCI = { -1, -1, 17, 22, "y", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtBCInfo cb_emlrtBCI = { -1, -1, 17, 28, "y", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };
static emlrtBCInfo db_emlrtBCI = { -1, -1, 10, 24, "y", "UGM_ConfigurationPotential", "E:/Code/Matlab Kits/UGM/sub/UGM_ConfigurationPotential.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * function [pot] = UGM_ConfigurationPotential(y,nodePot,edgePot,edgeEnds)
 */
real_T UGM_ConfigurationPotential(const emxArray_real_T *y, const emxArray_real_T *nodePot, const emxArray_real_T *edgePot, const emxArray_int32_T *edgeEnds)
{
    real_T pot;
    int32_T nNodes;
    int32_T nEdges;
    uint32_T n;
    /*  [pot] = UGM_ConfigurationPotential(y,nodePot,edgePot,edgeEnds) */
    /* 'UGM_ConfigurationPotential:3' nNodes = size(nodePot,1); */
    nNodes = nodePot->size[0];
    /* 'UGM_ConfigurationPotential:4' nEdges = size(edgeEnds,1); */
    nEdges = edgeEnds->size[0];
    /* 'UGM_ConfigurationPotential:6' pot = 1; */
    pot = 1.0;
    /*  Nodes */
    /* 'UGM_ConfigurationPotential:9' for n = 1:nNodes */
    n = 1U;
    while (n <= (uint32_T)nNodes) {
        /* 'UGM_ConfigurationPotential:10' pot = pot*nodePot(n,y(n)); */
        emlrtDynamicBoundsCheckR2011a((int32_T)n, 1, nodePot->size[0], &t_emlrtBCI, &emlrtContextGlobal);
        emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(y->data[emlrtDynamicBoundsCheckR2011a((int32_T)n, 1, y->size[1], &db_emlrtBCI, &emlrtContextGlobal) - 1], &e_emlrtDCI, &emlrtContextGlobal), &u_emlrtBCI, &emlrtContextGlobal);
        pot *= nodePot->data[((int32_T)n + nodePot->size[0] * ((int32_T)y->data[(int32_T)n - 1] - 1)) - 1];
        n++;
        emlrtBreakCheck();
    }
    /*  Edges */
    /* 'UGM_ConfigurationPotential:14' for e = 1:nEdges */
    n = 1U;
    while (n <= (uint32_T)nEdges) {
        /* 'UGM_ConfigurationPotential:15' n1 = edgeEnds(e,1); */
        emlrtDynamicBoundsCheckR2011a((int32_T)n, 1, edgeEnds->size[0], &v_emlrtBCI, &emlrtContextGlobal);
        /* 'UGM_ConfigurationPotential:16' n2 = edgeEnds(e,2); */
        emlrtDynamicBoundsCheckR2011a((int32_T)n, 1, edgeEnds->size[0], &w_emlrtBCI, &emlrtContextGlobal);
        /* 'UGM_ConfigurationPotential:17' pot = pot*edgePot(y(n1),y(n2),e); */
        emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(y->data[emlrtDynamicBoundsCheckR2011a(edgeEnds->data[(int32_T)n - 1], 1, y->size[1], &bb_emlrtBCI, &emlrtContextGlobal) - 1], &f_emlrtDCI, &emlrtContextGlobal), &x_emlrtBCI, &emlrtContextGlobal);
        emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(y->data[emlrtDynamicBoundsCheckR2011a(edgeEnds->data[((int32_T)n + edgeEnds->size[0]) - 1], 1, y->size[1], &cb_emlrtBCI, &emlrtContextGlobal) - 1], &g_emlrtDCI, &emlrtContextGlobal), &y_emlrtBCI, &emlrtContextGlobal);
        emlrtDynamicBoundsCheckR2011a((int32_T)n, 1, edgePot->size[2], &ab_emlrtBCI, &emlrtContextGlobal);
        pot *= edgePot->data[(((int32_T)y->data[edgeEnds->data[(int32_T)n - 1] - 1] + edgePot->size[0] * ((int32_T)y->data[edgeEnds->data[((int32_T)n + edgeEnds->size[0]) - 1] - 1] - 1)) + edgePot->size[0] * edgePot->size[1] * ((int32_T)n - 1)) - 1];
        n++;
        emlrtBreakCheck();
    }
    return pot;
}
/* End of code generation (UGM_ConfigurationPotential.c) */
