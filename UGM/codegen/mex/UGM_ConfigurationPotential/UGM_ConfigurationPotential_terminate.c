/*
 * UGM_ConfigurationPotential_terminate.c
 *
 * Code generation for function 'UGM_ConfigurationPotential_terminate'
 *
 * C source code generated on: Mon Sep 10 15:47:03 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "UGM_ConfigurationPotential.h"
#include "UGM_ConfigurationPotential_terminate.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void UGM_ConfigurationPotential_atexit(void)
{
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void UGM_ConfigurationPotential_terminate(void)
{
    emlrtLeaveRtStack(&emlrtContextGlobal);
}
/* End of code generation (UGM_ConfigurationPotential_terminate.c) */
