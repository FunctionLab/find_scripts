/*
 * genomeWalkerFunc.h
 *
 * Code generation for function 'genomeWalkerFunc'
 *
 * C source code generated on: Mon Sep 10 17:00:55 2012
 *
 */

#ifndef __GENOMEWALKERFUNC_H__
#define __GENOMEWALKERFUNC_H__
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
extern void genomeWalkerFunc(const emxArray_boolean_T *chrom_data, const emxArray_real_T *nodePot, const emxArray_real_T *edgePot, const emxArray_int32_T *edgeEnds, real_T nNodes, real_T maxRounds, emxArray_real_T *Chrom_maxima, emxArray_real_T *Maximas, real_T Mcount[20000], real_T Mpot[20000], real_T *nMaxima);
#endif
/* End of code generation (genomeWalkerFunc.h) */
