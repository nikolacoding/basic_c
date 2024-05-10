#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *left, *right;
} NODE;

NODE *new_node(int info){
    NODE *new = malloc(sizeof(NODE));
    if (!new) return NULL;

    new->info = info;
    new->left = new->right = NULL;
    return new;
}

NODE *BST_add(NODE *root, int info){
    if (!root) return new_node(info);

    if (info < root->info) root->left = BST_add(root->left, info);
    else if (info > root->info) root->right = BST_add(root->right, info);
    
    return root;
}

NODE *BST_delete(NODE *root, int target){
    if (!root) return NULL;

    if (target > root->info) root->right = BST_delete(root->right, target); // target veci, trazimo na desnoj strani
    else if (target < root->info) root->left = BST_delete(root->left, target); // target manji, trazimo na lijevoj strani
    else{ // target pronadjen
        if (!root->left && !root->right) { free(root); return NULL; }
        else if (!root->right) { NODE *L = root->left; free(root); return L; }
        else if (!root->left) { NODE *R = root->right; free(root); return R; }
        else{
            NODE *max = root->left;
            while (max->right) max = max->right;
            root->info = max->info;
            BST_delete(root->left, max->info);
        }
    }
    return root;
}

NODE *findNode(NODE *root, int info){
    if (!root) return NULL;

    if (info > root->info) return findNode(root->right, info);
    else if (info < root->info) return findNode(root->left, info);
    else return root;
}

void printInOrder(NODE *root){
    if (root){
        printInOrder(root->left);
        printf("%d ", root->info);
        printInOrder(root->right);
    }
}

int main(void){
    int array1[8] = {10, 30, 50, 70, 20, 40, 60, 80};
    int array2[8] = {40, 80, 70, 50, 20, 10, 60, 30};
    int array3[10] = {50, 60, 10, 30, 90, 40, 20, 70, 80, 100};
    NODE *root = NULL;

    for (int i = 0; i < 10; i++)
        root = BST_add(root, array3[i]);
    
    BST_delete(root, 50);
    printInOrder(root);
    int iTarget = 20;
    NODE *nTarget = findNode(root, iTarget);
    
    if (nTarget) printf("Target found: %d\n", nTarget->info);

    return 0;
}