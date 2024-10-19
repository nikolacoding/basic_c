#include <stdio.h>
#include <stdlib.h>

typedef struct ARTIKAL
{
    char naziv[16];
    float kolicina;
    float cijena;
} ARTIKAL;

void citaj(ARTIKAL *);
void sortiraj(ARTIKAL *, int);
void pisi(ARTIKAL *);
void ispis(ARTIKAL *, int);

int main()
{
    int n;
    ARTIKAL *niz;

    do
    {
        printf("Unesi broj artikala: ");
        scanf("%d", &n);
    } while (n < 1);

    niz = (ARTIKAL *)malloc(n * sizeof(ARTIKAL));

    for (int i = 0; i < n; i++)
        citaj(niz + i);

    sortiraj(niz, n);
    ispis(niz, n);

    free(niz);
    return 0;
}

void citaj(ARTIKAL *artikal)
{
    static int index = 1;
    printf("Unesi ime artikla (%d): ", index);
    scanf("%s", &artikal->naziv);

    do
    {
        printf("Unesi kolicinu artikla (%d): ", index);
        scanf("%f", &artikal->kolicina);
    } while (artikal->kolicina <= 0);

    do
    {
        printf("Unesi cijenu artikla (%d): ", index);
        scanf("%f", &artikal->cijena);
    } while (artikal->cijena < 0);

    index++;
}

void sortiraj(ARTIKAL *niz, int len)
{
    ARTIKAL temp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i; j < len; j++)
        {
            if ((*(niz + i)).cijena * (*(niz + i)).kolicina < (*(niz + j)).cijena * (*(niz + j)).kolicina)
            {
                temp = *(niz + i);
                *(niz + i) = *(niz + j);
                *(niz + j) = temp;
            }
        }
    }
}

void pisi(ARTIKAL *artikal)
{
    static int rb = 1;

    printf("%02d ", rb);
    printf("%-16s", artikal->naziv);
    printf("%4.1f", artikal->kolicina);
    printf("%8.2f", artikal->cijena);
    printf("%10.2f", artikal->kolicina * artikal->cijena);

    rb++;
}

void ispis(ARTIKAL *niz, int len)
{
    printf("RB. NAZIV           KOL.   CIJENA   UKUPNO\n");

    for (int i = 0; i < len; i++)
    {
        pisi(niz + i);
        printf("\n");
    }
}