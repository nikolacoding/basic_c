#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char info;
    struct node *next;
} NODE;

int put(NODE **front, NODE **rear, char info){ // stavljanje na kraj reda
    NODE *new = malloc(sizeof(NODE)); if (!new) return 0;
    new->info = info;

    if (!*rear) *front = *rear = new;
    else{
        (*rear)->next = new;
        *rear = new;
    }
    return 1;
}

int get(NODE **front, NODE **rear, char *info){ // uzimanje s pocetka reda
    if (!*front) return 0;
    NODE *target = *front;

    *info = target->info;

    if (target->next) *front = target->next;
    else *front = *rear = NULL;
    free(target);
    return 1;
}

int main(void){
    
    NODE *front, *rear;
    front = rear = NULL;
    
    char retval;

    put(&front, &rear, 'A');
    put(&front, &rear, 'B');
    put(&front, &rear, 'C');

    get(&front, &rear, &retval);
    printf("%c ", retval);

    get(&front, &rear, &retval);
    printf("%c ", retval);

    get(&front, &rear, &retval);
    printf("%c ", retval);

    get(&front, &rear, &retval);
    printf("%c ", retval);

    return 0;
}