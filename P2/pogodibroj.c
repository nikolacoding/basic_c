// Implementacija eksponencijalnog pretrazivanja

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void pogadjaj(int, int);

int main(int argc, char const *argv[])
{
    int min, max;
    do
        printf("Unesi opseg (min: 0, max: 100): "), scanf("%d %d", &min, &max);
    while (min < 0 || max > 100 || min > max);

    pogadjaj(min, max);

    return 0;
}

void pogadjaj(int min, int max)
{
    int begin = min, end = min + 1, guess, sredina;

    while (1)
    {
        printf("Da li je broj veci od %d (1/0)? ", min);
        scanf("%d", &guess);
        if (!guess)
        {
            printf("Broj je %d.", min);
            return;
        }
        else
        {
            begin = end + 1;
            end *= 2;
            break;
        }
    }
    while (begin < end)
    {
        sredina = (begin + end) / 2;
        printf("Da li je broj veci od %d? (1/0) ", sredina);
        scanf("%d", &guess);

        if (guess)
            begin = sredina + 1;
        else
            end = sredina;
    }
    printf("Zamislili ste broj %d!\n", end);
    return;
}