#include <stdio.h>
#include <stdlib.h>

int **ucitaj(int *n, int *m);
int ispisi(int **, int, int);
int **saberi(int **, int **, int, int);

int main()
{
    int n, m;
    int **mat1;
    int **mat2;
    int **matRez;

    mat1 = ucitaj(&n, &m);
    mat2 = ucitaj(&n, &m);

    saberi(mat1, mat2, n, m);
    ispisi(matRez, n, m);
}

int **ucitaj(int *n, int *m)
{
    do
    {
        printf("Unesi dimenzije matrice: ");
        scanf("%d %d", n, m);
    } while (*n < 1 || *m < 1);

    int **tempMat;

    tempMat = (int **)calloc(*n, sizeof(int *));
    for (int i = 0; i < *n; i++)
    {
        tempMat[i] = (int *)calloc(*m, sizeof(int));

        for (int j = 0; j < *m; j++)
        {
            printf("a%d%d: ", i, j);
            scanf("%d", &tempMat[i][j]);
        }
    }

    return tempMat;
}

int ispisi(int **mat, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n | ");
        for (int j = 0; j < m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("|");
    }
}

int **saberi(int **mat1, int **mat2, int n, int m)
{
    int **tempMat;
    tempMat = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        tempMat[i] = (int *)calloc(m, sizeof(int));
        for (int j = 0; j < m; j++)
        {
            tempMat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return tempMat;
}