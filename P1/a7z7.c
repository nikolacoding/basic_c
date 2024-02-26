#include <stdio.h>

int main()
{
    int H, L;

    do
    {
        printf("Unesi dimenzije matrice: ");
        scanf("%d %d", &H, &L);
    } while (H < 1 || L < 1);

    int mx[H][L];
    int mx1d[H * L];

    for (int h = 0, d = 0; h < H; h++)
    {
        for (int l = 0; l < L; l++)
        {
            printf("a[%d][%d] = ", h + 1, l + 1);
            scanf("%d", &mx[h][l]);

            mx1d[d] = mx[h][l];
            d++;
        }
    }

    for (int i = 0; i < H * L - 1; i++)
    {
        for (int j = i + 1; j < H * L; j++)
        {
            if (mx1d[i] > mx1d[j])
            {
                int temp = mx1d[i];
                mx1d[i] = mx1d[j];
                mx1d[j] = temp;
            }
        }
    }

    printf("Sortirani elementi matrice: ");
    for (int p = 0; p < H * L; p++)
    {
        printf((p != H * L - 1) ? "%d, " : "%d.", mx1d[p]);
    }

    return 0;
}