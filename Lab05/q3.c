#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static size_t counter = 0;


void merger(int *arr, int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int k = 0;
  int *temp = (int *)malloc(sizeof(int) * (right - left + 1));
  while (i <= mid && j <= right) {
    counter++;
    if (arr[i] < arr[j])
      temp[k++] = arr[i++];
    else if (arr[i] > arr[j])
      temp[k++] = arr[j++];
    else {
      temp[k++] = arr[i++];
      j++;
    }
  }

  while (i <= mid) {
    counter++;
    temp[k++] = arr[i++];
  }

  while (j <= right) {
    counter++;
    temp[k++] = arr[j++];
  }

  for (int i = 0; i < (right - left + 1); i++) {
    counter++;
    arr[i + left] = temp[i];
  }

  free(temp);
}

void insertionSort(int *arr, int l, int r) {
  for (int i = l + 1; i <= r; i++) {
    int j = i - 1;
    int ele = arr[i];
    while (++counter && arr[j] > ele && j >= 0) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = ele;
  }
}

void mergeSort(int *arr, int left, int right) {
  if (right - left + 1 <= 20)
    insertionSort(arr, left, right);
  else if (left < right) {
    int mid = left + ((right - left) >> 1);
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
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