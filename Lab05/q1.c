#include <stdio.h>
#include <stdlib.h>

void merger(int* arr, int left, int mid ,int right) {
  int i = left;
  int j = mid +1;
  int k=0;
  int *temp = (int *)malloc(sizeof(int) *(right-left+1));
  while (i <= mid && j <= right) {
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
    temp[k++] = arr[i++];
  }
  while (j <= right) {
    temp[k++] = arr[j++];
  }

  for (int i = 0;i<(right-left+1); i++) {
    arr[i + left] = temp[i];
  }

  free(temp);
}

void mergeSort(int *arr, int left, int right) {
  if (left < right) {
    int mid = left + ((right-left) >> 1);
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merger(arr, left, mid, right);
  }
}

int main(int argc, char **argv) {
  int arr[] = {5, 4, 3, 2, 1};
  int size = sizeof(arr)/sizeof(int);
  mergeSort(arr, 0, size-1);

  for (int i=0;i<size; i++) {
    printf("%d ", arr[i]);
  }

  remove(argv[0]);
  return EXIT_SUCCESS;
}