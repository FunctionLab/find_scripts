/*
 * length.c
 *
 * Code generation for function 'length'
 *
 * C source code generated on: Sun Sep 09 23:00:54 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "matdiff.h"
#include "length.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
real_T length(const boolean_T x_data[215927], const int32_T x_sizes[2])
{
    real_T n;
    if (x_sizes[1] == 0) {
        n = 0.0;
    } else {
        n = (real_T)x_sizes[1];
    }
    return n;
}
/* End of code generation (length.c) */
