#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
      printf("%d ", i);

  free(prime);
}

int main(int argc, char **argv) {
  isPrime(100);
  printf("\n");
  remove(argv[0]);
  return EXIT_SUCCESS;
}