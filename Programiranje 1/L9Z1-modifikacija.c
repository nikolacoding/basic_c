#include <stdio.h>
#define MAX 160

int main()
{
    int n;
    int e;

    do
    {
        printf("Unesi n: ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    printf("Unesi eksponent: ");
    scanf("%d", &e);

    int e_init = e;

    int exp[MAX] = {1}, temp;

    while (e_init--)
    {
        for (int j = 0, prenos = 0; j < MAX; j++)
        {
            temp = exp[j] * e + prenos;
            exp[j] = temp % 10;
            prenos = temp / 10;
        }
    }

    int iter;
    printf("%d^%d = ", n, e);
    for (iter = MAX - 1; exp[iter] == 0; iter--)
        ;
    for (; iter >= 0; iter--)
    {
        printf("%d", exp[iter]);
    }

    return 0;
}