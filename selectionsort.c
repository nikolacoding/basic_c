#include <stdio.h>

int main()
{
    int n;
    do
    {
        printf("Unesi broj elemenata niza: ");
        scanf("%d", &n);
    } while (n < 1);

    int niz[n];

    for (int i = 0; i < n; i++)
    {
        printf("Unesi %d. element niza: ", i + 1);
        scanf("%d", &niz[i]);
    }

    printf("Originalni niz: ");
    for (int i = 0; i < n; i++)
    {
        printf((i != n - 1) ? "%d, " : "%d.", niz[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (niz[i] > niz[j])
            {
                int temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }

    printf("\nSortirani niz: ");
    for (int i = 0; i < n; i++)
    {
        printf((i != n - 1) ? "%d, " : "%d.", niz[i]);
    }

    return 0;
}