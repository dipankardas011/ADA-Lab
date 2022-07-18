#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int main() {
	srand(time(0));
	int arr[N]={0};

	for (int i=0;i<N;i++)
		arr[i] = rand()%50;

	for (int i=0;i <N;i++) {
		for (int j=0; j<N-1-i;j++) {
			if (arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	for (int i=0;i<N;i++)
		printf("%d ",arr[i]);

	printf("\n");

	for (int i=1;i<N;) {
		char flag=0;
		while (arr[i] == arr[i-1]){
			if (flag == 0)
				printf("(%d)\n",arr[i]);
			flag = 1;
			i++;
		}
		i++;
	}
}
