#include <stdio.h>

int main()
{
    int n;
    int pozitivno = 0;

    do
    {
        printf("Koliko brojeva zelis da uneses: ");
        scanf("%d", &n);
    } while (n < 1);

    int brojevi[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nUnesi %d. broj: ", i + 1);
        scanf("%d", &brojevi[i]);
        if (brojevi[i] > 0)
            pozitivno++;
    }

    int pozitivni[pozitivno];

    for (int i = 0, k = 0; k < pozitivno; i++)
    {
        if (brojevi[i] > 0)
        {
            pozitivni[k] = brojevi[i];
            k++;
        }
    }

    printf("Postoji %d pozitivnih brojeva, a to su: ", pozitivno);
    for (int i = 0; i < pozitivno; i++)
    {
        printf((i != pozitivno - 1) ? "%d, " : "%d.", pozitivni[i]);
    }

    return 0;
}