// Depth-first search

#include <stdio.h>
#define MAX 10

typedef struct graph{
    int n;
    char nodes[MAX];
    int ms[MAX][MAX];
} GRAF;

void dfs_visit(int u, GRAF *g, int visited[]){
    // oznacavamo trenutni cvor kao posjecen
    visited[u] = 1;
    // obradjujemo ga (u ovom slucaju ispisujemo)
    printf("%c ", g->nodes[u]);
    // prolazimo svako moguce susjedstvo trenutnog
    // cvora sa svim ostalima
    for (int v = 0; v < g->n; v++)
        // ukoliko smo pronasli vezu i
        // taj susjedni cvor nije vec posjecen
        // rekurzivno pozivamo da se posjeti
        // ovom istom funkcijom
        if (g->ms[u][v] && !visited[v]) 
            dfs_visit(v, g, visited);
}

void dfs(GRAF *g){
    // kreiramo i inicijalizujemo na
    // nulu pomocni niz posjecenosti
    int visited[MAX] = {};

    // pozivamo glavnu funkciju
    // sa pocetnim cvorom indeksa 0
    dfs_visit(0, g, visited);
}

int main(void){
    // graf iz primjera iznad
    GRAF g = {6, {'1', '2', '3', '4', '5', '6'},
    {
        {0, 1, 1, 1, 0, 0}, 
        {1, 0, 0, 1, 0, 0}, 
        {1, 0, 0, 1, 1, 0},
        {1, 1, 1, 0, 1, 0}, 
        {0, 0, 1, 1, 0, 1}, 
        {0, 0, 0, 0, 1, 0} 
    }};

    dfs(&g);
    return 0;
}