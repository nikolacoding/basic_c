#include <stdio.h>
#include <stdlib.h>

typedef struct DATUM
{
    int dan;
    int mjesec;
    int godina;
} DATUM;

typedef struct DOKUMENT
{
    char naziv[32];
    char ekstenzija[8];
    int velicina;
    DATUM datumKreacije;
} DOKUMENT;

DOKUMENT *formiraj(int *);
void ispisi(DOKUMENT);

int main()
{
    int n;
    int prag;
    DOKUMENT *niz;

    niz = formiraj(&n);

    do
    {
        printf("Unesi prag velicine dokumenata: ");
        scanf("%d", &prag);
    } while (prag < 1);

    printf("\n========================\n");
    for (int i = 0; i < n; i++)
    {
        if (niz[i].velicina > prag && niz[i].datumKreacije.godina == 2022)
        {
            ispisi(niz[i]);
            printf("\n");
        }
    }
    printf("========================\n");

    free(niz);
    niz = NULL;

    return 0;
}

DOKUMENT *formiraj(int *n)
{
    DOKUMENT *niz;
    do
    {
        printf("Unesi broj dokumenata: ");
        scanf("%d", n);
    } while (*n < 1);

    niz = (DOKUMENT *)malloc(*n * sizeof(DOKUMENT));
    if (niz)
    {
        for (int i = 0; i < *n; i++)
        {
            printf("%d. dokument:\n", i + 1);
            printf("Ime: ");
            scanf("%s", &niz[i].naziv);
            printf("Ekstenzija: ");
            scanf("%s", &niz[i].ekstenzija);
            printf("Velicina [B]: ");
            scanf("%d", &niz[i].velicina);
            printf("Datum kreacije: ");
            scanf("%d %d %d", &niz[i].datumKreacije.dan,
                  &niz[i].datumKreacije.mjesec,
                  &niz[i].datumKreacije.godina);
        }
    }

    return niz;
}

void ispisi(DOKUMENT doc)
{
    printf("%s.%s | %dB", doc.naziv, doc.ekstenzija, doc.velicina);
}