#include <stdio.h>
#define MAX 1000

int main()
{
    int zrna[MAX] = {1};
    int temp;

    for (int i = 0; i < 64; i++)
    {
        for (int j = 0, prenos = 0; j < MAX; j++)
        {
            temp = zrna[j] * 2 + prenos;
            zrna[j] = temp % 10;
            prenos = temp / 10;
        }
    }

    int iter;
    for (iter = MAX - 1; zrna[iter] == 0; iter--)
        ;
    for (; iter > 0; iter--)
    {
        printf("%d", zrna[iter]);
    }
    printf("\n");

    return 0;
}