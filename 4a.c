#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void dij(int n,int cost[MAX][MAX],int s,int dist[MAX]){
     int count = 0;
    int i,j,v,min;
    int visted[MAX];
    
    for(i = 1;i<=n;i++){
        visted[i]= 0;
        dist[i] = cost[s][i];
    }

    visted[s] = 1;
    dist[s] = 0;

    while(count < n){
        min = 999;
    for(i = 1;i <=n;i++)
      {
    if( visted[i] == 0 && dist[i] < min ){
        min = dist[i];
        v = i;    
    }
}
visted[v] = 1;
count++;


for(i = 1;i <=n ;i++){
    if(dist[i] > dist[v] + cost[v][i])
    dist[i] = dist[v] + cost[v][i];
}

}    
}


void main(){
    int n, cost[MAX][MAX],s,dist[MAX];
    printf("enter the number of nodes:");
    scanf("%d",&n);

    printf("enter the adjacency matrix:\n");
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(i != j && cost[i][j] == 0)
            cost[i][j] = 999;
        }
    }

    printf("enter the source vertex:");
    scanf("%d",&s);


    dij(n,cost,s,dist);

    printf("the shortest distance from %d:\n",&s);
    for(int i = 1;i <= n;i++){
        if(s!=i){
            printf("%d -> %d = %d\n",s,i,dist[i]);
        }
    }

}
