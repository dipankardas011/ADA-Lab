#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int counter = 0;

int RandomeIdx(int left, int right) {
  return rand() % (right - left) + left;
}

int partition(int *arr, int left, int right) {
  int low = left-1;
  int high = right+1;

  int getRandIdx = RandomeIdx(left, right);

  int t = arr[left];
  arr[left] = arr[getRandIdx];
  arr[getRandIdx] = t;

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


void quickSort(int* arr, int left, int right) {
  if (left < right) {
    int part = partition(arr, left, right);
    quickSort(arr, left, part);
    quickSort(arr, part+1, right);
  }
}

void executor(int N) {
  srand(time(0));
  int arr[N];
  for (int i = 0;i < N;i++)
    arr[i] = rand();
  quickSort(arr,0, N-1);
  printf("Comparison of inp: %d\ttook: %d\n", N, counter);
  counter = 0;
}

int main(int argc, char **argv) {
  executor(100);
  executor(1000);
  executor(10000);
  executor(100000);
  executor(1000000);
  remove(argv[0]);
  return EXIT_SUCCESS;
}