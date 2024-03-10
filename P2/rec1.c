#include <stdio.h>

void cifra(unsigned);

int main(int argc, char const *argv[])
{
    unsigned n;
    do
    {
        printf("Unesi broj: ");
        scanf("%u", &n);
    } while (!n);

    cifra(n);
    return 0;
}

void cifra(unsigned n)
{
    if (n / 10 == 0)
    {
        printf("%u", n % 10);
        return;
    }
    else
        cifra(n / 10);
    printf("%u", n % 10);
}