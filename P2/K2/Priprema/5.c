// Dat je tip 'NASTAVNIK' kojim se reprezentuje jedan nastavnik.
// Dat je tip 'PREDMET' kojim se reprezentuje jedan predmet pri cemu je 'niz' adresa pocetka niza nastavnika, a n
// broj elemenata tog niza. 
// Dat je tip 'NODE' kojim se reprezentuje cvor dvostruko povezane liste ciji je informacioni sadrzaj predmet.
// Napisati funkciju koja briše iz dvostruko povezane liste (parametri head i tail) sve čvorove koji ispunjavaju 
// određeni uslov. Čvorovi za brisanje ispunjavaju uslov ukoliko pokazivač na funkciju (parametar criteria) koji je 
// proslijeđen kao argument funkcije vraća vrijednost 1 za trenutni čvor. Prototip funkcije je:
// void delete(NODE **head, NODE **tail , int (*criteria)(NODE *n))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void printList(NODE *head){ // pomocna/test funkcija: rekurzivni ispis liste
    if (head){
        printf("%s ", head->predmet.naziv);
        printList(head->right);
    }
    else printf("\n");
}

int criteria(NODE *n){ // pomocna/test funkcija: da li zavrsava sa navedenim slovom
    const char letter = 'i';
    if (n->predmet.naziv[strlen(n->predmet.naziv) - 1] == letter) return 1;
    // ako neko ovo cita izvinjavam se al stvarno me smara da pisem citke pomocne funkcije u brzini
    return 0;
}

void delete(NODE **head, NODE **tail , int (*criteria)(NODE *n)){ // funkcija iz zadatka
    NODE *curr = *tail;

    while (curr){
        if ((*criteria)(curr)){
            NODE *target = curr;
            NODE *L = target->left;
            NODE *R = target->right;

            if (L) L->right = R;
            if (R) R->left = L;

            if (target == *tail) *tail = L;
            if (target == *head) *head = R;
            else curr = L;
            free(target);
        }
        else curr = curr->left;
    }
}

NODE* add_front(NODE **glava, PREDMET predmet) // pomocna/test funkcija: dodavanje elemanta na pocetak liste
{
    NODE *q = (NODE *) malloc(sizeof(NODE));
    if (q==NULL) return 0;
    q->predmet = predmet;
    if (*glava == NULL)
    {
        q->left = q->right = NULL;
        *glava = q;
    }
    else
    {
        q->right = *glava;
        q->left = NULL;
        (*glava)->left = q;
        *glava = q;
    }
    return q;
}


int main(void){
    NODE *head = NULL, *tail = NULL;

    NASTAVNIK *n1 = NULL;
    PREDMET p1 = {"Matematika", n1, 5};

    NASTAVNIK *n2 = NULL;
    PREDMET p2 = {"Srpski", n2, 5};

    NASTAVNIK *n3 = NULL;
    PREDMET p3 = {"Engleski", n3, 5};

    tail = add_front(&head, p1);
    add_front(&head, p2);
    add_front(&head, p3);

    printList(head);
    delete(&head, &tail, criteria);
    printList(head);
}