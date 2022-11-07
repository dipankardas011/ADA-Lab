#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX INT_MAX

bool isEdgePresent(int graph[7][7], int start, int end) {
  return graph[start][end] != -1;
}

void DisplayGraph(int graph[7][7], int M, int N) {
  for (int start = 0; start<M; start++) {
    for (int end = 0; end < N; end++) {
      if (isEdgePresent(graph, start, end)) {
        printf("{%d}--{%d}-->{%d}\n", start+1, graph[start][end], end+1);
      }
    }
  }
}

int getIndexOfMin(int *distArr, bool *visited, int size){

  int min = MAX;
  int retIdx = 0;
  for (int i=0;i<size;i++) {
    if (!visited[i] && distArr[i] < min) {
      min = distArr[i];
      retIdx = i;
    }
  }
  return retIdx;
}


int* Prims(int graph[7][7], int vertex, int M, int N) {
  int startVertex = vertex - 1;
  int dist[M];
  for (int i=0;i<M;i++)
    dist[i] = MAX;
  int *predecessor = (int*)malloc(sizeof(int) * M);
  for (int i=0;i<M;i++)
    predecessor[i] = -1;

  bool isVisited[M];
  for (int i=0;i<M;i++)
    isVisited[i] = false;

  dist[startVertex] = 0;

  int noOfLeftVertex = M - 1;

  while (noOfLeftVertex > 0) {

    int minVertexIdx = getIndexOfMin(dist, isVisited, M);
    noOfLeftVertex -= 1;
    isVisited[minVertexIdx] = true;

    for (int i=0;i<N;i++) {
      if (isEdgePresent(graph, minVertexIdx, i) &&
          !isVisited[i] &&
          dist[i] > graph[minVertexIdx][i]) {
            dist[i] = graph[minVertexIdx][i];
            predecessor[i] = minVertexIdx;
          }
    }
  }

  return predecessor;
}


int main(int argc, char **argv) {
  int G[7][7] = {
    {-1, -1, -1, -1, -1, 35, 45},
    {-1, -1, 35, -1, 25, 10, 20},
    {-1, 35, -1, 10, 20, 15, -1},
    {-1, -1, 10, -1, 30, -1, -1},
    {-1, 25, 20, 30, -1, -1, 10},
    {35, 10, 15, -1, -1, -1, 15},
    {45, 20, -1, -1, 10, 15, -1}
  };
  int *MinSpanningTree = Prims(G, 4, 7, 7);
  for (int i = 0; i<7; i++) {
    int vertex = i;
    int parent = MinSpanningTree[i];

    if (parent != -1)
      printf("{%d}\t{%d}\n", vertex+1, parent+1);
    else
      printf("{%d}\t{%d}\n", vertex+1, parent);
  }
  remove(argv[0]);
  return EXIT_SUCCESS;
}