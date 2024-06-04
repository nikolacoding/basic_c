/*
*    Dat je neusmjeren graf predstavljen matricom susjednosti. Ispisati originalni oblik matrice susjednosti kao i
*    matricu susjednosti obuhvatnog stabla datog grafa. Informacioni sadrzaj stabla je jednoslovni podatak.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct graph{
    int n;
    char nodes[MAX];
    int ms[MAX][MAX];
} graph_t;

/*
    A   B   C   D   E   F
A       1   0   0   1   0
B   1       1   1   0   0
C   0   1       1   1   0
D   0   1   1       1   1
E   1   0   1   1       0
F   0   0   0   1   0

*/

void pisi_ms(graph_t *g){
    for (int i = 0; i < g->n; i++, printf("\n"))
        for (int j = 0; j < g->n; j++)
            printf("%d ", g->ms[i][j]);
    printf("\n\n");
}

void st_visit(int u, graph_t *g, graph_t *st, int visited[]){
    visited[u] = 1;
    for (int v = 0; v < g->n; v++){
        if (!visited[v] && g->ms[u][v]){
            st->ms[u][v] = st->ms[v][u] = 1;
            st_visit(v, g, st, visited);
        }
    }
}

void make_st(graph_t *g, graph_t *st){
    int visited[MAX] = {};
    st_visit(0, g, st, visited); // pocinjemo od indeksa 0 (cvor 'A')
}

int main(void){

    graph_t g = {6, {'A', 'B', 'C', 'D', 'E', 'F'},
        {
            {0, 1, 0, 0, 1, 0},
            {1, 0, 1, 1, 0, 0},
            {0, 1, 0, 1, 1, 0},
            {0, 1, 1, 0, 1, 1},
            {1, 0, 1, 1, 0, 0},
            {0, 0, 0, 1, 0, 0}
        }
    };

    graph_t st = {6, {'A', 'B', 'C', 'D', 'E', 'F'}, {{0}}};
    make_st(&g, &st);
    pisi_ms(&g);
    pisi_ms(&st);

    return 0;
}