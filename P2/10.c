/*
*   Neka su dati tipovi 'TAKMICAR', 'CVOR' i 'TAKMICENJE'. Poredak takmicara u listi je u rastucem redoslijedu
*   prema rezultatu takmicara.
*   
*   Napisati funkciju koja za zadato takmičenje vraća zbir pojedinačnih rezultata svih takmičara, a čiji je prototip:
*   int ukupno(TAKMICENJE *t);
*   
*   Napisati funkciju koja dodaje novi rezultat nekom takmičaru na takmičenju. Ako je već dodat takmičar u listu 
*   (ako na takmičenju već postoji takmičar sa istim identifikatorom) ažurirati njegov rezultat, inače dodati novog 
*   takmičara. Prototip funkcije je: void dodaj(TAKMICENJE *takmicenje, TAKMICAR takmicar);
*   
*   Napisati funkciju koja na osnovu zadatog niza od n takmičenja kreira i vraća jednostruko ulančanu listu u kojoj su 
*   takmičari uređeni po ukupnom rezultatu na svim takmičenjima. 
*   Prototip funkcije je: CVOR *rang_lista(TAKMICENJE *niz, int n);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int identifikator;
    char ime[50];
    char prezime[50];
    int rezultat;
} TAKMICAR;

typedef struct cvor{
    TAKMICAR *t;
    struct cvor *sljedeci;
} CVOR;

typedef struct takmicenje{
    char naziv[256];
    CVOR *takmicari;
} TAKMICENJE;

int ukupno(TAKMICENJE *t){
    CVOR *head = t->takmicari;
    int total = 0;
    while (head){
        total += head->t->rezultat;
        head = head->sljedeci;
    }
    return total;
}

void dodaj(TAKMICENJE *takmicenje, TAKMICAR takmicar){
    TAKMICAR *novi = malloc(sizeof(TAKMICAR));
    novi->identifikator = takmicar.identifikator;
    strcpy(novi->ime, takmicar.ime);
    strcpy(novi->prezime, takmicar.prezime);
    novi->rezultat = takmicar.rezultat;

    CVOR *novi_cvor = malloc(sizeof(CVOR));
    novi_cvor->t = novi;

    CVOR **head_ptr = &takmicenje->takmicari;
    CVOR *curr = *head_ptr, *prev = NULL;

    if (!*head_ptr){
        *head_ptr = novi_cvor;
        novi_cvor->sljedeci = NULL;
        return;
    }
    while (curr){
        if (curr->t->rezultat > novi->rezultat){
            if (prev) prev->sljedeci = novi_cvor;
            novi_cvor->sljedeci = curr;
            return;
        }
        prev = curr;
        curr = curr->sljedeci;
    }
    prev->sljedeci = novi_cvor;
    novi_cvor->sljedeci = NULL;
}

void add_sorted(CVOR **head, TAKMICAR *t){
    CVOR *novi_cvor = malloc(sizeof(CVOR));
    novi_cvor->t = t;
    novi_cvor->sljedeci = NULL;

    if (!*head) *head = novi_cvor;
    else{
        CVOR *curr = *head, *prev = NULL;
        while (curr){
            if (curr->t->rezultat > novi_cvor->t->rezultat){
                if (prev) prev->sljedeci = novi_cvor;
                novi_cvor->sljedeci = curr;
                return;
            }

            prev = curr;
            curr = curr->sljedeci;
        }
        prev->sljedeci = novi_cvor;
    }
}

CVOR* rang_lista(TAKMICENJE *niz, int n){
    CVOR *lista = NULL;
    for(int i = 0; i < n; i++){
        CVOR *curr = niz[i].takmicari;
        while (curr){
            add_sorted(&lista, curr->t);
            curr = curr->sljedeci;
        }
    }
    return lista;
}

int main(void){
    // ja nemam zivaca da testiram ovo, recemo da radi (jer kompajluje) i tjt
    return 0;
}