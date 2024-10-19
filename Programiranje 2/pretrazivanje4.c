// Napisati program u kom korisnik sa standardnog ulaza bira rezim rada (upis/ispis).
// (od korisnika se trazi unos stringa; ako je prvi karakter #, ulazi se u rezim ispisa, u suprotnom rezim za upis)
//
// Izborom rezima za upis, korisnik na standardni ulaz unosi cjelobrojnu vrijednost n kao i niz od n studenata.
// Svakog studenta karakterise broj indeksa, ime, prezime, godina studija i prosjek. Navedeni niz studenata se
// sortira opadajuce prvo prema godini pa potom prema prosjeku, te formatirano upisuje u tekstualnu datoteku.
// Pored strukture za studenta, takodje se treba napraviti dodatna struktura INDEKS koju karakterisu broj indeksa
// kao i adresa njegovog upisa u formatiranoj tekstualnoj datoteci sa studentima, te svaki indeks i adresu
// potom treba upisati u odvojenu tekstualnu datoteku kao look-up tabelu, takodje u opadajucem redoslijedu. Studenti
// se sortiraju shell-sort algoritmom dok se indeksi sortiraju quick-sort algoritmom.
//
// Izborom rezima za ispis, korisnik na standardni ulaz unosi broj indeksa jednog studenta koji se sekvencijalnom
// pretragom trazi u look-up tabeli sa indeksima, te pri uspjesnoj pretrazi vraca njegovu adresu, a pri neuspjesnoj
// vraca '-1'. Na standardni izlaz se potom ispisuju svi studenti, a poslije njih, ukoliko postoji, trazeni student.
// Obratiti paznju na to da se broj studenata/indeksa inicijalno smatra nepoznatim pri radu u ovom rezimu.

// Kod cjelokupnog rada u rezimu za ispis, nije dozvoljeno ucitavanje informacija iz datoteka
// u memoriju.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// Strukture
typedef struct
{
    char broj[8];
    int adresa;
} INDEKS;

typedef struct
{
    char indeks[8];
    char ime[21], prezime[21];
    int godina;
    double prosjek;
} STUDENT;

// Prototipi
void definisi_studenta(STUDENT *);
void sortiraj_studente(STUDENT *, int); // shell-sort

void ispisi_studente(STUDENT *, int);
void ispisi_jednog_studenta(STUDENT *);

void file_header(FILE *);
void file_pisi_studente(FILE *, STUDENT *, INDEKS *, int);
void file_footer(FILE *);

void sortiraj_indekse(INDEKS *, int, int); // quick-sort
int split(INDEKS *, int, int);             // pomocna funkcija za quick-sort

void file_pisi_indekse(FILE *, INDEKS *, int);

int trazi_studenta_seq(FILE *, char *); // sekvencijalna pretraga

int main(int argc, char const *argv[])
{
    enum eMODE
    {
        UPIS = 0,
        ISPIS = 1
    };

    char choice[64], buffer[1024];
    int mode;
    printf("Unesi rezim rada: ");
    gets(choice);
    if (choice[0] == '#')
        mode = ISPIS;
    else
        mode = UPIS;

    const char const filenametxt[64] = "pretrazivanje4.txt", filenamelt[64] = "pretrazivanje4lt.txt";
    FILE *txt, *lt;
    int n = 0;
    STUDENT *studenti;
    INDEKS *indeksi;

    if (mode == UPIS)
    {
        if (txt = fopen(filenametxt, "w"))
        {
            if (lt = fopen(filenamelt, "w"))
            {
                do
                    printf("Unesi broj studenata: "), scanf("%d", &n);
                while (n < 1 || n > MAX);

                studenti = (STUDENT *)malloc(n * sizeof(STUDENT));
                indeksi = (INDEKS *)malloc(n * sizeof(INDEKS));

                for (int i = 0; i < n; i++)
                    printf(">> Podaci o %d. studentu:\n", i + 1), definisi_studenta(studenti + i);

                sortiraj_studente(studenti, n);
                file_header(txt);
                file_pisi_studente(txt, studenti, indeksi, n);
                file_footer(txt);
                sortiraj_indekse(indeksi, 0, n - 1);
                file_pisi_indekse(lt, indeksi, n);

                fclose(txt);
                fclose(lt);
                free(studenti);
                free(indeksi);
            }
            else
                printf("Datoteka '%s' se ne moze otvoriti.\n", filenamelt);
        }
        else
            printf("Datoteka '%s' se ne moze otvoriti.\n", filenametxt);
    }
    else
    {
        if (txt = fopen(filenametxt, "r"))
        {
            if (lt = fopen(filenamelt, "r"))
            {
                char *kljuc = (char *)calloc(8, sizeof(char));
                printf("Unesi trazeni indeks: "), scanf("%s", kljuc);
                int rez = trazi_studenta_seq(lt, kljuc);

                rewind(lt);
                while (fgets(buffer, 1024, lt))
                    n++;

                if (rez != -1)
                {
                    STUDENT st, sttxt;
                    fseek(txt, rez, SEEK_SET);
                    fscanf(txt, "%s %s %s %lf %d\n", st.indeks, st.ime, st.prezime, &st.prosjek, &st.godina);
                    rewind(txt);

                    fgets(buffer, 1024, txt);
                    fgets(buffer, 1024, txt);
                    fgets(buffer, 1024, txt);
                    for (int i = 0; i < n; i++)
                    {
                        fscanf(txt, "%s %s %s %lf %d", sttxt.indeks, sttxt.ime, sttxt.prezime,
                               &sttxt.prosjek, &sttxt.godina);

                        ispisi_jednog_studenta(&sttxt);
                    }
                    printf("\nPronadjen je student sa indeksom '%s':\n", kljuc);
                    ispisi_jednog_studenta(&st);
                    free(kljuc);
                    fclose(txt);
                    fclose(lt);
                }
                else
                    printf("Nije pronadjen student sa indeksom '%s'.\n", kljuc);
            }
            else
                printf("Datoteka '%s' se ne moze otvoriti.\n", filenamelt);
        }
        else
            printf("Datoteka '%s' se ne moze otvoriti.\n", filenametxt);

        return 0;
    }
}

void definisi_studenta(STUDENT *st)
{
    printf("%16s: ", "Indeks"), scanf("%s", st->indeks);
    printf("%16s: ", "Ime i prezime"), scanf("%s %s", st->ime, st->prezime);
    printf("%16s: ", "Godina"), scanf("%d", &st->godina);
    printf("%16s: ", "Prosjek"), scanf("%lf", &st->prosjek);
}

void sortiraj_studente(STUDENT *niz, int n)
{
    // shell-sort
    // 1. kriterijum: godina
    // 2. kriterijum: prosjek
    int i, j, h;
    STUDENT temp;

    for (h = n / 2; h > 0; h /= 2)
        for (i = 1; i < n; i++)
        {
            temp = niz[i];
            for (j = i; j >= h && (temp.godina > niz[j - h].godina ||
                                   (temp.godina == niz[j - h].godina && temp.prosjek > niz[j - h].prosjek));
                 j -= h)
                niz[j] = niz[j - h];
            niz[j] = temp;
        }
}

void ispisi_studente(STUDENT *niz, int n)
{
    printf("======== ==================== ==================== ======= =\n");
    printf("%-8s %-20s %-20s %7s %1s\n", "INDEKS", "IME", "PREZIME", "PROSJEK", "G");
    printf("======== ==================== ==================== ======= =\n");

    for (int i = 0; i < n; i++)
        printf("%-8s %-20s %-20s %7.2lf %d\n",
               niz[i].indeks,
               niz[i].ime,
               niz[i].prezime,
               niz[i].prosjek,
               niz[i].godina);
    printf("======== ==================== ==================== ======= =\n");
}
void ispisi_jednog_studenta(STUDENT *st)
{
    printf("%-8s %-20s %-20s %7.2lf %d\n",
           st->indeks,
           st->ime,
           st->prezime,
           st->prosjek,
           st->godina);
}

void file_header(FILE *dat)
{
    fprintf(dat, "======== ==================== ==================== ======= =\n");
    fprintf(dat, "%-8s %-20s %-20s %7s %1s\n", "INDEKS", "IME", "PREZIME", "PROSJEK", "G");
    fprintf(dat, "======== ==================== ==================== ======= =\n");
}

void file_pisi_studente(FILE *dat, STUDENT *niz, INDEKS *indeksi, int n)
{
    for (int i = 0; i < n; i++)
    {
        strcpy(indeksi[i].broj, niz[i].indeks);
        indeksi[i].adresa = ftell(dat);
        fprintf(dat, "%-8s %-20s %-20s %-7.2lf %d\n",
                niz[i].indeks,
                niz[i].ime,
                niz[i].prezime,
                niz[i].prosjek,
                niz[i].godina);
    }
}

void file_footer(FILE *dat)
{
    fprintf(dat, "======== ==================== ==================== ======= =\n");
}

void sortiraj_indekse(INDEKS *niz, int begin, int end)
{
    if (begin < end)
    {
        int pivot = split(niz, begin, end);
        sortiraj_indekse(niz, begin, pivot - 1);
        sortiraj_indekse(niz, pivot + 1, end);
    }
}

int split(INDEKS *niz, int begin, int end)
{
    int i = begin, j = end;
    INDEKS pivot = niz[begin];

    while (i < j)
    {
        while (strcmp(pivot.broj, niz[j].broj) <= 0 && i < j)
            i++;
        while (strcmp(pivot.broj, niz[j].broj) > 0)
            j--;

        if (i < j)
        {
            INDEKS temp = niz[i];
            niz[i] = niz[j];
            niz[j] = temp;
        }
    }
    niz[begin] = niz[j];
    niz[j] = pivot;
    return j;
}

void file_pisi_indekse(FILE *dat, INDEKS *niz, int n)
{
    for (int i = 0; i < n; i++)
        fprintf(dat, "%s %d\n", niz[i].broj, niz[i].adresa);
}

int trazi_studenta_seq(FILE *dat, char *kljuc)
{
    char buffer[8];
    int adr;

    while (fscanf(dat, "%s %d", buffer, &adr) != EOF)
        if (!strcmp(buffer, kljuc))
            return adr;
    return -1;
}