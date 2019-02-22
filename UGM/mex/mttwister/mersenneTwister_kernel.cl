/*
 * MersenneTwister_kernel.cl
 *
 *  Created on: Mar 1, 2010
 *      Author: Federico Dal Castello
 */

/*
 * Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property and
 * proprietary rights in and to this software and related documentation.
 * Any use, reproduction, disclosure, or distribution of this software
 * and related documentation without an express license agreement from
 * NVIDIA Corporation is strictly prohibited.
 *
 * Please refer to the applicable NVIDIA end user license agreement (EULA)
 * associated with this source code for terms and conditions that govern
 * your use of this NVIDIA software.
 *
 */


#define      DCMT_SEED 4172


typedef struct{
  unsigned int matrix_a;
  unsigned int mask_b;
  unsigned int mask_c;
  unsigned int seed;
} mt_struct_stripped;


typedef unsigned int uint32_t;
//#define UINT32_C(a) ((uint32_t)a)

//typedef struct {
//    uint32_t aaa;
//    int mm,nn,rr,ww;
//    uint32_t wmask,umask,lmask;
//    int shift0, shift1, shiftB, shiftC;
//    uint32_t maskB, maskC;
//    int i;
//    uint32_t *state;
//} mt_struct;


#define   MT_RNG_COUNT 4096
#define          MT_MM 9
#define          MT_NN 19
#define       MT_WMASK 0xFFFFFFFFU
#define       MT_UMASK 0xFFFFFFFEU
#define       MT_LMASK 0x1U
#define      MT_SHIFT0 12
#define      MT_SHIFTB 7
#define      MT_SHIFTC 15
#define      MT_SHIFT1 18
#define 			PI 3.14159265358979f



////////////////////////////////////////////////////////////////////////////////
// OpenCL Kernel for Mersenne Twister RNG
////////////////////////////////////////////////////////////////////////////////
__kernel void mersenneTwister_kernel_cl(
					__global float* results,
			        __global mt_struct_stripped* parameters,
			        int nPerRng)
{
    int globalID = get_global_id(0);

    int iState, iState1, iStateM, iOut;
    unsigned int mti, mti1, mtiM, x;
    unsigned int /*mt[MT_NN],*/ matrix_a, mask_b, mask_c;

    unsigned int mt[MT_NN];

    //Load bit-vector Mersenne Twister parameters
    matrix_a = parameters[globalID].matrix_a;
    mask_b   = parameters[globalID].mask_b;
    mask_c   = parameters[globalID].mask_c;

    //Initialize current state
    mt[0] = parameters[globalID].seed;
    for (iState = 1; iState < MT_NN; iState++)
        mt[iState] = (1812433253U * (mt[iState - 1] ^ (mt[iState - 1] >> 30)) + iState) & MT_WMASK;

    iState = 0;
    mti1 = mt[0];

    iOut = 0;
    for (iOut = 0; iOut < nPerRng; iOut++) {
        iState1 = iState + 1;
        iStateM = iState + MT_MM;
        if(iState1 >= MT_NN) iState1 -= MT_NN;
        if(iStateM >= MT_NN) iStateM -= MT_NN;
        mti  = mti1;
        mti1 = mt[iState1];
        mtiM = mt[iStateM];

	    // MT recurrence
        x = (mti & MT_UMASK) | (mti1 & MT_LMASK);
	    x = mtiM ^ (x >> 1) ^ ((x & 1) ? matrix_a : 0);

        mt[iState] = x;
        iState = iState1;

        // Tempering transformation
        x ^= (x >> MT_SHIFT0);
        x ^= (x << MT_SHIFTB) & mask_b;
        x ^= (x << MT_SHIFTC) & mask_c;
        x ^= (x >> MT_SHIFT1);

        /* For a k-bit word length, the Mersenne Twister generates numbers with
           a uniform distribution in the range [0, 2^k − 1]. Here, k = 32bit */
        // Convert to (0, 1] float and write to global memory
        results[globalID + iOut * MT_RNG_COUNT] = ((float)x + 1.0f) / 4294967296.0f;
    }
}


