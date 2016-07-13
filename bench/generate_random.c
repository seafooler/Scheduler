/*
 * sched/bench/generate_random.c
 *
 * Seafooler, <seafooler@hust.edu.cn>
 */
#include "generate_random.h"

/*
 *generate uniform random number
 */
int * generate_random_uniform(int count, int low, int high)
{
	int* array_rand = (int *)malloc(count*sizeof(int));
	int i;
	srand((unsigned)time(0));
	for(i=0; i<count; i++)
		array_rand[i] = rand()%(high - low) + low;
	return array_rand;
}

/*
 *generate normal random number
 */
int * generate_random_normal(int count, int mu, int sigma)
{
	int* array_rand = (int *)malloc(count*sizeof(int));
	int i;
	double a,b;

	srand((unsigned)time(0));
	for(i=0; i<count-1; i=i+2)
	{
		a = (double)rand()/RAND_MAX;
		b = (double)rand()/RAND_MAX;
		array_rand[i] = sqrt(-2*log(a))*sin(2*PI*b)*sigma + mu;
		array_rand[i+1] = sqrt(-2*log(a))*cos(2*PI*b)*sigma + mu;
	}

	/*n is an odd number*/
	if(count % 2 == 1)
	{
		a = (double)rand()/RAND_MAX;
		b = (double)rand()/RAND_MAX;
		array_rand[count-1] = sqrt(-2*log(a))*sin(2*PI*b)*sigma + mu;
	}

	return array_rand;
}

/*
 *adjust the normal number in the section[low, high]
 */
int * generate_random_normal_adjust(int count, int low, int high, int mu, int sigma)
{
	int * array_normal = generate_random_normal(count, mu, sigma);
	int i;
	for(i=0; i<count; i++)
	{
		if(array_normal[i] < low)
			array_normal[i] = low;
		else if(array_normal[i] > high)
			array_normal[i] = high;
	}
	return array_normal;
}
