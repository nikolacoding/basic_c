#include <stdio.h>

int main()
{
    int n = 0;

    do
    {
        printf("Unesi: ");
        scanf("%d", &n);
    } while (n < 1 || n > 10);

    double x = 1, ex = 0, temp = 0;
    int e = 1, i_i;
    double f = 1;

    while (x >= 1)
    {
        scanf("%lf", &x);

        for (int i = 0; i <= n; i++)
        {
            e = 1;
            f = i;
            i_i = 1;
            temp = 0;
            ex = 0;
            while (i_i--)
            {
                e *= x;
            }

            i_i = i;

            if (i == 0)
                f = 1;
            else
            {
                while (--i_i)
                {
                    f *= i_i;
                }
            }

            temp = e / f;
            printf("e=%.5lf; f=%.5lf", e, f);
            ex += temp;
        }

        printf("e^%lf = %lf", x, ex);
    }

    return 0;
}