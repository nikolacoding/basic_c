/*
* Neka je dat tip 'NODE' kojim se reprezentuje cvor binarnog stabla:
* 
*     - Napisati funkciju koja ispisuje sadržaj stabla (u jednom redu, bez razdvajanja stringova) u preorder
*     redoslijedu obilaska, a čiji je prototip: void preorder(NODE *root);
*     - Napisati funkciju koja ispisuje sadržaj stabla (u jednom redu, bez razdvajanja stringova) u inorder
*     redoslijedu obilaska, a čiji je prototip: void inorder(NODE *root);
*     - Napisati funkciju koja ispisuje sadržaj stabla (u jednom redu, bez razdvajanja stringova) u postorder
*     redoslijedu obilaska, a čiji je prototip: void postorder(NODE *root);
*     - Napisati funkciju koja briše stablo, a čiji je prototip: void delete(NODE *root);
* 
* Napisati glavnu funkciju u kojoj treba kreirati binarno stablo prikazano na sljedećoj slici (informacioni
* sadržaj čvora prikazan je unutar čvora), a zatim ispisati sadržaj kreiranog binarnog stabla u preorder,
* inorder i postorder redoslijedu obilaska.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nullptr NULL

typedef struct node{
    char str[100];
    struct node *left, *right;
} NODE;

// Funkcije iz zadatka
void preorder(NODE *root);
void inorder(NODE *root);
void postorder(NODE *root);
void delete(NODE *root);

// Pomocne funkcije
NODE* new_node(char *str);

int main(void){
    NODE *root = nullptr;
    NODE *nA = new_node("A");
    NODE *nB = new_node("B");
    NODE *nC = new_node("C");
    NODE *nD = new_node("D");
    NODE *nE = new_node("E");
    NODE *nF = new_node("F");
    NODE *nG = new_node("G");
    NODE *nH = new_node("H");
    NODE *nI = new_node("I");
    NODE *nJ = new_node("J");

    root = nA;
    nA->left = nB; nA->right = nC; 
    nB->left = nD; nB->right = nE; 
    nD->left = nG; 
    nE->right = nH;
    nH->left = nJ;

    nC->right = nF;
    nF->left = nI;

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    delete(root);
    return 0;
}

void preorder(NODE *root){
    if (root){
        printf("%s", root->str);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE *root){
    if (root){
        inorder(root->left);
        printf("%s", root->str);
        inorder(root->right);
    }
}

void postorder(NODE *root){
    if (root){
        postorder(root->left);
        postorder(root->right);
        printf("%s", root->str);
    }
}

void delete(NODE *root){
    if (root){
        delete(root->left);
        delete(root->right);
        free(root);
    }
}

NODE* new_node(char *str){
    NODE *new = malloc(sizeof(NODE));
    if (!new) return nullptr;

    strcpy(new->str, str);
    new->left = new->right = nullptr;
    return new;
}