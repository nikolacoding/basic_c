/*
*   Neka su dati tipovi 'POINT' i 'TREE_NODE'.
*   
*   Napisati rekurzivnu funkciju koja dodaje novu tačku (parametar p) u stablo binarne pretrage tačaka prema nekom 
*   kriterijumu. Funkcija prihvata (parametar root) i vraća korijen stabla. Kriterijum pretrage je funkcija na koju 
*   pokazuje cmp, a koja vraća rezultat poređenja dvije tačke, i to: -1 ako je prva tačka manja od druge, 0 ako su 
*   tačke jednake i 1 ako je prva tačka veća od druge. 
*   Prototip: TREE_NODE* bst_add(TREE_NODE *root, const POINT *p, int (*cmp)(const POINT *p1, const POINT *p2));
*   
*   Napisati rekurzivnu funkciju koja u izlaznu tekstualnu datoteku (parametar f) upisuje stablo binarne pretrage 
*   tačaka u rastućem redoslijedu. Korijen stabla je parametar root. Svaku tačku treba upisati u zaseban red u 
*   formatu (x,y). Prototip funkcije je: void bst_print(TREE_NODE *root, FILE *f);
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x, y; // u zadatku se trazi double ali sam stavio int da olaksam testiranje
} POINT;

typedef struct tn{
    POINT p;
    struct tn *l, *r;
} TREE_NODE;

TREE_NODE* new_node(const POINT *p){
    TREE_NODE *new = malloc(sizeof(TREE_NODE));
    if (!new) return NULL;

    new->p = *p;
    new->l = new->r = NULL;
    return new;
}

TREE_NODE* bst_add(TREE_NODE *root, const POINT *p, int (*cmp)(const POINT *p1, const POINT *p2)){
    if (!root) return new_node(p);

    int cmpres = (*cmp)(p, &root->p);
    if (cmpres > 0) root->r = bst_add(root->r, p, cmp);
    else if (cmpres < 0) root->l = bst_add(root->l, p, cmp);
    
    return root;
}

void bst_print(TREE_NODE *root, FILE *f){
    if (root){
        bst_print(root->l, f);
        fprintf(stdout, "(%d,%d) [%d]\n", root->p.x, root->p.y, root->p.x + root->p.y);
        bst_print(root->r, f);
    }
}

int cmp_points(const POINT *a, const POINT *b){
    int sumA = a->x + a->y;
    int sumB = b->x + b->y;
    return sumA - sumB;
}

#define N 5
int main(void){

    TREE_NODE *root = NULL;
    POINT p1 = {4, 5}, p2 = {0, -4}, p3 = {5, 12}, p4 = {1, 3}, p5 = {-2, 5};
    POINT points[N] = {p1, p2, p3, p4, p5};

    for (int i = 0; i < N; i++)
        root = bst_add(root, &points[i], cmp_points);
    
    bst_print(root, stdout);

    return 0;
}