/*
*   Dat je neusmjeren graf informacionog podatka tipa 'char'. Obici graf po sirini (BFS) i ispisati cvorove.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct graph{
    int n;
    char nodes[MAX];
    int ms[MAX][MAX];
} graph_t;

typedef struct node{
    int info;
    struct node *next;
} node_t;

void enqueue(node_t **front, node_t **rear, int info){
    node_t *new = malloc(sizeof(node_t));
    if (!new) return;

    new->info = info;
    new->next = NULL;

    if (!*rear) *front = *rear = new;
    else{
        (*rear)->next = new;
        *rear = new;
    }
}

int dequeue(node_t **front, node_t **rear, int *info){
    if (!*front) return 0;

    node_t *target = *front;
    *info = target->info;
    
    if (*front == *rear) *front = *rear = NULL;
    else *front = target->next;
    free(target);
    return 1;
}

void bfs(int start, graph_t *g){
    if (start >= g->n) return;

    int visited[MAX] = {};
    node_t *front = NULL, *rear = NULL;
    enqueue(&front, &rear, start);
    visited[start] = 1;
    int u;

    while (dequeue(&front, &rear, &u)){
        printf("%c ", g->nodes[u]);
        for (int v = 0; v < g->n; v++)
            if (!visited[v] && g->ms[u][v])
            {
                enqueue(&front, &rear, v);
                visited[v] = 1;
            }
    }
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

    bfs(0, &g);
    return 0;
}