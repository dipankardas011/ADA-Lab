#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void flordWarshell(int Graph[][4], int V)
{

  int **dist = (int **)malloc(sizeof(int *) * V);
  int **path = (int **)malloc(sizeof(int *) * V);

  for (int i = 0; i < V; i++) {
    dist[i] = (int *)malloc(sizeof(int) * V);
    path[i] = (int *)malloc(sizeof(int) * V);
  }

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      dist[i][j] = Graph[i][j];
      path[i][j] = 0;
    }
  }


  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        int t = dist[i][k] + dist[k][j];
        if (dist[i][k] != INT_MAX &&
            dist[k][j] != INT_MAX && t < dist[i][j]) {
          dist[i][j] = t;
          path[i][j] = k;
        }
      }
    }
  }

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++)
      printf("\t%d(%d)", dist[i][j], path[i][j]);
    printf("\n");
  }

}

int main(int argc, char **argv)
{
  int v = 4;
  int graph[4][4] = {
      {0, 5, INT_MAX, 10},
      {INT_MAX, 0, 3, INT_MAX},
      {INT_MAX, INT_MAX, 0, 1},
      {INT_MAX, INT_MAX, INT_MAX, 0},
  };
  flordWarshell(graph, v);
  remove(argv[0]);
  return EXIT_SUCCESS;
}
