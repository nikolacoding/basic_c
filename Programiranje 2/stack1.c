#include <stdio.h>

#define MAX 4

typedef struct stek{
    int niz[MAX];
    int tos;
} STEK;

int isFull(STEK *s) { return s->tos == MAX - 1; }
int isEmpty(STEK *s) { return s->tos == -1; }

int push(STEK *s, int info);
int pop(STEK *s, int *info);

void ispisi(STEK *s);

int main(void){

    STEK s = {{0}, -1};
    push(&s, 5);
    push(&s, 6);
    push(&s, 7);
    push(&s, 8);
    
    ispisi(&s);

    return 0;
}

int push(STEK *s, int info){
    if (isFull(s)) return 0;
    
    s->niz[++s->tos] = info;
    return 1;
}

int pop(STEK *s, int *info){
    if (isEmpty(s)) return 0;

    *info = s->niz[s->tos--];
    return 1;
}

void ispisi(STEK *s){
    int i = s->tos;
    while (i >= 0){
        printf("%d\n", s->niz[i]);
        i--;
    }
}