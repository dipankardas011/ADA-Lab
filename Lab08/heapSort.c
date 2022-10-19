#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

# define HEAP_SIZE 100


int size = 1;

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
  for (int i = size/2; i >= 1; i--) {
    heapify(arr, i);
  }
}

int popHeap(int *arr) {
  int ret = arr[1];
  int t = arr[1];
  arr[1] = arr[size-1];
  arr[size-1] = t;
  size--;
  heapify(arr, 1);
  return ret;
}

void heapSort(int *arr, int length) {
  int heap[HEAP_SIZE]={INT_MIN};

  for (int i = 0; i < length; i++) {
    heap[i+1] = arr[i];
    size++; // global size of heap
  }
  buildHeap(heap);
  for (int i=0; i<length; i++) {
    arr[i] = popHeap(heap);
  }
}

int main(int argc, char **argv) {
  int arr[] = {3,1,6,7,5};
  int len = sizeof(arr)/sizeof(int);
  heapSort(arr, len);
  for (int i=0; i<len; i++) {
    printf("%d ",arr[i]);
  }
  printf("\n");
  remove(argv[0]);
  return EXIT_SUCCESS;
}
