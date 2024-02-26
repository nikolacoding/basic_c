#include <stdio.h>

int main()
{
    int a = 0, b = 0;
    int i2;
    int nD = 0;

    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i++)
    {
        i2 = i;
        nD = 0;
        for (int d = i / 2; d > 1; d--)
        {
            if (i % d == 0)
                nD++;
        }
        if (nD == 0)
        {
            while (i2)
            {
                if (i2 % 3 == 2)
                {
                    printf("%d\n", i);
                    i2 = 0;
                }

                i2 /= 3;
            }
        }
    }
}