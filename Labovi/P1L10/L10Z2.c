#include <stdio.h>
#define MAX 10

void ucitaj(int[][10], int, int);
void ispisi(int[][10], int, int);
void pomnozi(int[][10], int[][10], int[][10], int, int, int, int);

int main()
{
    int n1, m1, n2, m2;

    int mat1[MAX][MAX];
    int mat2[MAX][MAX];

    do
    {
        printf("Unesi dimenzije dvije matrice (n1 m1 n2 m2): ");
        scanf("%d %d %d %d", &n1, &m1, &n2, &m2);
    } while (n1 < 1 || m1 < 1 || n2 < 1 || m2 < 1 ||
             n1 > MAX || m1 > MAX || n2 > MAX || m2 > MAX);

    int matRez[n1][m2];

    ucitaj(mat1, n1, m1);
    ucitaj(mat2, n2, m2);
    pomnozi(mat1, mat2, matRez, n1, m1, n2, m2);
    ispisi(matRez, n1, m2);

    return 0;
}

void ucitaj(int mat[][10], int n, int m)
{
    static char index = 'a';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c%d%d: ", index, i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    index++;
}

void pomnozi(int mat1[][10], int mat2[][10], int matR[][10], int n1, int m1, int n2, int m2)
{
    if (n2 == m1)
    {
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                matR[i][j] = 0;
                for (int k = 0; k < m1; k++)
                {
                    matR[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
    }
    else
    {
        printf("\nMatrice se ne mogu pomnoziti.");
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                matR[i][j] = 0;
            }
        }
    }
}

void ispisi(int mat[][10], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n| ");
        for (int j = 0; j < m; j++)
        {
            printf("%2d ", mat[i][j]);
        }
        printf(" |");
    }
}
