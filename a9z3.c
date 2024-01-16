#include <stdio.h>
#define MAX 10

void ucitaj(int[][10], int, int);
void ispisi(int[][10], int, int);
void pomnozi(int[][10], int[][10], int[][10], int, int, int, int);

int main()
{
    int n1, m1, n2, m2, nR, mR;

    do
    {
        printf("Unesi dimenzije matrice (n1, m1, n2, m2): ");
        scanf("%d %d %d %d", &n1, &m1, &n2, &m2);
    } while (n1 < 1 || m1 < 1 || n2 < 1 || m2 < 1 ||
             n1 > 10 || m1 > 10 || n2 > 10 || m2 > 10);

    nR = n1;
    mR = m2;

    int mat1[MAX][MAX];
    int mat2[MAX][MAX];
    int matRez[MAX][MAX];

    ucitaj(mat1, n1, m1);
    ucitaj(mat2, n2, m2);

    ispisi(mat1, n1, m1);
    ispisi(mat2, n2, m2);

    pomnozi(mat1, mat2, matRez, n1, m1, n2, m2);
    ispisi(matRez, nR, mR);

    return 0;
}

void ucitaj(int mat[][10], int nLen, int mLen)
{
    printf("Pravim matricu: %d x %d\n", nLen, mLen);
    static char id = 'a';
    for (int i = 0; i < nLen; i++)
    {
        for (int j = 0; j < mLen; j++)
        {
            printf("%c%d%d: ", id, i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    id++;
}

void ispisi(int mat[][10], int nLen, int mLen)
{
    for (int i = 0; i < nLen; i++)
    {
        printf("\n| ");
        for (int j = 0; j < mLen; j++)
        {
            printf("%2d ", mat[i][j]);
        }
        printf(" |");
    }

    printf("\n");
}

void pomnozi(int mat1[][10], int mat2[][10], int mat3[][10], int nLen1, int mLen1, int nLen2, int mLen2)
{
    int additions = mLen1;
    int nR = nLen1;
    int mR = mLen2;

    for (int i = 0; i < nR; i++)
    {
        for (int j = 0; j < mR; j++)
        {
            mat3[i][j] = 0;
            for (int k = 0; k < additions; k++)
            {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
