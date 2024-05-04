// Napisati program u kojem treba:
// definisati tip CVOR kojim se reprezentuje čvor binarnog stabla (informacioni sadržaj treba da bude cijeli broj),
// definisati funkciju koja dodaje lijevog sina zadatom čvoru,
// definisati funkciju koja dodaje desnog sina zadatom čvoru,
// definisati funkciju koja briše zadati čvor iz stabla,
// definisati funkciju koja briše stablo,
// definisati funkciju koja ispisuje sadržaj stabla u preorder redoslijedu obilaska,
// definisati funkciju koja ispisuje sadržaj stabla u inorder redoslijedu obilaska,
// definisati funkciju koja ispisuje sadržaj stabla u postorder redoslijedu obilaska,
// definisati funkciju koja računa i vraća ukupan broj čvorova stabla,
// definisati funkciju koja računa i vraća sumu vrijednosti svih čvorova stabla,
// definisati funkciju koja računa i vraća ukupan broj listova stabla,
// definisati funkciju koja računa i vraća dubinu stabla,
// u glavnom programu ilustrovati rad sa binarnim stablom tj. definisanim funkcijama.


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *parent, *left, *right;
} NODE;

NODE* new_node(int info){ // pomocna funkcija za kreiranje novog cvora
    NODE *new = malloc(sizeof(NODE)); // pretpostavljamo da ce alokacija uspjeti
    new->parent = new->right = new->left = 0;
    new->info = info;
    return new;
}

NODE* add_left(NODE *node, int info){
    NODE *new = new_node(info);
    if (node->left){ 
        new->left = node->left;
        new->left->parent = new;
    }
    node->left = new;
    new->parent = node;
    return new;
}

NODE* add_right(NODE *node, int info){
    NODE *new = new_node(info);
    if (node->right){
        new->right = node->right;
        node->right->parent = new;
    }
    node->right = new;
    new->parent = node;
    return new;
}

void preorder(NODE *root){
    if (root){
        printf(" %d", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE *root){
    if (root){
        preorder(root->left);
        printf(" %d", root->info);
        preorder(root->right);
    }
}

void postorder(NODE *root){
    if (root){
        preorder(root->left);
        preorder(root->right);
        printf(" %d", root->info);
    }
}

int num_nodes(NODE *root){
    if (!root) return 0;
    return num_nodes(root->left) + 1 + num_nodes(root->right);
}

int sum(NODE *root){
    if (!root) return 0;
    return sum(root->left) + root->info + sum(root->right);
}

int num_leaves(NODE *root){
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    
    return num_leaves(root->left) + num_leaves(root->right);
}

int depth(NODE *root){
    if (!root) return 0;
    int dL = depth(root->left), dR = depth(root->right);
    
    return 1 + (dL > dR ? dL : dR);
}


void delete_node(NODE **root, NODE *node){
    NODE *parent = node->parent;

    if (!node->right){
        if (!parent) *root = node->left;
        else if (node == parent->left) parent->left = node->left;
        else parent->right = node->left;

        if (node->left) node->left->parent = parent;
        free(node);
    }
    else if (!node->left){
        if (!parent) *root = node->right;
        else if (node == parent->left) parent->left = node->right;
        else parent->right = node->right;

        if (node->right) node->right->parent = parent;
        free(node);
    }
    else{
        node->info = node->left->info;
        delete_node(root, node->left);
    }
}

void delete_tree(NODE *root){
    if (!root){
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}

int main(void){
    
    NODE *root = new_node(10);
    NODE *c1 = add_left(root, 20);
    NODE *c2 = add_right(root, 30);
    NODE *c3 = add_left(c1, 40);
    NODE *c4 = add_right(c1, 50);
    add_left(c4, 60);
    add_right(c4, 70);
    add_right(c2, 100);
    delete_node(&root, c3);

    printf("Pre-order: "); preorder(root); printf("\n");
    printf("In-order: "); inorder(root); printf("\n");
    printf("Post-order: "); postorder(root); printf("\n");
    printf("Broj cvorova: %d", num_nodes(root)); printf("\n");
    printf("Broj listova: %d", num_leaves(root)) ; printf("\n");
    printf("Suma: %d", sum(root)) ; printf("\n");
    printf("Dubina: %d", depth(root)) ; printf("\n");

    /*
            10
        20      30
          50      100
        60  70
    */

    return 0;
}