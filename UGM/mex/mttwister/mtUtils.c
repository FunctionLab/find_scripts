/*
 * mtUtils.c
 *
 *  Created on: May 6, 2010
 *      Author: Federico Dal Castello
 */

#include "mtUtils.h"


double computeThroughput(double exec_time)
/* compute the algorithm throughput in MBytes given the execution time in seconds */
{
	return ( (N * sizeof(float)) * 1e-6 ) / exec_time; // ( (bytes_read + bytes_written) * 1e-6 ) / exec_time;
}


int checkInputData(void)
/* check for the correctness of input and header-defined data. Returns 1 if
 * something is wrong; 0 otherwise */
{
	/* check if the number of samples is greater than the maximum allowed limit
	 * to correctly perform calculations */
	if(N > 134217728) {
		printf("ERROR: the number of samples must be less than 2^27 for GPUs with 1GB RAM\n");
		return 1;
	}

	return 0; // all values are ok
}


void printMaxMin(float *samples)
/* print max and min values of 'samples' array to check if Mersenne Twister respects [0, 1] bounds */
{
	float min = 2;
	float max = -1;

	for(int i = 0; i < N; i++) {
		if(samples[i] > max) max = samples[i];
		if(samples[i] < min) min = samples[i];
	}

	printf("max = %.10f\n", max);
	printf("min = %.10f\n", min);
}


void cleanSamples(float *samples)
/* clean samples filling them with -1 */
{
	for(int i = 0; i < N; i++) {
		samples[i] = 0.5;
	}
}


