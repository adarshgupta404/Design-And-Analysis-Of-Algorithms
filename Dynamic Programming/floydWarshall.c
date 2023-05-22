// Floyd-Warshall Algorithm in C
#include <stdio.h>

// defining the number of vertices
#define nV 8

#define INF 999

void printMatrix(int matrix[][nV]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV]) {
  int matrix[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  
  int graph[nV][nV] = {
    {0  , 11 ,13,  INF, 2, INF, INF, INF },
    {11 , 0  ,15 , 8, 12, INF, 6, INF},
    {13 , 15 , 0  ,INF, INF ,INF,INF ,INF},
    {INF, 8  ,INF, 0 ,14, INF, 10, 17},
    {2  , 12 ,INF ,14 ,0 ,INF ,INF ,5},
    {INF, INF, INF, INF, INF, 0, 21, 7},
    {INF, 6  ,INF, 10, INF, 21, 0 ,11},
    {INF, INF, INF ,17 ,5 ,7, 11 ,0 }
  };
  
  floydWarshall(graph);
}
