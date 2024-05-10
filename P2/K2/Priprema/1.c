// Neka su dati tipovi 'glumac' i 'film' kojim se reprezentuju klumac i film u kom glume glumci, respektivno.
// Neka su dati tipovi 'broj_pojavljivanja' i 'cvor'. kojim se reprezentuju glumac sa ukupnim brojem pojavljivanja 
// u svim filmovima i čvor jednostruko povezane liste čiji je informacioni sadržaj glumac sa brojem pojavljivanja u 
// filmovima, respektivno. Napisati funkciju koja iz niza filmova kreira jednostruko povezanu listu u čijim su čvorovima 
// informacioni sadržaj glumci (tip GLUMAC_POJAVLJIVANJA) sa ukupnim brojem pojavljivanja u svim filmovima. Funkcija 
// kao rezultat vraća glavu liste. Glumac se jedinstveno identifikuje imenom i prezimenom (u obzir uzeti velika i 
// mala slova). Prototip funkcije je 'CVOR* dodaj(FILM *f, int n)'. Pri tome je parametar f adresa niza filmova, a 
// parametar n broj filmova u nizu.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct glumac{
    char *ime, *prezime;
} GLUMAC;

typedef struct film{
    GLUMAC *niz;
    int n; // broj glumaca u filmu
} FILM;

typedef struct glumac_pojavljivanja{
    char *ime, *prezime;
    int broj_pojavljivanja;
} GLUMAC_POJAVLJIVANJA;

typedef struct cvor {
    GLUMAC_POJAVLJIVANJA gp;
    struct cvor *sljedeci;
} CVOR;

CVOR* dodaj(FILM *f, int n){
    int space = 10;
    GLUMAC_POJAVLJIVANJA *poj = malloc(space * sizeof(GLUMAC_POJAVLJIVANJA));
    int p = 0, pronadjen = 0;;

    for (int i = 0; i < n; i++){ // prolazimo kroz n filmova
        FILM currentF = f[i];
        for (int j = 0; j < currentF.n; j++){ // prolazimo kroz f[i].n glumaca u datom filmu
            GLUMAC currentG = currentF.niz[j];
            pronadjen = 0;
            for (int k = 0; k < p; k++){ // provjeravamo da li u nizu pojavljivanja postoji dati glumac
                if (!strcmp(poj[k].ime, currentG.ime) && !strcmp(poj[k].prezime, currentG.prezime)){
                    poj[k].broj_pojavljivanja++; // ukoliko ga nadjemo po imenu i prezimenu, inkrementiramo broj poj.
                    pronadjen = 1; // oznacimo da je pronadjen
                    break; // nema potrebe za vise iteracija
                }
            }
            if (!pronadjen){ // na kraju petlje, ukoliko nije pronadjen, unosimo ga kao novog glumca sa jednim poj.
                if (p == space){
                    space *= 2;
                    poj = realloc(poj, space * sizeof(GLUMAC_POJAVLJIVANJA));
                }
                
                char *ime = calloc(strlen(currentG.ime) + 1, sizeof(char));
                char *prezime = calloc(strlen(currentG.prezime) + 1, sizeof(char));
                strcpy(ime, currentG.ime);
                strcpy(prezime, currentG.prezime);

                poj[p].ime = ime;
                poj[p].prezime = prezime;
            
                poj[p].broj_pojavljivanja = 1;
                p++; // obavezno inkrementiramo p
            }
        }
    }

    poj = realloc(poj, p * sizeof(GLUMAC_POJAVLJIVANJA));

    CVOR *head = NULL, *tail = NULL;
    CVOR **headptr = &head;
    for (int i = 0; i < p; i++){
        CVOR *new = malloc(sizeof(CVOR));
        new->gp = poj[i];
        new->sljedeci = NULL;

        if (!*headptr){
            *headptr = new;
            tail = new;
        }
        else{
            tail->sljedeci = new;
            tail = new;
        }
    }

    return head;
}

void printList(CVOR *head);
int main(void){
    
    GLUMAC g1[3] = {{"John", "Travolta"}, {"Ivan", "Primorac"}, {"Dragan", "Nikolic"}};
    FILM f1 = {g1, 3};

    GLUMAC g2[4] = {{"Ivan", "Primorac"}, {"Nebojsa", "Glogovac"}, {"Rados", "Bajic"}, {"John", "Travolta"}};
    FILM f2 = {g2, 4};

    GLUMAC g3[4] = {{"Nenad", "Okanovic"}, {"Dragan", "Nikolic"}, {"Bata", "Zivojinovic"}, {"John", "Travolta"}};
    FILM f3 = {g3, 4};

    FILM filmovi[3] = {f1, f2, f3};
    CVOR *head = dodaj(filmovi, 3);
    printList(head);

    return 0;
}

void printList(CVOR *head){
    while (head){
        printf("%s %s [%d]\n", head->gp.ime, head->gp.prezime, head->gp.broj_pojavljivanja);
        head = head->sljedeci;
    }
}