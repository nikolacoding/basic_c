#include <stdio.h>
#include <stdlib.h>
#define NFUNC 2

void serija(int *, int, int (*)(int), int **, int *);
int paran(int n) { return (n % 2) ? 0 : 1; }
int pozitivan(int n) { return (n >= 0) ? 1 : 0; };

int main(int argc, char const *argv[])
{
    int n, *niz, **pocetak, *duzina;

    do
    {
        printf("Unesi broj clanova niza: ");
        scanf("%d", &n);
    } while (n < 1);

    niz = (int *)malloc(n * sizeof(int));
    duzina = (int *)malloc(NFUNC * sizeof(int));
    pocetak = (int **)malloc(NFUNC * sizeof(int *)); // niz pokazivaca na clanove niza koji zadovoljavaju svojstva

    for (int i = 0; i < n; i++)
    {
        printf("Clan (%d/%d): ", i + 1, n);
        scanf("%d", &niz[i]);
    }

    serija(niz, n, &paran, pocetak, duzina);     // 0
    serija(niz, n, &pozitivan, pocetak, duzina); // 1

    enum index
    {
        PAR = 0,
        POZ = 1
    };

    printf("Najduza serija parnih: ");
    for (int i = 0; i < duzina[PAR]; i++)
        printf("%d ", pocetak[PAR][i]);

    printf("\nNajduza serija pozitivnih: ");
    for (int i = 0; i < duzina[POZ]; i++)
        printf("%d ", pocetak[POZ][i]);

    free(niz);
    free(duzina);
    free(pocetak);

    return 0;
}

void serija(int *niz, int n, int (*s)(int), int **pocetak, int *duzina)
{
    static int ind = 0;
    int duz = 0;
    int max = 0;
    int *max_poc;

    for (int i = 0; i < n; i++)
    {
        if ((*s)(niz[i]))
        {
            duz++;
            if (duz > max)
            {
                max = duz;
                max_poc = &niz[i] - max + 1;
            }
        }
        else
            duz = 0;
    }
    duzina[ind] = max;
    pocetak[ind] = max_poc;
    ind++;
}
