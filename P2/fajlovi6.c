// Napisati program koji iscitava artikle iz datoteke kreirane u sklopu prethodnog zadatka (fajlovi5.c).
// Program treba na standardni izlaz da ispise sve artikle zajedno sa njihovim cijenama i kolicinama, kao
// i ukupnu cijenu svih artikala i istaci najskuplji i najjeftiniji artikal pri cijeni 1.00, respektivno.
// Artikli pri ispisu trebaju biti sortirani opadajuce po cijeni. ID nije neophodno sortirati.
// Naziv datoteke iz koje se artikli iscitavaju se navodi preko komandne linije, kao i PROIZVOLJAN popust koji
// korisnik moze ali ne mora da unese, u cjelobrojnim procentima (0-100).

// Napomena: ne podrzava viserjecna imena artikala!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char naziv[16];
    double kolicina, cijena;
} ARTIKAL;

void definisi(ARTIKAL *, char *, double, double);
void sortiraj(ARTIKAL *, int);
void ispisi(ARTIKAL *, int);

int main(int argc, char const *argv[])
{
    int popust = 0;
    char filename[64];

    int iBuffer;
    char nBuffer[128];
    double kBuffer, cBuffer, uBuffer;
    char trashBuffer[128];

    double total = 0;

    ARTIKAL *artikli = (ARTIKAL *)malloc(MAX * sizeof(ARTIKAL));
    int n = 0;

    FILE *fp;
    if (argc == 2 || argc == 3)
    {
        strcpy(filename, argv[1]);
        if (argc == 3)
        {
            popust = atoi(argv[2]);
            if (popust > 100 || popust < 0)
            {
                printf("Popust nije pravilno naveden. Uzima se 0%%.");
                popust = 0;
            }
        }

        if (fp = fopen(filename, "r"))
        {
            fgets(trashBuffer, 127, fp);
            fgets(trashBuffer, 127, fp);

            while (fscanf(fp, "%d %s %lf %lf %lf", &iBuffer, nBuffer, &kBuffer, &cBuffer, &uBuffer) != EOF &&
                   fgetc(fp) != '=' && n < MAX)
            {

                definisi(&artikli[n++], nBuffer, kBuffer, cBuffer - (cBuffer * popust) / 100);
                total += artikli[n - 1].cijena * artikli[n - 1].kolicina;
            }

            artikli = (ARTIKAL *)realloc(artikli, n * sizeof(ARTIKAL));
            sortiraj(artikli, n);
            ispisi(artikli, n);
            printf("\nUkupna cijena svih artikala: %.2lf\n", total);

            if (popust)
                printf("\nOstvaren popust: %d%%\n", popust);
        }
        else
            printf("Greska pri otvaranju datoteke '%s'.", filename);
    }
    else
        printf("Argumenti nisu pravilno navedeni.");

    free(artikli);
    return 0;
}

void definisi(ARTIKAL *artikal, char *naziv, double kolicina, double cijena)
{
    strcpy(artikal->naziv, naziv);
    artikal->kolicina = kolicina;
    artikal->cijena = cijena;
}

void ispisi(ARTIKAL *niz, int n)
{
    static int id = 1;
    printf("\n%02s %15s %10s %11s %11s", "ID", "Naziv", "Kolicina", "Cijena", "Ukupno\n");
    for (int i = 0; i < n; i++)
    {
        printf("%02d %15s %10.1lf %11.1lf %10.1lf\n", id++,
               niz[i].naziv, niz[i].kolicina, niz[i].cijena, niz[i].cijena * niz[i].kolicina);
    }
}

void sortiraj(ARTIKAL *niz, int n)
{
    ARTIKAL temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (niz[i].cijena * niz[i].kolicina < niz[j].cijena * niz[j].kolicina)
            {
                temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
}