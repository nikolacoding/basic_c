// Neka su dati tipovi 'POINT' i 'TREE_NODE' kojim se reprezentuju tačka u dvodimenzionom prostoru i čvor binarnog 
// stabla tačaka, respektivno. Napisati rekurzivnu funkciju koja dodaje novu tačku (parametar p) u stablo binarne 
// pretrage tačaka prema nekom kriterijumu. Funkcija prihvata (parametar root) i vraća korijen stabla. Kriterijum 
// pretrage je funkcija na koju pokazuje cmp, a koja vraća rezultat poređenja dvije tačke, i to: -1 ako je prva tačka 
// manja od druge, 0 ako su tačke jednake i 1 ako je prva tačka veća od druge. Prototip funkcije je: 
// TREE_NODE* bst_add(TREE_NODE *root, const POINT *p, int (*cmp)(const POINT *p1, const POINT *p2));
// Napisati rekurzivnu funkciju koja u izlaznu tekstualnu datoteku (parametar f) upisuje stablo binarne pretrage 
// tačaka u rastućem redoslijedu. Korijen stabla je parametar root. Svaku tačku treba upisati u zaseban red u formatu 
// (x,y). Prototip funkcije je: void bst_print(TREE_NODE *root, FILE *f);

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SQ(x) (x)*(x)

typedef struct point{
    double x, y;
} POINT;

typedef struct tn{
    POINT p;
    struct tn *L, *R;
} TREE_NODE;

int cmp(const POINT *p1, const POINT *p2){ return (int)sqrt(SQ(p1->x - p2->x) + SQ(p1->y - p2->y)); }

TREE_NODE* bst_add(TREE_NODE *root, const POINT *p, int (*cmp)(const POINT *p1, const POINT *p2));
void bst_print(TREE_NODE *root, FILE *f);

int main(void){
    
    POINT p1 = {1, 2};
    POINT p2 = {3, 4};
    POINT p3 = {5, 3};
    POINT p4 = {2, 1};
    POINT p5 = {3, 8};
    POINT p6 = {7, 0};
    POINT points[6] = {p1, p2, p3, p4, p5, p6};
    TREE_NODE *root = NULL;

    for (int i = 0; i < 6; i++)
        root = bst_add(root, &points[i], cmp);
    
    bst_print(root, stdout);
    return 0;
}

void bst_print(TREE_NODE *root, FILE *f){
    if (root){
        bst_print(root->L, f);
        fprintf(f, "(%.1lf, %.1lf)\n", root->p.x, root->p.y);
        bst_print(root->R, f);
    }   
}

TREE_NODE* bst_add(TREE_NODE *root, const POINT *p, int (*cmp)(const POINT *p1, const POINT *p2)){
    TREE_NODE *new = malloc(sizeof(TREE_NODE));
    new->L = new->R = NULL;
    new->p = *p;
    
    if (!root) return new;

    if ((*cmp)(p, &root->p) < 0) root->L = bst_add(root->L, p, cmp);
    else if ((*cmp)(p, &root->p) > 0) root->R = bst_add(root->R, p, cmp);

    return root;
}