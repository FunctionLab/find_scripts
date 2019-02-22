/*
 * timer.h
 *
 *  Created on: Nov 27, 2009
 *      Author: Federico Dal Castello
 */

#include <stdlib.h>
#include <sys/time.h>
#include <sys/timeb.h>

#ifndef TIMER_H_
#define TIMER_H_

#define TIMER_SIZE	2	// how many timers are available to the function

/*
 * Returns the difference in seconds between the previous and the current function call.
 * The argument "number" specifies which timer is used. The available number of
 * timers are specified by the TIMER_SIZE macro.
 */
double timer(int number);

#endif /* TIMER_H_ */
