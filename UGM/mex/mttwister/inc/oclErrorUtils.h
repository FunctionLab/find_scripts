/*
 * oclErrorUtils.h
 *
 *  Created on: Jan 7, 2010
 *      Author: Federico Dal Castello
 */

#include <stdio.h>

#include "opencl.h"

#ifndef OCLERRORUTILS_H_
#define OCLERRORUTILS_H_

void checkCreateKernelReturnValue(cl_int err);
void checkSetKernelArgReturnValue(cl_int err);
void checkEnqueueReadBufferReturnValue(cl_int err);
void checkEnqueueWriteBufferReturnValue(cl_int err);
void checkBuildProgram(cl_program program, cl_device_id device);
void checkEnqueueNDRangeKernel(cl_int err);
void checkCreateProgramWithBinary(cl_int err);
void checkGetDeviceIDs(cl_int err);
void checkGetProgramInfo(cl_int err);

#endif /* OCLERRORUTILS_H_ */
