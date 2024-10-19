#include <stdio.h>

int main()
{
    int a = 0, b = 0;
    int i_i;
    int count = 0;

    do
    {
        printf("Unesi: ");
        scanf("%d %d", &a, &b);
    } while (a < 1 || b < 1 || a > b);

    for (int i = a; i <= b; i++)
    {
        count = 0;
        i_i = i;
        for (int c = 0; c <= sizeof(i) * 8; c++)
        {
            if (i_i & 1 == 1)
            {
                count++;
            }
            i_i >>= 1;
        }

        if (count >= 3)
            printf("Broj %d ispunjava svojstvo.\n", i);
    }
    return 0;
}