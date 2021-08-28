#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define SIZE 70000
#define N_THREAD 6

void swap(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

// Fills a list with randoms
void *fill(void *list) {
	srand(time(NULL));
	
	int *l = list;
	int i;

	for (i = 0; i < SIZE; i++) l[i] = rand() / (RAND_MAX / SIZE);
}

// Sorts a list through bubblesort
void *sort(void *list) {
	int *l = list;
	int i, j;

	for (i = 0; i < SIZE - 1; i++) {
		for (j = i; j < SIZE; j++) if(l[j] < l[i]) swap(&l[i], &l[j]);
	}
}

int main(void) {
	pthread_t thread[N_THREAD];
	int list[SIZE];
	int i;
	clock_t t;

	t = clock();

	fill(list);
	sort(list);

	t = clock() - t;

	printf("%.5lf s\n", ((double)t) / CLOCKS_PER_SEC);
	
	t = clock();

	for (i = 0; i < N_THREAD; i++) pthread_create(&thread[i], NULL, fill, &list);
	for (i = 0; i < N_THREAD; i++) pthread_join(thread[i], NULL);

	for (i = 0; i < N_THREAD; i++) pthread_create(&thread[i], NULL, sort, &list);
	for (i = 0; i < N_THREAD; i++) pthread_join(thread[i], NULL);

	t = clock() - t;

	printf("%.5lf s\n", (((double)t) / CLOCKS_PER_SEC) / N_THREAD);

	return 0;
}
