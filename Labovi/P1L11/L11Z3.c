#include <stdio.h>
#include <stdlib.h>

typedef struct DOKUMENT
{
    char naziv[32];
    char ekstenzija[8];
    int velicina;
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
        if ((*(niz + i)).velicina > prag)
        {
            ispisi(*(niz + i));
            printf("\n");
        }
    }
    printf("========================\n");

    free(niz);
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
    for (int i = 0; i < *n; i++)
    {
        printf("%d. dokument:\n", i + 1);
        printf("Ime: ");
        scanf("%s", &(*(niz + i)).naziv);
        printf("Ekstenzija: ");
        scanf("%s", &(*(niz + i)).ekstenzija);
        printf("Velicina [B]: ");
        scanf("%d", &(*(niz + i)).velicina);
    }

    return niz;
}

void ispisi(DOKUMENT doc)
{
    printf("%s.%s | %dB", doc.naziv, doc.ekstenzija, doc.velicina);
}