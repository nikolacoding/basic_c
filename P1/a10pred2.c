#include <stdio.h>
#include <stdlib.h>

int *citaj(int *);

int main()
{
    int n, *niz;

    niz = citaj(&n);

    printf("Clanovi niza: ");
    for (int i = 0; i < n; i++)
    {
        printf((i != n - 1) ? "%d, " : "%d.", niz[i]);
    }

    free(niz);
    return 0;
}

int *citaj(int *n)
{
    int *niz;

    do
    {
        printf("Unesi broj clanova niza: ");
        scanf("%d", n);
    } while (*n < 1);

    niz = (int *)malloc(*n * sizeof(int));
    int temp;

    for (int i = 0; i < *n; i++)
    {
        printf("%d. clan niza: ", i + 1);
        scanf("%d", niz + i);
    }

    for (int i = 0; i < *n - 1; i++)
    {
        for (int j = i; j < *n; j++)
        {
            if (niz[i] > niz[j])
            {
                temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }

    return niz;
}