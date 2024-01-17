#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct datum
{
    int d, m, g;
} DATUM;

typedef struct student
{
    char indeks[10];
    char ime[21];
    char prezime[21];
    DATUM datum_rodjenja;
    double prosek;
} STUDENT;

STUDENT *ucitaj(int *);
STUDENT *pronadji(STUDENT *, int, const char *);
void sortiraj(STUDENT *, int);
void ispisi(STUDENT *, int);

int main()
{
    int n = 0;
    STUDENT *niz = ucitaj(&n);

    printf("Da li fakultet pohadja 1230/23? - %s\n", (pronadji(niz, n, "1230/23") == NULL) ? "Ne." : "Da.");

    ispisi(niz, n);
    sortiraj(niz, n);
    ispisi(niz, n);

    return 0;
}

STUDENT *ucitaj(int *pn)
{
    int n;
    printf("Unesi broj studenata: ");
    scanf("%d", &n);

    STUDENT *niz = (STUDENT *)malloc(n * sizeof(STUDENT));
    *pn = n;

    for (int i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);

        printf("Broj indeksa: ");
        scanf("%s", &niz[i].indeks);

        printf("Ime: ");
        scanf("%s", &niz[i].ime);

        printf("Prezime: ");
        scanf("%s", &niz[i].prezime);

        printf("Datum rodjenja: ");
        scanf("%d %d %d", &niz[i].datum_rodjenja.d, &niz[i].datum_rodjenja.m, &niz[i].datum_rodjenja.g);

        printf("Prosjek: ");
        scanf("%lf", &niz[i].prosek);
    }

    return niz;
}

STUDENT *pronadji(STUDENT *niz, int n, const char *indeks)
{
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(niz[i].indeks, indeks))
        {
            return (niz + i);
        }
    }

    printf("Vracamo null\n");
    return NULL;
}

void sortiraj(STUDENT *niz, int n)
{
    STUDENT temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (niz[i].prosek < niz[j].prosek)
            {
                temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
}

void ispisi(STUDENT *niz, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s | %s %s (%d.%d.%d) - %.2lf\n", niz[i].indeks, niz[i].ime, niz[i].prezime,
               niz[i].datum_rodjenja.d, niz[i].datum_rodjenja.m, niz[i].datum_rodjenja.g, niz[i].prosek);
    }
    printf("\n\n");
}