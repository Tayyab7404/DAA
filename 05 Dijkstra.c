#include<stdio.h>

#define INF 99999

void Dijkstra(int cost[][], int n, int dist[], int v);

int main()
{
    int n=6;
    int cost[n+1][n+1] = {{0, 0,   0,   0,   0,   0,   0},
                          {0, 0,   2,   4,   INF, INF, INF},
                          {0, INF, 0,   1,   7,   INF, INF},
                          {0, INF, INF, 0,   INF, 3,   INF},
                          {0, INF, INF, INF, 0,   INF, 1},
                          {0, INF, INF, INF, 2,   0,   5},
                          {0, INF, INF, INF, INF, INF, 0}};

    int v;
    printf("Enter the source node: ");
    scanf(" %d", &v);

    int dist[n+1];

    Dijkstra(cost, n, dist, v);

    printf("Distance to each node from Node %d:\n");
    for(int i=1; i<=n; i++)
        printf("Node %d: %d\n", i, dist[i]);
}

void Dijkstra(int cost[][], int n, int dist[], int v)
{

}