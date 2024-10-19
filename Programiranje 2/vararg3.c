#include <stdio.h>
#include <stdarg.h>

double prosjek(int n, ...)
{
    double s = 0;
    va_list args;

    va_start(args, n);
    for (int i = 0; i < n; i++)
        s += va_arg(args, double);

    va_end(args);

    return n ? s / n : 0;
}

int main(int argc, char const *argv[])
{
    printf("Prosjek (10, 12, 14, 15): %.2lf\n", prosjek(4, 10.0, 12.0, 14.0, 15.0));
    printf("Prosjek (7.5, 8, 9.5, 9, 9.85, 7.15, 6.65): %.2lf\n", prosjek(7, 7.5, 8.0, 9.5, 9.0, 9.85, 7.15, 6.65));
    return 0;
}
