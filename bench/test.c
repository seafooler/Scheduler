#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{

/*
	int i,count;
//	char *str[5] = {"aaaaaa","bbbbbb","cccccc","dddddd","eeeeee"};
	char **str;
	printf("Input:");
	scanf("%d", &count);

	str =  (char**)malloc(sizeof(char*)*count);
	for(i=0; i<count; i++)
        {
		str[i] = (char*)malloc(sizeof(char)*8);
        }

	for(i=0; i<5; i++)
	{
		printf("Input the string:");
		scanf("%s", str[i]);
	}

	for(i=0; i<5; i++)
		printf("%s\n",str[i]);
	return 0;
*/

	/*
	int i=5;
	printf("%f\n", sqrt(i));
	return 0;
	*/

//	printf("%s\n", "hello/world");
	char result[20];
	int res;
//	int result;
//	sprintf(result, "%d", "1234herllo");
	sscanf("1234hello", "%d", &res);
	printf("%d\n", res);
	return 0;
}
