// Neka je dat tip 'NODE' kojim se reprezentuje cvor dvostruko povezane uredjene liste podataka proizvoljnog tipa.
//
// Napisati funkciju koja dodaje novi podatak (data) u listu (onemogućiti dodavanje istih podataka više puta) 
// tako da je poredak elemenata u listi uvijek u rastućem redoslijedu, pri čemu je prototip funkcije:
//      void add(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *));
//
// Napisati funkciju koja briše zadati podatak (data) iz liste, a čiji je prototip:
//      void delete(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *));
//
// Napisati funkciju koja omogućava pretraživanje liste prema zadatom podatku (data), a čiji je prototip:
//      NODE* search(NODE *head, NODE *tail, const void *data, int (*cmp)(const void *, const void *));
// 
// Napisati funkciju koja na standardni izlaz ispisuje sve podatke iz liste (svaki podatak u novom redu) prototipa:
//      void write(NODE *head, void (*write_one)(const void *));
//
// Napisati funkciju koja briše listu (obratiti pažnju na dinamički alocirane podatke u čvorovima):
//      void delete_list(NODE **phead, NODE **ptail);
//
// Koristeći prethodno definisane funkcije (i neophodne dodatne funkcije), u glavnom programu ilustrovati rad sa 
// uređenom dvostruko povezanom listom stringova. Ilustrovati pravljenje liste sa sljedećim stringovima: 
// “ponedjeljak”, “utorak”, “srijeda”, “cetvrtak”, “petak” i “subota”, a zatim ispisati sadržaj liste. 
// Obrisati čvor sa podatkom “subota” i ponovo ispisati sadržaj liste. Pri implementaciji funkcije za poređenje dva 
// stringa potrebno je koristiti leksikografski poredak.
//
// Napomene: 
//      Parametar cmp predstavlja pokazivač na funkciju koja vrši poređenje dva podatka proizvoljnog tipa prema nekom 
// kriterijumu. Funkcija za poređenje vraća negativnu vrijednost ako je prvi podatak manji od drugog, vrijednost 0 ako 
// su podaci jednaki te pozitivnu vrijednost ako je prvi podatak veći od drugog.
//      Parametar write_one predstavlja pokazivač na funkciju koja na standardni izlaz ispisuje jedan podatak 
/// proizvoljnog tipa.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

typedef struct node{
    void *data;
    struct node *prev, *next;
} NODE;

// Funkcije iz zadatka
void add(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *));
void delete(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *));
NODE* search(NODE *head, NODE *tail, const void *data, int (*cmp)(const void *, const void *));
void write(NODE *head, void (*write_one)(const void *));
void delete_list(NODE **phead, NODE **ptail);
int cmpstr(const void *a, const void *b);
void write_one(const void *);

// Pomocne funkcije
void to_lower(char *string); // pretvaranje svih velikih slova u mala
void bulk_free(int n, ...); // free-ovanje n stringova

#define BUFFER 21
int main(void){
    NODE *head = NULL, *tail = NULL;

    char *pon = calloc(BUFFER, sizeof(char)); strcpy(pon, "ponedjeljak");
    char *uto = calloc(BUFFER, sizeof(char)); strcpy(uto, "utorak");
    char *sri = calloc(BUFFER, sizeof(char)); strcpy(sri, "srijeda");
    char *cet = calloc(BUFFER, sizeof(char)); strcpy(cet, "cetvrtak");
    char *pet = calloc(BUFFER, sizeof(char)); strcpy(pet, "petak");
    char *sub = calloc(BUFFER, sizeof(char)); strcpy(sub, "subota");
    add(&head, &tail, pon, cmpstr);
    add(&head, &tail, uto, cmpstr);
    add(&head, &tail, sri, cmpstr);
    add(&head, &tail, cet, cmpstr);
    add(&head, &tail, pet, cmpstr);
    add(&head, &tail, sub, cmpstr);

    write(head, write_one);
    delete(&head, &tail, sub, cmpstr); // brisemo subotu
    write(head, write_one);

    bulk_free(6, pon, uto, sri, cet, pet, sub);
    return 0;
}

void add(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *)){
    NODE *new = malloc(sizeof(NODE));
    new->data = data;
    new->next = new->prev = NULL;
    if (!*phead){ // ako je lista prazna
        *phead = *ptail = new;
        new->next = new->prev = NULL;
    }
    else{ // ako nije prazna
        NODE *curr = *phead; // krecemo od pocetka (glave)
        while (curr){
            int cmpres = (*cmp)(curr->data, data); // poredimo podatak cvora na kom smo trenutno sa novim
            if (cmpres >= 0){ // ako je ILI veci ILI jednak trenutnom
                if (!cmpres) { printf("Ne mozemo dodati isti podatak.\n"); free(new); return; } // ako je strogo jednak
                else{ // ako je strogo veci
                    if (curr->prev){ // ako postoji prethodni element tj. ako novi ne dodajemo na sami pocetak
                        new->prev = curr->prev;
                        curr->prev->next = new;
                    } else { *phead = new; } // ako ipak dodajemo na pocetak, cinimo ga novom glavom liste
                    curr->prev = new;
                    new->next = curr;
                    return;
                }
            }
            curr = curr->next; // ukoliko nismo pronasli mjesto za novog nastavljamo naprijed kroz listu
        }
        new->prev = *ptail; // ako nismo pronasli mjesto, znamo da je najveci i stavljamo ga na kraj kao novi rep
        (*ptail)->next = new;
        *ptail = new;
        new->next = NULL;
    }
}

void delete(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *)){
    if (!*phead) return; // prazna lista

    NODE *target = search(*phead, *ptail, data, cmp);
    if (!target) return; // nije pronadjen

    NODE *L = target->prev, *R = target->next;
    if (L && R){ // ako imamo cvor i lijevo i desno od onog koji brisemo
        L->next = target->next;
        R->prev = target->prev;
    }
    else if (L){ // ako imamo cvor samo lijevo od onog koji brisemo (brisemo zadnji u listi)
        L->next = NULL;
        *ptail = L;
    }
    else if (R){ // ako imamo cvor samo desno od onog koji brisemo (brisemo prvi u listi)
        R->prev = NULL;
        *phead = R;
    }
    else{ // ako je cvor koji brisemo jedini u listi
        *ptail = *phead = NULL;
    }
    free(target);
}

NODE* search(NODE *head, NODE *tail, const void *data, int (*cmp)(const void *, const void *)){
    while (head){
        if (!(*cmp)(head->data, data)) return head;
        head = head->next;
    }
    return NULL;
}

void write(NODE *head, void (*write_one)(const void *)){
    if (!head) { printf("Lista je prazna."); return; }
    while (head){
        (*write_one)(head->data);
        head = head->next;
    }
    printf("\n");
}

void delete_list(NODE **phead, NODE **ptail){
    NODE *curr = *phead;
    while (curr) {
        free(curr);
        curr = curr->next;
    }

    *phead = *ptail = NULL;
}

void write_one(const void *data){
    printf("%s\n", (char *)data); // eksplicitno kastujemo u char * jer pri implicitnoj konverziji se zali kompajler
    // ovako pretpostavljamo da je podatak string
}

#define MAXCHARS 128
int cmpstr(const void *a, const void *b){
    if (!strcmp((char *)a, (char *)b)) return 0; // ako su stringovi isti u potpunosti

    int retVal = 0;
    char *str1 = calloc(MAXCHARS, sizeof(char)); char *str2 = calloc(MAXCHARS, sizeof(char));
    strcpy(str1, (char *)a); strcpy(str2, (char *)b);
    to_lower(str1); to_lower(str2);
    
    int len1 = strlen(str1); int len2 = strlen(str2);
    bool checkLengthDisparity = true; // da li su stringovi isti do tacke kada jedan od njih zavrsava

    int i = 0, j = 0;
    for ( ; i < len1 && j < len2; i++, j++){
        if (str1[i] < str2[j]) { retVal = -1; checkLengthDisparity = false; break; } // ako je prvi razlicit char slijeva leksikografski "jaci"
        if (str1[i] > str2[j]) { retVal = 1; checkLengthDisparity = false; break; } // ako je drugi ^
        // ako su karakteri isti nastavljamo s petljom dok ne nadjemo razliku ili dok ne dodjemo do kraja jednog stringa
    }

    // ako imamo npr. "Marko" i "Markovic", uzimamo da je "Marko" leksifografski "jaci" jer je kraca rijec
    // posto se poredjenje zaustavlja na kraju stringa "Marko" pa bi u tom slucaju funkcija vratila 0, sto je netacno
    if (checkLengthDisparity) retVal = (len1 > len2 ? 1 : -1);

    free(str1); free(str2);
    return retVal;
}

#define LOWERONE(c) (*c = (*c >= 'A' && *c <= 'Z') ? *c + 32 : *c) // pretvori jedno veliko slovo u malo
void to_lower(char *string){
    int i = 0;
    while (string[i]) LOWERONE(&string[i]), i++;
}

void bulk_free(int n, ...){
    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++){
        char *string = va_arg(args, char *);
        free(string);
    }
    va_end(args);
}