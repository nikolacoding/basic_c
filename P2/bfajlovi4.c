// Napisati program u kojem treba iz datoteke, čiji je naziv prvi argument komandne linije,
// pročitati (binarno upisane, nesortirane) podatke o nepoznatom broju artikala i formirati
// odgovarajući dinamički niz, a zatim učitani niz podataka o artiklima sortirati opadajuće
// prema ukupnoj cijeni i formatirano ispisati na standardni izlaz. Atributi artikla su naziv, količina i cijena.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char naziv[32];
    double kolicina, cijena;
} ARTIKAL;

void sortiraj(ARTIKAL *, int);
void swap(ARTIKAL *, ARTIKAL *);

void ispisi(ARTIKAL *, int);

int main(int argc, char const *argv[])
{
    ARTIKAL *artikli, art;
    FILE *fp;
    int p, n;
    char filename[64];

    if (argc == 2)
    {
        strcpy(filename, argv[1]);
        artikli = (ARTIKAL *)malloc(MAX * sizeof(ARTIKAL));

        if (fp = fopen(argv[1], "rb"))
        {
            do
            {
                p = fread(&art, sizeof(ARTIKAL), 1, fp);
                if (p)
                    artikli[n++] = art;
            } while (p);

            artikli = (ARTIKAL *)realloc(artikli, n * sizeof(ARTIKAL));
        }
        fclose(fp);

        sortiraj(artikli, n);
        ispisi(artikli, n);
    }
    else
        printf("Argumenti nisu pravilno navedeni.");

    free(artikli);
    return 0;
}

void swap(ARTIKAL *a, ARTIKAL *b)
{
    ARTIKAL temp;
    temp = *a, *a = *b, *b = temp;
}

void sortiraj(ARTIKAL *niz, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (niz[i].cijena * niz[i].kolicina < niz[j].cijena * niz[j].kolicina)
                swap(niz + i, niz + j);
}

void ispisi(ARTIKAL *niz, int n)
{
    int ind = 1;
    printf("=== ================ ========= ======\n");
    printf("%-3s %-16s %-9s %-6s", "BR.", "NAZIV", "KOLICINA", "CIJENA\n");
    printf("=== ================ ========= ======\n");

    for (int i = 0; i < n; i++)
        printf("%03d %-16s %-9.1lf %-6.1lf\n", ind++, niz[i].naziv, niz[i].kolicina, niz[i].cijena);

    printf("=== ================ ========= ======\n");
}