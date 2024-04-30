#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char c;
    struct node *left, *right;
} NODE;

void ispisi(NODE *head);
void ispisi_unazad(NODE *head);

NODE *add_front(NODE **head, int c);
NODE *add_back(NODE **head, int c); 
NODE *insert_after(NODE *target, int c);
NODE *insert_before(NODE *target, int c);

int delete(NODE *target);
int delete_front(NODE **head);
int delete_back(NODE **head);
int delete_first_n(NODE **head, int n);
int delete_list(NODE **head);

int main(void)
{
    // B E H F A C G D
    // E H A C G
    NODE *lista = NULL;
    NODE *nodes[10];

    nodes[0] = add_front(&lista, 'A');
    nodes[1] = add_front(&lista, 'B');
    nodes[2] = add_back(&lista, 'C');
    nodes[3] = add_back(&lista, 'D');
    nodes[4] = insert_after(nodes[1], 'E');
    nodes[5] = insert_after(nodes[4], 'F');
    nodes[6] = insert_before(nodes[3], 'G');
    nodes[7] = insert_before(nodes[5], 'H');

    delete(nodes[5]);
    delete_front(&lista);
    delete_back(&lista);
    // delete_first_n(&lista, 2);
    // delete_list(&lista);

    ispisi(lista);
    ispisi_unazad(lista);
    return 0;
}

NODE *add_front(NODE **head, int c){

    NODE *new = malloc(sizeof(NODE));
    new->c = c;
    new->left = NULL;

    if (!*head){
        *head = new;
        (*head)->right = NULL;
        return *head;
    }
    else{
        new->right = *head;
        *head = new;
        return *head;
    }
}

NODE *add_back(NODE **head, int c){
    NODE *new = malloc(sizeof(NODE));
    new->c = c;
    new->right = NULL;

    // A B C [D]

    if (!*head){
        new->left = NULL;
        *head = new;
        return *head;
    }
    else{
        NODE *tail = *head;
        while (tail->right) tail = tail->right;

        new->left = tail;
        tail->right = new;

        return tail->right;
    }
}

NODE *insert_after(NODE *target, int c){
    NODE *R = target->right;
    if (!R) return NULL;

    NODE *new = malloc(sizeof(NODE));
    new->c = c;

    new->left = target;
    new->right = R;
    target->right = new;
    R->left = new;

    return new;
}

NODE *insert_before(NODE *target, int c){
    NODE *L = target->left;
    if (!L) return NULL;

    NODE *new = malloc(sizeof(NODE));
    new->c = c;

    new->right = target;
    new->left = L;
    target->left = new;
    L->right = new;

    return new;
}

int delete(NODE *target){
    NODE *L = target->left;
    NODE *R = target->right;

    if (R && L){
        L->right = R;
        R->left = L;

        free(target);
        return 1;
    }
    return 0;
}

int delete_front(NODE **head){
    NODE *target = *head;
    NODE *R = (*head)->right;

    if (!*head) return 0;
    else if (!R){
        *head = NULL;

        free(target);
        return 1;
    }
    else{
        R->left = NULL;
        *head = R;

        free(target);
        return 1;
    }
}

int delete_back(NODE **head){
    NODE *target = *head;
    NODE *R = (*head)->right;
    if (!*head) return 0;
    else if (!R){
        *head = NULL;

        free(target);
        return 1;
    }
    else{
        while (target->right) target = target->right;
        NODE *L = target->left;
        L->right = NULL;

        free(target);
        return 1;
    }
}

int delete_first_n(NODE **head, int n){
    int deleted = 0;

    for (int i = 0; i < n; i++){
        NODE *target = *head, *R = (*head)->right;

        if (!R){
            *head = NULL;
            break;
        }
        else{
            *head = R;
            (*head)->left = NULL;
        }
        free(target);
        deleted++;
    }
    return deleted;
}

int delete_list(NODE **head){
    while (*head){
        NODE *target = *head, *R = (*head)->right;
        if (R) R->left = NULL;
        *head = R;
        
        free(target);
    }
    return 0;
}

void ispisi(NODE *head){
    if (head) printf("%c", head->c);
    else { printf("Lista je prazna.\n"); return; }

    head = head->right;

    while (head){
        printf("->%c", head->c);
        head = head->right;
    }
    printf("\n");
}

void ispisi_unazad(NODE *head){

    NODE *tail = head;
    while (tail->right) tail = tail->right;

    if (tail) printf("%c", tail->c);
    else { printf("Lista je prazna.\n"); return; }

    tail = tail->left;

    while (1){
        printf("<-%c", tail->c);
        if (tail == head) break;
        tail = tail->left;
    }
    printf("\n");

    // odvratno ali ce posluziti
}