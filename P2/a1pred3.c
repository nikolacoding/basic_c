// Napisati program koji učitava (neoznačen) broj n, a zatim
// ispisuje broj n u brojnom sistemu sa osnovom bo (bo ≤ 10).
// Ispis (neoznačenog) broja n u brojnom sistemu sa osnovom bo treba da se vrši u rekurzivnoj funkciji konv.

#include <stdio.h>

unsigned konv(unsigned, int);

int main()
{
    unsigned n;
    int bo;

    do
    {
        printf("Unesi broj: ");
        scanf("%d", &n);
    } while (n < 1);

    do
    {
        printf("Unesi bazu: ");
        scanf("%d", &bo);
    } while (bo < 1 || bo > 10);

    konv(n, bo);

    return 0;
}

unsigned konv(unsigned n, int bo)
{
    if (n / bo)
        konv(n / bo, bo);

    printf("%d", n % bo);
}