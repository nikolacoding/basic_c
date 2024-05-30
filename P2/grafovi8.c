/*
*   Napisati program u kojem treba sa standardnog ulaza učitati graf sa odgovarajućim vezama između čvorova, pri čemu 
*   je potrebno koristiti ulančanu reprezentaciju grafa. Graf se predstavlja pomoću vektora zaglavlja i odgovarajuće 
*   ulančane liste susjeda za svaki čvor grafa. Informacioni sadržaj čvora grafa je indeks vektora zaglavlja koji 
*   odgovara tom čvoru (uvećan za 1). Nakon toga realizovati funkciju koja obilazi graf po širini (BFS) i ispisuje 
*   rezultat na standardni izlaz. Dodatno, realizovati funkciju koja ispisuje sve susjedne čvorove zadatog čvora.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define nullptr NULL

typedef struct node{
    int info;
    struct node *next;
} node_t;

typedef struct graph{
    int n;
    node_t *nodes[MAX];
} graph_t;

typedef struct queue{
    int niz[MAX];
    int f, r;
} queue_t;

int is_full(queue_t *q) { return q->r == MAX; }
int is_empty(queue_t *q) { return q->f == -1 || q->f == q->r; }

int put(queue_t *q, int info){
    if (is_full(q)) return 0;
    if (q->f == -1) q->f = 0;
    q->niz[q->r++] = info;
    return 1;
}

int get(queue_t *q, int *info){
    if (is_empty(q)) return 0;
    *info = q->niz[q->f++];
    return 1;
}

void bfs(graph_t g, int start){
    queue_t queue; queue.f = -1; queue.r = 0;
    char visited[MAX] = {0};
    int v;
    visited[start] = 1;
    put(&queue, start);

    while (get(&queue, &v)){
        printf("%d ", v + 1);
        node_t *curr = g.nodes[v];
        while (curr){
            int u = curr->info;
            if (!visited[u]){
                visited[u] = 1;
                put(&queue, u);
            }
            curr = curr->next;
        }
    }
}

void pisi_susjede(node_t *head){
    while (head){
        printf(" %d", head->info + 1);
        head = head->next;
    }
}

node_t* dodaj_kraj(node_t **head_ptr, int info){
    node_t *p, *new = malloc(sizeof(node_t));
    new->info = info;
    new->next = nullptr;

    if (!*head_ptr) *head_ptr = new;
    else{
        for (p = *head_ptr; p->next; p = p->next );
        p->next = new;
    } 
    return new;
}

void delete_list(node_t **head_ptr){
    while (*head_ptr){
        node_t *p = (*head_ptr)->next;
        free(*head_ptr);
        *head_ptr = p;
    }
}

void delete_graph(graph_t *g){
    for (int i = 0; i < g->n; i++)
        delete_list(&g->nodes[i]);
}

void get_graph(graph_t *g){
    int n_adj, adj;
    printf("Unesi broj cvorova: "); scanf("%d", &g->n);
    for (int i = 0; i < g->n; i++){
        g->nodes[i] = nullptr;
        printf("Unesi broj susjeda cvora %d: ", i + 1); scanf("%d", &n_adj);
        for (int j = 0; j < n_adj; j++){
            do{
                printf("    %d. susjed cvora %d: ", j + 1, i + 1); 
                scanf("%d", &adj);
            } while (adj < 1 && adj > g->n);
            dodaj_kraj(&g->nodes[i], adj - 1);
        }
    }
}

int main(void){
    graph_t g;
    get_graph(&g);
    printf("Susjedi svih cvorova:\n");
    for (int i = 0; i < g.n; i++){
        printf("    %d: ", i + 1);
        pisi_susjede(g.nodes[i]); printf("\n");
    }
    printf("BFS: ");
    bfs(g, 0);
    delete_graph(&g);
    return 0;
}