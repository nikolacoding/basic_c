#include <stdio.h>
int main()
{
    double x, br, m, g, im, sum;
    int n;
    do
    {
        printf("Unesite prirodan broj n manji od 11");
        scanf("%d", &n);
    } while (n < 0 || n > 10);
    do
    {
        printf("Unesite broj x: ");
        scanf("%lf", &x);
        if (x >= 1)
        {
            sum = 1;
            for (int i = 1; i <= n; i++)
            {
                br = 1;
                m = i;
                while (m > 0)
                {
                    br *= x;
                    m--;
                }
                im = 1;
                g = i;
                while (g > 0)
                {
                    im *= g;
                    g--;
                }
                sum += (br / im);
            }
            printf("%lf\n", sum);
        }
    } while (x >= 1);
    return 0;
}