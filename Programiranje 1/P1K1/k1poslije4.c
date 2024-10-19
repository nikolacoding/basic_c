#include <stdio.h>

int main()
{
    /* neparni */
    int a = 0, b = 0;
    int t, nD = 0;
    int d_f = 0;

    do
    {
        printf("Unesi segment: ");
        scanf("%d %d", &a, &b);
    } while (a < 1 || b < 1 || a > b);

    for (int i = a; i <= b; i++)
    {
        nD = 0;
        t = 0;
        for (int d = i / 2; d > 1; d--)
        {
            if (i % d == 0)
            {
                d = -1;
            }
            d_f = d;
        }

        if (d_f != -1)
        {
            t = i;

            while (t)
            {
                if (t % 3 == 2)
                {
                    printf("Zadovoljava uslov: %d\n", i);
                    t = 0;
                }
                t /= 3;
            }
        }
    }

    return 0;
}