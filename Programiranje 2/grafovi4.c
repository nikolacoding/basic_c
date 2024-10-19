/*
*   Napisati program koji omogućava obilazak grafa po dubini (DFS) pri čemu je potrebno ispisivati informacioni sadržaj 
*   čvorova grafa. Potrebno je koristiti matričnu reprezentaciju grafa. Informacioni sadržaj čvora je znakovni podatak. 
*   Dodatno, realizovati funkciju koja ispisuje matricu susjednosti grafa.
*/

#include <stdio.h>
#define MAX 10

typedef struct graph{
    int n;
    char nodes[MAX];
    int ms[MAX][MAX];
} GRAF;

void dfs_visit(int u, GRAF *g, int visited[]){
    printf("%c ", g->nodes[u]);
    visited[u] = 1;

    for (int v = 0; v < g->n; v++){
        if (g->ms[u][v] && !visited[v])
            dfs_visit(v, g, visited);
    }
}

void dfs(GRAF *g){
    int visited[MAX] = {0};
    dfs_visit(0, g, visited);
}

void ispisi_ms(GRAF *g, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            printf("%d ", g->ms[i][j]);
        printf("\n");
    }
}

int main(void){
    GRAF g = { 6, { '1', '2', '3', '4', '5', '6' },
        {
            { 0, 1, 1, 1, 0, 0 }, 
            { 1, 0, 0, 1, 0, 0 }, 
            { 1, 0, 0, 1, 1, 0 }, 
            { 1, 1, 1, 0, 1, 0 }, 
            { 0, 0, 1, 1, 0, 1 }, 
            { 0, 0, 0, 0, 1, 0 } 
        } 
    };
    dfs(&g);
    printf("\n\n");
    ispisi_ms(&g, g.n, g.n);
    return 0;
}