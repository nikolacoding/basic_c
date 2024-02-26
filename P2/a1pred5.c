// Napisati program koji učitava prirodan broj n, a zatim ispisuje n-ti član Fibonačijevog niza.
// n-ti član Fibonačijevog niza treba da se računa u rekurzivnoj funkciji fib.

#include <stdio.h>
#define MAX 100

unsigned fib(unsigned);
unsigned fib_nomemo(unsigned);

int main()
{
    unsigned n;

    do
    {
        printf("Unesi broj Fibonacijevog niza za ucitati: ");
        scanf("%u", &n);
    } while (!n);

    printf("%u. clan Fibonacijevog niza je %u.", n, fib(n));

    return 0;
}

unsigned fib(unsigned n)
{
    static unsigned memo[MAX] = {1, 1};

    if (n == 0 || n == 1)
        return 1;

    if (memo[n])
        return memo[n];

    return memo[n] = fib(n - 1) + fib(n - 2);
}

unsigned fib_nomemo(unsigned n)
{
    if (n == 0 || n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}