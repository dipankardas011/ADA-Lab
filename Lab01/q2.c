#include <stdio.h>
#include <stdlib.h>

#define N 5
int main() {

	int arr[N]={0};
	scanf("Enter the inp..\n");
	for (int i=0;i<N;i++)
		scanf("%d",&arr[i]);

	// Bubble sort
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
}
