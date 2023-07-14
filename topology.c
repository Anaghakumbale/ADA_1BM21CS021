#include<stdio.h>
#include<stdlib.h>
 
int s[100], j, res[100]; 
 
void dfs(int u, int n, int a[][100]) {
 
    int v;
    s[u] = 1;
    for (v = 0; v < n - 1; v++) {
        if (a[u][v] == 1 && s[v] == 0) {
            dfs(v, n, a);
        }
    }
    j += 1;
    res[j] = u;
}
 
void topological(int n, int a[][100]) { 
 
    int i, u;
    for (i = 0; i < n; i++) {
        s[i] = 0;
    }
    j = 0;
    for (u = 0; u < n; u++) {
        if (s[u] == 0) {
            dfs(u, n, a);
        }
    }
    return;
}
int main() {
    int a[100][100], n, i, j;
 
    printf("Enter number of vertices\n");
    scanf("%d", &n);
    printf("enter the graph in terms of adjacency matrix\n");
    for(int k=0;k<n;k++){
        for(int l=0;l<n;l++){
            scanf("%d",&a[k][l]);
        }
    }
 
    topological(n, a);
 
    for (i = n; i >= 1; i--) {
        printf("%d ", res[i]);
    }
    return 0;
}