#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int data[10000];
	int n = 10000;
	int i, j, temp;
	double start, end;

	//program start time
	start = (double)clock() / CLOCKS_PER_SEC;

	//random generated data
	srand((int)time(NULL));
	for (i = 0; i < n; i++) {
		data[i] = rand() % 1000;
	}

	//data exchange sort
	for (i = 0; i < n - 1; i++) {
		for (j = (i + 1); j < n; j++) {
			if (data[i] > data[j]) {
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}

	//sorted data print
	for (i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	//program end time
	end = (double)clock() / CLOCKS_PER_SEC;
	printf("실행시간: %lf\n", (end - start));

	return 0;
}