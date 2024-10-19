/*
*   Odabrati najadekvatniju strukturu za implementaciju undo akcije. Undo akcija podrazumijeva poništenje efekta 
*   prethodne akcije. Implementirati kreiranje akcije u vidu upisivanja cijelog broja u datu strukturu, dok 
*   poništavanje akcije odnosno undo podrazumijeva uklanjanje broja iz strukture. Maksimalan broj akcija nije 
*   unaprijed poznat. Predstaviti sadržaj strukture nakon izvršenja sljedećih akcija:
*   
*   > Dodavanje: 1
*   > Dodavanje: 2
*   > Undo
*   > Dodavanje: 3
*   > Undo
*   > Dodavanje: 5
*   > Dodavanje: 6
*   > Undo.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *next;
} node_t;

void push(node_t **tos, int info){
    node_t *new = malloc(sizeof(node_t));
    if (!new) return;

    new->next = NULL;
    new->info = info;
    
    if (!*tos) *tos = new;
    else{
        new->next = *tos;
        *tos = new;
    }
}

int pop(node_t **tos, int *info){
    if (!*tos) return 0;

    node_t *target = *tos;
    *info = target->info;
    *tos = target->next;
    free(target);
    return 1;
}

int main(void){

    node_t *tos = NULL;
    int last;

    push(&tos, 1);
    push(&tos, 2);
    pop(&tos, &last);
    push(&tos, 3);
    pop(&tos, &last);
    push(&tos, 5);
    push(&tos, 6);
    pop(&tos, &last);

    while (pop(&tos, &last))
        printf("%d ", last);

    return 0;
}