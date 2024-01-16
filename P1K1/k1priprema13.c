#include <stdio.h>

int main()
{
    int x = 0;
    int count = 0;

    do
    {
        printf("Unesi x: ");
        scanf("%d", &x);
    } while (x < 1);

    for (int i = x; i <= 2 * x; i++)
    {
        count = 0;
        for (int d = i / 2; d > 1; d--)
        {
            if ((i % d == 0) && (d % 2 == 1))
                count++;
        }

        if (count >= 3)
            printf("Broj %d ima 3+ neparna djelioca.\n", i);
    }

    return 0;
}