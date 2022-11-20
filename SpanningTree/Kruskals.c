#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct ItemSet {
  int from;
  int to;
  int weight;
};

int setFind(int *set, int i) {
  while (set[i] >= 0) {
    i = set[i];
  }
  return i;
}


void setUnion(int* set, int i, int j) {
  set[i] = j;
}

void kruskals(int V, int Graph[][V]) {

  int* Set = (int*)malloc(sizeof(int)*V);
  for (int i=0; i<V; i++)
    Set[i] = -1;

  int noOfEdges = 0;
  for (int i=0; i<V; i++)
    for (int j=0; j<V; j++)
      if (Graph[i][j] != -1)
      noOfEdges++;


  struct ItemSet *GraphSet = (struct ItemSet*)malloc(sizeof(struct ItemSet)*noOfEdges);

  int pos = 0;
  for (int i=0; i<V; i++) {
    for (int j=0; j<V; j++) {
      if (Graph[i][j] != -1) {
        GraphSet[pos].from = i;
        GraphSet[pos].to = j;
        GraphSet[pos].weight = Graph[i][j];
        pos++;
      }
    }
  }

  // sort it
  for (int i=0;i<noOfEdges;i++) {
    for (int j=0; j<noOfEdges-i-1; j++){
      if (GraphSet[j].weight > GraphSet[j+1].weight) {
        struct ItemSet temp = GraphSet[j];
        GraphSet[j] = GraphSet[j+1];
        GraphSet[j+1] = temp;
      }
    }
  }

  int minCost = 0;
  int idxForGraphSet = 0;
  for (int i=1; i<V;) {
    // extract Min
    struct ItemSet edge = GraphSet[idxForGraphSet++];

    int j = setFind(Set, edge.from);
    int k = setFind(Set, edge.to);

    if (j != k) {

      printf("%d -> %d\n", edge.from, edge.to);

      setUnion(Set, j, k);
      minCost += edge.weight;

      i++;
    }
  }

  printf("Min COst: %d\n", minCost);
}



int main () {
  int Graph[4][4];
  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
      Graph[i][j] = -1;
  Graph[0][1] = 10;
  Graph[1][3] = 15;
  Graph[2][3] = 4;
  Graph[2][0] = 6;
  Graph[0][3] = 5;

  kruskals(4, Graph);
  return 0;
}
