#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
  return a > b ? a : b;
}

int min(int a, int b) {
  return a < b ? a : b;
}

int COUNT_MAX_CMP = 0;
int COUNT_MIN_CMP = 0;

// FIXME: add in same function to reduce the comparation
int findSmallest(int* a, int left, int right) {
  if (right-left <= 1) {
    COUNT_MIN_CMP++;
    return min(a[left], a[right]);
  } else {
    int mid = left + (right-left)/2;
    int x = findSmallest(a, left, mid);
    int y = findSmallest(a, mid+1, right);

    COUNT_MIN_CMP++;
    return min(x,y);
  }
}

int findLargest(int* a, int left, int right) {
  if (right-left <= 1) {
    COUNT_MAX_CMP++;
    return max(a[left], a[right]);
  } else {
    int mid = left + (right-left)/2;
    int x = findLargest(a, left, mid);
    int y = findLargest(a, mid+1, right);

    COUNT_MAX_CMP++;
    return max(x,y);
  }
}

int main(int argc, char **argv) {
  int arr[] = {234,3453,342,64,345,21,34,23};
  int n = sizeof(arr)/sizeof(arr[0]);

  printf("count-Compare: %d\tSmallest element: %d\n",COUNT_MIN_CMP, findSmallest(arr,0, n-1));
  printf("count-Compare: %d\tLargest element: %d\n", COUNT_MAX_CMP, findLargest(arr,0, n-1));

  remove(argv[0]);
  return EXIT_SUCCESS;
}