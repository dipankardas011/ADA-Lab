#include <stdio.h>
#include <stdlib.h>

struct Item {
  int profit;
  int weight;
};

void sortIt(struct Item *arr, int size) {
  for (int i=1; i<size;i++) {
    int j = i-1;
    struct Item tempE = arr[i];
    float temp = arr[i].profit/(float)arr[i].weight;

    while (j>=0 && temp > (arr[j].profit/arr[j].weight) ) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = tempE;
  }
}

int main(int argc, char **argv) {
  struct Item itemSet[] = {
    {480,2},
    {40,10},
    {40,2}
  };
  int size= sizeof(itemSet)/sizeof(itemSet[0]);
  sortIt(itemSet, size);

  int profit = 0;

  int weight = 11;

  for (int i=0; i<size && weight > 0; i++) {
    if (itemSet[i].weight <= weight) {
      profit += itemSet[i].profit;
      weight -= itemSet[i].weight;
    } else {
      profit += (weight/(float)itemSet[i].weight) * itemSet[i].profit;
      weight = 0;
      itemSet[i].weight -= weight;
    }
  }

  printf("Profit: %d\n", profit);

  remove(argv[0]);
  return EXIT_SUCCESS;
}
