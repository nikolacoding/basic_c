#include <stdio.h>
#define MAX 100

int prost(int);

int main()
{
    int n;
    int niz[MAX];

    do
    {
        printf("Unesi broj clanova niza: ");
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        printf("Unesi %d. clan niza: ", i + 1);
        scanf("%d", &niz[i]);
    }

    printf("Prosti brojevi u datom nizu su: ");
    for (int i = 0; i < n; i++)
    {
        if (prost(niz[i]))
            printf((i != n - 1) ? "%d, " : "%d.", niz[i]);
    }

    return 0;
}

int prost(int a)
{
    int nD = 0;

    for (int i = 2; i <= a / 2; i++)
    {
        if (a % i == 0)
            nD++;
    }

    return (nD) ? 0 : 1;
}