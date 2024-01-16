#include <stdio.h>
#define MAXCIF 1000

int main()
{
    int f[MAXCIF] = {1};
    int n, temp;

    do
    {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0, prenos = 0; j < MAXCIF; j++)
        {
            temp = f[j] * i + prenos;
            f[j] = temp % 10;
            prenos = temp / 10;
        }
    }

    printf("%d! = ", n);

    for (int i; i >= 0; i--)
        printf("%d", f[i]);

    return 0;
}