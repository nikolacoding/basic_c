// Napisati program koji omogućava učitavanje artikala sa standardnog ulaza i njihovo
// smještanje u tekstualnu datoteku u formatiranom obliku. Atributi artikla su naziv, količina i cijena.
// Naziv datoteke se navodi kao argument komandne linije (pretpostaviti da će argumenti biti pravilno navedeni).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MARGINWIDTH 52
#define MARGINSTR "="

typedef struct
{
    char naziv[16];
    double kolicina, cijena;
} ARTIKAL;

void pisi(ARTIKAL *, int, FILE *);
void definisi(ARTIKAL *);
void addmargin(FILE *, int, const char const *);

int main(int argc, char const *argv[])
{
    char const *filename = argv[1];
    char choice[16];
    int n_art;
    FILE *fp;
    ARTIKAL *artikli = (ARTIKAL *)malloc(n_art * sizeof(ARTIKAL));

    if (argc != 2)
        printf("Argumenti nisu pravilno navedeni.");
    else
    {
        if ((fp = fopen(filename, "w")) != NULL)
        {
            printf("Unesi broj artikala: ");
            gets(choice);
            n_art = atoi(choice);
            artikli = (ARTIKAL *)malloc(n_art * sizeof(ARTIKAL));

            for (int i = 0; i < n_art; i++)
            {
                printf("[%d/%d] Podaci o artiklu:\n", i + 1, n_art);
                definisi(artikli + i);
            }

            pisi(artikli, n_art, fp);
            fclose(fp);
        }
        else
            printf("Neuspjesno otvaranje datoteke '%s'.", filename);
    }
    free(artikli);
    return 0;
}

void definisi(ARTIKAL *artikal)
{
    char choice[64];

    printf("Naziv: ");
    gets(choice);
    strcpy(artikal->naziv, choice);

    printf("Kolicina: ");
    gets(choice);
    artikal->kolicina = atof(choice);

    printf("Cijena: ");
    gets(choice);
    artikal->cijena = atof(choice);
}

void pisi(ARTIKAL *niz, int n, FILE *fp)
{
    int id = 1;
    double ukupno = 0;
    fprintf(fp, "%02s %15s %10s %11s %11s", "ID", "Naziv", "Kolicina", "Cijena", "Ukupno\n");
    addmargin(fp, MARGINWIDTH, MARGINSTR);
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%02d %15s %10.1lf %11.1lf %10.1lf\n",
                id++,
                niz[i].naziv,
                niz[i].kolicina,
                niz[i].cijena,
                niz[i].cijena * niz[i].kolicina);
        ukupno += niz[i].cijena * niz[i].kolicina;
    }
    addmargin(fp, MARGINWIDTH, MARGINSTR);
    fprintf(fp, "%52s\n", "UKUPNO");
    fprintf(fp, "%52.1lf\n", ukupno);
    fclose(fp);
}

void addmargin(FILE *fp, int n, const char const *s)
{
    static int mar = 0;
    for (int i = 0; i < n; i++, mar++)
        fprintf(fp, s);
    fprintf(fp, "\n");
}