// Definisati tip DATUM koji se reprezentuje danom, mjesecom i godinom.
// Definisati tip STUDENT kog reprezentuje: jedinstveni ID, ime, prezime, br. indeksa, prosjek i datum rodjenja.
// Definisati tip CVOR/NODE kojim se pristupa jednostruko ulancanoj listi.
// Napisati program koji funkcionise kao meni sa 4 opcije:
// 1) dodaj [a]
// 2) obrisi [d]
// 3) ispisi [w]
// 4) kraj [0]
// Korisniku se unosom jednog od karaktera u uglastim zagradama omogucava da manipulise listom studenata koja se
// reprezentuje jednostruko ulancanom listom. Korisniku se na pocetku rada kao i poslije koriscenja bilo koje opcije
// na ekran formatirano ispisuje lista postojecih studenata u obliku "ID | prosjek", te pri izboru bilo koje opcije
// koja radi sa vec postojecim studentima, korisnik treba da studente bira preko ID-a.
//
// Opcijom 'dodaj [a]', korisnik dodaje korisnika u ulancanu listu sortiranog po prosjeku u odnosu na ostale.
// Opcijom 'obrisi [d]', korisnik brise odabranog studenta.
// Opcijom 'ispisi [w]', korisnik ispisuje sve podatke o odabranom studentu.
// Opcijom 'kraj [0]', korisnik bira da prestane sa radom i izvrsvanje programa prestaje.
// 
// Vremenska slozenost mora biti manja od O(n^2) u najgorem slucaju.
// Sortiranje studenata se mora obaviti sa O(1) prostornom slozenoscu, dakle direktno u listi odmah pri dodavanju.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int dan, mjesec, godina;
} DATUM;

typedef struct{
    int id;
    char ime[21], prezime[21], indeks[8];
    double prosjek;
    DATUM datum_rodjenja;
} STUDENT;

typedef struct node{
    STUDENT st;
    struct node *next;
} NODE;

// Meni funkcije
void ispisi_opcije(const char *message); // ispisuje opcije kao i poruku o prethodno koristenoj
void ispisi_studente(NODE *lista); // formatirano ispisuje listu dostupnih studenata u listi
void ispisi_o_studentu(char **pString); // ispisuje i dealocira dodatan info string o studentu ukoliko nije prazan
void wipe(const unsigned n); // ciscenje terminala ('\n' spam)
 
// Handleri
void dodajHandler(void (*addNode)(NODE **), NODE **lista, int maxN, char **msg, const char *suc, const char *err);
void obrisiHandler(bool (*pretraga)(NODE **, NODE **), void (*brisanje)(NODE **, NODE *), NODE **l, char **msg, const char *suc, const char *err);
void ispisiHandler(bool (*pretraga)(NODE **, NODE **), char *(*dis)(NODE *), NODE **lista, char **msg, char **infoMsg, const char *suc, const char *err);
void krajHandler(bool *status, const char *message);
void invalidInputHandler(char **msg, const char *err);

// Rad sa ulancanom listom
bool unesiStudentaVratiNode(NODE **lista, NODE **ret); // true - pronadjen; false - nije pronadjen
void defineAndAddNode(NODE **lista); // definise studenta i dodaje kao cvor
void deleteTargetNode(NODE **lista, NODE *target); // brise ciljani cvor

// Pomocne funkcije
void definisi_studenta(STUDENT *st); // za definisanje studenta (p.f. za dodajHandler)
char *detaljan_info_string(NODE *target); // vraca detaljan string o target studentu (p.f. za ispisiHandler)

#define WIPE_NEWLINE_COUNT 100
#define MAX 20
#define MESSAGE_BUFFER 128

#define DEFAULT_MESSAGE "Izaberi opciju:\n"
#define INVALID_INPUT "Unos nije validan.\n"
#define END "Kraj rada.\n"

#define ADD_SUCCESS "Student uspjesno dodan.\n"
#define DELETE_SUCCESS "Student uspjesno obrisan.\n"
#define WRITE_SUCCESS "Podaci o unesenom studentu:\n"

#define ADD_ERROR "Nije moguce dodati studenta (mozda je dostignut maksimum?).\n"
#define DELETE_ERROR "Nije moguce obrisati navedenog studenta.\n"
#define WRITE_ERROR "Nije moguce ispisati podatke o navedenom studentu.\n"

int main(void)
{
    NODE *lista = NULL;

    enum choices_e { DODAJ = 'a', OBRISI = 'd', ISPISI = 'w', KRAJ = '0'};
    char cchoice[8]; // iako je unos jedan karakter, citamo kratak string i uzimamo [0] da izbjegnemo probleme sa stdin
    
    bool isActive = true;

    char *message = calloc(MESSAGE_BUFFER, sizeof(char)); // poruka nakon unosa izbora i/ili izvrsavanja opcije
    char *stInfoMessage = NULL; // detaljne informacije o studentu koje se ispisuju izborom opcije ISPISI

    while (isActive){
        wipe(WIPE_NEWLINE_COUNT);
        ispisi_studente(lista);
        ispisi_o_studentu(&stInfoMessage);
        ispisi_opcije(message);
        
        printf("Izbor: ");
        scanf("%s", cchoice);

        switch(cchoice[0]){
            case DODAJ: dodajHandler(&defineAndAddNode, &lista, MAX, &message, ADD_SUCCESS, ADD_ERROR); break;
            case OBRISI: obrisiHandler(&unesiStudentaVratiNode, &deleteTargetNode, &lista, &message, DELETE_SUCCESS, DELETE_ERROR); break;
            case ISPISI: ispisiHandler(&unesiStudentaVratiNode, &detaljan_info_string, &lista, &message, &stInfoMessage, WRITE_SUCCESS, WRITE_ERROR); break;
            case KRAJ: krajHandler(&isActive, END); break;
            default: invalidInputHandler(&message, INVALID_INPUT); break;
        }
    }
    return 0;
}



void ispisi_opcije(const char *message){
    printf("> %s", message);
    printf("\n> Dodaj [a]\n");
    printf("> Obrisi [d]\n");
    printf("> Ispisi [w]\n");
    printf("> Kraj [0]\n");
}

void ispisi_studente(NODE *lista){
    if (!lista) { printf("Lista studenata je prazna.\n"); return; }

    printf("Dostupni studenti:\n");
    STUDENT st;
    while (lista){
        st = lista->st;
        printf("%d | %.2lf\n", st.id, st.prosjek);
        lista = lista->next;
    }
    printf("\n");
}

void ispisi_o_studentu(char **pString){
    if (*pString){
        printf("%s\n", *pString);
        free(*pString);
        *pString = NULL;
    }
}

void wipe(const unsigned n) { for (unsigned i = 0; i < n; i++) printf("\n"); };



void dodajHandler(void (*addNode)(NODE **), NODE **lista, int maxN, char **msg, const char *suc, const char *err){
    static int count = 0;
    if (count < maxN){
        (*addNode)(lista);
        strcpy(*msg, suc);
    } else strcpy(*msg, err);
}

void obrisiHandler(bool (*pretraga)(NODE **, NODE **), void (*brisanje)(NODE **, NODE *), NODE **lista, char **msg, const char *suc, const char *err){
    NODE *target = malloc(sizeof(NODE));

    if ((*pretraga)(lista, &target)){
        (*brisanje)(lista, target);
        strcpy(*msg, suc);
    }
    else strcpy(*msg, err);
    free(target);
}

void ispisiHandler(bool (*pretraga)(NODE **, NODE **), char *(*dis)(NODE *), NODE **lista, char **msg, char **infoMsg, const char *suc, const char *err){
    NODE *target = malloc(sizeof(NODE));
    if (pretraga(lista, &target)){
        *infoMsg = (*dis)(target);
        strcpy(*msg, suc);
    } else strcpy(*msg, err);
}

void krajHandler(bool *status, const char *message){
    *status = false;
    printf("%s", message);
}

void invalidInputHandler(char **msg, const char *err){ strcpy(*msg, err); }



bool unesiStudentaVratiNode(NODE **lista, NODE **ret){
    int id;
    printf("Unesi ID trazenog studenta: ");
    scanf("%d", &id);

    NODE *target = *lista;
    while (target){
        if (target->st.id == id){
            *ret = target;
            return true;
        }
        target = target->next;
    }
    return false;
}

void defineAndAddNode(NODE **lista){
    STUDENT st;
    definisi_studenta(&st);
    
    NODE *new;
    new = malloc(sizeof(NODE));
    new->st = st;
    new->next = NULL;

    if (*lista == NULL) *lista = new;
    else{
        NODE *curr = *lista, *prev = NULL;
        while (curr->st.prosjek >= st.prosjek && curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        if (prev){ // ako je poredjenje zavrseno na bilo kom cvoru liste sem prvog:
            if (curr->st.prosjek >= st.prosjek){ // ako je prosjek el. na kom je curr pokazivac >= od novog, umecemo poslije prvog
                curr->next = new;
            }
            else{ // ako je prosjek elementa na kom je curr pokazivac < od novog, umecemo prije
                prev->next = new;
                new->next = curr;
            }
        }
        else{ // ako je poredjenje zavrseno na prvom cvoru liste:
            if (curr->st.prosjek >= st.prosjek){ // ako je prosjek novog <= od pokazanog-
                NODE *R = curr->next; // -gledamo da li postoji element poslije poredjenog-
                new->next = R; // -i to je sada sljedeci element novog bilo da postoji ili ne (NULL)-
                curr->next = new; // -i sljedeci element pokazanog je nov
                // ovim dobijamo curr -> new -> R ili curr -> new -> NULL
            }
            else{ // ako je prosjek novog > od pokazanog, cinimo ga novom glavom liste
                *lista = new;
                (*lista)->next = curr;
            }
        }
    }
}

void deleteTargetNode(NODE **lista, NODE *target){
    NODE *curr = *lista, *prev = NULL;

    if (!(*lista)) return; // ako je lista prazna
    else{
        while (curr != target){ // podrazumijeva se da NODE *target postoji na NODE **lista
            prev = curr;
            curr = curr->next;
        }
        if (prev) prev->next = curr->next; // ako prev postoji znaci da nije prvi, te je brisanje standardno
        else *lista = (*lista)->next; // ako prev ne postoji onda je u pitanju prvi element pa glavu pomjeramo unaprijed
        free(target);                 // ^ ne moramo provjeravati naredni jer je vracanje NULL glave takodje povoljno
                                      // u slucaju kada lista ima samo jedan element
    }
}



void definisi_studenta(STUDENT *st){
    static int id = 1;
    st->id = id++;

    printf(">> Ime: ");
    scanf("%s", st->ime);

    printf(">> Prezime: ");
    scanf("%s", st->prezime);

    printf(">> Indeks: ");
    scanf("%s", st->indeks);

    printf(">> Prosjek: ");
    scanf("%lf", &st->prosjek);

    printf(">> Datum rodjenja (format: d m g): ");
    scanf("%d %d %d", &st->datum_rodjenja.dan, &st->datum_rodjenja.mjesec, &st->datum_rodjenja.godina);
}

char *detaljan_info_string(NODE *target){
    const int maxLen = 1024;
    int len;

    char *ret = calloc(maxLen, sizeof(char));

    STUDENT st = target->st;

    len = sprintf(ret, "(ID: %d) %s | %s %s (%d.%d.%d) - %.2lf\n", 
    st.id, st.indeks, st.prezime, st.ime, 
    st.datum_rodjenja.dan, st.datum_rodjenja.mjesec, st.datum_rodjenja.godina,
    st.prosjek);
    ret = realloc(ret, len * sizeof(char) + 1);

    return ret;
}