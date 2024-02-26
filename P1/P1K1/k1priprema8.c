#include <stdio.h>

int main()
{
    int s = 0, t = 0, t_i;
    int e = 1;
    int nD, sum = 0;

    do
    {
        printf("Unesi: ");
        scanf("%d %d", &s, &t);
    } while (s < 1 || t < 1 || t > 10);

    t_i = t;

    for (int i = 1; i <= s; i++)
    {
        t = t_i;
        e = 1;
        while (t--)
        {
            e *= i;
        }

        while (e)
        {
            nD = 0;
            for (int d = (e % 10) / 2; d > 1; d--)
            {
                if ((e % 10) % d == 0)
                    nD++;
            }

            if (nD == 0 && e % 10 != 1)
            {
                sum += (e % 10);
                printf("Sumi dodano: %d\n", e % 10);
            }

            e /= 10;
        }
    }

    printf("Suma: %d", sum);
    printf("%d", sizeof(int));

    return 0;
}