// Napisati funkciju koja ucitava N clanova ulancane liste sa info podatkom tipa char tako da podatak info:
// 1) se inkrementira za svaki naredni clan;
// 2) je unikatan svakom clanu.
// U glavnom programu demonstrirati upotrebu funkcije kreiranjem ulancane liste ciji info podaci redom
// formiraju engleski alfabet.

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char info;
    struct node *next;
} NODE;

int addNodes(NODE **head, int n, char info){
    NODE *tail;
    int i = 0;
    if (*head == NULL){
        *head = (NODE *)malloc(sizeof(NODE)); if (!*head) return 0;
        (*head)->info = info;
        i++;
    }
    (*head)->next = NULL;

    for (; i < n; i++){
        tail = (NODE *)malloc(sizeof(NODE));
        tail->next = NULL;
        tail->info = info + i;

        NODE *temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = tail;
    }
    
    return 1;
}

int main(void)
{
    NODE *lista = NULL;
    addNodes(&lista, 26, 'A');
    while (lista){
        printf("%c ", lista->info);
        lista = lista->next;
    }
    
    return 0;
}