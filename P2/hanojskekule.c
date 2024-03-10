#include <stdio.h>

void prebaci(unsigned, char, char, char);

int main(int argc, char const *argv[])
{
    unsigned n;

    do
    {
        printf("Unesi broj diskova: ");
        scanf("%u", &n);
    } while (!n);

    prebaci(n, 'A', 'B', 'P');

    return 0;
}

// A -> P -> B

void prebaci(unsigned n, char sa, char na, char preko)
{
    if (n == 1)
        printf("%c -> %c\n", sa, na);
    else
    {
        prebaci(n - 1, sa, preko, na);
        printf("%c -> %c\n", sa, na);
        prebaci(n - 1, preko, na, sa);
    }
}