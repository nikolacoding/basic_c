// Napisati funkciju koja iz ulazne tekstualne datoteke (dat) učitava i vraća sve prirode brojeve.
// Prirodan broj (u datoteci) je jedna ili više uzastopnih cifara, a od drugog prirodnog broja odvojen
// je jednim ili više znakova koji nisu cifre. Pretpostaviti da se svaki prirodan broj može reprezetovati
// tipom int. Preko parametra n funkcija vraća ukupan broj učitanih prirodnih brojeva.
// Prototip funkcije je: int *prirodni(FILE *dat, int *n);

// Napisati rekurzivnu funkciju koja sabira niz od n prirodnih brojeva, a čiji je prototip:
// int zbir(const int *niz, int n);

// Napisati funkciju sa promjenljivim brojem argumenata koja prihvata prirodan broj k i k stringova
// koji predstavljaju nazive ulaznih tekstualnih datoteka. Funkcija treba da izračuna i vrati zbir svih
// prirodnih brojeva koji su upisani u ulaznim tekstualnim datotekama. Prototip funkcije je int zbir_d(int k, ...);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define MAX 1000

int *prirodni(FILE *, int *);
int zbir(const int *, int);
int zbir_d(int, ...);

int main(int argc, char const *argv[])
{
    char filename[6] = "2.txt";
    FILE *fp;

    int n;
    const int k = 2;

    if (fp = fopen(filename, "r"))
    {
        printf("Open.\n");
        int *niz = prirodni(fp, &n);

        printf("Brojevi u '%s': ", filename);
        for (int i = 0; i < n; i++)
            printf("%d ", niz[i]);

        printf("\nZbir ^ brojeva: %d", zbir(niz, n));

        printf("\nZbir brojeva u %d navedene datoteke je: %d", k, zbir_d(k, "2(1).txt", "2(2).txt"));
    }
    else
        printf("Nije moguce otvoriti datoteku '%s'.", filename);
    return 0;
}

int zbir_d(int k, ...)
{
    int *niz = (int *)malloc(MAX * sizeof(int));
    int zb = 0;
    int n = 0;
    FILE *fp;

    va_list args;
    va_start(args, k);
    for (int i = 0; i < k; i++)
    {
        char *arg = va_arg(args, char *);
        if (fp = fopen(arg, "r"))
            niz = prirodni(fp, &n);

        zb += zbir(niz, n);
        free(niz);
    }
    va_end(args);

    return zb;
}

int *prirodni(FILE *fp, int *n)
{
    int *niz = (int *)malloc(MAX * sizeof(int));
    char *buffer = (char *)calloc(MAX, sizeof(char));
    char c;
    int cnt = 0, i = 0, j = 0;

    printf("\n");
    do
    {
        c = getc(fp);

        if (c >= '0' && c <= '9')
            buffer[i++] = c;
        else
        {
            int len = strlen(buffer);
            if (len)
            {
                niz[j++] = atoi(buffer);
                for (int d = 0; d < len; d++)
                    buffer[d] = 0;
                i = 0;
            }
        }
    } while (c != EOF);

    *n = j;
    niz = (int *)realloc(niz, j * sizeof(int));
    free(buffer);

    return niz;
}

int zbir(const int *niz, int n)
{
    if (n == 1)
        return niz[0];
    if (!n)
        return 0;

    return niz[n - 1] + zbir(niz, n - 1);
}