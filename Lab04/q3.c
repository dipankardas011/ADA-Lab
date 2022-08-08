#include <stdio.h>
#include <stdlib.h>

#define N 100000

size_t binarySearch(int *arr, int pos, int ele) {
	size_t counter = 0;
	int left = 0;
	int right = pos;
	while (++counter && left <= right) {
		int mid = left + ((right - left) >> 1);
		if (arr[mid] == ele)
			break;
		else if (arr[mid] > ele)
			right = mid - 1;
		else
			left = mid + 1;
	}
	int i = right;

	int j=pos+1;

	while (++counter && j > i+1) {
		arr[j] = arr[j-1];
		j--;
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
	int arr[N];

	fillData(arr);
	size_t counter = 0;
	for (int i = 1; i<N;i++) {
		counter += binarySearch(arr, i-1, arr[i]);
	}
	printf("%ld\n", counter);

	return 0;
}
