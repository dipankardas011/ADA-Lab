#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int counter = 0;

int partition(int *arr, int left, int right) {
  int low = left-1;
  int high = right+1;

  int parition = arr[left];

  while (1) {
    while (++counter && arr[++low] < parition);
    while (++counter && arr[--high] > parition);
    if (low < high) {
      int t = arr[low];
      arr[low] = arr[high];
      arr[high] = t;
    }
    else
      return high;
  }
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


void quickSort(int* arr, int left, int right) {

  if (right - left + 1 <= SIZE/4)
    insertionSort(arr, left, right);
  else if (left < right) {
    int part = partition(arr, left, right);
    quickSort(arr, left, part);
    quickSort(arr, part+1, right);
  }
}

int main(int argc, char **argv) {
  int arr[SIZE];
  srand(time(0));
  for (int i = 0; i < SIZE; i++)
    arr[i] = rand()%500;
  int n = sizeof(arr)/sizeof(int);
  quickSort(arr, 0,n-1);
  printf(",%d\n", counter);
  counter = 0;
  remove(argv[0]);
  return EXIT_SUCCESS;
}