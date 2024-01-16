#include <stdio.h>
#define MAXCIF 100
int main()
{
    int f[MAXCIF] = {1};
    int n, pom, prenos;
    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    for (int i = 2; i <= n; i++)
        for (int j = 0, prenos = 0; j < MAXCIF; j++)
        {
            pom = f[j] * i + prenos;
            f[j] = pom % 10;
            prenos = pom / 10;
        }
    printf("%d != ", n);

    int iter;

    for (iter = MAXCIF - 1; f[iter] == 0; iter--)
        ;
    for (; iter >= 0; iter--)
    {
        printf("%d", f[iter]);
    }

    return 0;
}
