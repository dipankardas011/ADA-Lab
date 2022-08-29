#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int arr[] = {234,236,345,14,3465,4234,23};
  int n = sizeof(arr)/sizeof(int);
  int max = arr[0];
  int min = arr[0];
  for (int i=1;i<n;i++) {
    if (max < arr[i])
      max = arr[i];
    if (min > arr[i])
      min = arr[i];
  }
  printf("Smallest: %d\tand largest element: %d\n", min,max);
  remove(argv[0]);
  return EXIT_SUCCESS;
}