#include <stdio.h>
#include <stdlib.h>

typedef struct osoba
{
    int id;
    double tezina, visina;
    char ime[512], prezime[512];
} OSOBA;

OSOBA *ucitaj();
OSOBA *ucitaj_n(int *);
void pisi(const OSOBA *);
int pronadji(const OSOBA *, int, int);

int main()
{
    OSOBA *niz;
    int n, tid;

    niz = ucitaj_n(&n);

    printf("Unesi ID trazene osobe: ");
    scanf("%d", &tid);

    if (pronadji(niz, n, tid) != -1)
    {
        OSOBA trazenaOsoba = niz[pronadji(niz, n, tid)];
        printf("Trazena osoba:\n");
        pisi(&trazenaOsoba);
    }
    else
    {
        printf("Trazena osoba nije pronadjena. ");
    }

    return 0;
}

OSOBA *ucitaj()
{
    OSOBA o, *pO = &o;
    static int index = 1;

    printf("Unesi identifikator osobe %d: ", index);
    scanf("%d", &pO->id);

    printf("Unesi ime i prezime osobe %d: ", index);
    scanf("%s %s", &pO->ime, &pO->prezime);

    printf("Unesi visinu osobe %d: ", index);
    scanf("%lf", &pO->visina);

    printf("Unesi tezinu osobe %d: ", index);
    scanf("%lf", &pO->tezina);

    index++;
    return pO;
}

OSOBA *ucitaj_n(int *pn)
{
    int n;

    do
    {
        printf("Unesi broj osoba: ");
        scanf("%d", &n);
    } while (n < 1);

    OSOBA *niz = (OSOBA *)malloc(n * sizeof(OSOBA));
    OSOBA *temp;
    *pn = n;

    for (int i = 0; i < n; i++)
    {
        temp = ucitaj();
        niz[i] = *temp;
    }

    return niz;
}

void pisi(const OSOBA *a)
{
    printf("%d | %s %s | %.1lfcm %.1lfkg\n", a->id, a->ime, a->prezime, a->visina, a->tezina);
}

int pronadji(const OSOBA *niz, int n, int id)
{
    for (int i = 0; i < n; i++)
    {
        if (niz[i].id == id)
            return i;
    }

    return -1;
}