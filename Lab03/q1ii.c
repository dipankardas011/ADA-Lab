#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

int isPrime(int x)
{
  if (x <= 1)
    return 0;
  for (int i = 2; i * i <= x; i++)
  {
    if (x % i == 0)
    {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char **argv)
{
  clock_t begin = clock();
  for (int avg = 0; avg < 100; avg++)
  {
    for (int i = 1; i < N; i++)
    {
      if (isPrime(i))
        printf("");
        // printf("%d ", i);
    }
  }
  clock_t end = clock();
  printf("\n");
  double time_spent = (double)(end - begin) / (CLOCKS_PER_SEC * 100.0);
  printf("Avg time of 100 times : %f\n", time_spent);
  remove(argv[0]);
  return EXIT_SUCCESS;
}