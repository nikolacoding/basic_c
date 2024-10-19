#include <stdio.h>
#define MAX 100

void citaj(int *, int *);

int main()
{
    int n, *nP = &n;
    int niz[MAX], *nizP = niz;
    double as = 0;

    citaj(nizP, nP);

    for (int i = 0; i < n; i++)
        as += (double)niz[i];

    as /= (double)n;

    printf("\nAritmeticka sredina niza: %.2lf", as);
    printf("\nClanovi niza veci od aritmeticke sredine: ");
    for (int i = 0; i < n; i++)
    {
        if ((double)niz[i] > as)
        {
            printf((i != n - 1) ? "%d, " : "%d.", niz[i]);
        }
    }

    return 0;
}

void citaj(int *niz, int *n)
{
    do
    {
        printf("Unesi broj clanova niza: ");
        scanf("%d", n);
    } while (*n < 1 || *n > 100);

    for (int i = 0; i < *n; i++)
    {
        printf("%d. clan: ", i + 1);
        scanf("%d", niz + i);
    }
}
