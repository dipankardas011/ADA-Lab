#include <stdio.h>
#include <stdlib.h>

#define HEAP_ARR_SIZE 10
// current heap elemtns
int HEAP_SIZE = 4 + 1;

#define ERR -0x3E7

struct heapElement {
  int* arrPtr;
  int index;
  int size;
};

struct Payload {
  int *arr;
  int size;
};

void display(struct heapElement *heap) {
  for (int i = 1; i < HEAP_SIZE; i++) {
    printf("[%d]-> idx: %d\tfirstElement: %d\tsize: %d\n",i , heap[i].index, heap[i].arrPtr[0], heap[i].size);
  }
}


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
  if (l < HEAP_SIZE &&
      heap[l].index < heap[l].size &&
      heap[smallest].index < heap[smallest].size &&
      heap[l].arrPtr[heap[l].index] < heap[smallest].arrPtr[heap[smallest].index])
    smallest = l;

  if (r < HEAP_SIZE &&
      heap[r].index < heap[r].size &&
      heap[smallest].index < heap[smallest].size &&
      heap[r].arrPtr[heap[r].index] < heap[smallest].arrPtr[heap[smallest].index]) {
    smallest = r;
  }

  if (smallest == idx)
    return;

  struct heapElement temp = heap[idx];
  heap[idx] = heap[smallest];
  heap[smallest] = temp;
  heapify(heap, smallest);
}

struct heapElement *build_heap(struct heapElement *heap) {
  for (int i=HEAP_SIZE/2; i>=1; i--) {
    heapify(heap, i);
  }

  return heap;
}

struct heapElement *deleteNodeFromHeap(struct heapElement *heap){

  // first swap first with the last element
  // then decrese the HEAP_SIZE
  // call heapify again

  heap[1] = heap[HEAP_SIZE-1];
  HEAP_SIZE--;
  heapify(heap, 1);
  return heap;
}

struct heapElement* IncrementIdxFirstArray(struct heapElement *heap) {
  heap[1].index += 1;
  if (heap[1].index == heap[1].size) {
    return deleteNodeFromHeap(heap);
  } else {
    return heap;
  }
}

int peekFromHeap(struct heapElement *heap) {
  if (HEAP_SIZE >= 1) {
    return heap[1].arrPtr[heap[1].index];
  } else {
    return ERR;
  }
}

struct heapElement *addToHeap(struct heapElement *heap, int* newArr, int size) {
  // it will add based on newArr[0]
  HEAP_SIZE += 1;
  int i = HEAP_SIZE-1;
  while ( i > 1 && newArr[0] > heap[i/2].arrPtr[heap[i/2].index] ) {
    heap[i].arrPtr[heap[i].index] = heap[i/2].arrPtr[heap[i/2].index];
    i /= 2;
  }
  heap[i].arrPtr = newArr;
  heap[i].index = 0;
  heap[i].size = size;
  return heap;
}

void mergeSortUsingHeap(struct heapElement *heap) {
  int resSize = 0;
  for (int i = 0; i < HEAP_SIZE; i++) {
    resSize += heap[i].size;
  }
  int* resArray = (int*)malloc(sizeof(int) * resSize);
  int resIdx = 0;
  while (HEAP_SIZE > 1) {
    resArray[resIdx++] = peekFromHeap(heap);
    heap = IncrementIdxFirstArray(heap);
    heapify(heap, 1);
  }
  printf("[");
  for (int i=0;i<resSize; i++)
    printf(" %d", resArray[i]);
  printf(" ]\n");
}


int main(int argc, char **argv) {
  struct heapElement* HeapArray = (struct heapElement*) malloc(sizeof(struct heapElement) * HEAP_ARR_SIZE);

  int arr1[] = {2,3,4,6,63,124};
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
  int newArr[] = {-9, -8, -7};
  HeapArray = addToHeap(HeapArray, newArr, sizeof(newArr) / sizeof(int));

  display(HeapArray);

  HeapArray = build_heap(HeapArray);
  mergeSortUsingHeap(HeapArray);

  remove(argv[0]);
  return EXIT_SUCCESS;
}