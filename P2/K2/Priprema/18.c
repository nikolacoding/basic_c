/*
*   Dat je tip GRAPH koji predstavlja ulancanu reprezentaciju usmjerenog grafa kod kog liste susjednosti
*   ne moraju biti uredjene.
*   
*   Napisati funkciju koja određuje i vraća broj susjeda čvora indeksa u. Prototip: int broj_susjeda(GRAPH *g, int u);
*   
*   Napisati funkciju koja dodaje novu granu između čvorova čiji su indeksi u i v. Ako ta grana već postoji u grafu, 
*   ignorisati pokušaj dodavanja grane. Prototip funkcije je: void dodaj_granu(GRAPH *g, int u, int v);
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define MAX 10

typedef struct list_node{
    int info;
    struct list_node *next;
} NODE;

typedef struct{
    int n;
    NODE *nodes[MAX];
} GRAPH;

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

int broj_susjeda(GRAPH *g, int u){
    NODE *curr = g->nodes[u];
    int total = 0;

    curr = curr->next;
    while (curr){
        total++;
        curr = curr->next;
    }
    return total;
}

void plist(NODE *head){
    if (head){
        printf("%d ", head->info);
        plist(head->next);
    }
}

void dodaj_granu(GRAPH *g, int u, int v){
    int u_val = g->nodes[u]->info;
    int v_val = g->nodes[v]->info;

    NODE *check = g->nodes[u];
    while (check){
        if (check->info == v_val) return;
        check = check->next;
    }

    NODE *u_head = g->nodes[u];
    while (u_head->next) u_head = u_head->next;
    u_head->next = new_node(v_val);
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

    GRAPH g = {6, {l1, l2, l3, l4, l5, l6}};
    printf("Broj susjeda cvora indeksa %d: %d\n", 3, broj_susjeda(&g, 3));
    dodaj_granu(&g, 5, 3);
    plist(g.nodes[5]);

    return 0;
}