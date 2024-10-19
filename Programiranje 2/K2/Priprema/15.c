/*
*   Neka su dati tipovi 'NASTAVNIK', 'PREDMET' i 'NODE'.
*   
*   Napisati funkciju koja briše iz dvostruko povezane liste (parametri head i tail) sve čvorove koji ispunjavaju 
*   određeni uslov. Čvorovi za brisanje ispunjavaju uslov ukoliko pokazivač na funkciju (parametar criteria) koji 
*   je proslijeđen kao argument funkcije vraća vrijednost 1 za trenutni čvor. 
*   Prototip funkcije je: void delete(NODE **head, NODE **tail , int (*criteria)(NODE *n))
*   
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nastavnik{
    char *ime, *prezime;
} NASTAVNIK;

typedef struct predmet{
    char *naziv;
    NASTAVNIK *niz;
    int n;
} PREDMET;

typedef struct node{
    PREDMET predmet;
    struct node *left, *right;
} NODE;

void append_node(NODE **head, NODE **tail, PREDMET info){
    NODE *new = malloc(sizeof(NODE));
    new->predmet = info;
    
    if (!*tail) *head = *tail = new;
    else{
        (*tail)->right = new;
        new->left = *tail;
        *tail = new;
    }
}

void plist(NODE *head){
    while (head){
        printf("%s\n", head->predmet.naziv);
        head = head->right;
    }
}

int criteria(NODE *n){ return n->predmet.n > 2; }

void delete_one(NODE **head, NODE **tail, NODE *n){
    if (n->left && n->right){
        n->left->right = n->right;
        n->right->left = n->left;
    }
    else if (n->left){
        *tail = n->left;
        (*tail)->right = NULL;
    }
    else if (n->right){
        *head = n->right;
        (*head)->left = NULL;
    }

    free(n);
}

void delete(NODE **head, NODE **tail , int (*criteria)(NODE *n)){
    NODE *curr = *head;

    while (curr){
        if ((*criteria)(curr)){
            delete_one(head, tail, curr);
            curr = *head;
        }
        else curr = curr->right;
    }
}

int main(void){
    NODE *head = NULL, *tail = NULL;

    NASTAVNIK *empty = NULL;
    PREDMET p1 = {"Srpski jezik", empty, 5};
    PREDMET p2 = {"Matematika", empty, 2};
    PREDMET p3 = {"Engleski jezik", empty, 3};
    PREDMET p4 = {"Istorija", empty, 2};
    PREDMET p5 = {"Geografija", empty, 3};

    append_node(&head, &tail, p1);
    append_node(&head, &tail, p2);
    append_node(&head, &tail, p3);
    append_node(&head, &tail, p4);
    append_node(&head, &tail, p5);

    delete(&head, &tail, criteria);
    plist(head);

    return 0;
}