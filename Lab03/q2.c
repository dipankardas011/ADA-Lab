#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
  int arr[] = {3, 4, 5, 1, 2};
  int prod = 1;
  for (int i = 0; i< sizeof(arr) / sizeof(int); i++)
    prod *= arr[i];

  for (int i = 0; i< sizeof(arr) / sizeof(int); i++)
    arr[i] = prod / arr[i];

  for (int i = 0; i< sizeof(arr) / sizeof(int); i++)
    printf("%d ", arr[i]);
  printf("\n");
  remove(argv[0]);
  return EXIT_SUCCESS;
}