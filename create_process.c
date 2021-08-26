#include <unistd.h>
#include <stdio.h>

int main(void)
{

	pid_t  pid;
	int i=0;

	while(i < 5)
	{
		pid = fork();
		if(pid==0)
		{
			printf("PID Child: %d\n ", getpid());
		}else
		{
			printf("PID Parent: %d\n", getpid());
		}


		sleep(2);
		i += 1;
	}

	scanf("%d", &i);

	return(0);
}

