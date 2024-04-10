// Napisati funkciju koja računa broj načina na koji se možemo popeti uz n stepenica.
// U jednom koraku možemo preći 1, 2 ili 3 stepenice. Ukoliko smo u trenutnom koraku
// prešli 2 ili 3 stepenice, u sljedećem koraku možemo preći samo 1 stepenicu.

#include <stdio.h>

int countClimbWays(int, int);

int main(int argc, char const *argv[])
{
    printf("Broj nacina: %d", countClimbWays(5, 0));
    return 0;
}

int countClimbWays(int n, int lastStep)
{
    if (n == 1)
        return 1;
    if (n < 0)
        return 0;
    if (!n)
        return 1;

    if (lastStep <= 1)
        return countClimbWays(n - 1, 1) + countClimbWays(n - 2, 2) + countClimbWays(n - 3, 3);
    else
        return countClimbWays(n - 1, 1);
}

// 5 =>
// 1, 1, 1, 1, 1
// 2, 1, 1, 1
// 1, 2, 1, 1
// 1, 1, 2, 1
// 1, 1, 1, 2
// 2, 1, 2
// 3, 1, 1
// 1, 3, 1
// 1, 1, 3
