/*
 * matdiff_types.h
 *
 * Code generation for function 'matdiff'
 *
 * C source code generated on: Sun Sep 09 23:00:54 2012
 *
 */

#ifndef __MATDIFF_TYPES_H__
#define __MATDIFF_TYPES_H__

/* Type Definitions */
typedef struct
{
    struct
    {
        int32_T tmp_data[215927];
        int32_T b_tmp_data[215927];
    } f0;
    struct
    {
        boolean_T all_data[15978598];
        real_T temp_data[215927];
        boolean_T b_all_data[215927];
        int8_T isTest_data[215927];
    } f1;
    struct
    {
        boolean_T all_data[15978598];
        boolean_T train_data[7989336];
        real_T TestInd_data[215927];
    } f2;
} matdiffStackData;

#endif
/* End of code generation (matdiff_types.h) */
