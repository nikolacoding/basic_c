#include <stdio.h>

int main()
{
    int n;
    int pon;
    int f = 0;
    do
    {
        printf("Unesi broj clanova niza: ");
        scanf("%d", &n);
    } while (n < 1);
    printf("\n");

    int pocetni[n];
    int finalni[n];

    for (int i = 0; i < n; i++)
    {
        printf("Unesi %d. clan niza: ", i + 1);
        scanf("%d", &pocetni[i]);
    }

    for (int i = 0; i < n; i++)
    {
        pon = 0;
        for (int k = 0; k < n; k++)
        {
            if (i != k)
            {
                if (pocetni[i] == pocetni[k])
                    pon++;
            }
        }
        if (!pon)
        {
            finalni[f] = pocetni[i];
            f++;
        }
    }

    printf("Clanovi niza koji se ne ponavjaju su: ");
    for (int i = 0; i < f; i++)
    {
        printf((i != f - 1) ? "%d, " : "%d.", finalni[i]);
    }

    return 0;
}