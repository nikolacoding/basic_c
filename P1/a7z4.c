#include <stdio.h>

int main()
{
    int n;
    float as;

    do
    {
        printf("Unesi broj clanova niza: ");
        scanf("%d", &n);
    } while (n < 1);

    int niz[n];

    for (int i = 0; i < n; i++)
    {
        printf("Unesi %d. clan tog niza: ", i + 1);
        scanf("%d", &niz[i]);
        as += niz[i];

        if (i == n - 1)
            as /= n;
    }

    printf("Parni clanovi niza veci od aritmeticke sredine niza (%.2f) su: ", as);
    for (int i = 0; i < n; i++)
    {
        if ((float)niz[i] > as && niz[i] % 2 == 0)
            printf("%d ", niz[i]);
    }

    return 0;
}