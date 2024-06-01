#include <stdio.h>
#include <stdlib.h>

typedef struct cvor{
    char node;
    struct cvor *roditelj, *lijevi, *desni;
} CVOR;

typedef struct g{
    int n;
    char nodes[100];
    int ms[100][100];
} GRAF;

void prebroj(CVOR *root, int *total){
    if (root){
        (*total)++;
        prebroj(root->lijevi, total);
        prebroj(root->desni, total);
    }
}

GRAF* konvertuj(CVOR *root){
    int nc = 0;
    prebroj(root, &nc);
    if (nc > 10) return NULL;

    GRAF *finalni = malloc(sizeof(GRAF));
    finalni->n = nc;
    
    for (int i = 0; i < finalni->n; i++){

    }
}

/*
    A   B   C   D   E   F   G
A   0   0   0   0   0   0   0
B   0   0   0   0   0   0   0
C   0   0   0   0   0   0   0 
D   0   0   0   0   0   0   0
E   0   0   0   0   0   0   0
F   0   0   0   0   0   0   0
G   0   0   0   0   0   0   0

*/

CVOR* new_node(char info){
    CVOR *new = malloc(sizeof(CVOR));
    if (!new) return NULL;

    new->node = info;
    new->lijevi = new->desni = NULL;
    return new;
}

void inorder(CVOR *root){
    if (root){
        inorder(root->lijevi);
        printf("%c ", root->node);
        inorder(root->desni);
    }
}

int main(void){
    CVOR *root = new_node('A');
    CVOR *b = new_node('B');
    CVOR *c = new_node('C');
    CVOR *d = new_node('D');
    CVOR *e = new_node('E');
    CVOR *f = new_node('F');
    CVOR *g = new_node('G');

    root->lijevi = b; root->desni = c; root->roditelj = NULL;
    b->lijevi = d; b->desni = e; b->roditelj = root;
    c->lijevi = f; c->desni = g; c->roditelj = root;
    d->roditelj = b; e->roditelj = b; f->roditelj = c; g->roditelj = c;

    inorder(root);

    return 0;
}