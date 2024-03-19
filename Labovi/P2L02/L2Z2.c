#include <stdio.h>

int suma_cifara(int);

int main(int argc, char const *argv[])
{
    int b;

    do
    {
        printf("Unesi broj: ");
        scanf("%d", &b);
    } while (b < 1);

    printf("Suma cifara broja %d: %d", b, suma_cifara(b));
    return 0;
}

int suma_cifara(int b)
{
    if (b / 10 == 0)
        return b % 10;

    return b % 10 + suma_cifara(b / 10);

    // 1234
    // 4 + sc(123)
    //     3 + sc(12)
    //         2 + sc(1)
    //              1
    //         2 + (1)
    //     3 + (2 + (1))
    // 4 + (3 + (2 + (1)))
    // => 10
}