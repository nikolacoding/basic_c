#include <stdio.h>

int main()
{
    int n;

    do
    {

        printf("Unesite n: ");
        scanf("%d", &n);

    } while (n >= 10);

    int slika[n][n][3];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Unesite RGB komponente piksela slike:\n");
            printf("piksel(%d,%d) - R = ", i, j);
            scanf("%d", &slika[i][j][0]);
            printf("piksel(%d,%d) - G = ", i, j);
            scanf("%d", &slika[i][j][1]);
            printf("piksel(%d,%d) - B = ", i, j);
            scanf("%d", &slika[i][j][2]);
        }
    }

    printf("Slika:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            printf("#%02x%02x%02x ", slika[i][j][0], slika[i][j][1], slika[i][j][2]);
        }
        printf("\n");
    }

    return 0;
}