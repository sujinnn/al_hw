#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int sorted[5000];

//merge sort �� 2���� ���� ������ �迭 �պ�
void merge_st2(int data[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (data[i] <= data[j]) {
			sorted[k] = data[i];
			i++;
		}
		else {
			sorted[k] = data[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (int l = j; l <= right; l++) {
			sorted[k] = data[l];
			k++;
		}
	}
	else {
		for (int l = i; l <= mid; l++) {
			sorted[k] = data[l];
			k++;
		}
	}
	for (int l = left; l <= right; l++) {
		data[l] = sorted[l];
	}
}

//merge sort �� ������ ������ ���� ����
void merge_st1(int data[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_st1(data, left, mid);         //���� ����
		merge_st1(data, mid + 1, right);    //���� ����
		merge_st2(data, left, mid, right);  //������ ���� �պ�
	}
}

int main() {
	int data[5000];
	int n = 5000;
	int i;
	double start, end;

	//program start time
	start = (double)clock() / CLOCKS_PER_SEC;

	//random generated data
	srand((int)time(NULL));
	for (i = 0; i < n; i++) {
		data[i] = rand() % 1000;
	}

	//merge sort
	merge_st1(data, 0, n - 1);

	//sorted data print
	for (int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	//program end time
	end = (double)clock() / CLOCKS_PER_SEC;
	printf("����ð�: %lf\n", (end - start));

	return 0;
}