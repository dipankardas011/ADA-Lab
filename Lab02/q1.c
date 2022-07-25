#include <stdio.h>
#include <stdlib.h>


void task3(int** A, int N) {
  for (int i = 0; i < N;i++){
    for (int j = 0; j < N;j++) {
      if (j >= N-i-1)
        printf("%3d ", A[i][j]);
      else
        printf("  * ");
    }
    printf("\n");
  }
}

void task4(int** A, int N) {
  int task4 = 1;
  for (int i = 0; i < N; i++)
    task4 *= A[i][i];
  for (int i = 0; i < N;i++)
    task4 *= A[i][N-i-1];

  if ((N & 1) == 1 && A[(N / 2)][(N / 2)] != 0){
    task4 /= A[(N / 2)][(N / 2)];
  }
  printf("Product of diagonal: %d\n", task4);
}

void task2(int** A, int N) {
  int task2 = 0;
  for (int i = 0; i < N;i++)
    for (int j = 0; j < N;j++)
      if (i <= j)
        task2 += A[i][i];
  printf("Sum of elements of above main diag: %d\n", task2);
}

void task1(int** A, int N) {
  int task1 = 0;
  for (int i = 0; i < N;i++)
    for (int j = 0; j < N;j++)
      if (A[i][j] != 0)
        task1++;
  printf("No of Non-Zero elements: %d\n", task1);
}

int main(int argc, char **argv) {
  int **A;
  int N;
  printf("Enter the size: ");
  scanf("%d", &N);
  A = (int **)malloc(sizeof(int *) * N);

  for (int i = 0; i < N; i++)
    A[i] = (int *)malloc(sizeof(int) * N);

  printf("Enter the elements\n");
  for (int i = 0; i < N;i++)
    for (int j = 0; j < N;j++)
      scanf("%d", &A[i][j]);

  ////// Task 1 //////
  task1(A, N);

  ////// Task 2 //////
  task2(A, N);

  ////// Task 3 //////
  task3(A, N);

  ///// task 4////
  task4(A, N);

  return EXIT_SUCCESS;
}