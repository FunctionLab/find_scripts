/*
 * oclUtils.h
 *
 *  Created on: Apr 14, 2010
 *      Author: Federico Dal Castello
 */

#ifndef OCLUTILS_H_
#define OCLUTILS_H_

#include "opencl.h"


double computeEventExecTime(cl_event *event);
char * load_program_source(const char *filename);
void printDeviceInformation(cl_device_id device);
void writePtxBinary(cl_program program, const char *filename);

#endif /* OCLUTILS_H_ */
