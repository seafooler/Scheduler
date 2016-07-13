#include <stdio.h>
#include <sched.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
	struct timeval tpstart, tpend;
	int i;
	float timeuse;
	
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
