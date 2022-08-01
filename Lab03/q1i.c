#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int isPrimeUtil(int n, int i) {
  if (i == n)
    return 1;

  if (n % i == 0)
    return 0;
  return isPrimeUtil(n, i + 1);
}

int isPrime(int x) {
  if (x == 1)
    return 0;
  return isPrimeUtil(x, 2);
}

int main(int argc, char **argv) {
  clock_t begin = clock();
  for (int i = 0; i < N; i++) {
    if (isPrime(i)) {
      printf("%d ", i);
    }
  }
  clock_t end = clock();
  printf("\n");
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%f\n", time_spent);
  remove(argv[0]);
  return EXIT_SUCCESS;
}