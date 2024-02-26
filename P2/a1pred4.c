// Napisati program koji Euklidovim algoritmom određuje NZD (mjeru) dva broja.
// NZD dva broja treba da se računa u rekurzivnoj funkciji nzd.

#include <stdio.h>

unsigned nzd(unsigned, unsigned);

int main()
{
    unsigned a, b;

    do
    {
        printf("Unesi dva prirodna broja: ");
        scanf("%u %u", &a, &b);
    } while (!a || !b);

    printf("Najveci zajednicki djelilac (%u, %u) je: %u", a, b, nzd(a, b));

    return 0;
}

unsigned nzd(unsigned x, unsigned y)
{
    if (!y)
        return x;

    nzd(y, x % y);
}