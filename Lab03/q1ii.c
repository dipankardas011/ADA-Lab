#include <stdio.h>
#include <stdlib.h>

int isPrime(int x) {
  if (x <= 1)
    return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x%i == 0){
      return 0;
    }
  }
  return 1;
}

int main(int argc, char **argv) {
  // int N = 0;
  // printf("Enter the number-> ");
  // scanf("%d", &N);
  // printf("Prime(%d): %d\n", N, isPrime(N));
  for (int i = 1; i < 100; i++) {
    if (isPrime(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");
  remove(argv[0]);
  return EXIT_SUCCESS;
}