#include <stdio.h>
#include <stdlib.h>

typedef struct anode{
    int *podaci;
    int n;
    struct anode *next;
} ANODE;

typedef struct bnode{
    int podatak;
    struct bnode *next;
} BNODE;

void dodaj_na_kraj(BNODE **, int);

BNODE* poravnaj_cvor(ANODE *node){ // funkcija iz zadatka (1)
    // glava rezultujuce liste
    BNODE *rez = NULL;
    for (int i = 0; i < node->n; i++)
        dodaj_na_kraj(&rez, node->podaci[i]);
        // ^ postavljamo svaki pojedini podatak iz 'node->podaci' kao cvorove liste 'rez'
    return rez;
    // ^ vracamo glavu rezultujuce liste
}

BNODE* poravnaj_listu(ANODE **head){ // funkcija iz zadatka (2)
    // rezultujuca BNODE lista i pokazivac trenutnog ANODE cvora
    BNODE *rez = NULL, *rep = NULL;
    ANODE *trenutni = *head;
    
    // standardan prolazak kroz ANODE listu
    while (trenutni){
        // ako je lista prazna, inicijalnu BNODE listu kacimo na pocetak
        if (!rep) rez = poravnaj_cvor(trenutni);
        else rep->next = poravnaj_cvor(trenutni);
        // ^ u suprotnom kacimo je na rep tj. kraj vec postojece

        // do repa dolazimo tako sto pocev od glave rezultujuce liste trazimo njen posljednji element
        rep = rez;
        while (rep->next) rep = rep->next;

        free(trenutni->podaci); // oslobadjamo din. niz
        free(trenutni); // pa i sam cvor
        trenutni = trenutni->next; // i krecemo se naprijed
    }
    return rez;
}

// Pomocne funkcije:
void dodaj_na_kraj(BNODE **head, int podatak){
    // prosta pomocna funkcija za dodavanje na kraj liste
    BNODE *new = malloc(sizeof(BNODE));
    new->podatak = podatak;
    new->next = NULL;

    if (!*head) *head = new;
    else{
        BNODE *temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = new;
    }
}

// za testiranje
void pisi_listu(BNODE *head){
    while (head){
        printf("%d ", head->podatak);
        head = head->next;
    }
}

int main(void){
    int *podaci1 = malloc(3 * sizeof(int)), *podaci2 = malloc(4 * sizeof(int)), *podaci3 = malloc(2 * sizeof(int));
    podaci1[0] = 1; podaci1[1] = 2; podaci1[2] = 3; 
    podaci2[0] = 4; podaci2[1] = 5; podaci2[2] = 6; podaci2[3] = 7;
    podaci3[0] = 8;podaci3[1] = 9;

    ANODE *a1 = malloc(sizeof(ANODE));
    ANODE *a2 = malloc(sizeof(ANODE));
    ANODE *a3 = malloc(sizeof(ANODE));

    // testiramo listom ANODE-ova: a1 -> a2 -> a3 -> NULL
    a1->n = 3; a2->n = 4; a3->n = 2;
    a1->podaci = podaci1; a2->podaci = podaci2; a3->podaci = podaci3;
    a1->next = a2; a2->next = a3; a3->next = NULL;

    // imamo tri ANODE liste (a1, a2, a3) sa dinamicki alociranim nizovima intova sa sljedecim podacima:
    // a1:      a2:     a3:
    // 1         4       8
    // 2         5       9
    // 3         6       
    //           7       
    //
    // cilj ih je poravnati u jednu jedinu BNODE listu ovakvog logickog poretka:
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> N

    BNODE *por = poravnaj_listu(&a1);
    pisi_listu(por);

    return 0;
}