#include <stdio.h>
#include <sched.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
	struct sched_param param;
	struct timeval tpstart, tpend;
	int maxpri, i;
	float timeuse;
	
	/*set the process's scheduler as fifo*/
	maxpri = sched_get_priority_max(SCHED_FIFO);
	if(maxpri == -1)	
	{	
		perror("sched_get_priority_max() failed");
		exit(1);
	}
	param.sched_priority = maxpri;
		
	if(sched_setscheduler(getpid(), SCHED_FIFO, &param) == -1)
	{
		perror("sched_setscheduler() failed");
		exit(1);
	}

	/*record the turnaround time*/
	gettimeofday(&tpstart, NULL);
	//we will insert nop within the loop body in the assembly format
	for(i=0 ;i<10000000; i++){}
	gettimeofday(&tpend, NULL);
	
	timeuse = 1000000 * (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
	timeuse /= 1000000;
	
	printf("Used time: %f seconds\n", timeuse);
	
	return 0;
}
