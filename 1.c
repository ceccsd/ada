#include <stdio.h>
#define MAX 10
#define INF 999

void kruskals(int n, int cost[MAX][MAX]) {
    int ne = 1, mincost = 0;
    int u, v, a, b, min;
    int parent[MAX];

    // Initialize parent array
    for (int i = 0; i < MAX; i++) {
        parent[i] = 0;
    }

    printf("\n\n********* Edges in the Minimum Spanning Tree *********\n");


    while (ne < n) {
        min = INF;
        a = b = -1;

        // Find the minimum cost edge (excluding 0-cost edges)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] != 0 && cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find the root of both vertices
        while (parent[u])
            u = parent[u];
        while (parent[v])
            v = parent[v];
        printf("%d, %d", u,v);

        // If they belong to different sets, include this edge in MST
        if (u != v) {
            printf("%d> Edge (%d, %d) with cost %d\n", ne++, a, b, min);
            mincost += min;
            parent[v] = u; // Union operation directly in loop
        }

        // Mark the edge as used
        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nThe minimum spanning tree cost is: %d\n", mincost);
}

int main() {
    int n, cost[MAX][MAX];

    printf("\n\n********* KRUSKAL'S ALGORITHM *********\n\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\nEntered cost matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    kruskals(n, cost);
    return 0;
}
