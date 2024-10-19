/*
    Dat je tip 'RED' i standardne funkcije za rukovanje istim: dodaj, obrisi, isFull, isEmpty.
    Dat je tip 'STEK' koji se sastoji iz dva reda. Napisati funkcije int push(STEK *s, int podatak) i
    int pop(STEK *s, int *podatak) koje rukuju ovim specificnim stekom reprezentovanim redovima.

    Napomene: 
        - nije neophodno koristiti oba reda, moze se napisati implementacija uz pomoc samo jednog
        - nije dozvoljeno pristupati elementima strukture 'RED' direktno, dakle samo pomocu vec
        definisanih funkcija
*/

#include <stdio.h>

typedef struct red{
    int niz[100];
    int f, r;
} RED;

typedef struct stek{
    RED r1, r2;
} STEK;

// Predefinisane funkcije
int isFull(RED *red) { return red->r == 100; }
int isEmpty(RED *red) { return red->f == -1 || red->f == red->r; }
int dodaj(RED *red, int podatak) {
    if (isFull(red)) return 0;
    if (red->f == -1) red->f = 0;
    red->niz[red->r++] = podatak;
    return 1;
}

int obrisi(RED *red, int *podatak) {
    if (isEmpty(red)) return 0;
    *podatak = red->niz[red->f++];
    return 1;
}

// Funkcije iz zadatka:

int push(STEK *s, int podatak){
    if (isFull(&s->r1)) return 0;

    dodaj(&s->r1, podatak);
    return 1;
}

int pop(STEK *s, int *podatak){
    if (isEmpty(&s->r1)) return 0;

    int n = 0, all[100], curr;

    while (obrisi(&s->r1, &curr))
        all[n++] = curr;
    
    *podatak = all[--n];
    for (int i = 0; i < n; i++)
        dodaj(&s->r1, all[i]);
    
    return 1;
}

int main(void){
    RED r1, r2;
    r1.f = -1; r1.r = 0;
    r2.f = -1; r2.r = 0;

    STEK s = {r1, r2};

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    int last;

    while (pop(&s, &last))
        printf("%d ", last);

    return 0;
}