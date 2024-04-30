#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *left;
    struct node *right;
} NODE;

void ispisi(NODE *head);
NODE *add_front(NODE **head, int info); // modifikovani tako da vracaju adresu dodanog cvora
NODE *add_back(NODE **head, int info); 
NODE *insert_after(NODE *target, int info);
NODE *insert_before(NODE *target, int info);

int delete(NODE *target);
int delete_front(NODE **head);
int delete_back(NODE **head);
int delete_first_n(NODE **head, int n);
int delete_list(NODE **head);

int main(void)
{
    NODE *lista = NULL;
    NODE *target1, *target2;

    add_front(&lista, 1); ispisi(lista);
    add_back(&lista, 5); ispisi(lista);
    add_back(&lista, 6); ispisi(lista);
    target1 = add_front(&lista, 2); ispisi(lista);
    add_front(&lista, 3); ispisi(lista);
    add_back(&lista, 7); ispisi(lista);
    target2 = insert_after(target1, 8); ispisi(lista);
    insert_before(target2, 9); ispisi(lista);
    delete(target2); ispisi(lista);
    delete_front(&lista); ispisi(lista);
    delete_first_n(&lista, 2); ispisi(lista);
    delete_back(&lista); ispisi(lista);
    delete_list(&lista); ispisi(lista);

    return 0;
}

NODE *add_front(NODE **head, int info){
    NODE *new = malloc(sizeof(NODE));
    if (!new) { printf("Neuspjesna alokacija.\n"); return NULL; }
    new->info = info;
    
    if (*head == NULL){
        new->left = new->right = NULL;
        *head = new;
        return *head;
    }
    else{
        new->right = *head;
        new->left = NULL;
        (*head)->left = new;
        *head = new;
        return *head;
    }
}

NODE *add_back(NODE **head, int info){
    NODE *new = malloc(sizeof(NODE));
    if (!new) { printf("Neuspjesna alokacija.\n"); return NULL; }
    new->info = info;

    if (*head == NULL){
        new->left = new->right = NULL;
        *head = new;
        return *head;
    }
    else{
        NODE *temp = *head;
        while (temp->right) temp = temp->right;
        new->left = temp;
        new->right = NULL;
        temp->right = new;
        return *head;
    }
}

NODE *insert_after(NODE *target, int info){
    NODE *r = target->right;
    if (!r) return NULL;

    NODE *new = malloc(sizeof(NODE));
    if (!new) { printf("Neuspjesna alokacija.\n"); return NULL; }

    new->info = info;

    new->left = target;
    new->right = r;
    target->right = new;
    r->left = new;
    return new;
}

NODE *insert_before(NODE *target, int info){
    NODE *l = target->left;
    if (!l) return NULL;

    NODE *new = malloc(sizeof(NODE));
    new->info = info;

    new->right = target;
    new->left = l;
    target->left = new;
    l->right = new;
    return new;
}

// A B [C] D E

int delete(NODE *target){
    if (target->right && target->left){
        NODE *L = target->left, *R = target->right;

        L->right = R;
        R->left = L;
        free(target);
        return 1;
    }
    return 0;
}

int delete_front(NODE **head){
    if (!*head) return 0;

    NODE *target = *head, *R = target->right;
    if (R) R->left = NULL;
    *head = target->right;
    free(target);
    return 1;
}

int delete_back(NODE **head){
    if (!*head) return 0;

    NODE *target = *head, *L;
    while (target->right) target = target->right;
    L = target->left;
    if (L) L->right = NULL;
    free(target);

    return 1;
}

int delete_first_n(NODE **head, int n){
    int deleted = 0;
    
    for (int i = 0; i < n; i++){
        if (!*head) return deleted;

        NODE *target = *head, *R = target->right;
        if (R) R->left = NULL;
        *head = target->right;
        free(target);
        deleted++;
    }
    return deleted;
}

int delete_list(NODE **head){
    while (*head){
        NODE *target = *head;
        NODE *R = target->right;
        *head = R;
        free(target);
    }
    return 1;
}

void ispisi(NODE *head){
    printf("Lista: ");
    while (head){
        printf("%d ", head->info);
        head = head->right;
    }
    printf("\n");
}