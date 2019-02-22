/*
 * MersenneTwisterCPU.c
 *
 *  Created on: Apr 13, 2010
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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

#include "mersenneTwisterCPU.h"
#include "dci.h"

static mt_struct 	 MT[MT_RNG_COUNT];
// variables for PGI Accelerator MT version
static mt_struct_pgi MTpgi[MT_RNG_COUNT];
#ifdef NOUINT
static int  	 MTpgi_state[MT_NN][MT_RNG_COUNT]; // explicit MT state array to cope with Accelerator restriction (no arrays in structures)
#else
static uint32_t  	 MTpgi_state[MT_NN][MT_RNG_COUNT]; // explicit MT state array to cope with Accelerator restriction (no arrays in structures)
#endif

static uint32_t state[32][MT_NN*16];

void initMTRefCPU(const char *fname, int init_pgi_structures)
/* Initialize MT structures from file specified in 'fname'. If 'init_pgi_structures'
 * is TRUE, also initializes MT structures for PGI Accelerator directives. */
{
    FILE* fd = 0;
#ifdef _WIN32
    // open the file for binary read
    errno_t err;
    if ((err = fopen_s(&fd, fname, "rb")) != 0)
#else
    // open the file for binary read
    if ((fd = fopen(fname, "rb")) == 0)
#endif
    {
        if(fd)
            fclose (fd);
    }

    for (int i = 0; i < MT_RNG_COUNT; i++) {
        //Inline structure size for compatibility,
        //since pointer types are 8-byte on 64-bit systems (unused *state variable)
        if( !fread(MT + i, 16 /* sizeof(mt_struct) */ * sizeof(int), 1, fd) ) {
//	        oclCheckError(0, 1);
        }
    }

    if(init_pgi_structures) {
        for (int i = 0; i < MT_RNG_COUNT; i++) {
            MTpgi[i].aaa = MT[i].aaa;
            MTpgi[i].mm = MT[i].mm;
            MTpgi[i].nn = MT[i].nn;
            MTpgi[i].rr = MT[i].rr;
            MTpgi[i].ww = MT[i].ww;
            MTpgi[i].wmask = MT[i].wmask;
            MTpgi[i].umask = MT[i].umask;
            MTpgi[i].lmask = MT[i].lmask;
            MTpgi[i].shift0 = MT[i].shift0;
            MTpgi[i].shift1 = MT[i].shift1;
            MTpgi[i].shiftB = MT[i].shiftB;
            MTpgi[i].shiftC = MT[i].shiftC;
            MTpgi[i].maskB = MT[i].maskB;
            MTpgi[i].maskC = MT[i].maskC;
            MTpgi[i].i = MT[i].i;
        }
    }

    fclose(fd);
}

void RandomRef(float *h_Rand, int NPerRng, unsigned int seed)
{
    int iRng, iOut;

    for(iRng = 0; iRng < MT_RNG_COUNT; iRng++){
        MT[iRng].state = state;
        sgenrand_mt(seed, &MT[iRng]);
        for(iOut = 0; iOut < NPerRng; iOut++)
            h_Rand[iRng * NPerRng + iOut] = (((float)genrand_mt(&MT[iRng]) + 1.0f) / 4294967296.0f);
    }
}


void RandomRef_OMP(float *h_Rand, int NPerRng, unsigned int seed)
{
    int iRng, iOut;

#pragma omp parallel for private(iRng, iOut)
    for(iRng = 0; iRng < MT_RNG_COUNT; iRng++) {
        MT[iRng].state = &state[omp_get_thread_num()][0];
        sgenrand_mt(seed, &MT[iRng]);
        for(iOut = 0; iOut < NPerRng; iOut++)
            h_Rand[iRng * NPerRng + iOut] = (((float)genrand_mt(&MT[iRng]) + 1.0f) / 4294967296.0f);
    }
}

void RandomRef_ACC_1(float *h_Rand, int NPerRng, unsigned int seed)
{
    int iRng, iOut;

#pragma acc region copyin(MTpgi[0:MT_RNG_COUNT-1]) \
                   copyout(h_Rand[0:N-1]) \
                   local(MTpgi_state[0:MT_NN-1][0:MT_RNG_COUNT-1])
{
#pragma acc for parallel(128) vector(32)
    for(iRng = 0; iRng < MT_RNG_COUNT; iRng++) {

// Inline version of sgenrand_mt

       MTpgi_state[0][iRng] = seed & MTpgi[iRng].wmask;

       for(int i = 1; i < MTpgi[iRng].nn; i++) {
            MTpgi_state[i][iRng] = (UINT32_C(1812433253) * (MTpgi_state[i-1][iRng] ^ (MTpgi_state[i-1][iRng] >> 30)) + i) & MTpgi[iRng].wmask;
       }
       MTpgi[iRng].i = MTpgi[iRng].nn;

       for(iOut = 0; iOut < NPerRng; iOut++) {

// Inline version of function genrand_mt

#ifdef NOUINT
          int uuu, lll, aa, x;
#else
          uint32_t uuu, lll, aa, x;
#endif
          int k,n,m,lim;

          if (MTpgi[iRng].i >= MTpgi[iRng].nn) {
               n = MTpgi[iRng].nn;
               m = MTpgi[iRng].mm;
               aa = MTpgi[iRng].aaa;
               uuu = MTpgi[iRng].umask;
               lll = MTpgi[iRng].lmask;

               for (k = 0; k < n - m; k++) {
                   x = (MTpgi_state[k][iRng] & uuu) | (MTpgi_state[k + 1][iRng] & lll);
                   MTpgi_state[k][iRng] = MTpgi_state[k + m][iRng] ^ (x >> 1) ^ (x & 1U ? aa : 0U);
               }
               for (k = n - m; k < n-1; k++) {
                   x = (MTpgi_state[k][iRng] & uuu) | (MTpgi_state[k + 1][iRng] & lll);
                   MTpgi_state[k][iRng] = MTpgi_state[k + m - n][iRng] ^ (x >> 1) ^ (x & 1U ? aa : 0U);
               }
               x = (MTpgi_state[n - 1][iRng] & uuu)|(MTpgi_state[0][iRng] & lll);
               MTpgi_state[n - 1][iRng] = MTpgi_state[m - 1][iRng] ^ (x >> 1) ^ (x & 1U ? aa : 0U);
               MTpgi[iRng].i = 0;
           }

           x = MTpgi_state[MTpgi[iRng].i][iRng];
           MTpgi[iRng].i += 1;
           x ^= x >> MTpgi[iRng].shift0;
           x ^= (x << MTpgi[iRng].shiftB) & MTpgi[iRng].maskB;
           x ^= (x << MTpgi[iRng].shiftC) & MTpgi[iRng].maskC;
           x ^= x >> MTpgi[iRng].shift1;
#ifdef NOUINT
           h_Rand[iRng * NPerRng + iOut] = ((x + 1.0f) / 4294967296.0f) * 2.0f;
#else
           h_Rand[iRng * NPerRng + iOut] = ((x + 1.0f) / 4294967296.0f);
#endif
        }
    }
}
}

void RandomRef_ACC_2(float *h_Rand, unsigned int NPerRng, unsigned int seed)
{
    int iRng, iOut;
    unsigned int mt[MT_NN][MT_RNG_COUNT];

#pragma acc region copyin(MTpgi[0:MT_RNG_COUNT-1]) \
                   copyout(h_Rand[0:N-1]) \
                   local(mt[0:MT_NN-1][MT_RNG_COUNT])
{
#pragma acc for parallel(128) vector(32)
    for(iRng = 0; iRng < MT_RNG_COUNT; iRng++) {
        int iState, iState1, iStateM;
        unsigned int mti, mti1, mtiM, x;
        unsigned int matrix_a, mask_b, mask_c;

        matrix_a = MTpgi[iRng].aaa;
        mask_b   = MTpgi[iRng].maskB;
        mask_c   = MTpgi[iRng].maskC;

        mt[0][iRng] = seed & MTpgi[iRng].wmask;

        for (iState = 1; iState < MT_NN; iState++) {
            mt[iState][iRng] = ( 1812433253U * 
                            (mt[iState - 1][iRng] ^ 
                            (mt[iState - 1][iRng] >> 30) ) + iState) & MT_WMASK;
        }

        iState = 0;
        mti1 = mt[0][iRng];
        mti  = mti1;

        for (iOut = 0; iOut < NPerRng; iOut++) {
            iState1 = iState + 1;
            iStateM = iState + MT_MM;
            if(iState1 >= MT_NN) iState1 -= MT_NN;
            if(iStateM >= MT_NN) iStateM -= MT_NN;
            mti1  = mt[iState1][iRng];
            mtiM  = mt[iStateM][iRng];

            x = (mti & MT_UMASK) | (mti1 & MT_LMASK);
            x = mtiM ^ (x >> 1) ^ ((x & 1) ? matrix_a : 0);

            mt[iState][iRng] = x;
            iState = iState1;

            x ^= (x >> MT_SHIFT0);
            x ^= (x << MT_SHIFTB) & mask_b;
            x ^= (x << MT_SHIFTC) & mask_c;
            x ^= (x >> MT_SHIFT1);

            h_Rand[iRng + iOut * MT_RNG_COUNT] = (((float)x + 1.0f) / 4294967296.0f);

            mti  = mti1;
        }
    }
}
}

void initSamples_MT_CPU(float *samples, const int num_openmp_threads)
/* initialize samples on CPU with random values by using Mersenne Twister OpenMP
 * implementation with a number of threads defined by "num_openmp_threads".
 * If 0, a non-OpenMP version is used. */
{
    unsigned int seed;
    int nPerRng = N/MT_RNG_COUNT;	// # of recurrence steps

    /* create and populate MT parameters array with initial pre-computed states*/
    initMTRefCPU("data/MersenneTwister.raw", FALSE);

    /* initialize the random number generator for the seed */
    srandom((unsigned int) (time(NULL)));
    double num = (random() / (float) RAND_MAX) * 4194304;
    seed = (unsigned int) trunc(num);

    /* populate samples */
    if(num_openmp_threads != 0) {
        omp_set_num_threads(num_openmp_threads);
        RandomRef_OMP(samples, nPerRng, seed);
    } else {
        RandomRef(samples, nPerRng, seed);
    }
}

void initSamples_MT_ACC_1(float *samples)
/* initialize samples on CPU with random values by using Mersenne Twister PGI Accelerator directives. */
{
    unsigned int seed;
    int nPerRng = N/MT_RNG_COUNT;	// # of recurrence steps

    /* create and populate MT parameters array with initial pre-computed states*/
    initMTRefCPU("data/MersenneTwister.raw", TRUE);

    /* initialize the random number generator for the seed */
    srandom((unsigned int) (time(NULL)));
    double num = (random() / (float) RAND_MAX) * 4194304;
    seed = (unsigned int) trunc(num);

    /* populate samples */
    RandomRef_ACC_1(samples, nPerRng, seed);
}

void initSamples_MT_ACC_2(float *samples)
/* initialize samples on CPU with random values by using Mersenne Twister PGI Accelerator directives. */
{
    unsigned int seed;
    int nPerRng = N/MT_RNG_COUNT;	// # of recurrence steps

    /* create and populate MT parameters array with initial pre-computed states*/
    initMTRefCPU("data/MersenneTwister.raw", TRUE);

    /* initialize the random number generator for the seed */
    srandom((unsigned int) (time(NULL)));
    double num = (random() / (float) RAND_MAX) * 4194304;
    seed = (unsigned int) trunc(num);

    /* populate samples */
    RandomRef_ACC_2(samples, nPerRng, seed);
}
