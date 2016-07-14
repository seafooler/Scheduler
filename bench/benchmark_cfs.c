/*
 * sched/bench/benchmark_cfs.c
 *
 * Seafooler, <seafooler@hust.edu.cn>
 */
#include <stdio.h>
#include <string.h>
#include "benchmark_cfs.h"

/*
 * Test the cfs scheduler
 * Four arguments from cli: count, low, high and type;
 * Type: 0 represents uniform distribution; 1 represents normal distribution
 * If normal distribution, there are two extra arguments to input: mu and sigma
 */
int main(int argc, char const *argv[])
{
	int count, low, high, type, mu, sigma;
	int *array_rand;
	char **array_task;
	int i;
	int fd, len;	
	char file_path[20];
	char ordinal[4];
	int time;
	char task_time[4];

/*
	if(argc != 5)
	{
		printf("Usage: ./benchmark_cfs count low high type\n");
		return 0;
	}
*/	
	/*
	 *read the arguments
	 */
//	sscanf(argv[1], "%d", &count);
//	sscanf(argv[2], "%d", &low);
//	sscanf(argv[3], "%d", &high);
//	sscanf(argv[4], "%d", &type);
	count = 20;
	low = 5;
	high = 50;
	type = 0;
	/*
	 *check the arguments
	 */
	if(low > high)
	{
		printf("Low is not larger than high\n");
                return 0;	
	}	
	if(!((type == 0)|(type == 1)) )
	{
		printf("Type must be 0 or 1\n");
		return 0;
	}
	/*
	 *if the type is normal distribution, two extra arguments are needed
	 */
	if(type == 1)
	{
		printf("Input mu and sigma:");
		scanf("%d %d", &mu, &sigma);
	}

	
	/*
	 * generate the array of tasks on the basis of type
	 */
	if(type == 0)	//uniform distribution
		array_task = benchmark_cfs_uniform(count, low, high);
	else		//normal distribution
		array_task = benchmark_cfs_normal(count, low, high, mu, sigma);	
	
	/*
	 *write the array_task[i] to filei
	 */	
	for(i=0; i<count; i++)
	{	
		//create the filei
		strcpy(file_path, "../expefile/file");
		sprintf(ordinal, "%d", i);
		strcat(file_path, ordinal);
		if((fd = open(file_path, O_RDWR|O_CREAT|O_TRUNC, FILE_MODE)) < 0)
		{
			printf("Create file%d failed!", i);
			return -1;
		}
	
		//extract the substring from array_task[i], such as: extract "10" from "10stask"
		sscanf(array_task[i], "%d", &time);	
		sprintf(task_time, "%d", time);
			
		//write task run_time to the file
		len = strlen(task_time);

		if(write(fd, task_time, len) != len)
		{
			printf("write error");
			return 0;
		}

		close(fd);
	}

	if(generate_sh(array_task, count) < 0)
	{
		printf("Generate shell script failed!");
		return -1;
	}
	return 0;	
	
}


/*
 * generate the shell script
 */
int generate_sh(char **array_task, int count)
{
	int fd, i;
	char *strtemp;
	int len;

	printf("SH_PATH:%s", SH_PATH);
	
	if((fd = open(SH_PATH, O_RDWR|O_CREAT|O_TRUNC|O_APPEND, FILE_MODE|S_IXUSR|S_IXGRP)) < 0)
	{
		printf("Open tasks/start.sh failed");
		return -1;
	}
	
	for(i=0; i< count; i++)
	{
		strcpy(strtemp, "./");
		strcat(strtemp, array_task[i]);
		strcat(strtemp, " &");
		strcat(strtemp, "\n");
		len = strlen(strtemp);		
		if(write(fd, strtemp, len) != len)
		{
			printf("Write tasks/start.sh failed");
			return -1;
		}
	}
	return 0;
}
