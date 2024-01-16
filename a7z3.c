#include <stdio.h>

int main()
{
    int n;
    int exception;
    do
    {
        printf("Unesi br. clanova niza: ");
        scanf("%d", &n);
    } while (n < 1);

    int niz[n];
    int pon[n];
    int except[n + 1];

    for (int i = 0; i < n; i++)
    {
        printf("\nUnesi %d. element niza: ", i + 1);
        scanf("%d", &niz[i]);
        pon[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        exception = 0;

        for (int e = 0; e < n; e++)
        {
            if (niz[i] == except[e])
            {
                exception = 1;
            }
        }

        for (int k = 0; k < n; k++)
        {
            if (niz[i] == niz[k] && !exception)
            {
                pon[i]++;
                except[i + 1] = niz[i];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (pon[i])
            printf("\n%d. element niza (%d) se ponavlja %d puta.", i + 1, niz[i], pon[i]);
    }

    return 0;
}