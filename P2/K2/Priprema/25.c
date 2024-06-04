/*
*    Primjeniti Primov algoritam na zadati tezinski neusmjereni graf reprezentovan matricom susjednosti. Ispisati 
*    matricu susjednosti inicijalnog grafa, te formiranog MST-a. Informacioni sadrzaj cvorova grafa je podatak tipa 
*    char.
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

void mst_prim(graph_t *g, graph_t *mst){
    int visited[MAX] = {1}; // pocinjemo od indeksa 0
    while (!all_visited(visited, g->n)){
        int min = INT_MAX;
        int mu = -1, mv = -1;
        
        for (int u = 0; u < g->n; u++)
            for (int v = 0; v < g->n; v++)
                if (g->ms[u][v] && g->ms[u][v] < min && visited[u] && !visited[v])
                    mu = u, mv = v, min = g->ms[u][v];

        if (mv > -1){
            mst->ms[mu][mv] = mst->ms[mv][mu] = min;
            visited[mv] = 1;
        }
    }
}

int main(void){

    /*
        A   B   C   D   E   F   G
    A       1   0   0   0   0   0
    B   1       3   6   0   0   0
    C   0   3       1   6   0   0
    D   0   6   1       2   0   0
    E   0   0   6   2       8   1
    F   0   0   0   0   8       2
    G   0   0   0   0   1   2   
    */

    graph_t graph = {7, {'A', 'B', 'C', 'D', 'E', 'F', 'G'}, {
        {0, 1, 0, 0, 0, 0, 0},
        {1, 0, 3, 6, 0, 0, 0},
        {0, 3, 0, 1, 6, 0, 0},
        {0, 6, 1, 0, 2, 0, 0},
        {0, 0, 0, 0, 8, 0, 1},
        {0, 0, 0, 0, 8, 0, 2},
        {0, 0, 0, 0, 1, 2, 0}
    }};

    graph_t mst = {7, {'A', 'B', 'C', 'D', 'E', 'F', 'G'}, {{}}};
    mst_prim(&graph, &mst);
    pisi_ms(&graph); pisi_ms(&mst);
    return 0;
}