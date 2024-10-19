/*
*   Dati su dolenavedeni tipovi. Napisati funkciju koja brise svaki cvor j.u. liste ciji inf. podatak student
*   posjeduje broj indeksa koji se nalazi u **indeksi.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct predmet{
    char *sifra, *naziv;
} PREDMET;

typedef struct student{
    char *br_indeksa, *ime, *prezime;
    PREDMET *niz;
    int n;
} STUDENT;

typedef struct cvor{
    STUDENT s;
    struct cvor *sljedeci;
} CVOR;

void delete_one(CVOR **glava, CVOR *target){
    CVOR *curr = *glava, *prev = NULL;

    while (curr != target) prev = curr, curr = curr->sljedeci;

    if (!prev) *glava = target->sljedeci;
    else prev->sljedeci = target->sljedeci;
}

int contains(char **ind, int n, char *key){
    for (int i = 0; i < n; i++)
        if (!strcmp(ind[i], key)) return 1;
    
    return 0;
}

void obrisi(char **indeksi, int n, CVOR **glava){
    CVOR *curr = *glava;
    while (curr){
        if (contains(indeksi, n, curr->s.br_indeksa)){
            delete_one(glava, curr);
            curr = *glava;
        } else curr = curr->sljedeci;
    }
}

void plist(CVOR *head){
    while (head) printf("%s\n", head->s.br_indeksa), head = head->sljedeci;
}

CVOR* new_node(STUDENT s){
    CVOR *new = malloc(sizeof(CVOR));
    if (!new) return NULL;

    new->s = s;
    new->sljedeci = NULL;
    return new;
}

void append_node(CVOR **head, STUDENT s){
    if (!*head) *head = new_node(s);
    else{
        CVOR *curr = *head;
        while (curr->sljedeci) curr = curr->sljedeci;
        curr->sljedeci = new_node(s);
    }
}

int main(void){
    CVOR *head = NULL;
    PREDMET *ph = NULL;

    STUDENT s1 = {"1230/23", "Nikola", "Markovic", ph, 5};
    STUDENT s2 = {"1231/23", "Marko", "Markovic", ph, 5};
    STUDENT s3 = {"1232/23", "Ivan", "Markovic", ph, 5};
    append_node(&head, s1); append_node(&head, s2); append_node(&head, s3);
    char **indeksi = malloc(2 * sizeof(char *));
    indeksi[0] = calloc(64, 1); indeksi[1] = calloc(64, 1);
    strcpy(indeksi[0], "1230/23"); strcpy(indeksi[1], "1231/23");
    plist(head);
    obrisi(indeksi, 2, &head);
    plist(head);
    return 0;
}