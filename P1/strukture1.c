#include <stdio.h>

int main()
{
    struct kompleks
    {
        double re, im;
    };

    struct kompleks x = {3.0, 2.0};
    struct kompleks y = {2.0, 3.0};
    struct kompleks zbir, proizvod;

    zbir.re = x.re + y.re;
    zbir.im = x.im + y.im;

    proizvod.re = x.re * y.re;
    proizvod.im = x.im + y.im;

    printf("Zbir je %.2lf + i%.2lf.\n", zbir.re, zbir.im);
    printf("Proizvod je: %.2lf + i%.2lf", proizvod.re, proizvod.im);

    return 0;
}