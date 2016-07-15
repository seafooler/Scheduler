#include <stdio.h>
#include <sched.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

//Be careful: 0stask is used to create 1stask, 0stask cannot be run
int main(int argc, char *argv[])
{
	struct timeval tpstart, tpend;
	int i, fd;
	float timeuse;
	int runtime = 0;	//Be careful, 0stask.c is only used to create 1stask.s, and follow with 2stask.s. The executable file 0stask built by 0stask.c cannot run, for we will divide by 0 below
	int ratio;
	char buf[20];
	char ratio_str[10];
	int len;

	if((fd = open("time_ratio", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)) < 0)
	{
		printf("Open time_ratio failed.");
		return -1;
	}
	
	
	/*record the turnaround time*/
	gettimeofday(&tpstart, NULL);
	
	/*we will insert nop within the loop body in the assembly format*/
	for(i=0 ;i<10000000; i++){}
	gettimeofday(&tpend, NULL);
	
	timeuse = 1000000 * (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
	timeuse /= 1000000;
	
	ratio = timeuse / runtime;
	
	/*write the ratio to the file: ratio_str*/
	sprintf(buf, "%d", runtime);
	sprintf(ratio_str, "%d", ratio);
	strcat(buf, "s task: ");
	strcat(buf, ratio_str);
	strcat(buf, "\n");	

	len = strlen(buf);
	
	if(write(fd, buf, len) != len)
	{
		printf("Write time_ratio error");
		return -1;
	}	

	printf("%d task used time: %f seconds\n", runtime, timeuse);
	
	return 0;
}
