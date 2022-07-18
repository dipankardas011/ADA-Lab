#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int main() {
	srand(time(0));
	int arr[N]={0};

	for (int i=0;i<N;i++)
		arr[i] = rand()%50;

	int hashMap[51]={0};
	for (int i=0;i<N;i++)
		printf("%d ",arr[i]);

	printf("\n");


	for (int i=0;i<N;i++)
		hashMap[arr[i]]++;

	for (int i=0;i<=50;i++) {
		if (hashMap[i] > 1) {
			printf("Duplicate(%d)\n",i);
		}
	}


}
