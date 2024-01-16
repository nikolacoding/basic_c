#include <stdio.h>

int main()
{

    int d;

    int dSum = 0;
    int d2Sum = 0;

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

            if (i == j)
                dSum += mx[i][j];

            if ((i + j + 2) == (d + 1))
                d2Sum += mx[i][j];
        }
    }

    /*
    a11 a12 a13 a14     a11 a12 a13
    a21 a22 a23 a24     a21 a22 a23  <===> i + j na sporednoj dijagonali je stranica (d) + 1
    a31 a32 a33 a34     a31 a32 a33
    a41 a42 a43 a44
    */

    printf("\nSuma glavne dijagonale je %d.", dSum);
    printf("\nSuma sporedne dijagonale je %d.", d2Sum);

    return 0;
}