/*
*      Pokusaj da kreiram graf sa ulancanom reprezentacijom i obidjem ga DFS-om i BFS-om na svoju ruku.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define MAX 10

typedef struct list_node{
    int info;
    struct list_node *next;
} NODE;

typedef struct queue_node{
    NODE *info;
    struct queue_node *next;
} qnode_t;

typedef struct{
    int n;
    NODE *nodes[MAX];
} graph_t;

void enqueue(qnode_t **front, qnode_t **rear, NODE *info){
    qnode_t *new = malloc(sizeof(qnode_t));
    if (!new) return;

    new->info = info;
    new->next = NULL;
    if (!*rear) *front = *rear = new;
    else{
        (*rear)->next = new;
        *rear = new;
    }
}

int dequeue(qnode_t **front, qnode_t **rear, NODE **info){
    if (!*front) return 0;

    qnode_t *target = *front;
    if (!target) return 0;
    *info = target->info;

    if (*front == *rear) *front = *rear = NULL;
    else *front = target->next;
    free(target);
    return 1;
}

void init(void *ptr, int n, ...){
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++)
        *va_arg(args, NODE **) = ptr;
    va_end(args);
}

NODE* new_node(int info){
    NODE *new = malloc(sizeof(NODE));
    if (!new) return NULL;

    new->info = info;
    new->next = NULL;
    return new;
}

void append_node(NODE **head, int info){
    if (!*head) *head = new_node(info);
    else{
        NODE *curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = new_node(info);
    }
}

void set_list(NODE **head, int n, ...){ 
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++)
        append_node(head, va_arg(args, int));
    va_end(args);
}

int are_linked(NODE *start, NODE *key){ // provjera da li su dva cvora spojena
    while (start){
        if (start->info == key->info)
            return 1;
        start = start->next;
    }
    return 0;
}

void dfs_visit(int u, graph_t *g, int visited[]){
    visited[u] = 1;
    printf("%d ", g->nodes[u]->info);
    for (int v = 0; v < g->n; v++)
        if (!visited[v] && are_linked(g->nodes[u], g->nodes[v])) 
            dfs_visit(v, g, visited);
}

void dfs(graph_t *g){
    int visited[MAX] = {0};
    dfs_visit(0, g, visited); // pocinjemo sa prvim cvorom (cvor '1')
    printf("\n");
}

void bfs(graph_t *g, qnode_t **front, qnode_t **rear, int start){
    int visited[MAX] = {0};
    
    visited[start] = 1;
    enqueue(front, rear, g->nodes[start]);
    NODE *curr;
    while (dequeue(front, rear, &curr)){
        printf("%d ", curr->info);
        for (int v = 0; v < g->n; v++)
            if (!visited[v] && are_linked(curr, g->nodes[v]))
                enqueue(front, rear, g->nodes[v]), visited[v] = 1;
    }
}

int main(void){

    NODE *l1, *l2, *l3, *l4, *l5, *l6;
    init(NULL, 6, &l1, &l2, &l3, &l4, &l5, &l6); // inicijalizujemo svaki pokazivac na NULL

    set_list(&l1, 3, 1, 2, 6); // [1] -> 2 -> 6
    set_list(&l2, 3, 2, 3, 5); // [2] -> 3 -> 5
    set_list(&l3, 3, 3, 2, 4); // [3] -> 2 -> 4
    set_list(&l4, 2, 4, 3); // [4] -> 3
    set_list(&l5, 4, 5, 2, 6); // [5] -> 2 -> 6
    set_list(&l6, 3, 6, 1, 5); // [6] -> 1 -> 5

    /*
        1 - 2 - - - - - - - 5
         \   \             /     
          \    3 - - 4    /  
           \             /   
            6 - - - - - -
    */

    graph_t graph = {6, {l1, l2, l3, l4, l5, l6}};
    qnode_t *front = NULL, *rear = NULL;
    dfs(&graph);
    bfs(&graph, &front, &rear, 0); // BFS pocev od cvora '1'
    return 0;
}