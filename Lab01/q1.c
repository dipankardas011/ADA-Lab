#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
	int N = 10;
	int *arr = (int*)malloc(sizeof(int)*N);
	for (int i=0;i<N;i++)
		scanf("%d",arr+i);

	int max = INT_MIN;
	for (int i=0;i <N; i++) {
		if (max < arr[i])
			max = arr[i];
	}

	printf("MAX=%d\n",max);
}
