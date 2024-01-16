#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ***slika;
    int x, y;
    char pikseli[4] = {'R', 'G', 'B'};

    do
    {
        printf("Unesi dimenzije slike: ");
        scanf("%d %d", &x, &y);
    } while (x < 1 || y < 1);

    slika = (int ***)calloc(y, sizeof(int **));

    for (int i = 0; i < y; i++)
    {
        *(slika + i) = (int **)calloc(x, sizeof(int *));
        for (int j = 0; j < x; j++)
        {
            *(*(slika + i) + j) = (int *)calloc(3, sizeof(int));
            for (int k = 0; k < 3; k++)
            {
                do
                {
                    printf("[%d][%d] %c: ", i, j, pikseli[k]);
                    scanf("%d", &(*(*(*(slika + i) + j) + k)));

                } while ((*(*(*(slika + i) + j) + k)) < 0 || *(*(*(slika + i) + j) + k) > 255);
            }
        }
    }

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (!k)
                    printf("#");

                printf("%02x", *(*(*(slika + i) + j) + k));
            }
            printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            free(*(*(slika + i) + j));
        }
        free(*(slika + i));
    }
    free(slika);

    return 0;
}