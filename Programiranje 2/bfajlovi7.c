// Napisati program u kojem treba iz datoteke, čiji je naziv prvi argument
// komandne linije, pročitati (binarno upisane) podatke o nepoznatom broju
// studenata i formatirano ih ispisati na standardni izlaz. Podaci koji se
// vode o studentu su: broj indeksa, prezime, ime i prosječna ocjena.
// DODATNO: sortirati opadajuce prema prosjeku

// ^ ovo je takodje inverz prethodnog zadatka iz 'bfajlovi6.c'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char broj_indeksa[8], prezime[64], ime[64];
    double prosjek;
} STUDENT;

void ispisi(STUDENT *, int);
void sortiraj(STUDENT *, int);

int main(int argc, char const *argv[])
{
    int n = 0, p;
    char filename[64];
    FILE *fp;
    STUDENT student;
    STUDENT *studenti = (STUDENT *)malloc(MAX * sizeof(STUDENT));

    if (argc == 2)
    {
        strcpy(filename, argv[1]);
        if (fp = fopen(filename, "rb"))
        {
            do
            {
                p = fread(&student, sizeof(STUDENT), 1, fp);
                if (p)
                    studenti[n++] = student;

            } while (p && n < MAX);

            studenti = (STUDENT *)realloc(studenti, n * sizeof(STUDENT));

            sortiraj(studenti, n);
            ispisi(studenti, n);

            fclose(fp);
            free(studenti);
        }
        else
            printf("Neuspjesno otvaranje datoteke '%s'.", filename);
    }
    else
        printf("Argumenti nisu pravilno navedeni.");
    return 0;
}

void swap(STUDENT *a, STUDENT *b)
{
    STUDENT temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sortiraj(STUDENT *niz, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (niz[j].prosjek > niz[i].prosjek)
                swap(niz + j, niz + i);
}

void ispisi(STUDENT *niz, int n)
{
    printf("=========== ============== =========== =======\n");
    printf("%-11s %-14s %-11s %-7s\n", "BR.IND.", "PREZIME", "IME", "PROSJEK");
    printf("=========== ============== =========== =======\n");

    for (int i = 0; i < n; i++)
        printf("%-11s %-14s %-11s %-7.2lf\n",
               niz[i].broj_indeksa,
               niz[i].prezime,
               niz[i].ime,
               niz[i].prosjek);

    printf("=========== ============== =========== =======\n");
}