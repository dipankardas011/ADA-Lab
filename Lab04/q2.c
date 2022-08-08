#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

size_t linearSearch(int *arr, int pos, int ele) {
	size_t counter = 0;
	int i = pos;
	while (++counter && i >= 0 && arr[i] > ele)
		i--;

	int j=pos+1;

	while (j > i+1) {
		arr[j] = arr[j-1];
		j--;
		++counter;
	}

	arr[i+1] = ele;
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

	size_t counter = 0;
	for (int i = 1; i<N;i++) {
		counter += linearSearch(arr, i-1, arr[i]);
	}

	printf("%ld\n",counter);

	return 0;
}
