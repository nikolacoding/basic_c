// Pokusaj optimizacije 'stepenice.c'
// Napisati rekurzivnu funkciju koja broji nacine da se popnemo uz n stepenica. Jednim korakom mozemo preci 1, 2 ili 3
// stepenice, ali predjemo 2 ili 3, u narednom koraku mozemo preci najvise jednu.

#include <stdio.h>

int stepenice(int, int);
int main(int argc, char const *argv[])
{
    const int n = 4;
    printf("Uz %d stepenica se mozemo popeti na %d nacina.\n", n, stepenice(n, 0));
    return 0;
}

int stepenice(int n, int lastStep)
{
    if (n == 1 || n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (lastStep <= 1)
        return stepenice(n - 1, 1) + stepenice(n - 2, 2) + stepenice(n - 3, 3);
    else
        return stepenice(n - 1, 1);
}
// 1 1 1 1
// 2 1 1
// 1 2 1
// 1 1 2
// 3 1
// 1 3