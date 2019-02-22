/*
 * timer.c
 *
 *  Created on: Nov 27, 2009
 *      Author: Federico Dal Castello
 */

#include <stdio.h>

#include "timer.h"


double timer(int n)
{
	// IMPORTANT: initialize the 'init' variable with 1
	static int init[TIMER_SIZE] = {1, 1};	// flag to initialize the variables: if != 0 not initialized; if 0 initialized
	static struct timeval previous_time[TIMER_SIZE]; // time saved from previous function call
	struct timeval actual_time[TIMER_SIZE]; 		 // time saved from the actual function call
	double delta_time; // time difference from the actual and the previous function call
	int i;

	if(n < 0 || n > TIMER_SIZE) {
		printf("ERROR: The argument 'number' must be comprised between 0 and %d. Actually, it is %d.\n", TIMER_SIZE-1, n);
		exit(EXIT_FAILURE);
	}

	/* function initialization: sets the previous time to zero */
	for(i = 0; i < TIMER_SIZE; i++) {
		if(init[n] != 0) {
			previous_time[n].tv_sec = 0;
			previous_time[n].tv_usec = 0;
			init[n] = 0;
		}
	}

	/* get the current time of day */
    gettimeofday(&actual_time[n], NULL);

    /* compute the time difference since the previous call */
    delta_time = (actual_time[n].tv_usec - previous_time[n].tv_usec) * 1E-6 + (actual_time[n].tv_sec - previous_time[n].tv_sec);

    /* updates the previous time with the actual time */
    previous_time[n] = actual_time[n];

    return delta_time;
}
