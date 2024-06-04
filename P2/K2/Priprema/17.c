/*
*   Neka je dat tip 'NODE' kojim se reprezentuje čvor binarnog stabla, čiji je informacioni sadržaj cijeli broj.
*   
*   Napisati rekurzivnu funkciju koja provjerаva da li je zadato binarno stablo (parametar root) stablo binarnog 
*   pretraživanja. Funkcija treba da vrati 1 ako jeste stablo binarnog pretraživanja, a 0 ako nije stablo binarnog 
*   pretraživanja. Prototip funkcije je: int is_bst(NODE *root);
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *left, *right;
} NODE;

int min(NODE *root){
    for (; root->left; root = root->left);
    return root->info;
}

int max(NODE *root){
    for (; root->right; root = root->right);
    return root->info;
}

int is_bst(NODE *root){
    if (root){
        int val = root->info;
        NODE *L = root->left;
        NODE *R = root->right;

        if (L && R){
            if (min(R) < val || max(L) > val) return 0;
            return is_bst(L) * is_bst(R);
        }
        else if (L){
            if (max(L) > val) return 0;
            return is_bst(L);
        }
        else if (R){
            if (max(R) > val) return 0;
            return is_bst(R);
        }
    }
    return 1;
}

NODE* new_node(int info){
    NODE *new = malloc(sizeof(NODE));
    if (!new) return NULL;

    new->info = info;
    new->left = new->right = NULL;
    return new;
}

int main(void){

    NODE *root = NULL;

    NODE *n7 = new_node(7);
    NODE *n5 = new_node(5);
    NODE *n9 = new_node(9);
    NODE *n3 = new_node(3);
    NODE *n6 = new_node(6);
    NODE *n8 = new_node(8);
    NODE *n11 = new_node(11);

    // NODE *n1 = new_node(1);

    root = n7;
    root->left = n5; root->right = n9;
    n5->left = n3; n5->right = n6; n9->left = n8; n9->right = n11;

    printf("Dato binarno stablo %s stablo binarne pretrage.\n", is_bst(root) ? "jeste" : "nije");

    return 0;
}