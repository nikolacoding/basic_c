// Napisati program u kojem treba sa standardnog ulaza učitati podatke za n studenata,
// a potom podatake o studentima upisati u datoteku čiji se naziv uzima takodje sa standardnog ulaza.
// Atributi studenta su indeks, prezime, ime i prosjek. Pored toga, potrebno je kreirati i strukturu INDEKS,
// koja predstavlja look-up tabelu, pomoću koje će se efikasnije pretraživati datoteka sa studentima.
// Atributi indeksa su kljuc i adresa. Indekse je potrebno održavati sortirane u dinamičkom nizu,
// a zatim sačuvati u datoteku čiji je naziv drugi argument komandne linije.

// Napomena: imena datoteka su stavljena kao konstantna zarad lakseg rada

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

void header(FILE *);
void footer(FILE *);

void ucitaj_studenta(STUDENT *);
void upisi_studenta(STUDENT, FILE *, INDEKS *, int);
void upisi_indekse(INDEKS *, int, FILE *);
void azuriraj_indekse(INDEKS *, INDEKS, int);

int main(int argc, char const *argv[])
{
    int n;
    // char filenameS[64], filenameI[64];
    FILE *dat;
    STUDENT st;
    INDEKS *indeksi;

    // printf("Unesi ime datoteke za studente: "), scanf("%s", filenameS);
    // printf("Unesi ime datoteke za indekse: "), scanf("%s", filenameI);

    const char filenameS[64] = "pretrazivanje2s.txt";
    const char filenameI[64] = "pretrazivanje2i.txt";
    printf("Unesi broj studenata: "), scanf("%d", &n);

    indeksi = (INDEKS *)malloc(n * sizeof(INDEKS));

    if (dat = fopen(filenameS, "w"))
    {
        header(dat);
        for (int i = 0; i < n; i++)
        {
            printf("Podaci o %d. studentu:\n", i + 1), ucitaj_studenta(&st);
            upisi_studenta(st, dat, indeksi, i + 1);
        }
        footer(dat);
        fclose(dat);
    }
    if (dat = fopen(filenameI, "w"))
    {
        upisi_indekse(indeksi, n, dat);
        fclose(dat);
    }

    free(indeksi);

    return 0;
}

void ucitaj_studenta(STUDENT *st)
{
    printf("    Indeks: "), scanf("%s", st->indeks);
    printf("    Ime: "), scanf("%s", st->ime);
    printf("    Prezime: "), scanf("%s", st->prezime);
    printf("    Prosjek: "), scanf("%lf", &st->prosjek);
}

void upisi_studenta(STUDENT st, FILE *dat, INDEKS *indeksi, int rb)
{
    INDEKS ind;
    strcpy(ind.kljuc, st.indeks);
    ind.adresa = ftell(dat);
    azuriraj_indekse(indeksi, ind, rb);

    fprintf(dat, "%02d. ", rb);
    fprintf(dat, "%-7s %-20s %-20s %7.2lf\n", st.indeks, st.ime, st.prezime, st.prosjek);
}

void upisi_indekse(INDEKS *niz, int n, FILE *dat)
{
    for (int i = 0; i < n; i++)
        fprintf(dat, "%s %d\n", niz[i].kljuc, niz[i].adresa);
}

void azuriraj_indekse(INDEKS *niz, INDEKS ind, int n)
{
    int i;
    for (i = n - 1; i > 0 && strcmp(ind.kljuc, niz[i - 1].kljuc) < 0; i--)
        niz[i] = niz[i - 1];
    niz[i] = ind;
}

void header(FILE *dat)
{
    fprintf(dat, "=== ======= ==================== ==================== =======\n");
    fprintf(dat, "RB. INDEKS  PREZIME              IME                  PROSJEK\n");
    fprintf(dat, "=== ======= ==================== ==================== =======\n");
}

void footer(FILE *dat)
{
    fprintf(dat, "=== ======= ==================== ==================== =======\n");
}