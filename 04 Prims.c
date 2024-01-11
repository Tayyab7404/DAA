#include<stdio.h>

#define INF 99999
#define n 7

int Prims(int graph[n+1][n+1]);
int LeastCostEdge(int graph[n+1][n+1], int MinEdge[2]);

int main()
{
    int graph[n+1][n+1] = {{0, 0,   0,   0,   0,   0,   0,   0},
                          {0, 0,   28,  INF, INF, INF, 10,  INF},
                          {0, 28,  0,   16,  INF, INF, INF, 14},
                          {0, INF, 16,  0,   12,  INF, INF, INF},
                          {0, INF, INF, 12,  0,   22,  INF, 18},
                          {0, INF, INF, INF, 22,  0,   25,  24},
                          {0, 10,  INF, INF, INF, 25,  0,   INF},
                          {0, INF, 14,  INF, 18,  24,  INF, 0}};

    int MinCostTree = Prims(graph);

    printf("The cost of the minimum spanning tree is: %d", MinCostTree);

    return 0;
}

int Prims(int graph[n+1][n+1])
{
    int MinEdge[2];
    int MinCost = LeastCostEdge(graph, MinEdge);

    

    return 0;   
}

int LeastCostEdge(int graph[n+1][n+1] int MinEdge[2])
{
    int min = INF;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(graph[i][j] != 0 && graph[i][j] < min)
            {
                min = graph[i][j];
                MinEdge[0] = i;
                MinEdge[1] = j;
            }
        }
    }

    return min;
}
