#include <stdio.h>
#include <stdlib.h>

# define HEAP_SIZE 100

int size = 0;

void heapify(int *arr, int index) {
  int smallest = index;
  int leftChild = 2*index;
  int rightChild = 2*index + 1;
  if (leftChild < size && arr[smallest] > arr[leftChild]){
    smallest = leftChild;
  }

  if (rightChild < size && arr[smallest] > arr[rightChild]){
    smallest = rightChild;
  }

  if (smallest != index){
    int t = arr[smallest];
    arr[smallest] = arr[index];
    arr[index] = t;
    heapify(arr, smallest);
  }
}

void buildHeap(int* arr) {
  for (int i = size-1; i >= 1; i--) {
    heapify(arr, i);
  }
}

int main(int argc, char **argv) {
  int arr[] = {-1, 3,4,56,2,435,64};
  size = sizeof(arr)/ sizeof(int);
  buildHeap(arr);
  for (int i=1; i<size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  remove(argv[0]);
  return EXIT_SUCCESS;
}