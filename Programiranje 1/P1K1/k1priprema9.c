#include <stdio.h>

int main()
{
    int n = 0, k = 0;
    int count;
    int i_t;

    do
    {
        printf("Unesi: ");
        scanf("%d %d", &n, &k);
    } while (n < 1 || k < 1);

    for (int i = 1; i <= n; i++)
    {
        i_t = i;
        count = 0;
        for (int k = 0; k < sizeof(i_t) * 8; k++)
        {
            if (i_t & 1 == 1)
            {
                count++;
            }

            i_t >>= 1;
        }
        if (count == k)
            printf("%d\n", i);
    }

    return 0;
}