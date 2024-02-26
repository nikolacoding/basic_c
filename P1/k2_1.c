#include <stdio.h>
#include <stdlib.h>

long *cifra(long *niz, int n, int c, int *m);
int sadrziCifru(long, int);
int cfr(long **mat, int n, int m, int c);

int main()
{
    int n;
    long *dynNiz;
    int dynLen;

    do
    {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 1);

    long niz[n];
    long **mat;

    mat = (long **)calloc(3, sizeof(long *));

    for (int i = 0; i < 3; i++)
    {
        mat[i] = (long *)calloc(3, sizeof(long));
    }

    mat[0][0] = 2;
    mat[0][1] = 4;
    mat[0][2] = 12;

    mat[1][0] = 17;
    mat[1][1] = 24;
    mat[1][2] = 31;

    mat[2][0] = 46;
    mat[2][1] = 12;
    mat[2][2] = 4;

    // 2  4  12 -- 0
    // 17 24 31 -- 1
    // 46 12 6  -- 2

    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("Unesi %d. clan niza: ", i + 1);
            scanf("%li", &niz[i]);
        } while (niz[i] < 1);
    }

    dynNiz = cifra(niz, n, 3, &dynLen);

    for (int i = 0; i < dynLen; i++)
    {
        printf("\n%li", dynNiz[i]);
    }

    printf("Indeks trazene vrste matrice je %d", cfr(mat, 3, 3, 6));

    return 0;
}

long *cifra(long *niz, int n, int c, int *m)
{
    long tempNiz[n];
    int tempNizLen = 0;

    long *tempNizD;

    for (int i = 0; i < n; i++)
    {
        if (sadrziCifru(niz[i], c))
        {
            tempNiz[tempNizLen++] = niz[i];
        }
    }

    tempNizD = (long *)malloc(tempNizLen * sizeof(long));

    for (int i = 0; i < tempNizLen; i++)
    {
        tempNizD[i] = tempNiz[i];
    }

    *m = tempNizLen;

    return (*m == 0) ? NULL : tempNizD;
}

int sadrziCifru(long broj, int trazenaCifra)
{
    while (broj)
    {
        if (broj % 10 == trazenaCifra)
            return 1;

        broj /= 10;
    }

    return 0;
}

int cfr(long **mat, int n, int m, int c)
{
    int tempDuzina;
    int najboljaDuzina = -1;
    int najboljiRed;
    long red[m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            red[j] = mat[i][j];
        }

        cifra(red, m, c, &tempDuzina);

        if (tempDuzina > najboljaDuzina)
        {
            najboljaDuzina = tempDuzina;
            najboljiRed = i;
        }
    }

    for (int i = 0; i < m; i++)
    {
        printf("%li ", mat[najboljiRed][i]);
    }

    return najboljiRed;
}