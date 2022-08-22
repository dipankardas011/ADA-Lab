#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int *arr, int l, int r) {
  while (l <= r)
    printf("%d ", arr[l++]);
  printf("\n\n");
}

void merger(int *arr, int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int k = 0;
  int *temp = (int *)malloc(sizeof(int) * (right - left + 1));
  while (i <= mid && j <= right) {
    if (arr[i] < arr[j])
      temp[k++] = arr[i++];
    else if (arr[i] > arr[j])
      temp[k++] = arr[j++];
    else {
      temp[k++] = arr[i++];
      j++;
    }
  }

  while (i <= mid)
    temp[k++] = arr[i++];

  while (j <= right)
    temp[k++] = arr[j++];

  for (int i = 0; i < (right - left + 1); i++)
    arr[i + left] = temp[i];

  free(temp);
}

void insertionSort(int *arr, int l, int r) {
  for (int i = l + 1; i <= r; i++) {
    int j = i - 1;
    int ele = arr[i];
    while (arr[j] > ele && j >= 0) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = ele;
  }
}

void mergeSort(int *arr, int left, int right) {
  if (right - left + 1 <= 4)
    insertionSort(arr, left, right);
  else if (left < right) {
    int mid = left + ((right - left) >> 1);
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merger(arr, left, mid, right);
  }
}

int main(int argc, char **argv) {
  srand(time(0));
  int arr[] = {5, 4, 3, 2, 1, 234, 235, 134};
  int size = sizeof(arr) / sizeof(int);
  mergeSort(arr, 0, size - 1);

  printf("--[RES]--\n");
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);

  remove(argv[0]);
  return EXIT_SUCCESS;
}