#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

# define HEAP_SIZE 100

int size = 0;

void heapify(int *arr, int index) {
  int largest = index;
  int leftChild = 2*index;
  int rightChild = 2*index + 1;
  if (leftChild < size && arr[largest] < arr[leftChild]){
    largest = leftChild;
  }

  if (rightChild < size && arr[largest] < arr[rightChild]){
    largest = rightChild;
  }

  if (largest != index){
    int t = arr[largest];
    arr[largest] = arr[index];
    arr[index] = t;
    heapify(arr, largest);
  }
}

void buildHeap(int* arr) {
  for (int i = size/2; i >= 1; i--) {
    heapify(arr, i);
  }
}

int deleteHeap(int *arr) {
  int ret = arr[1];
  int t = arr[1];
  arr[1] = arr[size-1];
  arr[size-1] = t;
  size--;
  heapify(arr, 1);
  return ret;
}

void insertHeap(int *arr, int ele) {
  
  assert(size+1 < HEAP_SIZE);

  size += 1;
  arr[size-1] = ele;
  
  int i = size-1;
  while (i > 1 && arr[i/2] < ele) {
    arr[i] = arr[i/2];
    i /= 2;
  }

  heapify(arr, 1);
}

void display(int* arr, int size) {
  for (int i=1; i<size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char **argv) {
  int arr[] = {-1, 3,4,56,2,435,64};
  size = sizeof(arr)/ sizeof(int);
  buildHeap(arr);
  display(arr, size);
  
  insertHeap(arr, 10);
  display(arr, size);

  printf("Removed Element: %d\n", deleteHeap(arr));

  remove(argv[0]);
  return EXIT_SUCCESS;
}
