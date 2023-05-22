// Dijkstra's Algorithm in C
#include <stdio.h>
#define INFINITY 99
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start);

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 1; i <= n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count <= n - 1) {
    mindistance = INFINITY;

    for (i = 1; i <= n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 1; i <= n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
  for (i = 1; i <= n; i++)
    if (i != start) {
      printf("\nDistance from source(%d) to %d: %d",start, i, distance[i]);
    }
}
int main() {
  int Graph[MAX][MAX], i, j, n, u;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  printf("\nEnter the connections: \n");
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
        scanf("%d", &Graph[i][j]);
    }
  }
  u = 1;
  Dijkstra(Graph, n, u);
  return 0;
}