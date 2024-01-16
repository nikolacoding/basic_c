#include <stdio.h>

int main()
{

    int n;
    int color;

    do
    {
        printf("Unesi dimenziju kv. matrice: ");
        scanf("%d", &n);
    } while (n < 1);

    int pixel[n][n][3];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int c = 0; c < 3; c++)
            {
                do
                {
                    switch (c)
                    {
                    case 0:
                        printf("piksel(%d, %d) - R: ", i, j);
                        break;
                    case 1:
                        printf("piksel(%d, %d) - G: ", i, j);
                        break;
                    case 2:
                        printf("piksel(%d, %d) - B: ", i, j);
                        break;
                    }

                    scanf("%d", &color);

                } while (color < 0 || color > 255);
                pixel[i][j][c] = color;
            }
        }
    }

    printf("Slika: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
            printf((pixel[i][j][0] < 16) ? "0%x" : "%x", pixel[i][j][0]);
            printf((pixel[i][j][1] < 16) ? "0%x" : "%x", pixel[i][j][1]);
            printf((pixel[i][j][2] < 16) ? "0%x" : "%x", pixel[i][j][2]);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}