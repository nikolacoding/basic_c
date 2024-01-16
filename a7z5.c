#include <stdio.h>

int main()
{
    int d;

    do
    {
        printf("Unesi dimenziju kvadratne matrice: ");
        scanf("%d", &d);
    } while (d < 1);

    int mat1[d][d];
    int mat2[d][d];
    int rez[d][d];

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            printf("b[%d][%d] = ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            int tempSum = mat1[i][j] + mat2[i][j];
            rez[i][j] = tempSum;
            printf("rez[%d][%d] = %d\n", i, j, tempSum);
        }
    }
}