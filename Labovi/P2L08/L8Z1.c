// Potrebno je definisati linearnu strukturu sa FIFO disciplinom pristupa (red) koja služi za smještanje
// podataka o procesima, pri čemu je potrebno koristiti ulančanu reprezentaciju reda. Podaci koji se vode o
// procesu su: naziv procesa i vrijeme izvršavanja u sekundama. Potrebno je napisati program kojim se
// simulira izvršavanje procêsa u realnom vremenu. Korisnik sa standardnog ulaza unosi broj procêsa koji
// će se izvršavati. Naziv procesa (“proces” + redni_broj_procesa) i vrijeme izvršavanja (poziv funkcije
// rand() iz stdlib.h biblioteke) se dodjeljuju automatski prilikom kreiranja novog elementa reda i ispisuju
// na standardni izlaz.
//
// Primjer:
//      - naziv_procesa: proces1; vrijeme_izvrsavanja: 3s
//      - naziv_procesa: proces2; vrijeme_izvrsavanja: 5s
//      - naziv_procesa: proces3; vrijeme_izvrsavanja: 4s 
//
// Izvršavanje procesa se pokreće kada korisnik unese riječ “START” sa standardnog ulaza. Izvršavanje
// jednog procesa podrazumijeva ispis naziva procesa na standardni izlaz i zaustavljanje izvršavanja
// glavnog programa pozivom funkcije sleep() iz unistd.h biblioteke (ili neke druge funkcije koja ima istu
// namjenu). Program se završava kada se izvrše (uklone) svi procesi iz reda.
//
// Napomene: 
//      - Za generisanje različitih cijelih brojeva, prije poziva funkcije rand() pozvati sljedeću liniju kôda:
//        srand (time(NULL));
//      - Maksimalno vrijeme izvršavanja procesa ograničiti na pet sekundi, a minimalno na jednu sekundu.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

typedef struct{
    char naziv[10];
    int vrijeme_izvrsvanja;
} PROCES;

typedef struct node{ // za reprezentaciju ulancanog reda
    PROCES info;
    struct node *next;
} NODE;
void put(NODE **qf, NODE **qr, PROCES info); // stavljanje na kraj reda
int get(NODE **qf, NODE **qr, PROCES *info); // uzimanje sa pocetka reda

void add_to_queue(NODE **qf, NODE **qr, int n);
void izvrsi(NODE **qf, NODE **qr);

void wipe(const int n) { for (int i = 0; i < n; i++) printf("\n"); } // "ciscenje" terminala

#define MAX_PROCESSES 10
#define WIPE_ROWS 100
int main(void){
    srand(time(NULL));
    int n;
    const char startcondition[6] = "START";
    char userinput[64];

    do { printf("Unesi broj procesa: "); scanf("%d", &n); } while (n < 1 || n > MAX_PROCESSES);
    printf("Unesi 'START' da pocnemo izvrsavati procese: ");
    do { scanf("%s", userinput); } while (strcmp(userinput, startcondition));

    NODE *front = NULL, *rear = NULL; // inicijalizujemo red
    wipe(WIPE_ROWS);
    add_to_queue(&front, &rear, n);
    izvrsi(&front, &rear);

    return 0;
}

#define MINTIME 1
#define MAXTIME 5
void add_to_queue(NODE **qf, NODE **qr, int n){ 
    PROCES tempinfo;
    for (int i = 0; i < n; i++){
        sprintf(tempinfo.naziv, "proces%d", i + 1);

        int exectime = rand() % MAXTIME;
        if (!exectime) exectime = MINTIME; // ako je nula stavljamo na minimalnu vrijednost

        tempinfo.vrijeme_izvrsvanja = exectime;

        put(qf, qr, tempinfo);
    }
}

void izvrsi(NODE **qf, NODE **qr){
    PROCES curr;

    int n_exec = 0, total_time = 0;
    while (get(qf, qr, &curr)){
        char *naziv = curr.naziv;
        int t = curr.vrijeme_izvrsvanja;

        printf("%s: %ds ", naziv, t);
        for (int i = 0; i < t; i++) { Sleep(1000); printf("."); };
        printf("\n");

        n_exec++;
        total_time += t;
    }
    printf("Uspjesno izvrseno %d procesa za %d sekundi!\n", n_exec, total_time);
}

void put(NODE **qf, NODE **qr, PROCES info){
    NODE *new = malloc(sizeof(NODE));
    if (!new) return;
    new->info = info;

    if (!*qr) *qf = *qr = new;
    else{
        (*qr)->next = new;
        *qr = new;
        new->next = NULL;
    }
}

int get(NODE **qf, NODE **qr, PROCES *info){
    if (!*qf) return 0;

    NODE *target = *qf;
    *info = target->info;

    if (target->next) *qf = target->next;
    else *qf = *qr = NULL;

    free(target);
    return 1;
}