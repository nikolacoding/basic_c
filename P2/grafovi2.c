// Formiranje obuhvatnog stabla uz DFS

#include <stdio.h>
#define MAX 10

typedef struct graph{
    int n;
    char nodes[MAX];
    int ms[MAX][MAX];
} GRAF;

void dfs_visit_st(int u, GRAF *g, GRAF *st, int visited[]){
    visited[u] = 1;
    for (int v = 0; v < g->n; v++)
        if (g->ms[u][v] && !visited[v]){
            st->ms[u][v] = st->ms[v][u] = 1;
            dfs_visit_st(v, g, st, visited);
        }
}

void st_dfs(GRAF *g, GRAF *st){
    int visited[MAX] = {0};
    dfs_visit_st(0, g, st, visited);
}

void dfs_visit_out(int u, GRAF *g, int visited[]){
    visited[u] = 1;
    printf("%c ", g->nodes[u]);
    for (int v = 0; v < g->n; v++)
        if (g->ms[u][v] && !visited[v])
            dfs_visit_out(v, g, visited);
}

void dfs_out(GRAF *g){
    int visited[MAX] = {0};
    dfs_visit_out(0, g, visited);
}

int main(){
    GRAF g = {6, {'1', '2', '3', '4', '5', '6'}, // pocetni graf
        { // 0  1  2  3  4  5
          // 1  2  3  4  5  6
/* 1 */     {0, 1, 1, 1, 0, 0}, 
/* 2 */     {1, 0, 0, 1, 0, 0}, 
/* 3 */     {1, 0, 0, 1, 1, 0},
/* 4 */     {1, 1, 1, 0, 1, 0}, 
/* 5 */     {0, 0, 1, 1, 0, 1}, 
/* 6 */     {0, 0, 0, 0, 1, 0}
        }
    };

    GRAF st = {6, {'1', '2', '3', '4', '5', '6'}, {0}}; // graf kojem pisemo m.s. i pretvaramo ga u o.s. prvog grafa
    // m.s. -> matrica susjednosti
    // o.s. -> obuhvatno stablo
    st_dfs(&g, &st);
    dfs_out(&st);

    printf("\n\n\n");
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            printf("%d ", st.ms[i][j]);
        }
        printf("\n");
    }
}