#include<stdio.h>

#define INF 99999

int Prims(int cost[][], int n);
int LeastCostEdge(int cost[][], int n, int MinEdge[]);

int main()
{
    int n=8;
    int cost[n][n] = {{0, 0,   0,   0,   0,   0,   0,   0},
                      {0, 0,   28,  INF, INF, INF, 10,  INF},
                      {0, 28,  0,   16,  INF, INF, INF, 14},
                      {0, INF, 16,  0,   12,  INF, INF, INF},
                      {0, INF, INF, 12,  0,   22,  INF, 18},
                      {0, INF, INF, INF, 22,  0,   25,  24},
                      {0, 10,  INF, INF, INF, 25,  0,   INF},
                      {0, INF, 14,  INF, 18,  24,  INF, 0}};

    int MinCostTree = Prims(cost, n);

    printf("The cost of the minimum spanning tree is: %d", MinCostTree);

    return 0;
}

int Prims(int cost[][], int n)
{
    int MinEdge[2];
    int MinCost = LeastCostEdge(cost, n, MinEdge);

    

    return 0;   
}

int LeastCostEdge(int cost[][], int n, int MinEdge[])
{
    int min = INF;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(cost[i][j] != 0 && cost[i][j] < min)
            {
                min = cost[i][j];
                MinEdge[0] = i;
                MinEdge[1] = j;
            }
        }
    }

    return min;
}