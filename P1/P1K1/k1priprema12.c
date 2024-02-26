#include <stdio.h>

int main()
{
    double x = 0, e = 1;
    int k = 0;

    int st = 1, f = 0;
    int j_i;

    double sum = 0;

    do
    {
        printf("Unesi x(R) i k(N): ");
        scanf("%lf %d", &x, &k);
    } while (k < 1);

    for (int j = 1; j <= k; j++)
    {
        j_i = j;
        st = j;
        f = j;

        e = 1;

        while (st--)
        {
            e *= x;
        }

        while (--j_i)
        {
            f *= j_i;
        }

        sum += (f / e);
    }

    printf("Suma: %lf", sum);
    return 0;
}