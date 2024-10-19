#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char info;
    struct node *next;
} NODE;

NODE *addNode(char info)
{
    NODE *ret = (NODE *)malloc(sizeof(NODE));
    ret->info = info;
    ret->next = NULL;

    return ret;
}

void appendNodes(NODE *list, int n)
{

    while (list->next)
        list = list->next;

    char info = list->info + 1;

    for (int i = 0; i < n; i++)
    {
        list->next = (NODE *)malloc(sizeof(NODE));
        list->next->info = info++;
        list = list->next;
    }
    list->next = NULL;
}

void appendNode(NODE *list, char info)
{
    while (list->next)
        list = list->next;

    list->next = (NODE *)malloc(sizeof(NODE));
    list->next->info = info;
    list->next->next = NULL;
}

int main(void)
{
    NODE *lista = addNode('A');
    appendNode(lista, 'B');
    appendNode(lista, 'C');
    appendNodes(lista, 23);

    while (lista)
    {
        printf("%c\n", lista->info);
        lista = lista->next;
    }

    return 0;
}
