/*
 * sched/bench/file_oper.h
 *
 * Seafooler, <seafooler@hust.edu.cn>
 */

#ifndef SCHED_BENCH_FILE_OPER_H_
#define SCHED_BENCH_FILE_OPER_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)
#define SH_PATH "./tasks/start.sh"

#endif //SCHED_BENCH_FILE_OPER_H_
