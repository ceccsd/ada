#include <stdio.h>

#define MAX 10
#define INF 999

void prims(int n, int cost[MAX][MAX])
{
    int mincost = 0;
    int i, j, k, u, min;
    int nearest[MAX];

    for(i = 2; i <= n; i++)
        nearest[i] = 1;
         nearest[1] = 0;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    for(i = 1; i < n; i++)
    {
        min = INF;

        for(j = 2; j <= n; j++)
        {
            if(nearest[j] != 0 && cost[j][nearest[j]] < min)
            {
                min = cost[j][nearest[j]];
                u = j;
            }
        }

        printf("%d> Edge (%d, %d) Cost = %d\n", i, u, nearest[u], min);

        mincost += min;
        nearest[u] = 0;

        for(k = 2; k <= n; k++)
        {
            if(nearest[k] != 0 && cost[k][nearest[k]] > cost[k][u])
                nearest[k] = u;
        }
    }

    printf("\nMinimum Cost = %d\n", mincost);
}

int main()
{
    int n, cost[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    prims(n, cost);

    return 0;
}
