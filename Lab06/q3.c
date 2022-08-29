#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int left, int right) {
  int low = left-1;
  int high = right+1;
  int parition = arr[left];

  while (1) {
    while (arr[++low] < parition);
    while (arr[--high] > parition);
    if (low < high) {
      int t = arr[low];
      arr[low] = arr[high];
      arr[high] = t;
    }
    else
      return high;
  }
}


void quickSort(int* arr, int left, int right) {
  if (left < right) {
    int part = partition(arr, left, right);
    quickSort(arr, left, part);
    quickSort(arr, part+1, right);
  }
}

int main(int argc, char **argv) {
  int arr[] = {324,34,234,24,245,24,2};
  int n = sizeof(arr)/sizeof(int);
  quickSort(arr, 0,n-1);
  for (int i=0; i<n; i++) {
    printf("%d ",arr[i]);
  }
  remove(argv[0]);
  return EXIT_SUCCESS;
}