/*
 * genomeWalkerFunc_terminate.c
 *
 * Code generation for function 'genomeWalkerFunc_terminate'
 *
 * C source code generated on: Mon Sep 10 17:00:55 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "genomeWalkerFunc.h"
#include "genomeWalkerFunc_terminate.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void genomeWalkerFunc_atexit(void)
{
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void genomeWalkerFunc_terminate(void)
{
    emlrtLeaveRtStack(&emlrtContextGlobal);
}
/* End of code generation (genomeWalkerFunc_terminate.c) */
