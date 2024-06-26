/*
*   Izabrati i definisati najpogodnije tipove za rješavanje sljedećeg problema:
*   Korisnik sluša pjesme iz određene plejliste. Tokom slušanja plejliste korisnik koristi akcije za prebacivanje 
*   pjesama naprijed i nazad. Napisati funkciju koja prima adekvatnu strukturu pjesama i listu akcija te na osnovu 
*   datih podataka pronaći koja je posljednja pjesma koju je korisnik slušao. Akcije treba da budu definisane tipom 
*   int gdje broj 0 definiše prebacivanje unazad, a broj 1 prebacivanje unaprijed. Ukoliko se dođe do kraja plejliste,
*   potrebno je ponovo krenuti od prve pjesme.
*   
*   Koristiti ulančane reprezentacije odabranih tipova.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_node{
    char pjesma[64];
    struct list_node *next, *prev;
} NODE;

void append_node(NODE **head, const char *pjesma){
    NODE *new = malloc(sizeof(NODE));
    if (!new) return;
    strcpy(new->pjesma, pjesma);
    new->next = new->prev = NULL;

    if (!*head) *head = new;
    else{
        NODE *curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = new;
        new->prev = curr;
    }
}

void zadnja_pjesma(NODE *head, int akcije[], int n){
    NODE *curr = head;
    for (int i = 0; i < n; i++){
        if (!akcije[i]) curr = curr->prev;
        else{
            if (!curr->next) curr = head;
            else curr = curr->next;
        }
    }
    printf("Zadnja pjesma: %s\n", curr->pjesma);
}

int main(void){
    NODE *lista = NULL;
    int akcije[11] = {1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1};

    append_node(&lista, "Pjesma1");
    append_node(&lista, "Pjesma2");
    append_node(&lista, "Pjesma3");
    append_node(&lista, "Pjesma4");

    zadnja_pjesma(lista, akcije, 11);
}