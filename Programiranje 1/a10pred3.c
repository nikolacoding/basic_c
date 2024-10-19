#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **mat;
    int n, m;
    int b = 0;

    do
    {
        printf("Unesi dimenzije (n m) matrice: ");
        scanf("%d %d", &n, &m);
    } while (n < 1 || m < 1);

    mat = (int **)calloc(n, sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        mat[i] = (int *)calloc(m, sizeof(int));

        for (int j = 0; j < m; j++)
        {
            printf("Unesi a[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Matrica:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < m; j++)
        {
            printf(" %4d", mat[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(mat[i]);
    }
    free(mat);

    return 0;
}