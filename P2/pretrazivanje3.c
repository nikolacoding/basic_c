// Napisati program u kojem treba u datoteci pretrazivanje2s.txt, iz prethodnog zadatka (pretrazivanje2.c) pronaći
// podatke o studentu čiji se broj indeksa unosi sa standardnog ulaza. Potrebno je iz datoteke pretrazivanje2i.txt
// pročitati sve indeksne zapise i formirati dinamički niz, u kojem će se na osnovu unesenog broja indeksa
// (kljuc), pronaći odgovarajuća adresa početka zapisa o studentu u datoteci pretrazivanje2s.txt, te na taj način
// pročitati i ispisati podatke o pronađenom studentu.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char indeks[8], ime[21], prezime[21];
    double prosjek;
} STUDENT;

typedef struct
{
    char kljuc[8];
    int adresa;
} INDEKS;

int binSearchR(INDEKS *, int, int, char *);
void ispisi_studenta(STUDENT *, int);
void header(); // ispis headera na std izlaz
void footer(); // ispis footera na std izlaz

int main(int argc, char const *argv[])
{
    int res, n = 0, max = 10;
    const char filenameS[64] = "pretrazivanje2s.txt";
    const char filenameI[64] = "pretrazivanje2i.txt";
    FILE *dat;
    STUDENT st;
    INDEKS ind, *indeksi;

    indeksi = (INDEKS *)malloc(max * sizeof(INDEKS));

    if (dat = fopen(filenameI, "r"))
    {
        while (fscanf(dat, "%s %d\n", ind.kljuc, &ind.adresa) != EOF)
        {
            if (n == max)
            {
                max *= 2;
                indeksi = (INDEKS *)realloc(indeksi, max * sizeof(INDEKS));
            }
            indeksi[n++] = ind;
        }
        fclose(dat);
    }

    printf("Unesi broj indeksa za pretragu: "), scanf("%s", st.indeks);
    res = binSearchR(indeksi, 0, n - 1, st.indeks);
    if (res == -1)
        printf("Student nije pronadjen.");
    else
    {
        int rb;
        if (dat = fopen(filenameS, "r"))
        {
            fseek(dat, indeksi[res].adresa, SEEK_SET);
            if (fscanf(dat, "%d. %s %s %s %lf\n", &rb, st.indeks, st.ime, st.prezime, &st.prosjek) == 5)
            {
                header();
                ispisi_studenta(&st, res);
                footer();
                fclose(dat);
            }
        }
    }
    free(indeksi);
    return 0;
}

int binSearchR(INDEKS *niz, int begin, int end, char *kljuc)
{
    int sredina = (begin + end) / 2;
    if (begin > end)
        return -1;

    if (!(strcmp(niz[sredina].kljuc, kljuc)))
        return sredina;

    if (strcmp(kljuc, niz[sredina].kljuc) < 0)
        return binSearchR(niz, begin, sredina - 1, kljuc);
    else if (strcmp(kljuc, niz[sredina].kljuc) > 0)
        return binSearchR(niz, sredina + 1, end, kljuc);
}

void ispisi_studenta(STUDENT *st, int rb)
{
    printf("%02d. %-7s %-16s %-16s %-7.2lf\n", rb, st->indeks, st->ime, st->prezime, st->prosjek);
}

void header()
{
    printf("=== ======= ================ ================ =======\n");
    printf("%2s %-7s %-16s %-16s %-7s\n", "RB.", "INDEKS", "IME", "PREZIME", "PROSJEK");
    printf("=== ======= ================ ================ =======\n");
}

void footer()
{
    printf("=== ======= ================ ================ =======\n");
}