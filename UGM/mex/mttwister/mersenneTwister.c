/*
 * MonteCarloIntegration.c
 *
 *  Created on: Dec 14, 2009
 *      Author: Federico Dal Castello
 */
#include <stdio.h>
#include <stdlib.h>

#include "mersenneTwister.h"
#include "mersenneTwisterCL.h"
#include "mersenneTwisterCPU.h"
#include "mtUtils.h"
#include "timer.h"

#ifdef _ACCEL
#include "accel.h"
#endif

double exec_time_cpu, exec_time_omp, exec_time_acc_1, exec_time_acc_2, exec_time_opencl;
double exec_time_dyn_compile, exec_time_opencl_malloc, exec_time_copyin,
       exec_time_kernel, exec_time_copyout, exec_time_opencl, exec_time_fileio,
       exec_time_opencl_startup, exec_time_opencl_cleanup, opencl_ohead_time;

int main()
{
    float *samples;		// array of random samples

    if(checkInputData()) {
        exit(EXIT_FAILURE);
    }

    samples = (float *) malloc(sizeof(float) * N);  // Allocate memory for samples
    for (int i = 0; i < N; i++) samples[i] = 0.0;

    printf("Computing over %d samples\n", N);

/* Mersenne Twister on CPU */

    printf("\n --- CPU Mersenne Twister ---\n");
    timer(0);
    initSamples_MT_CPU(samples, 0);
    exec_time_cpu = timer(0);
    printf("exec time = %f s\n", exec_time_cpu);
    printf("throughput = %f [MB/s]\n", computeThroughput(exec_time_cpu));

    printMaxMin(samples);
    cleanSamples(samples);

/* Mersenne Twister on CPU with OpenMP */

    for(int i = 1; i <= 4; i++) {
        printf("\n --- CPU Mersenne Twister with OpenMP (%d threads) ---\n", i);
        timer(0);
        initSamples_MT_CPU(samples, i);
        exec_time_omp = timer(0);
        printf("exec time = %f s\n", exec_time_omp);
        printf("throughput = %f [MB/s]\n", computeThroughput(exec_time_omp));

        printMaxMin(samples);
        cleanSamples(samples);
    }

#ifdef _ACCEL
    acc_init(acc_device_nvidia);  /* initialize the device */
#endif

/* GPU Mersenne Twister with PGI Accelerator directives - main loop derived from */
/* original serial CPU version of Mersenne Twister algorithm */

    printf("\n --- Mersenne Twister on GPU with PGI Accelerator directives ---\n");
    printf(" --- Main loop based on original serial CPU Mersenne Twister ---\n");
    timer(0);
    initSamples_MT_ACC_1(samples);
    exec_time_acc_1 = timer(0);
    printf("exec time = %f s\n", exec_time_acc_1);
    printf("throughput = %f [MB/s]\n", computeThroughput(exec_time_acc_1));

    printMaxMin(samples);
    cleanSamples(samples);

/* GPU Mersenne Twister with PGI Accelerator directives - main loop derived from */
/* CUDA and OpenCL Mersenne Twister kernels */

    printf("\n --- Mersenne Twister on GPU with PGI Accelerator directives ---\n");
    printf(" --- Main loop based on CUDA/OpenCL Mersenne Twister kernels ---\n");
    timer(0);
    initSamples_MT_ACC_2(samples);
    exec_time_acc_2 = timer(0);
    printf("exec time = %f s\n", exec_time_acc_2);
    printf("throughput = %f [MB/s]\n", computeThroughput(exec_time_acc_2));

    printMaxMin(samples);
    cleanSamples(samples);

/* Mersenne Twister on GPU with OpenCL */

    printf("\n --- Mersenne Twister on GPU with OpenCL ---\n");
    timer(0);
    initSamples_MT_CL(samples);
    exec_time_opencl = timer(0);
    printf("OpenCL platform query time  = %f s\n", exec_time_opencl_startup);
    printf("OpenCL dynamic compile time  = %f s\n", exec_time_dyn_compile);
    printf("OpenCL malloc time  = %f s\n", exec_time_opencl_malloc);
    printf("file i/o time  = %f s\n", exec_time_fileio);
    printf("copyin time  = %f s\n", exec_time_copyin);
    printf("kernel exec time  = %f s\n", exec_time_kernel);
    printf("copyout time  = %f s\n", exec_time_copyout);
    printf("OpenCL cleanup time  = %f s\n", exec_time_opencl_cleanup);
    opencl_ohead_time = (exec_time_opencl_startup + exec_time_dyn_compile + exec_time_opencl_cleanup);
    exec_time_opencl = exec_time_opencl - opencl_ohead_time;
    printf("total exec time  = %f s (not including OpenCL overhead)\n", exec_time_opencl);
    printf("OpenCL overhead time  = %f s\n", opencl_ohead_time);
    printf("throughput = %f [MB/s]\n", computeThroughput(exec_time_opencl));

    printMaxMin(samples);

    free(samples);  // Free up samples memory

    return EXIT_SUCCESS;
}
