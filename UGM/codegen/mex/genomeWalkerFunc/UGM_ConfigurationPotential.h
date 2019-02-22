/*
 * UGM_ConfigurationPotential.h
 *
 * Code generation for function 'UGM_ConfigurationPotential'
 *
 * C source code generated on: Mon Sep 10 17:00:55 2012
 *
 */

#ifndef __UGM_CONFIGURATIONPOTENTIAL_H__
#define __UGM_CONFIGURATIONPOTENTIAL_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blascompat32.h"
#include "rtwtypes.h"
#include "genomeWalkerFunc_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern real_T UGM_ConfigurationPotential(const emxArray_real_T *y, const emxArray_real_T *nodePot, const emxArray_real_T *edgePot, const emxArray_int32_T *edgeEnds);
#ifdef __WATCOMC__
#pragma aux UGM_ConfigurationPotential value [8087];
#endif
#endif
/* End of code generation (UGM_ConfigurationPotential.h) */
