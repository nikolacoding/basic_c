#include <stdio.h>

int main()
{
    int n, k, suma = 0, sp, t, radnok, zbircifara = 0;

    // suma sabira sve sp(t) gdje je sp(t) zbir parnih //cifara broja t i t je neko: i na k (i<=n)

    do
    {
        printf("Unesite broj članova sume i stepen: ");
        scanf("%d %d", &n, &k);
    } while (n < 1 || k > 10 || k < 1);

    for (int i = 1; i <= n; i++)
    {
        radnok = k;
        sp = 1;
        while (radnok--)
        {
            sp *= i;
        }

        while (sp)
        {
            if ((sp % 10) % 2 == 0)
            {
                suma += sp % 10;
                printf("Sumi dodano: %d\n\n", sp % 10);
            }
            sp = sp / 10;
        }
    }

    printf("Suma je: %d", suma);

    return 0;
}