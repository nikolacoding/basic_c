// Izabrati i definisati najpogodnije tipove za rješavanje sljedećeg problema:
// Korisnik sluša pjesme iz određene plejliste. Tokom slušanja plejliste korisnik koristi akcije za prebacivanje pjesama 
// naprijed i nazad. Napisati funkciju koja prima adekvatnu strukturu pjesama i listu akcija te na osnovu datih podataka pronaći koja je posljednja pjesma koju je korisnik slušao. Akcije treba da budu definisane tipom int gdje broj 0 definiše prebacivanje unazad, a broj 1 prebacivanje unaprijed. Ukoliko se dođe do kraja plejliste, potrebno je ponovo krenuti od prve pjesme.
// Koristiti ulančane reprezentacije odabranih tipova.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *info;
    struct node *left, *right;
} NODE;

NODE *songsToList(char **songs, int n){
    NODE *head = NULL, *tail = NULL;
    NODE **headptr = &head;

    for (int i = 0; i < n; i++){
        NODE *new = malloc(sizeof(NODE));
        new->right = NULL;
        new->info = songs[i];

        if (!*headptr){
            *headptr = new;
            new->left = NULL;
            tail = new;
        }
        else{
            tail->right = new;
            new->left = tail;
            tail = new;
        }
    }
    return head;
}

void last_song(NODE **head, int *actions, int n){
    NODE *curr = *head;

    for (int i = 0; i < n; i++){
        int act = actions[i];

        if (act){
            if (curr->right) curr = curr->right; // ako nismo na kraju (ako postoji naredna pjesma) preci na nju
            else curr = *head; // ako prebacimo naprijed (->right) na zadnjoj pjesmi vracamo se na pocetak
        }
        else curr = curr->left;
    }
    printf("Zadnja pjesma: %s\n", curr->info);
}

void printList(NODE *head){
    while (head){
        printf("%s\n", head->info);
        head = head->right;
    }
}

int main(void){
    // https://www.chosic.com/song-name-generator-by-genre-and-mood/
    char pj[4][21] = {"Clear Light", "The Moon", "Kiss Power", "New Anthem"};

    const int n = 4;
    const int buffer = 21;
    char **pjesme = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++){
        pjesme[i] = calloc(buffer, sizeof(char));
        strcpy(pjesme[i], pj[i]);
    }

    const int nActions = 11;
    int actions[11] = {1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1};

    NODE *head = songsToList(pjesme, 4);
    printList(head);
    last_song(&head, actions, nActions);

    return 0;
}