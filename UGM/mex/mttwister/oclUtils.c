/*
 * oclUtils.c
 *
 *  Created on: Apr 14, 2010
 *      Author: Federico Dal Castello
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <sys/stat.h>

#include "oclUtils.h"
#include "oclErrorUtils.h"


double computeEventExecTime(cl_event *event)
{
    cl_ulong start, end;

    if(event == NULL) {
    	printf("computeEventExecTime: 'event' is NULL");
    	exit(EXIT_FAILURE);
    }

    clGetEventProfilingInfo(*event, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &start, NULL);
    clGetEventProfilingInfo(*event, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &end, NULL);

    return (double)1.0e-9 * (end - start); // convert nanoseconds to seconds on return
}

char * load_program_source(const char *filename)
{
	struct stat statbuf;
	FILE *fh;
	char *source;

	fh = fopen(filename, "r");
	if (fh == NULL) {
		return NULL;
	}

	stat(filename, &statbuf);
	source = (char *) malloc(statbuf.st_size + 1);
	fread(source, statbuf.st_size, 1, fh);
	source[statbuf.st_size] = '\0';

	fclose(fh);

	return source;
}


void printDeviceInformation(cl_device_id device)
/* Get some information about the returned device */
{
	size_t returned_size = 0;
	cl_int err = 0;
	cl_char vendor_name[128] = "";
	cl_char device_name[128] = "";

	err = clGetDeviceInfo(device, CL_DEVICE_VENDOR, sizeof(vendor_name), vendor_name, &returned_size);
	err |= clGetDeviceInfo(device, CL_DEVICE_NAME, sizeof(device_name),	device_name, &returned_size);
	if (err != CL_SUCCESS) {
	    printf("%s:%u: OpenCL error: Failed to retrieve device information\n", __FILE__, __LINE__);
	} else {
		printf("Using %s %s...\n", vendor_name, device_name);
	}
}


void writePtxBinary(cl_program program, const char *filename)
/* Get and log the binary (PTX) from the OpenCL compiler for the requested program */
{
	// get the binary size
	size_t binary_size;
	clGetProgramInfo(program, CL_PROGRAM_BINARY_SIZES, sizeof(size_t), &binary_size, NULL);

	if (binary_size == 0) {
		// no binary available
		printf("writePtxBinary: no binary available\n");
		return;
	}

	// get the binary code
	char *full_ptx_code = (char*) malloc(binary_size);
	clGetProgramInfo(program, CL_PROGRAM_BINARIES, 1, full_ptx_code, NULL);

	// append PTX suffix to filename
	char *filename_full = (char*) malloc(strlen(filename) + 4 + 1); // +4 bytes for the extension; +1 for '\0'
	strcpy(filename_full, filename);
	strcat(filename_full, ".ptx");

	// write the binary to file
	FILE* fp = NULL;
	fp = fopen(filename_full, "wb");
	if (fp == NULL) {
		perror("** Unable to create the file to store the PTX binary");
	} else {
		fwrite(full_ptx_code, binary_size, 1, fp);
	}

	// cleanup
	fclose(fp);
	free(full_ptx_code);
	free(filename_full);
}
