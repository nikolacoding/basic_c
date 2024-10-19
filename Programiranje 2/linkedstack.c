#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char info;
    struct node *next;
} NODE;

int push(NODE **tos, char info);
int pop (NODE **tos, char *info);

int main(void)
{
    NODE *tos = NULL;
    char chars[3];

    push(&tos, 'A');
    push(&tos, 'B');
    push(&tos, 'C');

    pop(&tos, &chars[0]);
    pop(&tos, &chars[1]);
    pop(&tos, &chars[2]);

    for (int i = 0; i < 3; i++)
        printf("%c\n", chars[i]);

    return 0;
}

int push(NODE **tos, char info){
    NODE *new = malloc(sizeof(NODE));
    if (!new) return 0;

    new->info = info;
    new->next = *tos;
    *tos = new;
    return 1;
}

int pop(NODE **tos, char *info){
    if (!*tos) return 0;

    NODE *toPop = *tos;
    *info = toPop->info;
    *tos = toPop->next;
    free(toPop);
    return 1;
}