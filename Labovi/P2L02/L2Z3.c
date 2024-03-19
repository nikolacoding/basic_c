#include <stdio.h>
#include <stdlib.h>

void saberi(double *, double *, double *, int);

int main(int argc, char const *argv[])
{
    int n;
    double *a, *b;
    double *apb; // a + b

    do
    {
        printf("Unesi broj dimenzija: ");
        scanf("%d", &n);
    } while (n < 1);

    a = (double *)malloc(n * sizeof(double));
    b = (double *)malloc(n * sizeof(double));
    apb = (double *)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
    {
        printf("Vektor a(%d): ", i + 1);
        scanf("%lf", &a[i]);
        printf("Vektor b(%d): ", i + 1);
        scanf("%lf", &b[i]);
    }

    saberi(a, b, apb, n);

    printf("Zbir dva data vektora:\n\n");
    printf("%2s %6s %5s %8s", "D", "a", "b", "a+b\n");
    for (int i = 0; i < n; i++)
        printf("[%d] -> %.1lf + %.1lf -> %.1lf\n", i + 1, a[i], b[i], apb[i]);

    free(a);
    free(b);
    free(apb);
    return 0;
}

void saberi(double *vektor_a, double *vektor_b, double *vektor_rez, int n)
{
    if (n)
    {
        vektor_rez[n - 1] = vektor_a[n - 1] + vektor_b[n - 1];
        saberi(vektor_a, vektor_b, vektor_rez, n - 1);
    }
}