#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int data[], int i, int n) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int bigest = i;

	if (left<n && data[left] > data[bigest]) {
		bigest = left;
	}
	if (right<n && data[right] > data[bigest]) {
		bigest = right;
	}

	if (bigest != i) {
		int temp = data[bigest];
		data[bigest] = data[i];
		data[i] = temp;

		heapify(data, bigest, n);
	}
}


void heapsort(int data[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(data, i, n);
	}

	for (int i = n - 1; i >= 0; i--) {
		int temp = data[0];
		data[0] = data[i];
		data[i] = temp;

		heapify(data, 0, i);
	}
}

int main() {
	int data[10000];
	int n = 10000;
	int i;
	double start, end;

	//program start time
	start = (double)clock() / CLOCKS_PER_SEC;

	//random generated data
	srand((int)time(NULL));
	for (i = 0; i < n; i++) {
		data[i] = rand() % 1000;
	}

	heapsort(data, n);


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