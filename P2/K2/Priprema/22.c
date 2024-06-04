/*
*   Neka je dat neusmjeren tezinski graf predstavljen matricom susjednosti informacionog sadrzaja tipa 'char'.
*       Ispisati matricu susjednosti:
*           1) njegovog originalnog oblika
*           2) njegovog minimalnog obuhvatnog stabla
*/

#include <stdio.h>
#include <limits.h>
#define MAX 10

typedef struct graph{
    int n;
    char nodes[MAX];
    int ms[MAX][MAX];
} graph_t;

void pisi_ms(graph_t *g){
    for (int i = 0; i < g->n; i++, printf("\n"))
        for (int j = 0; j < g->n; j++)
            printf("%d ", g->ms[i][j]);
    printf("\n\n");
}

int all_visited(int visited[], int n){
    for (int i = 0; i < n; i++)
        if (!visited[i]) return 0;
    return 1;
}

void get_mst(int start, graph_t *g, graph_t *mst){
    int visited[MAX] = {};
    if (start >= g->n) return;
    visited[start] = 1;
    while (!all_visited(visited, g->n)){
        int min = INT_MAX;
        int mu = -1, mv = -1;
        for (int u = 0; u < g->n; u++){
            for (int v = 0; v < g->n; v++){
                if (g->ms[u][v] && visited[u] && !visited[v] && g->ms[u][v] < min)
                    mu = u, mv = v, min = g->ms[u][v];
            }
        }

        if (mv > -1)
            mst->ms[mu][mv] = mst->ms[mv][mu] = min, visited[mv] = 1;
    }
}

/*
*       A   B   C   D   E   F
*   A       1   0   7   0   0
*   B   1       5   3   5   9
*   C   0   5       0   0   2
*   D   7   3   0       2   0
*   E   0   5   0   2       3
*   F   0   9   2   0   3
*   
*/

int main(void){

    graph_t g = {6, {'A', 'B', 'C', 'D', 'E', 'F'},
        {
            {0, 1, 0, 7, 0, 0},
            {1, 0, 5, 3, 5, 9},
            {0, 5, 0, 0, 0, 2},
            {7, 3, 0, 0, 2, 0},
            {0, 5, 0, 2, 0, 3},
            {0, 9, 2, 0, 3, 0}
        }
    };

    graph_t mst = {6, {'A', 'B', 'C', 'D', 'E', 'F'}, {{0}}};
    get_mst(0, &g, &mst);
    pisi_ms(&g); pisi_ms(&mst);

    return 0;
}