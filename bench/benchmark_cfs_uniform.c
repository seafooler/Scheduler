/*
 * ched/bench/benchmark_cfs_uniform.c
 *
 * Seafooler, <seafooler@hust.edu.cn>
 */
#include <stdio.h>
#include "generate_random.h"
#include "benchmark_cfs_uniform.h"

/* just for test
int main()
{
	int count, low, high;
	printf("Input count, low and high:");
	scanf("%d %d %d", &count, &low ,&high);
	benchmark_cfs_uniform(count, low, high);
	return 0;
}
*/

char** benchmark_cfs_uniform(int count, int low, int high)
{
	int i;
	int *array_rand;	//array of random numbers
	char **array_task;	//array of tasks

	/*
	 * allocate the two-dimension array dynamically
	 */
	array_task = (char**)malloc(sizeof(char*)*count);
	for(i=0; i<count; i++)
		array_task[i] = (char*)malloc(sizeof(char)*MAX_TASK_NAME_LEN);	//MAX_TASK_NAME_LEN defined in the benchmark.h
	
	/*
	 *generate the random numbers
	 */
	array_rand = generate_random_uniform(count, low, high);

	/*
         *generate the corresponding random tasks
         */	
	for(i=0; i<count; i++)
	{
		sprintf(array_task[i], "%d", array_rand[i]);
		strcat(array_task[i], "stask");
		printf("%dth task: %s\n", i, array_task[i]); 		//just for test
	}
	
	return array_task;
}
