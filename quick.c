#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_st(int data[], int left, int right) {
	if (left >= right) {
		return;
	}

	int pivot = left;
	int i = pivot + 1;
	int j = right;
	int temp;

	while (i <= j) {
		while (data[i] <= data[pivot]) {
			i++;
		}
		while (data[j] >= data[pivot]) {
			j--;
		}
		if (i > j) {
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	quick_st(data, left, j - 1);
	quick_st(data, j + 1, right);
}

int main() {
	int data[10];
	int i;
	double start, end;

	//program start time
	start = (double)clock() / CLOCKS_PER_SEC;

	//random generated data
	srand((int)time(NULL));
	for (i = 0; i < 10; i++) {
		data[i] = rand() % 1000;
	}

	//quick sort
	quick_st(data, 0, 10 - 1);

	//sorted data print
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	//program end time
	end = (double)clock() / CLOCKS_PER_SEC;
	printf("실행시간: %lf\n", (end - start));

	return 0;
}