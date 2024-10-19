// Primov algoritam - rekreacija

#include <stdio.h>
#include <limits.h>
#define MAX 10

typedef struct graph{
    int n;
    char nodes[MAX];
    int ms[MAX][MAX];
} GRAF;

int allVisited(int visited[], int n){
    for (int i = 0; i < n; i++)
        if (!visited[i]) return 0;
    return 1;
}

void mst_prim(GRAF *g, GRAF *mst){
    int visited[MAX] = {1};
    while (!allVisited(visited, g->n)){
        int w_min = INT_MAX, mu = -1, mv = -1;
        for (int u = 0; u < g->n; u++){
            for (int v = 0; v < g->n; v++){
                if (visited[u] && !visited[v] && g->ms[u][v])
                    if (g->ms[u][v] < w_min)
                        w_min = g->ms[u][v], mu = u, mv = v;
            }
        }
    
    if (mv > -1)
        visited[mv] = 1, mst->ms[mu][mv] = mst->ms[mv][mu] = w_min;
    }
}

int main(){
    GRAF g = {6, {'A', 'B', 'C', 'D', 'E', 'F'}, 
        {
            {0, 70, 50, 80, 0, 0},
            {70, 0, 0, 60, 0, 0},
            {50, 0, 0, 50, 20, 0},
            {80, 60, 50, 0, 20,0},
            {0, 0, 20, 20, 0, 30},
            {0, 0, 0, 0, 30, 0}
        }
    };
    GRAF MST = {6, {'A', 'B', 'C', 'D', 'E', 'F'}, {{0}}};
    mst_prim(&g, &MST);
    for (int i = 0; i < g.n; i++){
        for (int j = 0; j < g.n; j++)
            printf("%02d ", g.ms[i][j]);
        printf("\n");
    }
    printf("\n\n");
    for (int i = 0; i < MST.n; i++){
        for (int j = 0; j < MST.n; j++)
            printf("%02d ", MST.ms[i][j]);
        printf("\n");
    }
    return 0;
}