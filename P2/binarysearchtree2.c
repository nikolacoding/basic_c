/*
* >> Napisati program u programu treba:
*       > definisati tip CVOR kojim se reprezentuje čvor stabla binarnog pretraživanja, pri čemu informacioni sadržaj 
            čvora čine dvije riječi (riječ na srpskom jeziku koja predstavlja ključ, te riječ na engleskom jeziku)
*       > definisati funkciju koja dodaje novi par riječi u stablo (rječnik)
*       > definisati funkciju koja omogućava pretraživanje stabla po riječi na srpskom jeziku
*       > definisati funkciju koja briše stablo
*       >> u glavnom programu treba:
*               iz datoteke čiji je naziv prvi argument komandne linije pročitati sve parove riječi (u svakom redu upisan je jedan par riječi) i formirati odgovarajuće stablo binarnog pretraživanja (rječnik),
*               sa standardnog ulaza učitavati riječi na srpskom jeziku, a na standardni izlaz ispisivati njihov prevod na engleski jezik, dok se ne učita riječ koja nema prevod.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nullptr NULL;

struct node{
    char ws[21], we[21]; // rijec na srpskom i rijec na engleskom
    struct node *left, *right;
};

// Funkcije iz zadatka
struct node* bst_add(struct node *root, const char *ws, const char *we); // rijec na srpskom je kljuc svakog cvora te po njoj kasnije i pretrazujemo
struct node* bst_find(struct node *root, const char *key);
void bst_delete(struct node *root);

// Pomocne funkcije
struct node *new_node(const char *ws, const char *we);
void print_tree(struct node *root);

#define READBUFFER 64 // citanje iz datoteke pri pravljenju BST-a
#define INPUT_BUFFER 21 // file name, unos za pretragu
int main(int argc, const char **argv){
    char filename[INPUT_BUFFER];
    if (argc != 2){
        printf("Argumenti na komandnoj liniji nisu pravilno navedeni.");
        return 1;
    }
    strcpy(filename, argv[1]);

    struct node *root = nullptr;
    FILE *stream;
    if (stream = fopen(filename, "r")){
        char s_buffer[READBUFFER], e_buffer[READBUFFER];
        while (fscanf(stream, "%s %s", s_buffer, e_buffer) != EOF) root = bst_add(root, s_buffer, e_buffer);
        print_tree(root);

        struct node *search_res = nullptr;
        do {
            char user_input[INPUT_BUFFER];
            printf("Unesi rijec na srpskom: "); scanf("%s", user_input);
            search_res = bst_find(root, user_input);
            if (search_res){
                printf("prevod: %s->%s\n", user_input, search_res->we);
            } 
            else printf("U rjecniku ne postoji engleski prevod za '%s'.", user_input);
        } while(search_res);
    }
    else printf("Nije moguce otvoriti datoteku '%s'.", filename);

    return 0;
}

struct node* bst_add(struct node *root, const char *ws, const char *we){
    if (!root) return new_node(ws, we);
    int cmp = strcmp(ws, root->ws);

    if (cmp > 0) root->right = bst_add(root->right, ws, we);
    else if (cmp < 0) root->left = bst_add(root->left, ws, we);
    else return root;
}

struct node* bst_find(struct node *root, const char *key){
    if (!root) return nullptr;
    int cmp = strcmp(key, root->ws);

    if (cmp == 0) return root;
    else if (cmp > 0) return bst_find(root->right, key);
    else if (cmp < 0) return bst_find(root->left, key);
}

void bst_delete(struct node *root){
    if (root){
        bst_delete(root->left);
        bst_delete(root->right);
        free(root);
    }
}

struct node *new_node(const char *ws, const char *we){
    struct node *new = malloc(sizeof(struct node));
    strcpy(new->ws, ws);
    strcpy(new->we, we);
    new->left = new->right = nullptr;
    return new;
}

void print_tree(struct node *root){ // in-order obilazak
    if (root){
        print_tree(root->left);
        printf("[%s | %s]\n", root->ws, root->we);
        print_tree(root->right);
    }
}