#include <stdio.h>

#define INF 999999

void Dijkstra(int cost[7][7], int *dist, int v, int n);

int main() {
  int cost[7][7] = {{0, 0, 0, 0, 0, 0},
                    {0, 0, 2, 4, INF, INF, INF},
                    {0, INF, 0, 1, 7, INF, INF},
                    {0, INF, INF, 0, INF, 3, INF},
                    {0, INF, INF, INF, 0, INF, 1},
                    {0, INF, INF, INF, 2, 0, 5},
                    {0, INF, INF, INF, INF, INF, 0}};

  int n = 6;
  int v;

  printf("Enter the source node: ");
  scanf("%d", &v);

  int dist[7];

  Dijkstra(cost, dist, v, n);

  printf("Distance to each node from %d: \n", v);
  for (int i = 1; i <= n; i++)
    printf("\tNode %d: %d\n", i, dist[i]);

  return 0;
}

void Dijkstra(int cost[7][7], int *dist, int v, int n) {
  int S[n + 1];
  dist[0] = INF;

  for (int i = 1; i <= n; i++) {
    S[i] = 0;
    dist[i] = cost[v][i];
  }

  S[v] = 1;
  dist[v] = 0;

  for (int num = 2; num < n; num++) {
    int u = 0;
    for (int i = 1; i <= n; i++) {
      if (dist[u] > dist[i] && i != v && S[i] == 0)
        u = i;
    }

    printf("Least distant node from %d: %d\n", v, u);

    S[u] = 1;

    for (int w = 1; w <= n; w++)
      if (dist[w] > dist[u] + cost[u][w] && !S[w] && cost[u][w] != INF &&
          w != u)
        dist[w] = dist[u] + cost[u][w];
  }
}