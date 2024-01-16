#include <stdio.h>

int main()
{

    int d;
    int bD = 0;

    do
    {
        printf("Unesi red matrice: ");
        scanf("%d", &d);
    } while (d < 1 || d >= 20);

    int mx[d][d];

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &mx[i][j]);
        }
    }

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            bD = 0;
            for (int p = 2; p <= mx[i][j] / 2; p++)
            {
                if (mx[i][j] % p == 0)
                {
                    bD++;
                }
            }
            if (!bD)
            {
                printf("\na[%d][%d] = %d je prost!", i + 1, j + 1, mx[i][j]);
            }
        }
    }
}