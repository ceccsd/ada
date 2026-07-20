#include<stdio.h>
void prims( );
int nearest[10], cost[10][10], t[10][2], i, j, n, k, min, u, mincost = 0;

int main( )
{
    printf("\n\n************** PRIMS ALGORITHM **************\n\n");
    printf("Enter the number of nodes\n");
    scanf("%d", &n);

    printf("\n\nEnter the cost matrix\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &cost[i][j]);

    printf("\n\nThe entered cost matrix is\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            printf("%d\t", cost[i][j]);
        printf("\n");
    }

    printf("\n\nMinimum Spanning Tree Edges and their costs are\n");
    prims( );

    printf("\n\nThe minimum spanning tree cost is %d", mincost);
    printf("\n\n******* ******************************** *******\n");
    return 0;
}

void prims()
{
    for(i=2; i<=n; i++)
        nearest[i]=1;     
    nearest[1]=0;           

    for(i=1; i<n; i++)
    {
        min=99;
        for(j=1; j<=n; j++) 
        {
            if(nearest[j]!=0 && cost[j][nearest[j]]<min)
            {
                min=cost[j][nearest[j]];
                u=j;
            }
        }

        t[i][1] = u;              
        t[i][2] = nearest[u];     
        mincost += min;           
        nearest[u] = 0;           


        for(k=1; k<=n; k++)
        {
            if(nearest[k] != 0 && cost[k][nearest[k]] > cost[k][u])
                nearest[k] = u;
        }

        printf("%d) edge (%d,%d) , cost %d\n", i, t[i][1], t[i][2], min);
    }
}
