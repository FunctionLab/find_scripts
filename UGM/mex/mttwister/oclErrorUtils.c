/*
 * oclErrorUtils.c
 *
 *  Created on: Jan 7, 2010
 *      Author: Federico Dal Castello
 */

#include "oclErrorUtils.h"


void checkCreateKernelReturnValue(cl_int err) {
	switch(err) {
	case CL_INVALID_PROGRAM:
		printf("** program is not a valid program object\n");
		break;
	case CL_INVALID_PROGRAM_EXECUTABLE:
		printf("** there is no successfully built executable for program\n");
		break;
	case CL_INVALID_KERNEL_NAME:
		printf("** kernel_name is not found in program\n");
		break;
	case CL_INVALID_KERNEL_DEFINITION:
		printf("** the function definition for __kernel function given by kernel_name such as the number of arguments, the argument types are not the same for all devices for which the program executable has been built\n");
		break;
	case CL_OUT_OF_HOST_MEMORY:
		printf("** there is a failure to allocate resources required by the OpenCL implementation on the host\n");
		break;
	default:
		printf("** unknown error\n");
		break;
	}
}


void checkSetKernelArgReturnValue(cl_int err) {
	switch(err) {
	case CL_INVALID_KERNEL:
		printf("** kernel is not a valid kernel object\n");
		break;
	case CL_INVALID_ARG_INDEX:
		printf("** arg_index is not a valid argument index\n");
		break;
	case CL_INVALID_ARG_VALUE:
		printf("** arg_value specified is NULL for an argument that is not declared with the __local qualifier or vice-versa\n");
		break;
	case CL_INVALID_MEM_OBJECT:
		printf("** an argument is declared to be a memory object when the specified arg_value is not a valid memory object\n");
		break;
	case CL_INVALID_SAMPLER:
		printf("** an argument is declared to be of type sampler_t when the specified arg_value is not a valid sampler object\n");
		break;
	case CL_INVALID_ARG_SIZE:
		printf("** arg_size does not match the size of the data type for an argument that is not a memory object or the argument is a memory object and arg_size != sizeof(cl_mem) or if arg_size is zero and the argument is declared with the __local qualifier or if the argument is a sampler and arg_size != sizeof(cl_sampler)\n");
		break;
	default:
		printf("** unknown error\n");
		break;
	}
}


void checkEnqueueReadBufferReturnValue(cl_int err) {
	switch(err) {
	case CL_INVALID_COMMAND_QUEUE:
		printf("** command_queue is not a valid command-queue\n");
		break;
	case CL_INVALID_CONTEXT:
		printf("** the context associated with command_queue and buffer are not the same or the context associated with command_queue and events in event_wait_list are not the same\n");
		break;
	case CL_INVALID_VALUE:
		printf("** the region being read or written specified by (offset, cb) is out of bounds or ptr is a NULL value\n");
		break;
	case CL_INVALID_EVENT_WAIT_LIST:
		printf("** event_wait_list is NULL and num_events_in_wait_list > 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or event objects in event_wait_list are not valid events\n");
		break;
	case CL_MEM_OBJECT_ALLOCATION_FAILURE:
		printf("** there is a failure to allocate memory for data store associated with buffer\n");
		break;
	case CL_OUT_OF_HOST_MEMORY:
		printf("** there is a failure to allocate resources required by the OpenCL implementation on the host\n");
		break;
	default:
		printf("** unknown error\n");
		break;
	}
}

void checkEnqueueWriteBufferReturnValue(cl_int err) {
	// clEnqueueWriteBuffer return values are the same as the Read version
	checkEnqueueReadBufferReturnValue(err);
}

void checkEnqueueNDRangeKernel(cl_int err) {
	switch(err) {
	case CL_INVALID_PROGRAM_EXECUTABLE:
		printf("** there is no successfully built program executable available for device associated with command_queue\n");
		break;
	case CL_INVALID_COMMAND_QUEUE:
		printf("** command_queue is not a valid command-queue\n");
		break;
	case CL_INVALID_KERNEL:
		printf("** kernel is not a valid kernel object\n");
		break;
	case CL_INVALID_CONTEXT:
		printf("** context associated with command_queue and kernel is not the same or the context associated with command_queue and events in event_wait_list are not the same\n");
		break;
	case CL_INVALID_KERNEL_ARGS:
		printf("** the kernel argument values have not been specified\n");
		break;
	case CL_INVALID_WORK_DIMENSION:
		printf("** work_dim is not a valid value (i.e. a value between 1 and 3)\n");
		break;
	case CL_INVALID_WORK_GROUP_SIZE:
		printf("** if local_work_size is specified and number of work-items specified by global_work_size is not evenly divisable by size of work-group given by local_work_size or does not match the work-group size specified for kernel using the __attribute__((reqd_work_group_size(X, Y, Z))) qualifier in program source\n");
		printf("** if local_work_size is specified and the total number of work-items in the work-group computed as local_work_size[0] * ... local_work_size[work_dim – 1] is greater than the value specified by CL_DEVICE_MAX_WORK_GROUP_SIZE\n");
		printf("** if local_work_size is NULL and the __attribute__((reqd_work_group_size(X, Y, Z))) qualifier is used to declare the work-group size for kernel in the program source\n");
		break;
	case CL_INVALID_WORK_ITEM_SIZE:
		printf("** the number of work-items specified in any of local_work_size[0], ... local_work_size[work_dim – 1] is greater than the corresponding values specified by CL_DEVICE_MAX_WORK_ITEM_SIZES[0], .... CL_DEVICE_MAX_WORK_ITEM_SIZES[work_dim – 1]\n");
		break;
	case CL_INVALID_GLOBAL_OFFSET:
		printf("** global_work_offset is not NULL\n");
		break;
	case CL_OUT_OF_RESOURCES:
		printf("** there is a failure to queue the execution instance of kernel	"
				"on the command-queue because of insufficient resources needed to "
				"execute the kernel.\n"
				"For example, the explicitly specified local_work_size causes a "
				"failure to execute the kernel because of insufficient resources "
				"such as registers or local memory.\n"
				"Another example would be the number of read-only image args used "
				"in kernel exceed the CL_DEVICE_MAX_READ_IMAGE_ARGS value for "
				"device or the number of write-only image args used in kernel "
				"exceed the CL_DEVICE_MAX_WRITE_IMAGE_ARGS value for device or "
				"the number of samplers used in kernel exceed CL_DEVICE_MAX_SAMPLERS "
				"for device\n");
		break;
	case CL_MEM_OBJECT_ALLOCATION_FAILURE:
		printf("** there is a failure to allocate memory for data store associated with image or buffer objects specified as arguments to kernel\n");
		break;
	case CL_INVALID_EVENT_WAIT_LIST:
		printf("** event_wait_list is NULL and num_events_in_wait_list > 0, or event_wait_list is not NULL and num_events_in_wait_list is 0, or if event objects in event_wait_list are not valid events\n");
		break;
	case CL_OUT_OF_HOST_MEMORY:
		printf("** there is a failure to allocate resources required by the OpenCL implementation on the host\n");
		break;
	default:
		printf("** unknown error\n");
		break;
	}
}


void checkCreateProgramWithBinary(cl_int err) {
	switch(err) {
	case CL_INVALID_CONTEXT:
		printf("** context is not a valid context\n");
		break;
	case CL_INVALID_VALUE:
		printf("** device_list is NULL or num_devices is zero, otherwise lengths or binaries are NULL or any entry in lengths[i] is zero or binaries[i] is NULL\n");
		break;
	case CL_INVALID_DEVICE:
		printf("** OpenCL devices listed in device_list are not in the list of devices associated with context\n");
		break;
	case CL_INVALID_BINARY:
		printf("** an invalid program binary was encountered for any device. binary_status will return specific status for each device\n");
		break;
	case CL_OUT_OF_HOST_MEMORY:
		printf("** there is a failure to allocate resources required by the OpenCL implementation on the host\n");
		break;
	default:
		printf("** unknown error\n");
		break;
	}
}


void checkGetDeviceIDs(cl_int err) {
	switch(err) {
	case CL_INVALID_PLATFORM:
		printf("** platform is not a valid platform\n");
		break;
	case CL_INVALID_DEVICE_TYPE:
		printf("** device_type is not a valid value\n");
		break;
	case CL_INVALID_VALUE:
		printf("** num_entries is equal to zero and devices is not NULL or if both num_devices and devices are NULL\n");
		break;
	case CL_DEVICE_NOT_FOUND:
		printf("** no OpenCL devices that matched device_type were found\n");
		break;
	default:
		printf("** unknown error\n");
		break;
	}
}



void checkBuildProgram(cl_program program, cl_device_id device) {
	// get the program build error log
	char log[2048];
	clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 2048, log, NULL);
	printf("** %s\n", log);
}


void checkGetProgramInfo(cl_int err) {
	switch(err) {
	case CL_INVALID_VALUE:
		printf("** param_name is not valid, or size in bytes specified by "
				"param_value_size is < size of return type (see table 5.11 of "
				"specifications) and param_value is not NULL\n");
		break;
	case CL_INVALID_PROGRAM:
		printf("** program is a not a valid program object\n");
		break;
	default:
		printf("** unknown error\n");
		break;
	}
}


