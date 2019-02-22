/*
 * mersenneTwisterCUDA.c
 *
 *  Created on: May 5, 2010
 *      Author: Federico Dal Castello
 */

#include <stdio.h>
#include <cuda/cuda.h>

#include "mersenneTwisterCUDA.h"

#include "mersenneTwister_kernel.cu"
#include "mtUtils.c"
#include "timer.c"


mt_struct MT[MT_RNG_COUNT];
//static uint32_t state[MT_NN];

double exec_time_cuda, exec_time_kernel, exec_time_copyin, exec_time_copyout, exec_time_fileio, exec_time_cudamalloc;

void initMTRef_cuda(const char *fname) {

	FILE* fd = 0;

	// open the file for binary read
	if ((fd = fopen(fname, "rb")) == 0)	{
		if(fd) {
			fclose (fd);
		}
//		shrCheckError(0, 1);
	}

    for (int i = 0; i < MT_RNG_COUNT; i++) {
        //Inline structure size for compatibility,
        //since pointer types are 8-byte on 64-bit systems (unused *state variable)
        if( !fread(MT + i, 16 /* sizeof(mt_struct) */ * sizeof(int), 1, fd) ) {
//	        shrCheckError(0, 1);
        }
    }

    fclose(fd);
}


// Load twister configurations
void loadMTGPU_cuda(const char *fname){
    FILE *fd = fopen(fname, "rb");
    if(!fd){
        printf("initMTGPU(): failed to open %s\n", fname);
        printf("TEST FAILED\n");
        exit(0);
    }
    if( !fread(h_MT, sizeof(h_MT), 1, fd) ){
        printf("initMTGPU(): failed to load %s\n", fname);
        printf("TEST FAILED\n");
        exit(0);
    }
    fclose(fd);
}

// Initialize/seed twister for current GPU context
void seedMTGPU_cuda(unsigned int seed){
    int i;
    // Need to be thread-safe
    mt_struct_stripped *MT = (mt_struct_stripped *)malloc(MT_RNG_COUNT * sizeof(mt_struct_stripped));

    for(i = 0; i < MT_RNG_COUNT; i++){
        MT[i]      = h_MT[i];
        MT[i].seed = seed;
    }
    cudaMemcpyToSymbol(ds_MT, MT, sizeof(h_MT));

    free(MT);
}


void initSamples_MT_CUDA(float *samples)
{
    float *d_Rand;	// device memory

    int r;

    unsigned int seed;
    unsigned int nPerRng = N/MT_RNG_COUNT;	// # of recurrence steps
    unsigned int num_results = MT_RNG_COUNT * nPerRng;	// Output size

	/* memory allocation on device */
	timer(1);
	cudaMalloc((void **)&d_Rand, N * sizeof(float));
	exec_time_cudamalloc = timer(1);

    /* create and populate MT parameters array with initial pre-computed states*/
    srandom((unsigned int) (time(NULL)));
    double num = (random() / (float) RAND_MAX) * 4194304;
    seed = (unsigned int) trunc(num);
	timer(1);
	initMTRef_cuda("data/MersenneTwister.raw");
	loadMTGPU_cuda("data/MersenneTwister.dat");
	exec_time_fileio = timer(1);
	timer(1);
	seedMTGPU_cuda(seed);
        r = cudaThreadSynchronize();
	exec_time_copyin = timer(1);

	/* GPU random numbers generation */
	timer(1);
	mersenneTwister_kernel_cuda<<<128, 32>>>(d_Rand, nPerRng);
        r = cudaThreadSynchronize();
	exec_time_kernel = timer(1);

	/* read back the results */
	timer(1);
	cudaMemcpy(samples, d_Rand, num_results * sizeof(float), cudaMemcpyDeviceToHost);
        r = cudaThreadSynchronize();
	exec_time_copyout = timer(1);

	/* show some results */
//	for(int j=num_results-20; j < num_results; j++) {
//	for(int j=0; j < 30; j++) {
//		printf("result #%d: %f\n", j, samples[j]);
//	}

}


int main()
{
	float *samples;		// array of random samples
	float *dummy;		// dummy array - cudamalloc it to init device

	if(checkInputData()) {
		exit(EXIT_FAILURE);
	}

	samples  = (float *) malloc(sizeof(float) * N);
        for (int i = 0; i < N; i++) samples[i] = 0.0;

	/* Dummy cudamalloc to initialize device */
	cudaMalloc((void **)&dummy, 32 * sizeof(float));

	printf("Computing over %d samples\n", N);


	/* Mersenne Twister on GPU with CUDA */
	printf("\n --- Mersenne Twister on GPU with CUDA ---\n");
	timer(0);
	initSamples_MT_CUDA(samples);
	double exec_time_cuda = timer(0);
	printf("cudamalloc time  = %f s\n", exec_time_cudamalloc);
	printf("file i/o time  = %f s\n", exec_time_fileio);
	printf("copyin time  = %f s\n", exec_time_copyin);
	printf("kernel exec time  = %f s\n", exec_time_kernel);
	printf("copyout time  = %f s\n", exec_time_copyout);
	printf("total exec time  = %f s\n", exec_time_cuda);
	printf("throughput = %f [MB/s]\n", computeThroughput(exec_time_cuda));

//	printMaxMin(samples);


	/* free up memory */
	free(samples);


	return EXIT_SUCCESS;
}

