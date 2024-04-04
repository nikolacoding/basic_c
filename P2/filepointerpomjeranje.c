#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void ispis(int *, int);

int main(int argc, char const *argv[])
{
    int *niz = (int *)malloc(MAX * sizeof(int));

    char filename[64];
    FILE *fp;

    printf("Unesi ime datoteke: ");
    gets(filename);

    if (fp = fopen(filename, "rb"))
    {
        int p, temp, n = 0;

        do
        {
            p = fread(&temp, sizeof(int), 1, fp);
            if (p)
                niz[n++] = temp;
        } while (p);

        niz = (int *)realloc(niz, sizeof(int) * n);

        ispis(niz, n);
        fclose(fp);
    }
    else
        printf("Datoteka '%s' se ne moze otvoriti.", filename);
    return 0;
}

void ispis(int *niz, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", niz[i]);
}