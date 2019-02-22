/*
 * MersenneTwisterCPU.h
 *
 *  Created on: Apr 13, 2010
 *      Author: Federico Dal Castello
 */

#ifndef MERSENNETWISTERCPU_H_
#define MERSENNETWISTERCPU_H_

#include "mersenneTwister.h"

void initSamples_MT_CPU(float *samples_x, const int num_openmp_threads);
void initSamples_MT_ACC(float *samples);

#endif /* MERSENNETWISTERCPU_H_ */
