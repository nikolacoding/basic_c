/*
*   Napisati program koji pronalazi i ispisuje obuhvatno stablo zadatog grafa, obilaskom grafa po dubini (DFS) pri 
*   čemu je potrebno koristiti matričnu reprezentaciju grafa. Informacioni sadržaj čvora je znakovni podatak. Na 
*   standardni izlaz potrebno je ispisati matricu susjednosti grafa kao i matricu susjednosti obuhvatnog stabla.
*/

#include <stdio.h>
#define MAX 10

typedef struct graph{
    int n;
    char nodes[MAX];
    int ms[MAX][MAX];
} GRAF;

void ispisi_ms(GRAF *g){
    int n = g->n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", g->ms[i][j]);
        printf("\n");
    }
    printf("\n");
}

void dfs_visit(int u, GRAF *g, GRAF *st, int visited[]){
    visited[u] = 1;
    for (int v = 0; v < g->n; v++){
        if (g->ms[u][v] && !visited[v]){
            st->ms[u][v] = st->ms[v][u] = 1;
            dfs_visit(v, g, st, visited);
        }
    }
}

void st_dfs(GRAF *g, GRAF *st){
    int visited[MAX] = {0};
    dfs_visit(0, g, st, visited);
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
    GRAF st = {6, {'1', '2', '3', '4', '5', '6'}, {{0}} };
    st_dfs(&g, &st);

    printf("MS (originalni graf):\n");
    ispisi_ms(&g);

    printf("MS (obuhvatno stablo):\n");
    ispisi_ms(&st);

    return 0;
}