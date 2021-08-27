#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *write(void *arg)
{
	int *arg_ = arg;

	if(*arg_ == 1)
	{
		printf("A");
	}else
	if(*arg_ == 2)
	{
		printf("B");
	}else
	if(*arg_ == 3)
	{
		printf("C");
	}
	
	return NULL;
}


int main() {
	pthread_t threads[3];
	int arg[3];

	arg[0] = 1;
	arg[1] = 2;
	arg[2] = 3;

	for(int i=0; i < 3; i++)
	{
		pthread_create(&threads[i], NULL, write, &arg[i]);
		//pthread_join(threads[i], NULL);
	}

	printf("\n");

	exit(0);
}
