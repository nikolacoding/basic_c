// Napisati funkciju zbir koja uzima promjenljiv broj argumenata i ispisuje njihov zbir

#include <stdio.h>
#include <stdarg.h>

int zbir(int n, ...)
{
    int s = 0;

    va_list args;
    va_start(args, n);

    for (int i = 1; i <= n; i++)
        s += va_arg(args, int);

    va_end(args);

    return s;
}

int main()
{
    printf("Zbir = %d", zbir(4, 20, 30, 40, 50));
}