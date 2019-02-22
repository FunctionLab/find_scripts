/*
 * Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property and 
 * proprietary rights in and to this software and related documentation. 
 * Any use, reproduction, disclosure, or distribution of this software 
 * and related documentation without an express license agreement from
 * NVIDIA Corporation is strictly prohibited.
 * 
 */

#ifndef MERSENNETWISTER_H
#define MERSENNETWISTER_H
#ifndef mersennetwister_h
#define mersennetwister_h


//#define N	1048576		// number of samples to generate
#define N	134217728		// number of samples to generate

#define TRUE	1
#define FALSE	0


#define      DCMT_SEED 4172

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
//#define 			PI 3.14159265358979f


typedef struct{
  unsigned int matrix_a;
  unsigned int mask_b;
  unsigned int mask_c;
  unsigned int seed;
} mt_struct_stripped;


/* Workaround to avoid a PGI Accelerator restriction: URSHIFT (unsigned right
 * shift) operation is not supported, so uint32_t is set to be signed integer
 * instead of unsigned. This cuts results width to half, so it is required to
 * double the results of Mersenne Twister algorithm.
*/
typedef unsigned int uint32_t;
//typedef int uint32_t;
//#define UINT32_C(a) ((uint32_t)a)

typedef struct {
    uint32_t aaa;
    int mm,nn,rr,ww;
    uint32_t wmask,umask,lmask;
    int shift0, shift1, shiftB, shiftC;
    uint32_t maskB, maskC;
    int i;
    uint32_t *state;
} mt_struct;

typedef struct {
    uint32_t aaa;
    int mm,nn,rr,ww;
    uint32_t wmask,umask,lmask;
    int shift0, shift1, shiftB, shiftC;
    uint32_t maskB, maskC;
    int i;
//    uint32_t *state;
} mt_struct_pgi;


#endif
#endif
