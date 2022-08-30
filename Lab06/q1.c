#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int COUNT = 0;

void exec(int *arr, int n) {
  int max = arr[0];
  int min = arr[0];
  for (int i=1;i<n;i++) {
    COUNT++;
    if (max < arr[i]) {
      max = arr[i];
    }
    COUNT++;
    if (min > arr[i]) {
      min = arr[i];
    }
  }
}

void executor(int N) {
  int arr[N];
  for (int i = 0;i < N;i++)
    arr[i] = rand();
  exec(arr, N);
  printf("Comparison of inp: %d\ttook: %d\n", N, COUNT);
  COUNT = 0;
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