#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50000

int isPrimeUtil(int n, int i) {
  if (i == n)
    return 1;

  if (n % i == 0)
    return 0;
  return isPrimeUtil(n, i + 1);
}

int isPrime(int x) {
  if (x <= 1)
    return 0;
  return isPrimeUtil(x, 2);
}

int main(int argc, char **argv) {
  clock_t begin = clock();
  for (int avg = 0; avg < 100; avg++) {

    for (int i = 0; i < N; i++)
    {
      if (isPrime(i))
      {
        // printf("%d ", i);
        printf("");
      }
    }
  }
  clock_t end = clock();
  printf("\n");
  double time_spent = (double)(end - begin) / (CLOCKS_PER_SEC*100.0);
  printf("Avg time of 100 times : %f\n", time_spent);
  remove(argv[0]);
  return EXIT_SUCCESS;
}
