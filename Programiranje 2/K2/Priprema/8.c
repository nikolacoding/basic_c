/*
* Neka su dati tipovi 'PROCESS' i 'NODE' kojim se reprezentuju podaci o jednom procesu čvoru ulančane reprezentacije 
* reda procesa, respektivno. 
* 
* Napisati funkciju koja dodaje novi proces u red: void enq(NODE **head, const char *name, int duration);
* 
* Napisati funkciju koja briše proces iz reda. Funkcija treba da vrati dinamičku kopiju obrisanog procesa. Ako je 
* red prazan, funkcija treba da vrati NULL. Prototip funkcije je: PROCESS* deq(NODE **head);
* 
* Napisati funkciju (korištenjem funkcije deq) koja izvršava i briše sve procese iz datog reda. Izvršavanje procesa 
* podrazumijeva ispis naziva i trajanja procesa na standardni izlaz. Prototip funkcije je: void execute(NODE **head);
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nullptr NULL

typedef struct{
    char name[64];
    int duration;
} PROCESS;

typedef struct node{
    PROCESS *p;
    struct node *next;
} NODE;

void enq(NODE **head, const char *name, int duration){
    NODE *new_node = malloc(sizeof(NODE)); if (!new_node) return;
    PROCESS *new_process = malloc(sizeof(PROCESS)); if (!new_process) return;
    strcpy(new_process->name, name);
    new_process->duration = duration;
    new_node->p = new_process;
    new_node->next = nullptr;

    if (!*head) *head = new_node;
    else{
        NODE *iter = *head;
        while (iter->next) iter = iter->next;
        iter->next = new_node;
    }
}

PROCESS* deq(NODE **head){
    if (!*head) return nullptr;

    NODE *target = *head;
    PROCESS *ret = target->p;
    *head = target->next;
    free(target);
    return ret;
}

void execute(NODE **head){
    PROCESS *ptr;
    while (ptr = deq(head)){
        printf("[%s] %ds\n", ptr->name, ptr->duration);
        free(ptr);
    }
}

int main(void){
    NODE *head = nullptr;
    enq(&head, "test1", 69);
    enq(&head, "test2", 123);
    enq(&head, "test3", 456);
    execute(&head);
    return 0;
}