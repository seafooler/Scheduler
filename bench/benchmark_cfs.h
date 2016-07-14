/*
 * sched/bench/benchmark_cfs.h
 *
 * Seafooler, <seafooler@hust.edu.cn>
 */
#ifndef SCHED_BENCH_BENCHMARK_CFS_H_
#define SCHED_BENCH_BENCHMARK_CFS_H_

#include "benchmark_cfs_uniform.h"
#include "benchmark_cfs_normal.h"
#include "file_oper.h"

/*
 * generate the shell script
*/
int generate_sh(char **array_task, int count);

#endif //SCHED_BENCH_BENCHMARK_CFS_H_
