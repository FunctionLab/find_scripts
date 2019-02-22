/*
 * MersenneTwisterCL.c
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

///////////////////////////////////////////////////////////////////////////////
// This sample implements Mersenne Twister random number generator
// and Cartesian Box-Muller transformation on the GPU
///////////////////////////////////////////////////////////////////////////////

// standard utilities and systems includes
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "mersenneTwisterCL.h"
#include "timer.h"
#include "oclUtils.h"
#include "oclErrorUtils.h"


mt_struct MT[MT_RNG_COUNT];
//static uint32_t state[MT_NN];

double exec_time_dyn_compile, exec_time_opencl_malloc, exec_time_copyin,
       exec_time_kernel, exec_time_copyout, exec_time_opencl, exec_time_fileio,
       exec_time_opencl_startup, exec_time_opencl_cleanup;

void initMTRef(const char *fname) {

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
		if(fd) {
			fclose (fd);
		}
	}

    for (int i = 0; i < MT_RNG_COUNT; i++) {
        //Inline structure size for compatibility,
        //since pointer types are 8-byte on 64-bit systems (unused *state variable)
        if( !fread(MT + i, 16 /* sizeof(mt_struct) */ * sizeof(int), 1, fd) ) {
        }
    }

    fclose(fd);
}


///////////////////////////////////////////////////////////////////////////////
//Load twister configurations
///////////////////////////////////////////////////////////////////////////////
void loadMTGPU_cl(const char *filename,
		const unsigned int seed,
		mt_struct_stripped *mt_parameters,
		const size_t size)
{
	FILE* fd = 0;
#ifdef _WIN32
	// open the file for binary read
	errno_t err;
	if ((err = fopen_s(&fd, filename, "rb")) != 0)
#else
		// open the file for binary read
		if ((fd = fopen(filename, "rb")) == 0)
#endif
		{
			if(fd) {
				fclose (fd);
			}
		}

	for (unsigned int i = 0; i < size; i++) {
		fread(&mt_parameters[i], sizeof(mt_struct_stripped), 1, fd);
		mt_parameters[i].seed = seed;
	}

	fclose(fd);

//    for(unsigned int i = 0; i < size; i++)
//        h_MT[i].seed = seed;
}



void initSamples_MT_CL(float *samples)
/* initialize the 1-dimensional integration domain samples on GPU with random
 * values by using Mersenne Twister OpenCL implementation. */
{
	/* OpenCL variables */
    cl_context context;			// OpenCL context
    cl_command_queue cmd_queue;	// OpenCL command queue
    cl_device_id device;		// OpenCL device
    cl_platform_id platform;	// OpenCL platform
    cl_program program;			// OpenCL program
    cl_int err;					// Error code var
    cl_kernel mersennetwister_kernel = NULL;	// OpenCL kernel
    cl_mem gpu_results_mem, mt_parameters_mem;	// OpenCL memory buffers
	cl_event kernel_exec_time = NULL;
	cl_event event_mem_read = NULL;
	cl_event event_mem_write = NULL;
    size_t global_work_size[1] = {MT_RNG_COUNT};	// 1D var for Total # of work items
    size_t local_work_size[1] = {128};				// 1D var for # of work items in the work group
	/* end of OpenCL variables */

    double mem_read_time = 0, mem_write_time = 0;

    unsigned int seed;
    unsigned int nPerRng = N/MT_RNG_COUNT;			// # of recurrence steps
    unsigned int num_results = MT_RNG_COUNT * nPerRng;	// Output size


    timer(1);
	/* get the device ID */
	err = clGetPlatformIDs(1, &platform, NULL);
	if (err != CL_SUCCESS) {
		printf("%s:%u: OpenCL error: Failed to retrieve a platform ID\n", __FILE__, __LINE__);
	}

	/* find the GPU CL device */
	err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
	if (err != CL_SUCCESS) {
		printf("%s:%u: OpenCL error: Failed to create a device group\n", __FILE__, __LINE__);
		checkGetDeviceIDs(err);
		exit(EXIT_FAILURE);
	}

    /* create a context to perform our calculation with the specified device */
    context = clCreateContext(0, 1, &device, NULL, NULL, &err);
    if (err != CL_SUCCESS) {
    	printf("%s:%u: OpenCL error: Failed to create the context\n", __FILE__, __LINE__);
    	exit(EXIT_FAILURE);
    }

    /* create a command queue */
	cmd_queue = clCreateCommandQueue(context, device, CL_QUEUE_PROFILING_ENABLE, &err);
	if (err != CL_SUCCESS) {
    	printf("%s:%u: OpenCL error: Failed to create the command queue\n", __FILE__, __LINE__);
    	exit(EXIT_FAILURE);
    }
    exec_time_opencl_startup = timer(1);

    /* load mersenne twister kernel source from disk */
    timer(1);
    char mersenne_kernel_filename[128];
	strcpy(mersenne_kernel_filename, "mersenneTwister_kernel.cl");
	// binary kernel load disabled due to NVIDIA implementation bug
//	if(LOAD_BINARY_KERNEL) strcat(mersenne_kernel_filename, ".ptx");	// append binary kernel suffix

    char *mersennetwister_source = load_program_source(mersenne_kernel_filename);
    if(mersennetwister_source == NULL) {
    	printf("%s:%u: OpenCL error: Failed to open the OpenCL program source file\n", __FILE__, __LINE__);
    	exit(EXIT_FAILURE);
    }

    /* set build options for OpenCL kernel compilation */
    char build_options[128] = "";
    strcat(build_options, "-I inc/ "); // add the directory inc/ to the list of directories to be searched for header files
//	if(USE_FAST_RELAXED_MATH) strcat(build_options, "-cl-fast-relaxed-math ");


    /*
     * Code section commented out - see below about inability to write out a
     * well-formed PTX binary file
     */
//	if(LOAD_BINARY_KERNEL) {
//		/* load kernel binary from disk */
//		size_t binary_size = strlen(mersennetwister_source);
//		cl_int status;
//		program = clCreateProgramWithBinary(context, 1, &device, &binary_size, (const unsigned char**)&mersennetwister_source, &status, &err);
//		if (status != CL_SUCCESS) {
//			printf("%s:%u: OpenCL error: Failed to load Mersenne Twister binary for specified device\n", __FILE__, __LINE__);
//			exit(EXIT_FAILURE);
//		}
//		if (err != CL_SUCCESS) {
//			printf("%s:%u: OpenCL error: Failed to create the program from Mersenne Twister binary\n", __FILE__, __LINE__);
//			exit(EXIT_FAILURE);
//		}
//
//		timer(1);
//		err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
//		double build_mersenne_source_time = timer(1);
//		// XXX rename output string
//		printf("build_mersenne_source_time from binary= %f s\n", build_mersenne_source_time);
//		if (err != CL_SUCCESS) {
//			printf("%s:%u: OpenCL error: Failed to build Mersenne Twister kernel\n", __FILE__, __LINE__);
//			checkBuildProgram(program, device);
//			exit(EXIT_FAILURE);
//		}
//
//	} else {
		/* build kernel from source file at runtime*/
	    program = clCreateProgramWithSource(context, 1, (const char**)&mersennetwister_source, NULL, &err);
	    if (err != CL_SUCCESS) {
	    	printf("%s:%u: OpenCL error: Failed to create Mersenne Twister kernel from the source\n", __FILE__, __LINE__);
	    	exit(EXIT_FAILURE);
	    }

	    err = clBuildProgram(program, 0, NULL, build_options, NULL, NULL);
	    if (err != CL_SUCCESS) {
	    	printf("%s:%u: OpenCL error: Failed to build Mersenne Twister kernel\n", __FILE__, __LINE__);
	    	checkBuildProgram(program, device);
	    	exit(EXIT_FAILURE);
	    }

		/* write binary kernel to file */
	    // Not working yet - can't seem to write a well-formed PTX binary file; NVIDIA bug?
//		writePtxBinary(program, mersenne_kernel_filename);
//	}

    /* create the Mersenne Twister kernel object */
    mersennetwister_kernel = clCreateKernel(program, "mersenneTwister_kernel_cl", &err);
    if (err != CL_SUCCESS) {
    	printf("%s:%u: OpenCL error: Cannot create the Mersenne Twister kernel\n", __FILE__, __LINE__);
    	checkCreateKernelReturnValue(err);
    	exit(EXIT_FAILURE);
    }
    exec_time_dyn_compile = timer(1);

    /* create and populate MT parameters array with initial pre-computed states*/
    srandom((unsigned int) (time(NULL)));
    double num = (random() / (float) RAND_MAX) * 4194304;
    seed = (unsigned int) trunc(num);
    mt_struct_stripped *mt_parameters = (mt_struct_stripped*) malloc(sizeof(mt_struct_stripped) * MT_RNG_COUNT);
    timer(1);
	loadMTGPU_cl("data/MersenneTwister.dat", seed, mt_parameters, MT_RNG_COUNT);	// populate MT initial states from .dat file
	initMTRef("data/MersenneTwister.raw");
    exec_time_fileio = timer(1);



	/* create and write MT parameter buffers on GPU */
        timer(1);
	mt_parameters_mem = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(mt_struct_stripped) * MT_RNG_COUNT, NULL, &err);
	err = clEnqueueWriteBuffer(cmd_queue, mt_parameters_mem, CL_TRUE, 0, sizeof(mt_struct_stripped) * MT_RNG_COUNT, mt_parameters, 0, NULL, &event_mem_write);
	if (err != CL_SUCCESS) {
		printf("%s:%u: OpenCL error: Cannot enqueue command to write MT parameters of initial states\n",__FILE__, __LINE__);
		checkEnqueueWriteBufferReturnValue(err);
		exit(EXIT_FAILURE);
	}
        exec_time_copyin = timer(1);
        /* Code below can be used to access performance data from OpenCL event timers */
//	mem_write_time = computeEventExecTime(&event_mem_write);
//	printf("MT parameters mem write took %f s\n", mem_write_time);

	/* create MT results buffer */
        timer(1);
	gpu_results_mem = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(float) * num_results, NULL, &err);
	clFinish(cmd_queue);
        exec_time_opencl_malloc = timer(1);

	/* set up the kernel argument variables */
        timer(1);
	err  = clSetKernelArg(mersennetwister_kernel, 0, sizeof(cl_mem), (void*)&gpu_results_mem);
	err |= clSetKernelArg(mersennetwister_kernel, 1, sizeof(cl_mem), (void*)&mt_parameters_mem);
	err |= clSetKernelArg(mersennetwister_kernel, 2, sizeof(int),    (void*)&nPerRng);
	if (err != CL_SUCCESS) {
		printf("%s:%u: OpenCL error: Failed to set up the kernel arguments\n", __FILE__, __LINE__);
		checkSetKernelArgReturnValue(err);
		exit(EXIT_FAILURE);
	}

	/* Run the calculation by queuing it and forcing the command queue to complete the task */
	err = clEnqueueNDRangeKernel(cmd_queue, mersennetwister_kernel, 1, NULL, global_work_size, local_work_size, 0, NULL, &kernel_exec_time);
	if (err != CL_SUCCESS) {
		printf("%s:%u: OpenCL error: Failed to enqueue NDRange kernel\n", __FILE__, __LINE__);
		checkEnqueueNDRangeKernel(err);
		exit(EXIT_FAILURE);
	}
	clFinish(cmd_queue);
        exec_time_kernel = timer(1);
        /* Code below can be used to access performance data from OpenCL event timers */
//	printf("Kernel execution time = %f s\n", computeEventExecTime(&kernel_exec_time));


	/* read back the results */
        timer(1);
	err = clEnqueueReadBuffer(cmd_queue, gpu_results_mem, CL_TRUE, 0, sizeof(float) * num_results, (void*)samples, 0, NULL, &event_mem_read);
	if (err != CL_SUCCESS) {
		printf("%s:%u: OpenCL error: Failed to read the results\n", __FILE__, __LINE__);
		checkEnqueueReadBufferReturnValue(err);
		exit(EXIT_FAILURE);
	}
	clFinish(cmd_queue);
        exec_time_copyout = timer(1);
        timer(1);
        /* Code below can be used to access performance data from OpenCL event timers */
//	mem_read_time = computeEventExecTime(&event_mem_read);
//	printf("Results mem read took %f s\n", mem_read_time);
//	printf("Mem transfers (write+read) time: %f s\n", mem_write_time + mem_read_time);

	/* show some results */
//	for(int j=num_results-20; j < num_results; j++) {
//	for(int j=0; j < 30; j++) {
//		printf("result #%d: %f\n", j, samples[j]);
//	}
//
//	printf("num_results=%d\n", num_results);


	/* free up the memory */
	if(gpu_results_mem != NULL)		clReleaseMemObject(gpu_results_mem);
	if(mt_parameters_mem != NULL)	clReleaseMemObject(mt_parameters_mem);

	if(kernel_exec_time != NULL)	clReleaseEvent(kernel_exec_time);
	if(event_mem_read != NULL)		clReleaseEvent(event_mem_read);
	if(event_mem_write != NULL)		clReleaseEvent(event_mem_write);

	if(mersennetwister_kernel != NULL)	clReleaseKernel(mersennetwister_kernel);
	if(program != NULL)		clReleaseProgram(program);
	if(cmd_queue != NULL)	clReleaseCommandQueue(cmd_queue);
	if(context != NULL)		clReleaseContext(context);

    free(mt_parameters);
    free(mersennetwister_source);
    free(device);
    exec_time_opencl_cleanup = timer(1);
}


