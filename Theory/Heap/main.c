#include <stdio.h>
#include <stdlib.h>

#define HEAP_ARR_SIZE 10
// current heap elemtns
int HEAP_SIZE = 4 + 1;

struct heapElement {
  int* arrPtr;
  int index;
  int size;
};

struct Payload {
  int *arr;
  int size;
};


/**
 * @brief Init the heap elements
 */
struct heapElement* initHeap(struct heapElement* heap, struct Payload* payload) {
  for (int i=0; i<HEAP_SIZE; i++) {
    heap[i+1].arrPtr = payload[i].arr;
    heap[i+1].index = 0;
    heap[i+1].size = payload[i].size;
  }
  return heap;
}

void heapify(struct heapElement* heap, int idx) {
  /**
   * @param heap Min-Heap elements
   * @param idx parent
   */

  int l = 2*idx;
  int r = 2*idx + 1;
  int smallest = idx;
  if (heap[l].arrPtr[heap[l].index] < heap[smallest].arrPtr[heap[smallest].index]) {
    smallest = l;
  }
  if (heap[l].arrPtr[heap[r].index] < heap[smallest].arrPtr[heap[smallest].index]) {
    smallest = r;
  }

  if (smallest == idx)
    return;

  heap[idx] = heap[smallest];
  heapify(heap, smallest);
}

struct heapElement *build_heap(struct heapElement *heap) {
  for (int i=HEAP_SIZE/2; i>=1; i--) {
    heapify(heap, i);
  }

  return heap;
}


int main(int argc, char **argv) {
  struct heapElement* HeapArray = (struct heapElement*) malloc(sizeof(struct heapElement) * HEAP_ARR_SIZE);

  int arr1[] = {3,4,6,2,63,123};
  int arr2[] = {1,23,43};
  int arr3[] = {-13,14,423,32323};
  int arr4[] = {123,141};


  struct Payload payload[4] = {
    {
      arr1,
      sizeof(arr1)/sizeof(arr1[0])
    },
    {
      arr2,
      sizeof(arr2)/sizeof(arr2[0])
    },
    {
      arr3,
      sizeof(arr3)/sizeof(arr3[0])
    },
    {
      arr4,
      sizeof(arr4)/sizeof(arr4[0])
    }
  };

  HeapArray = initHeap(HeapArray, payload);

  HeapArray = build_heap(HeapArray);

  remove(argv[0]);
  return EXIT_SUCCESS;
}