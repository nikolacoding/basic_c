#include <stdio.h>

float stepen(float, int);

int main()
{
    float x;
    int e;
    int brojIzvrsavanja;

    printf("Unesi broj i stepen: ");

    do
    {
        scanf("%f %d", &x, &e);
    } while (e < 1);

    printf("\n%.1f^%d = %.2f", x, e, stepen(x, e));

    return 0;
}

float stepen(float x, int e)
{
    static int brojIzvrsavanja = 0;
    brojIzvrsavanja++;

    if (!e)

        return 1;

    return x * stepen(x, e - 1);
}