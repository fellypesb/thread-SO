#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	pid_t  pid_parent, pid2;

	pid_parent = getpid();
	printf("PID Parent: %d\n", pid_parent);	

	pid2 = fork();

	if(pid2==0)
	{
		pid2 = fork();
	}

	getchar();

	return(0);
}

