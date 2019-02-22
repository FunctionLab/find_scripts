/*
 * mtUtils.h
 *
 *  Created on: May 6, 2010
 *      Author: Federico Dal Castello
 */

#ifndef MTUTILS_H_
#define MTUTILS_H_


#include "mersenneTwister.h"

double computeThroughput(double exec_time);
int checkInputData(void);
void printMaxMin(float *samples);
void cleanSamples(float *samples);


#endif /* MTUTILS_H_ */
