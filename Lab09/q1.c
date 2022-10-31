#include <stdio.h>
#include <stdlib.h>

struct Activity {
  int start;
  int end;
};



// Insertion sort
void sortIt(struct Activity *arr, int size) {
  struct Activity temp;
  for (int i=1; i<size;i++) {
    int j = i-1;
    temp = arr[i];

    while (j>=0 && temp.end < arr[j].end ) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = temp;
  }
}


int main(int argc, char **argv) {

  struct Activity activityList[] = {
    {1,2},{3,4},{0,6},{5,7},{8,9},{5,9}
  };

  int size = sizeof(activityList)/sizeof(activityList[0]);
  sortIt(activityList, size);

  int sol[size];

  int prev = 0;
  sol[0] = 1;

  for (int i = 1; i<size;i++) {
    if (activityList[prev].end <= activityList[i].start) {
      sol[i] = 1;
      prev = i;
    }
  }
  for (int i = 0; i<size;i++) {
    if (sol[i] == 1)
      printf("[SELECTED] start: %d\tend: %d\n", activityList[i].start, activityList[i].end);
  }

  remove(argv[0]);
  return EXIT_SUCCESS;
}
