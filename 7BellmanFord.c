#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* BellmanFord(int graph[][10], int v, int n);

int main()
{
    int n, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[][10] = {{0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 6, 5, 5, INT_MAX, INT_MAX, INT_MAX},
                       {0, INT_MAX, 0, INT_MAX, INT_MAX, -1, INT_MAX, INT_MAX},
                       {0, INT_MAX, -2, 0, INT_MAX, 1, INT_MAX, INT_MAX},
                       {0, INT_MAX, INT_MAX, -2, 0, INT_MAX, -1, INT_MAX},
                       {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 3},
                       {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 3},
                       {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}};
    
    printf("Enter the source node: ");
    scanf("%d", &v);

    int *dist = BellmanFord(graph, v, n);

    printf("Distance from %d to: \n", v);
    for (int i=1; i<=n; i++)
        printf("\t%d: %d\n", i, dist[i]);
}

int* BellmanFord(int graph[][10], int v, int n)
{
    int* dist = (int*)malloc((n+1)*sizeof(int));
    dist[0] = 0;
  
    for (int i=1; i<=n; i++)
        dist[i] = graph[v][i];

    for (int k=2; k<=n-1; k++)
        for (int i = 1; i <= n; i++)
            for (int u = 1; u <= n; u++)
                if ((u!=i && u!=v && graph[i][u]!=__INT_MAX__) && (dist[u] > dist[i]+graph[i][u]))
                    dist[u] = dist[i] + graph[i][u];
  
    return dist;
}