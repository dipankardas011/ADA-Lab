#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500000

size_t insertionSort(int* arr) {
	size_t counter = 0;

	for (int i = 1; i<N;i++) {
		int j = i-1;
		int ele = arr[i];
		while (++counter && arr[j] > ele && j >= 0) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = ele;
	}

	return counter;
}

void fillData(int *arr) {
	printf("Enter 1 for ascending 2 desc and 3 for random\n");
	int ch;
	scanf("%d",&ch);
	switch (ch) {
		case 1: {
			for (int i=0;i<N;i++)
				*(arr + i) = i+1;
		}
		break;
		case 2: {
			for (int i=0;i<N;i++)
				*(arr + i) = N - (i+1);
		}
		break;
		case 3: {
			for (int i=0;i<N;i++)
				*(arr + i) = rand()%100;
		}
		break;
	}
}

int main() {
	srand(time(0));
	int arr[N];

	fillData(arr);

	printf("%ld\n",insertionSort(arr));

	return 0;
}
