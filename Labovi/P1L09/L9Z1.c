#include <stdio.h>
#define MAX 160

// MODIFIKACIJA: Izracunati i ispisati 2^n

int main()
{
    int n;

    do
    {
        printf("Unesi n: ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    int fact[MAX] = {1}, tempF;
    int exp[MAX] = {1}, tempE;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0, prenos = 0; j < MAX; j++)
        {
            tempF = fact[j] * i + prenos;
            fact[j] = tempF % 10;
            prenos = tempF / 10;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0, prenos = 0; j < MAX; j++)
        {
            tempE = exp[j] * 2 + prenos;
            exp[j] = tempE % 10;
            prenos = tempE / 10;
        }
    }

    int iter;
    printf("%d! = ", n);
    for (iter = MAX - 1; fact[iter] == 0; iter--)
        ;
    for (; iter >= 0; iter--)
    {
        printf("%d", fact[iter]);
    }

    printf("\n\n");

    printf("2^%d = ", n);
    for (iter = MAX - 1; exp[iter] == 0; iter--)
        ;
    for (; iter >= 0; iter--)
    {
        printf("%d", exp[iter]);
    }

    return 0;
}