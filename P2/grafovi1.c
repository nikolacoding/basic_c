// Depth-first search

#include <stdio.h>
#define MAX 10

typedef struct graph{
    int n;
    char nodes[MAX];
    int ms[MAX][MAX];
} GRAF;

void dfs_visit(int u, GRAF *g, int visited[]){
    visited[u] = 1;
    printf("%c ", g->nodes[u]);
    for (int v = 0; v < g->n; v++)
        if (g->ms[u][v] && !visited[v]) 
            dfs_visit(v, g, visited);
}

void dfs(GRAF *g){
    int visited[MAX] = {0};
    dfs_visit(0, g, visited);
}

int main(void){
    GRAF g = {6, {'1', '2', '3', '4', '5', '6'},
    {
        {0, 1, 1, 1, 0, 0}, {1, 0, 0, 1, 0, 0}, {1, 0, 0, 1, 1, 0},
        {1, 1, 1, 0, 1, 0}, {0, 0, 1, 1, 0, 1}, {0, 0, 0, 0, 1, 0} 
    }};

    dfs(&g);
    return 0;
}