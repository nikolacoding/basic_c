/*
*   Data su dva tipa neusmjerenog grafa koja se razlikuju po nacinu reprezentacije u kodu:
*       am_graph_t - graf reprezentovan matricom susjednosti
*       al_graph_t - graf reprezentovan nizom ulancanih listi
*   
*   Formirati dva identicna grafa sa najmanje 6 cvorova (informacionog sadrzaja tipa char) - jednom matricnom,
*   drugi put ulancanom reprezentacijom, te napisati funkcije koje ove grafove obilaze
*       1) po dubini (DFS) (am)
*       2) po sirini (BFS) (al)
*   i ispisuju njihov sadrzaj pri respektivnim obilascima.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define MAX 10

typedef struct adjacency_matrix_graph{
    int n;
    char nodes[MAX];
    int am[MAX][MAX];
} am_graph_t;

typedef struct list_node{
    char info;
    struct list_node *next;
} lnode_t;

typedef struct adjacency_list_graph{
    int n;
    lnode_t *nodes[MAX];
} al_graph_t;

// typedef struct queue_node nedovrseno

void init(void *ptr, int n, ...){
    va_list args; va_start(args, n);
    for (int i = 0; i < n; i++)
        *va_arg(args, lnode_t **) = ptr;
    va_end(args);
}

void append_node(lnode_t **head, char info){
    lnode_t *new = malloc(sizeof(lnode_t));
    if (!new) return;

    new->info = info;
    new->next = NULL;
    if (!*head) *head = new;
    else{
        lnode_t *curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = new;
    }
}

void make_list(lnode_t **head, int n, ...){
    va_list args; va_start(args, n);
    for (int i = 0; i < n; i++)
        append_node(head, va_arg(args, int));
    va_end(args);
}

void am_dfs_visit(int u, am_graph_t *graph, int visited[]){
    visited[u] = 1;
    printf("%c ", graph->nodes[u]);
    for (int v = 0; v < graph->n; v++)
        if (graph->am[u][v] && !visited[v])
            am_dfs_visit(v, graph, visited);
}

void am_dfs(am_graph_t *graph){
    int visited[MAX] = {};
    am_dfs_visit(0, graph, visited);
}

void am_bfs(am_graph_t *graph){

}

int main(void){
    /*
        A   B   C   D   E   F
    A       1   0   1   0   0
    B   1       1   0   0   0
    C   0   1       1   1   0
    D   1   0   1       0   1
    E   0   0   1   0       0
    F   0   0   0   1   0   
    */
    const int n_nodes = 6;

    am_graph_t am_graph = {n_nodes, {'A', 'B', 'C', 'D', 'E', 'F'},{
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0},
        {1, 0, 1, 0, 0, 1},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0}
    }};

    lnode_t *l0, *l1, *l2, *l3, *l4, *l5;
    init(NULL, n_nodes, &l0, &l1, &l2, &l3, &l4, &l5);
    make_list(&l0, 3, 'A', 'B', 'D');
    make_list(&l1, 3, 'B', 'A', 'C');
    make_list(&l2, 4, 'C', 'B', 'D', 'E');
    make_list(&l3, 4, 'D', 'A', 'C', 'F');
    make_list(&l4, 2, 'E', 'C');
    make_list(&l5, 2, 'F', 'D');

    am_dfs(&am_graph);

    al_graph_t al_graph = {n_nodes, {l0, l1, l2, l3, l4, l5}};

    return 0;
}