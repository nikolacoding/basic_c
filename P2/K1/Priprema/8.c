// Neka su dati tipovi VOZILO i INDEKS.
// Napisati program u kojem treba u binarnoj datoteci, čiji je naziv prvi argument linije, pronaći podatke o vozilu
// čiji se broj šasije unosi kao drugi argument linije. Potrebno je iz binarne datoteke, čiji je naziv dat kao
// treći argument komandne linije, pročitati sve indeksne zapise i formirati dinamički niz u kojem će se, na
// osnovu unesenog broja šasije (parametar broj_sasije), pronaći odgovarajuća adresa početka zapisa o vozilu u
// datoteci, te na taj način pročitati i ispisati podatke o pronađenom vozilu. Za pretragu indeksne datoteke
// koristiti interpolaciono pretraživanje.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct vozilo
{
    char broj_sasije[8];
    char proizvodjac[21];
    char model[21];
    double snaga;
} VOZILO;

typedef struct indeks
{
    char broj_sasije[8];
    int adresa;
} INDEKS;

void upisi_vozila(const char *, const char *, VOZILO *, int);
void pronadji_vozilo(const char *, const char *, const char *);

int main(int argc, char const *argv[])
{
    if (argc == 4)
    {
        char voziladat[21], indeksdat[21], target[8];
        strcpy(voziladat, argv[1]);
        strcpy(target, argv[2]);
        strcpy(indeksdat, argv[3]);

        const int n = 3;
        VOZILO vozilazaupis[3] = {{"123", "Renault", "Megane", 112.5},
                                  {"124", "Porsche", "Panamera", 670},
                                  {"125", "Skoda", "Superb", 140}};
        upisi_vozila(voziladat, indeksdat, vozilazaupis, n);
        pronadji_vozilo(voziladat, indeksdat, target);
    }
    else
        printf("Argumenti nisu pravilno navedeni.\n");

    return 0;
}

void pronadji_vozilo(const char *dat, const char *ind, const char *target)
{
    FILE *fp, *fpi;
    int n = 0, p = 0, max = 100, kljuc = -1;
    INDEKS in, *niz = (INDEKS *)malloc(max * sizeof(INDEKS));
    VOZILO v;

    if (fpi = fopen(ind, "rb"))
    {
        do
        {
            p = fread(&in, sizeof(INDEKS), 1, fpi);
            if (p)
            {
                niz[n++] = in;
                if (!strcmp(in.broj_sasije, target))
                    kljuc = in.adresa;
            }

        } while (p);
        niz = (INDEKS *)realloc(niz, n * sizeof(INDEKS));
        fclose(fpi);
    }
    else
        printf("Greska.\n");

    int begin = 0, end = n - 1, sredina, brojilac, imenilac;
    do
    {
        brojilac = (kljuc - niz[begin].adresa) * (end - begin);
        imenilac = (niz[end].adresa - niz[begin].adresa);
        sredina = begin + brojilac / imenilac;

        if (niz[sredina].adresa == kljuc)
        {
            printf("Pronadjen je automobil sasije '%s':\n", target);
            if (fp = fopen(dat, "rb"))
            {
                fseek(fp, niz[sredina].adresa, SEEK_SET);
                fread(&v, sizeof(VOZILO), 1, fp);
                printf("- %s\n- %s\n- %.1lfhp\n", v.proizvodjac, v.model, v.snaga);
                fclose(fp);
                free(niz);
                return;
            }
            else
                printf("Greska.\n");
        }

        if (kljuc > niz[sredina].adresa)
            begin = sredina + 1;
        if (kljuc < niz[sredina].adresa)
            end = sredina - 1;

    } while (begin <= end);
    printf("Vozilo sasije '%s' nije pronadjeno.\n", target);
}

void upisi_vozila(const char *dat, const char *ind, VOZILO *niz, int n)
{
    FILE *fp, *fpi;
    INDEKS in[n];
    if (fp = fopen(dat, "wb"))
    {
        if (fpi = fopen(ind, "wb"))
        {
            for (int i = 0; i < n; i++)
            {
                in[i].adresa = ftell(fp);
                strcpy(in[i].broj_sasije, niz[i].broj_sasije);
                fwrite(niz + i, sizeof(VOZILO), 1, fp);
            }
            fwrite(in, sizeof(INDEKS), n, fpi);
        }
    }
    fclose(fp);
    fclose(fpi);
}