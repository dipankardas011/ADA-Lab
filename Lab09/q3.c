#include <stdio.h>
#include <stdlib.h>

#include "server.c"

int main() {
  char msgr[1000]={'\0'};
  printf("Enter the message\n");
  scanf(" %[^\n]s", msgr);

  HeapSize = 1;

  printf("Message received from [client]: %s\n", msgr);

  int hashMap[HASHMAP_CHARACTER_SIZE] = {0};
  getFreq(msgr, hashMap);
  execute_heap(msgr, hashMap);
  printerHuffmanTable(payload.table, payload.sizeTable);
  printf("Encoded Message: %s\n", payload.encode);
  return 0;
}
