#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 5

void swap(int*a, int*b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void bubbleSortAsc(int a[N]) {

  int counter = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - 1 - i;j++) {
      if (a[j] > a[j+1]) {
        counter++;
        swap(a + j, a + j + 1);
      }
    }
  }
  printf("Enter the no of swaps in ascending: %d\n", counter);
}

void bubbleSortDes(int a[N]) {
  int counter = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - 1 - i;j++) {
      if (a[j] < a[j+1]) {
        counter++;
        swap(a + j, a + j + 1);
      }
    }
  }
  printf("Enter the no of swaps in descending: %d\n", counter);
}

int main(int argc, char **argv) {
  srand(time(0));

  int *arr = malloc(sizeof(int) * N);

  for (int i = 0; i < N;i++)
    scanf("%d", arr + i);
  // arr[i] = rand()%1000;
  for (int i = 0; i < N;i++)
    printf("%d ", arr[i]);
  printf("\n");

  int temp[N];
  for (int i = 0; i < N;i++)
    temp[i] = arr[i];

  bubbleSortAsc(arr);
  bubbleSortDes(temp);

  remove(argv[0]);
  return EXIT_SUCCESS;
}