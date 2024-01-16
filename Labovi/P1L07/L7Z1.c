#include <stdio.h>

int main()
{
    int n;

    do
    {
        printf("Unesi broj clanova niza: ");
        scanf("%d", &n);
    } while (n < 1);

    int niz[n];

    for (int i = 0; i < n; i++)
    {
        printf("Unesi %d. element niza: ", i + 1);
        scanf("%d", &niz[i]);
    }

    printf("\nOriginalni niz: ");
    for (int i = 0; i < n; i++)
    {
        printf((i != n - 1) ? "%d, " : "%d.", niz[i]);
    }

    for (int i = 0; i < n / 2; i++)
    {
        int temp = niz[i];
        niz[i] = niz[n - i - 1];
        niz[n - i - 1] = temp;
    }

    printf("\nSortirani niz: ");
    for (int i = 0; i < n; i++)
    {
        printf((i != n - 1) ? "%d, " : "%d.", niz[i]);
    }

    return 0;
}