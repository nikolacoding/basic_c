#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *next;
} NODE;

void printList(NODE *head){
    while (head){
        printf("%d ", head->info);
        head = head->next;
    }
}

NODE* arrayToList(int *array, const int n){
    NODE *head = NULL, *tail = NULL;
    NODE **headptr = &head;

    for (int i = 0; i < n; i++){
        NODE *new = malloc(sizeof(NODE));
        new->info = array[i];
        new->next = NULL;

        if (!*headptr) {
            *headptr = new;
            tail = new;
        }
        else{
            tail->next = new;
            tail = new;
        }
    }

    return head;
}

int main(void){
    const int n = 5;
    int *array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) array[i] = 3 * i;

    NODE *list = arrayToList(array, n);
    printList(list);

    return 0;
}