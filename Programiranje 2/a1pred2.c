#include <stdio.h>
#define MAX 100

double suma(double niz[], int n)
{
    if (n == 0)
        return 0;

    return niz[n - 1] + suma(niz, n - 1);
}

int main()
{
    double niz[MAX];
    int n;

    do
    {
        printf("Unesi broj clanova niza: ");
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        printf("(%d/%d) Unesi realan broj: ", i + 1, n);
        scanf("%lf", &niz[i]);
    }

    printf("\n======================\nSuma svih clanova niza: %.2lf\n======================", suma(niz, n));

    return 0;
}