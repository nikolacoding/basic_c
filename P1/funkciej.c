#include <stdio.h>

int expt(int a, int b)
{
    int e = 1;

    while (b--)
    {
        e *= a;
    }
    return e;
}

int fact(int a)
{
    if (a == 0)
        return 1;

    int temp = a;
    int f = a;

    while (--f)
    {
        temp *= f;
    }
    return temp;
}

int main()
{

    double x, ex = 0;
    int n;

    scanf("%lf %d", &x, &n);

    for (int i = 0; i <= n; i++)
    {
        ex += (expt(x, i) / fact(i));
    }

    printf("%lf\n", ex);

    return 0;
}