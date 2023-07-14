#include<stdio.h>
#include<stdlib.h>
 
int visited[50] = {0};
int A[50][50];
int n;
void DFS(int root){
    printf("%d ", root);
    visited[root] = 1;
    for (int j = 0; j < n; j++)
    {
        if(A[root][j]==1 && !visited[j]){
            DFS(j);
        }
    }
}
 
int main(){ 
    int root;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    printf("enter the graph in terms of adjacency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("enter the root node\n");
    scanf("%d",&root);
    DFS(root); 
    return 0;
}
