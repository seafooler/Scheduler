/*
 * sched/bench/generate_random.h
 *
 * Seafooler, <seafooler@hust.edu.cn>
 */
#ifndef SCHED_BENCH_GENERATE_RANDOM_H_
#define SCHED_BENCH_GENERATE_RANDOM_H_

#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.1415926

/*generate uniform random number */
int * generate_random_uniform(int count, int low, int high);

/*generate normal random number*/
int * generate_random_normal(int count, int mu, int sigma);

/*adjust the normal number in the section[low, high]*/
int * generate_random_normal_adjust(int count, int low, int high, int mu, int sigma);

#endif // SCHED_BENCH_GENERATE_RANDOM_H_
