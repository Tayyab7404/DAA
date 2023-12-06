#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

int Prims(int cost[8][8], int n);
int leastCostEdge(int cost[8][8], int n, int minEdge[2]);

int main() 
{
    int cost[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 28, INF, INF, INF, 10, INF},
                      {0, 28, 0, 16, INF, INF, INF, 14},
                      {0, INF, 16, 0, 12, INF, INF, INF},
                      {0, INF, INF, 12, 0, 22, INF, 18},
                      {0, INF, INF, INF, 22, 0, 25, 24},
                      {0, 10, INF, INF, INF, 25, 0, INF},
                      {0, INF, 14, INF, 18, 24, INF, 0}};

    int minCostTree = Prims(cost, 7);
    printf("The cost of the minimum spanning tree = %d\n", minCostTree);

    return 0;
}

int Prims(int cost[8][8], int n) 
{
    int minEdge[2];
    int minCost = leastCostEdge(cost, n, minEdge);

    int tree[n+1][2];

    tree[1][0] = minEdge[0];
    tree[1][1] = minEdge[1];

    int near[n+1];

    for (int i=1; i<=n; i++) 
    {
        if (cost[i][minEdge[0]] < cost[i][minEdge[1]])
            near[i] = minEdge[0];
        else
            near[i] = minEdge[1];
    }

    near[minEdge[0]] = near[minEdge[1]] = 0;

    for (int i=2; i<=n-1; i++) 
    {
        int j = 0;
        int minJ = INF;

        for (int x=1; x<=n; x++) 
        {
            if (near[x]!=0 && cost[x][near[x]]<minJ) 
            {
                j = x;
                minJ = cost[j][near[j]];
            }
        }

        tree[i][0] = j;
        tree[i][1] = near[j];
        minCost += cost[j][near[j]];
        near[j] = 0;

        for (int k=1; k<=n; k++) 
        {
            if ((near[k] != 0) && (cost[k][near[k]] > cost[k][j]))
                near[k] = j;
        }
    }

    printf("The minimum cost spanning tree is:\n");
    for (int i=1; i<n; i++) 
    {
        printf("\t%d to %d\n", tree[i][0], tree[i][1]);
    }

    return minCost;
}

int leastCostEdge(int cost[8][8], int n, int minEdge[2]) 
{
    int min = INF;

    for (int i=1; i<=n; i++) 
    {
        for (int j=1; j<=n; j++) 
        {
            if (cost[i][j]!=0 && cost[i][j]<min) 
            {
                min = cost[i][j];
                minEdge[0] = i;
                minEdge[1] = j;
            }
        }
    }

    return min;
}
