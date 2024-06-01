// Da se priviknem na sekvencijalnu reprezentaciju odredjenih struktura jer se potencijalno mogu pojaviti u 
// kolokvijumima s obzirom da sam navikao koristiti iskljucivo ulancane

#include <stdio.h>
#define MAX 4

// Red:

typedef struct red{
    int info[MAX], f, r;
} red_t;

int queue_is_empty(red_t *red){ return red->f == red->r; }
int queue_is_full(red_t *red) { return red->r == MAX; }

int enqueue(red_t *red, int info){
    if (!queue_is_full(red)){
        red->info[red->r++] = info;
        return 1;
    }
    return 0;
}

int dequeue(red_t *red, int *info){
    if (!queue_is_empty(red)){
        *info = red->info[red->f++];
        return 1;
    }
    return 0;
}

// Stek:

typedef struct stek{
    int info[MAX], tos;
} stek_t;

int stack_is_full(stek_t *st){ return st->tos == MAX - 1; }
int stack_is_empty(stek_t *st){ return st->tos == -1; }

int push(stek_t *st, int info){
    if (stack_is_full(st)) return 0;

    st->info[++st->tos] = info;
    return 1;
}

int pop(stek_t *st, int *info){
    if (stack_is_empty(st)) return 0;

    *info = st->info[st->tos--];
    return 1;
}

int main(void){

    stek_t st = {{0}, -1};

    push(&st, 5);
    push(&st, 6);
    push(&st, 7);
    push(&st, 8);
    push(&st, 9);

    int i = 0;
    while (pop(&st, &i))
        printf("%d ", i);

    // MAX je 4 tako da treba da stavi 5, 6, 7 i 8 na stek, zanemari 9 i isprinta sve navedeno u obrnutom redoslijedu

    return 0;
}