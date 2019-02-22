/*
 * matdiff_terminate.c
 *
 * Code generation for function 'matdiff_terminate'
 *
 * C source code generated on: Sun Sep 09 23:00:54 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "matdiff.h"
#include "matdiff_terminate.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void matdiff_atexit(void)
{
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void matdiff_terminate(void)
{
    emlrtLeaveRtStack(&emlrtContextGlobal);
}
/* End of code generation (matdiff_terminate.c) */
