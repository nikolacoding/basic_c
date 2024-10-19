#include <stdio.h>

int main()
{
    int d;
    int max = 0;

    do
    {
        printf("Unesi dimenziju kvadratne matrice: ");
        scanf("%d", &d);
    } while (d < 1);

    int mx[d][d];

    for (int i = 0; i < d; i++)
    {
        for (int k = 0; k < d; k++)
        {
            printf("\na[%d][%d] = ", i + 1, k + 1);
            scanf("%d", &mx[i][k]);
        }
    }

    for (int i = 0; i < d; i++)
    {
        if (mx[i][i] > max)
            max = mx[i][i];
    }

    for (int i = 0; i < d; i++)
    {
        for (int k = 0; k < d; k++)
        {
            if (mx[i][k] > max)
            {
                printf("a[%d][%d] = %d je veci od najveceg clana glavne dijagonale (%d).", i + 1, k + 1, mx[i][k], max);
            }
        }
    }
}