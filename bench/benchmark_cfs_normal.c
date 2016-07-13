/*
 * ched/bench/benchmark_cfs_normal.c
 *
 * Seafooler, <seafooler@hust.edu.cn>
 */
#include <stdio.h>
#include "generate_random.h"
#include "benchmark_cfs_normal.h"

/* just for test
int main()
{
	int count, low, high, mu, sigma;
	printf("Input count, low, high, mu and sigma:");
	scanf("%d %d %d %d %d", &count, &low ,&high, &mu, &sigma);
	benchmark_cfs_normal(count, low, high, mu, sigma);
	return 0;
}
*/

char** benchmark_cfs_normal(int count, int low, int high, int mu, int sigma)
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
	array_rand = generate_random_normal_adjust(count, low, high, mu, sigma);

	/*
         *generate the corresponding random tasks
         */	
	for(i=0; i<count; i++)
	{
		sprintf(array_task[i], "%d", array_rand[i]);
		strcat(array_task[i], "stask");
		printf("%dth task: %s\n", i, array_task[i]);	//just for test
	}
	
	return array_task;
}
