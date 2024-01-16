#include <stdio.h>
int main()
{
    int a, b, n, bd, m;
    do
    {
        printf("Unesite 2 broja ");
        scanf("%d", &a);
        scanf("%d", &b);
    } while (a >= b || !(a > 0 && b > 0));
    for (int i = a; i <= b; i++)
    {
        n = i;
        bd = 0;
        while (n > 0)
        {
            if (i % n == 0)
            {
                bd++;
            }
            n--;
        }
        if (bd == 2)
        {
            m = i;
            while (m > 0)
            {
                if (m % 3 == 2)
                {
                    printf("%d\n", i);
                    m = 0;
                }
                m /= 3;
            }
        }
    }
    return 0;
}