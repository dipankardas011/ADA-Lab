#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int *arr, int l, int r) {
  while (l <= r)
    printf("%d ",arr[l++]);
  printf("\n\n");
}

static size_t counter = 0;


void merger(int* arr, int left, int mid ,int right) {

  int i = left;
  int j = mid +1;
  int k=0;
  int *temp = (int *)malloc(sizeof(int) *(right-left+1));
  while (i <= mid && j <= right) {
    counter++;

    if (arr[i] < arr[j])
      temp[k++] = arr[i++];
    else if (arr[left] > arr[right])
      temp[k++] = arr[j++];
    else {
      temp[k++] = arr[i++];
      j++;
    }
  }

  while (i<=mid) {
    counter++;
    temp[k++] = arr[i++];
  }
  while (j <= right) {
    counter++;
    temp[k++] = arr[j++];
  }

  for (int i = 0;i<(right-left+1); i++) {
    counter++;
    arr[i + left] = temp[i];
  }

  free(temp);
}

void mergeSort(int *arr, int left, int right) {
  if (left < right) {
    counter++;
    int mid = left + ((right-left) / 4);
    // int mid = (rand()%2) * (right - left) + left;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merger(arr, left, mid, right);
  }
}

void executor(int N) {
  int arr[N];
  for (int i = 0;i < N;i++)
    arr[i] = rand();
  mergeSort(arr, 0, N-1);
  printf("SOrted the array of [%d] elements in STEPS: %ld\n", N, counter);
  counter = 0;
}

int main(int argc, char **argv) {
	srand(time(0));
  executor(100);
  executor(1000);
  executor(10000);
  executor(100000);
  executor(1000000);

  remove(argv[0]);
  return EXIT_SUCCESS;
}