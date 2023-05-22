// Prim's Algorithm in C
#include<stdio.h>
#include<stdbool.h> 
#include<string.h>

#define INF 9999999

#define V 9
int G[V][V] = {
    {0  , 11 ,13,  INF, 2, INF, INF, INF },
    {11 , 0  ,15 , 8, 12, INF, 6, INF},
    {13 , 15 , 0  ,INF ,INF,INF ,INF},
    {INF, 8  ,INF, 0 ,14, INF, 10, 17},
    {2  , 12 ,INF ,14 ,0 ,INF ,INF ,5},
    {INF, INF, INF, INF, INF, 0, 21, 7},
    {INF, 6  ,INF, 10, INF, 21, 0 ,11},
    {INF, INF, INF ,17 ,5 ,7, 11 ,0 }
  };

int main() {
  int no_edge;

  int selected[V];

  memset(selected, false, sizeof(selected));
  
  no_edge = 0;
  selected[0] = true;

  int x;  
  int y;  
  printf("Edge : Weight\n");

  while (no_edge < V - 1) {
    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x+1, y+1, G[x][y]);
    selected[y] = true;
    no_edge++;
  }

  return 0;
}