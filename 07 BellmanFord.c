#include<stdio.h>
#include<stdlib.h>

#define n 7
#define INF 9999

int* BellmanFord(int graph[n+1][n+1], int v);

int main()
{
    int graph[n+1][n+1] = {{0, 0,   0,   0,   0,   0,   0,   0},
                           {0, 0,   6,   5,   5,   INF, INF, INF},
                           {0, INF, 0,   INF, INF, -1,  INF, INF},
                           {0, INF, -2,  0,   INF, 1,   INF, INF},
                           {0, INF, INF, -2,  0,   INF, -1,  INF},
                           {0, INF, INF, INF, INF, 0,   INF, 3},
                           {0, INF, INF, INF, INF, INF, 0,   3},
                           {0, INF, INF, INF, INF, INF, INF, 0}};

    int v;
    printf("Enter the source vertex: ");
    scanf(" %d", &v);
    
    int *dist = BellmanFord(graph, v);

    printf("Distance from vertex %d to:\n", v);
    for(int i=1; i<=n; i++)
        printf("%d: %d\n", i, dist[i]);
    printf("\n");

    return 0;
}

int* BellmanFord(int graph[n+1][n+1], int v)
{
    int* dist = (int*)malloc((n+1) * sizeof(int));
    dist[0] = 0;
    for(int i=1; i<=n; i++)
        dist[i] = graph[v][i];

    for(int k=2; k<=n-1; k++)
        for(int i=1; i<=n; i++)
            for(int u=1; u<=n; u++)
                if((u != i && u != v && graph[i][u] != INF) && (dist[u] > dist[i] + graph[i][u]))
                    dist[u] = dist[i] + graph[i][u];

    return dist;
}