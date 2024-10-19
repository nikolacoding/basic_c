// Folder: 2021
// K2 – 27.01.2021. (A)
// Zadatak: 2

// NAPOMENA: u ovom zadatku se traze prvo tipovi i prototipne funkcije pa tek potom int main() [glavna funkcija]

#include <stdio.h>
#include <stdlib.h>

typedef struct datum
{
    int d, m, g;
} DATUM;

typedef struct kontakt
{
    char ime[21], prezime[21], broj_telefona[21];
    DATUM datum_rodjenja;
} KONTAKT;

KONTAKT ucitaj();
void ispisi(KONTAKT *k);
void ispisi_r(KONTAKT *niz, int n, DATUM d);

int main()
{
    int n;
    KONTAKT *niz;
    DATUM trazeni;
    trazeni.d = 16;
    trazeni.m = 1;
    trazeni.g = 2001;

    do
    {
        printf("Unesi broj kontakata: ");
        scanf("%d", &n);
    } while (n < 1);

    niz = (KONTAKT *)malloc(n * sizeof(KONTAKT));

    for (int i = 0; i < n; i++)
        niz[i] = ucitaj();

    ispisi_r(niz, n, trazeni);
}

KONTAKT ucitaj()
{
    KONTAKT temp;

    printf("Ime: ");
    scanf("%s", &temp.ime);
    printf("Prezime: ");
    scanf("%s", &temp.prezime);
    printf("Datum rodjenja: ");
    scanf("%d %d %d", &temp.datum_rodjenja.d, &temp.datum_rodjenja.m, &temp.datum_rodjenja.g);
    printf("Broj telefona: ");
    scanf("%s", &temp.broj_telefona);

    return temp;
}

void ispisi(KONTAKT *k)
{
    printf("%s %s (%d.%d.%d) - %s", k->ime, k->prezime,
           k->datum_rodjenja.d, k->datum_rodjenja.m, k->datum_rodjenja.g,
           k->broj_telefona);
}

void ispisi_r(KONTAKT *niz, int n, DATUM d)
{
    for (int i = 0; i < n; i++)
    {
        if (niz[i].datum_rodjenja.d == d.d && niz[i].datum_rodjenja.m && niz[i].datum_rodjenja.g)
        {
            ispisi(&niz[i]);
        }
    }
}