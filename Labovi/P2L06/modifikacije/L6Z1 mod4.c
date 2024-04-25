// Napisati program u kojem treba:
//    - definisati tip STUDENT kojim se reprezentuje student čiji su atributi: ime, prezime i broj indeksa;
//    - definisati tip CVOR kojim se reprezentuje čvor jednostruko povezane liste (informacioni sadržaj
//      treba da bude tipa STUDENT);
//    - definisati funkciju koja dodaje novi čvor na početak liste;
//    - definisati funkciju koja ispisuje sadržaj liste na standardni izlaz;
//    - definisati funkciju koja formatirano upisuje u tekstualnu datoteku čvorove liste tipa STUDENT;
//     
//    - u glavnom programu ilustrovati rad sa (neuređenom) jednostruko povezanom listom tj. definisanim funkcijama.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ime[21], prezime[21], indeks[8];
} STUDENT;

typedef struct cvor{
    STUDENT info;
    struct cvor *next;
} CVOR;

// Funkcije iz zadatka
void dodaj(CVOR **, const STUDENT);
void ispisi(CVOR *);
int upisi_u_datoteku(CVOR *, const char *);

// Pomocne funkcije
void writeHeader(FILE *);
void writeFooter(FILE *);
void definisiStudenta(STUDENT *);

// Modifikacija
CVOR *pretrazi(CVOR **, const char *);

#define MAXSTUDENTS 10
#define BUFF 32
int main(int argc, char **argv) // modifikacija
{
    if (argc != 2) { fprintf(stdout, "Argumenti nisu pravilno navedeni.\n"); return 1; } // modifikacija
    int n;
    char filename[BUFF];
    char target[BUFF]; // modifikacija
    strcpy(target, argv[1]); // modifikacija
    CVOR *lista = NULL, *targetNode;
    STUDENT student;
    
    fprintf(stdout, "Unesi broj studenata: ");
    fscanf(stdin, "%d", &n);

    fprintf(stdout, "Unesi ime datoteke: ");
    fscanf(stdin, "%s", filename);

    if (n > 0 && n < MAXSTUDENTS){
        for (int i = 0; i < n; i++){
            printf("> Podaci o %d. studentu:\n", i + 1);
            definisiStudenta(&student);
            dodaj(&lista, student);
        }
    }
    else { printf("Broj studenata (%d) nije validan.\n", n); return 1; }

    targetNode = pretrazi(&lista, target);
    if (!targetNode) printf("Trazeni student imena %s nije pronadjen.\n", target);
    else printf("Pronadjen je student sa datim indeksom: %s %s %s\n", 
                targetNode->info.prezime, targetNode->info.ime, targetNode->info.indeks);

    if (upisi_u_datoteku(lista, filename)){
        printf("U '%s' su uspjesno uneseni podaci o sljedecim studentima:\n", filename);
        ispisi(lista);
    }
    else { printf("Nije moguc upis u '%s'.\n", filename); return 1; }

    return 0;
}
void dodaj(CVOR **head, const STUDENT info){
    CVOR *new = malloc(sizeof(CVOR));
    new->info = info;
    new->next = NULL;

    if (*head == NULL) *head = new;
    else{
        // '0' 
        // '1h' -> '2' -> '3'
        // '0' -> '1h' -> '2' -> '3'
        // '0h' -> '1' -> '2' -> '3'
        new->next = *head;
        *head = new;
    }
}

void ispisi(CVOR *c){
    while (c){
        printf("%s %s %s\n", c->info.prezime, c->info.ime, c->info.indeks);
        c = c->next;
    }
}

int upisi_u_datoteku(CVOR *c, const char *filename){
    FILE *fp;
    static int rb = 1;
    if (fp = fopen(filename, "w")){
        writeHeader(fp);
        while (c){
            fprintf(fp, "%02d %-20s %-20s %-8s\n", rb++, c->info.prezime, c->info.ime, c->info.indeks);
            c = c->next;
        }
        writeFooter(fp);
        fclose(fp);
        return 1;
    }
    else return 0;
}

void definisiStudenta(STUDENT *st){
    fprintf(stdout, ">> Ime: ");
    fscanf(stdin, "%s", st->ime);

    fprintf(stdout, ">> Prezime: ");
    fscanf(stdin, "%s", st->prezime);

    fprintf(stdout, ">> Broj indeksa: ");
    fscanf(stdin, "%s", st->indeks);
}

CVOR *pretrazi(CVOR **head, const char *kljuc){
    CVOR *ptr = *head;
    while (ptr){
        if (!strcmp(ptr->info.ime, kljuc)) return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void writeHeader(FILE *fp){
    fprintf(fp, "== ==================== ==================== =======\n");
    fprintf(fp, "%2s %-20s %-20s %-8s", "RB", "PREZIME", "IME", "BR.IND.\n");
    fprintf(fp, "== ==================== ==================== =======\n");
}

void writeFooter(FILE *fp){
    fprintf(fp, "== ==================== ==================== =======\n");
}