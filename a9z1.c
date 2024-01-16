#include <stdio.h>

int savrsen(int);

int main()
{
    int n;

    do
    {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 1);

    for (int i = 1; i < n; i++)
    {
        if (savrsen(i))
            printf("Broj %d je savrsen.\n", i);
    }

    return 0;
}

int savrsen(int n)
{
    int sum = 0;

    for (int i = n - 1; i > 0; i--)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }

    return (sum == n) ? 1 : 0;
}