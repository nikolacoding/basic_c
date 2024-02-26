#include <stdio.h>

int main()
{
    int n = 0, k = 0;
    int stepen, e = 1;
    int sum = 0;

    do
    {
        printf("Unesi: ");
        scanf("%d %d", &n, &k);
    } while (n < 1 || k < 1 || k > 10);

    for (int i = 1; i <= n; i++)
    {
        stepen = k;
        e = 1;

        while (stepen--)
        {
            e *= i;
        }

        while (e)
        {
            if ((e % 10) % 2 == 0)
            {
                sum += e % 10;
            }

            e /= 10;
        }
    }
    printf("Suma: %d", sum);

    return 0;
}