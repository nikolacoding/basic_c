#include <stdio.h>
#define MAX 1000

int main()
{
    int n;
    int e;
    int e_init;

    int exp[MAX] = {1}, temp;

    do
    {
        printf("Unesi prirodan broj i njegov eksponent (do 100): ");
        scanf("%d %d", &n, &e);
    } while (n < 1 || e < 1 || n > 100 || e > 100);

    e_init = e;

    while (e_init--)
    {
        for (int i = 0, prenos = 0; i < MAX; i++)
        {
            temp = exp[i] * n + prenos;
            exp[i] = temp % 10;
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
