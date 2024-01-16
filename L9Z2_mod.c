#include <stdio.h>

// MODIFIKACIJA 1: Transponovati matricu proizvoda
// MODIFIKACIJA 2: Sabrati elemente glavne dijagonale matrice proizvoda

int main()
{
    int n1, n2, m1, m2;
    float sumaGlavneDijagonale = 0;

    do
    {
        printf("Unesi dimenzije dvije matrice (n1 m1 n2 m2): ");
        scanf("%d %d %d %d", &n1, &m1, &n2, &m2);
    } while (n1 < 1 || m1 < 1 || n1 > 10 || m1 > 10 || n2 < 1 || m2 < 1 || n2 > 10 || m2 > 10);

    float mat1[n1][m1];
    float mat2[n2][m2];

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            printf("a%d%d = ", i, j);
            scanf("%f", &mat1[i][j]);
        }
    }

    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            printf("b%d%d = ", i, j);
            scanf("%f", &mat2[i][j]);
        }
    }

    float matSab[n1][m1];
    float matMnoz[n1][m2];
    float matMnozT[m2][n1];

    if (n1 != n2 || m1 != m2)
    {
        printf("Matrice se ne mogu sabrati!\n");
    }
    else
    {
        printf("\nZbir matrica:\n");
        for (int i = 0; i < n1; i++)
        {
            printf("\n");
            printf("| ");
            for (int j = 0; j < m1; j++)
            {
                matSab[i][j] = mat1[i][j] + mat2[i][j];
                printf(((int)matSab[i][j] == matSab[i][j]) ? "%3.0f " : "%3.2f ", matSab[i][j]);
            }
            printf(" |");
        }
    }

    if (m1 != n2)
    {
        printf("Matrice se ne mogu pomnoziti!\n");
    }
    else
    {
        printf("\n\nProizvod matrica:\n");
        for (int i = 0; i < n1; i++)
        {
            printf("\n");
            printf("| ");
            for (int j = 0; j < m2; j++)
            {
                matMnoz[i][j] = 0;
                for (int k = 0; k < m1; k++)
                {
                    matMnoz[i][j] += mat1[i][k] * mat2[k][j];
                    matMnozT[j][i] = matMnoz[i][j];
                }
                printf(((int)matMnoz[i][j] == matMnoz[i][j]) ? "%3.0f " : "%3.2f ", matMnoz[i][j]);
            }
            printf(" |");
        }

        printf("\n\nTransponovana matrica proizvoda:\n");
        for (int i = 0; i < n1; i++)
        {
            printf("\n");
            printf("| ");
            for (int j = 0; j < m2; j++)
            {
                printf(((int)matMnozT[i][j] == matMnozT[i][j]) ? "%3.0f " : "%3.2f ", matMnozT[i][j]);
            }
            printf(" |");
        }
    }

    int iter = (n1 > m2) ? m2 : n1;

    for (int i = 0; i < iter; i++)
        sumaGlavneDijagonale += matMnoz[i][i];

    printf("\nSuma clanova glavne dijagonale matrice mnozenja %.2f: ", sumaGlavneDijagonale);

    return 0;
}