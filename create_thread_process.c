#define _GNU_SOURCE
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define STACK_SIZE 4096

int fn_test(void *arg)
{
	getchar();
	return (0);
}

int main(){
	void *stack = malloc(STACK_SIZE);
	pid_t thread_PID;

	printf("Parent process PID: %d\n", getpid());

	printf("\nCreating new thread... \n");
	thread_PID = clone(fn_test, stack+STACK_SIZE, CLONE_THREAD|CLONE_SIGHAND|CLONE_VM, NULL);
	if(thread_PID != -1)
	{
		printf("\nDone! Thread PID: %d\n", thread_PID);
	}else
	{
		printf("Failed to create thread!\n\n");
	}

	getchar();

	return (0);
}
