/*
 * UGM_ConfigurationPotential.h
 *
 * Code generation for function 'UGM_ConfigurationPotential'
 *
 * C source code generated on: Mon Sep 10 15:47:03 2012
 *
 */

#ifndef __UGM_CONFIGURATIONPOTENTIAL_H__
#define __UGM_CONFIGURATIONPOTENTIAL_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blascompat32.h"
#include "rtwtypes.h"
#include "UGM_ConfigurationPotential_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern real_T UGM_ConfigurationPotential(const real_T y_data[72], const int32_T y_sizes[2], const real_T nodePot_data[144], const int32_T nodePot_sizes[2], const real_T edgePot_data[10224], const int32_T edgePot_sizes[3], const int32_T edgeEnds_data[5112], const int32_T edgeEnds_sizes[2]);
#ifdef __WATCOMC__
#pragma aux UGM_ConfigurationPotential value [8087];
#endif
#endif
/* End of code generation (UGM_ConfigurationPotential.h) */
