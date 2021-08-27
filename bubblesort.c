#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

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
	int list[SIZE];
	int i;

	fill(list);

	for (i = 0; i < SIZE; i++) printf("%d ", list[i]);
	printf("\n");

	sort(list);

	for (i = 0; i < SIZE; i++) printf("%d ", list[i]);
	printf("\n");



	return 0;
}
