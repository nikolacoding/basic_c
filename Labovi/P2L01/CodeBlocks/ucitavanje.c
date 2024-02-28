#include "ucitavanje.h"

void ucitavanje()
{
    do
    {
        printf("Unesi broj clanova niza: ");
        scanf("%d", &n);
    } while (n < 1);

    niz = (long long *)malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++)
    {
        printf("Unesi %d. clan niza: ", i + 1);
        scanf("%ld", &niz[i]);
    }
}
