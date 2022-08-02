#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 100000

void isPrime(int n)
{
  bool *prime = (bool *)malloc(sizeof(bool) * (n + 1));
  for (int i = 0; i <= n; i++)
    prime[i] = true;

  for (int i = 2; i * i <= n; i++)
  {
    if (prime[i]) {
      // make all the next elements which are divisiable by i to be not prime
      for (int j = i * i; j <= n; j+=i)
        prime[j] = false;
    }
  }

  for (int i = 2; i <= n; i++)
    if (prime[i])
      printf("");
      // printf("%d ", i);

  free(prime);
}

int main(int argc, char **argv) {

  clock_t begin = clock();
  for (int avg = 0; avg < 100; avg++)
    isPrime(N);

  clock_t end = clock();
  printf("\n");
  double time_spent = (double)(end - begin) / (CLOCKS_PER_SEC*100.0);
  printf("Avg time of 100 times : %f\n", time_spent);
  remove(argv[0]);
  return EXIT_SUCCESS;
}