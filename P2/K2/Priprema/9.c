/*
* Neka je definisan tip 'NODE' kojim se reprezentuje cvor BST-a podataka tipa string, te tip 'BST' kojim se 
* reprezentuje BST.
* 
* Napisati funkciju koja dodaje novi string (str) u BST. Ukoliko string već postoji u stablu, ne dodavati novi 
* čvor već uvećati broj ponavljanja tog stringa. Prototip funkcije je: void dodaj(BST *bst, char *str);
* 
* Napisati funkciju koja obilazi stablo u odgovarajućem poretku tako da se ispišu stringovi u rastućem redoslijedu 
* (leksikografski). Za svaki string ispisati broj ponavljanja. Prototip funkcije je: void ispis(BST *bst);
* 
* Napisati glavni program u kojem se ilustruje dodavanje sljedećih stringova u stablo binarne pretrage i njihov ispis 
* u rastućem redoslijedu: "stablo", "binarne", "pretrage", "stablo".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *str;
    int br;
    struct node *left, *right;
} NODE;

typedef struct bst{
    NODE *root;
} BST;

NODE* new_node(char *str){
    NODE *new = malloc(sizeof(NODE));
    if (!new) return NULL;
    char *string = calloc(strlen(str) + 1, sizeof(char));
    strcpy(string, str);
    new->str = string;
    new->left = new->right = NULL;
    new->br = 1;
    return new;
}

void dodaj(BST *bst, char *str){
    if (!bst->root) {
        bst->root = new_node(str);
        return;
    }
    NODE *curr = bst->root, *parent = NULL;
    int cmp;
    while (curr){
        cmp = strcmp(str, curr->str);
        if (!cmp){ // ako je pronadjen isti
            curr->br++;
            return;
        }
        if (cmp > 0) parent = curr, curr = curr->right;
        else if (cmp < 0) parent = curr, curr = curr->left;
    }
    if (cmp > 0) parent->right = new_node(str);
    else if (cmp < 0) parent->left = new_node(str);
}

void ispisi_rec(NODE *root){ // funkcija samo za provjeru
    if (root){
        ispisi_rec(root->left);
        printf("%s [%d]\n", root->str, root->br);
        ispisi_rec(root->right);
    }
}

void ispis(BST *bst){
    // dovrsiti iterativni ispis
}

int main(){
    BST bst = { NULL };

    dodaj(&bst, "stablo");
    dodaj(&bst, "binarne");
    dodaj(&bst, "pretrage");
    dodaj(&bst, "stablo");
    ispisi_rec(bst.root);
    return 0;
}