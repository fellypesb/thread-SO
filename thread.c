#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *write(void *arg){
	int *val = arg;

	// Talvez sirva um switch

	if (*val == 1) {
		printf("A");
	} else if (*val == 2) {
		printf("B");
	} else if (*val == 3) {
		printf("C");
	} else {
		printf("D");
	}

}

int main() {
	pthread_t t1, t2, t3;
	int a1, a2, a3;

	a1 = 1;
	a2 = 2;
	a3 = 3;

	pthread_create(&t1, NULL, write, &a1);
	pthread_create(&t2, NULL, write, &a2);
	pthread_create(&t3, NULL, write, &a3);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);

	printf("\n");

	exit(EXIT_SUCCESS);
}
