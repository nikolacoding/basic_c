// Breatdh-first search

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct graph{
    int n;
    char nodes[MAX];
    int ms[MAX][MAX];
} GRAF;

typedef struct node{
    int v;
    struct node *next;
} NODE;

void enqueue(NODE **f, NODE **r, int info){
    NODE *new = malloc(sizeof(NODE));
    if (!new) return;
    new->v = info;
    new->next = NULL;

    if (!*r) *f = *r = new;
    else{
        (*r)->next = new;
        *r = new;
    }
}

int dequeue(NODE **f, NODE **r, int *info){
    if (!*f) return 0;

    NODE *ret = *f;
    *info = ret->v;
    if (*f == *r) *f = *r = NULL;
    else *f = ret->next;
    free(ret);

    return 1;
}

void bfs(GRAF *g, int pocetni){
    // kreiramo i inicijalizujemo na
    // nulu pomocni niz posjecenosti
    int visited[MAX] = {};

    // inicijalizujemo red
    NODE *front = NULL, *rear = NULL;
    // dodajemo prvi cvor u red
    enqueue(&front, &rear, pocetni);
    visited[pocetni] = 1;
    // promjenljiva koja hvata obrisane
    // elemente niza
    int u;

    // algoritam radi dok red nije prazan
    while (dequeue(&front, &rear, &u)){
        // obradjujemo ga (u ovom slucaju ispisujemo)
        printf("%c ", g->nodes[u]);
        // dodajemo sve neposjecene susjede u red
        for (int v = 0; v < g->n; v++)
            if (g->ms[u][v] && !visited[v]){
                visited[v] = 1;
                enqueue(&front, &rear, v);
            }
        // ponavljamo
    }
}

int main(void){
    // graf iz primjera iznad
    GRAF g = {6, {'A', 'B', 'C', 'D', 'E', 'F'},
    {
        {0, 1, 1, 1, 0, 0}, 
        {1, 0, 0, 1, 0, 0}, 
        {1, 0, 0, 1, 1, 0},
        {1, 1, 1, 0, 1, 0}, 
        {0, 0, 1, 1, 0, 1}, 
        {0, 0, 0, 0, 1, 0} 
    }};

    bfs(&g, 0);
    return 0;
}