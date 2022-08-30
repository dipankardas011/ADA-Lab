#include <stdio.h>
#include <stdlib.h>


struct Result {
  int min, max;
};

int COUNTER = 0;

struct Result findMinMax(int *a, int left, int right) {
  if (right-left <= 1) {
    COUNTER++;
    struct Result result;
    if (a[left] > a[right]) {
      result.max = a[left];
      result.min = a[right];
    } else {
      result.min = a[left];
      result.max = a[right];
    }
    return result;
  }else {
    int mid = left + (right - left)/2;
    struct Result x = findMinMax(a, left, mid);
    struct Result y = findMinMax(a, mid+1, right);

    struct Result res;
    COUNTER++;
    res.min = x.min < y.min ? x.min : y.min;
    res.max = x.max > y.max ? x.max : y.max;

    return res;
  }
}


void executor(int N) {
  int arr[N];
  for (int i = 0;i < N;i++)
    arr[i] = rand();
  struct Result res = findMinMax(arr,0, N-1);
  printf("Comparison of inp: %d\ttook: %d\n", N, COUNTER);
  COUNTER = 0;
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