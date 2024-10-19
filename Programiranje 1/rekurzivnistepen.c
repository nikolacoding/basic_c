#include <stdio.h>

double e(double, int);
enum limits
{
    EXP_LIMIT = 99,
    N_LIMIT = 1000
};

int main()
{
    double n;
    int ex;

    do
    {
        printf("Unesi broj i eksponent [n e]: ");
        scanf("%lf %d", &n, &ex);
    } while (ex < 1 || ex > EXP_LIMIT || n > N_LIMIT);

    printf("%.1lf^%d = %.2lf", n, ex, e(n, ex));
    return 0;
}

double e(double base, int exponent)
{
    if (exponent == 0)
        return 1;

    return base * e(base, exponent - 1);
}

// e(2, 4)
// ^ ret: 2 * e(2, 3)
//            ^ ret: 2 * e(2, 2)
//                       ^ ret: 2 * e(2, 1)
//                                  ^ ret: 2 * e(2, 0)
//                                             ^ ret: 1