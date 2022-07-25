#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int main(int argc, char **argv) {

  int a, b, c;
  printf("Enter the a, b, c\n");
  scanf("%d %d %d", &a, &b, &c);
  printf("((BEFORE))a=%d\tb=%d\tc=%d\n", a, b, c);
  swap(&a, &b);
  swap(&a, &c);
  printf("((AFTER))a=%d\tb=%d\tc=%d\n", a, b, c);

  return EXIT_SUCCESS;
}