#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void FloydWarshall(int **graph, int n);

int main() 
{
    int n, x;
  
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
  
    int **graph = (int **)malloc((n+1) * sizeof(int *));
    graph[0] = (int *)malloc((n+1) * sizeof(int));
    
    for (int i=0; i<=n; i++)
        graph[0][i] = 0;
  
    printf("Enter the costs of edges: \n");
    for (int i=1; i<=n; i++) 
    {
        graph[i] = (int *)malloc((n + 1) * sizeof(int));
        printf("Node %d: ", i);
        graph[i][0] = 0;
        for (int j=1; j<=n; j++) 
        {
            scanf("%d", &x);
            if (x == -1)
                graph[i][j] = INT_MAX;
            else
                graph[i][j] = x;
        }
    }
  
    printf("The graph is: \n");
    for(int i=1; i<=n; i++) 
    {
        for(int j=1; j<=n; j++) 
        {
          if (graph[i][j] == INT_MAX)
              printf("INF\t");
          else
              printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
  
    FloydWarshall(graph, n);
  
    printf("The shortest path between all pairs: \n");
    for(int i=1; i<=n; i++) 
    {
        for(int j=1; j<=n; j++)
            printf("%d\t", graph[i][j]);
        printf("\n");
    }
  
    return 0;
}

void FloydWarshall(int **graph, int n) 
{
    for (int k = 1; k <= n; k++) 
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                if ((graph[i][k]+graph[k][j]) < graph[i][j] && (graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX))
                    graph[i][j] = graph[i][k] + graph[k][j];
}