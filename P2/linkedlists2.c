#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char ime[21], prezime[21];
    double prosjek;
} STUDENT;

typedef struct node
{
    STUDENT info;
    struct node *next;
} NODE;

int appendNode(NODE **lista, STUDENT info)
{
    NODE *tail = (NODE *)malloc(sizeof(NODE));
    if (!tail)
        return 0; // neuspjesna alokacija
    tail->info = info;
    tail->next = NULL;

    if (*lista == NULL) *lista = tail;
    else
    {
        NODE *temp = *lista;
        while (temp->next) temp = temp->next;
        temp->next = tail;
    }
    return 1; // uspjesna alokacija i dodavanje na kraj
}

int insertNodeAfter(NODE *p, STUDENT info)
{
    NODE *q = (NODE *)malloc(sizeof(NODE));
    if (!q) return 0; // neuspjesna alokacija
    q->info = info;

    q->next = p->next;
    p->next = q;
    return 1; // uspjesna alokacija i dodavanje na kraj
}

int insertNodeBefore(NODE *p, STUDENT info)
{
    NODE *q = (NODE *)malloc(sizeof(NODE));
    if (!q) return 0;
    q->info = p->info;
    q->next = p->next;

    p->info = info;
    p->next = q;
    return 1;
}

int deleteNodeAfter(NODE *p)
{
    if (!p) return 0;
    NODE *q = p->next;

    if (q){
        p->next = q->next;
        free(q);
        return 1;
    } 
    return 0;
}

int main(void)
{
    STUDENT studenti[3] = {{"Marko", "Markovic", 7.67}, {"Jovan", "Jovanovic", 8.90}, {"Ivan", "Ivanovic", 9.70}};
    STUDENT dodatniStudent1 = {"Zoran", "Zoranovic", 9.15};
    STUDENT dodatniStudent2 = {"Nikola", "Nikolic", 8.20};

    NODE *lista = NULL;
    appendNode(&lista, studenti[0]);
    appendNode(&lista, studenti[1]);
    appendNode(&lista, studenti[2]);
    insertNodeAfter(lista->next, dodatniStudent1);
    insertNodeBefore(lista->next->next, dodatniStudent2);
    deleteNodeAfter(lista);
    // curi memorija!

    while (lista)
    {
        printf("%s\n", lista->info.ime);
        lista = lista->next;
    }
    return 0;
}
