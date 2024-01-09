#include<stdio.h>

#define n 4
#define INF 9999

void FloydWarshall(int graph[n][n]);

int main()
{
    int graph[n][n] = {{0, 3,   INF, 7},
                       {8, 0,   2,   INF},
                       {5, INF, 0,   1},
                       {2, INF, INF, 0}};

    FloydWarshall(graph);

    printf("Shortest distance between all pairs:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d\t", graph[i][j]);
        printf("\n");
    }

    return 0;
}

void FloydWarshall(int graph[n][n])
{
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
}