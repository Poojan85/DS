#include<stdio.h>
#define MAX 30

int graph[MAX][MAX],visited[MAX],n,count=0;

void DFS(int v){
    visited[v]=1;
    printf("%d ",v);
    count++;
    for(int i=0;i<n;i++){
        if(graph[v][i]==1 && !visited[i])
            DFS(i);
    }
}

int main(){
    int start;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    printf("Enter adjacency matrix :\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    
    for(int i=0;i<n;i++)
        visited[i]=0;
    printf("Enter starting vertex : ");
    scanf("%d",&start);
    printf("DFS Traversal : ");
    DFS(start);
    if(count==n)
        printf("\nGraph is connected");
    else
        printf("\nGraph is not connected");
    return 0;
}