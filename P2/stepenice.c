// Napisati funkciju koja računa broj načina na koji se možemo popeti uz n stepenica.
// U jednom koraku možemo preći 1, 2 ili 3 stepenice. Ukoliko smo u trenutnom koraku
// prešli 2 ili 3 stepenice, u sljedećem koraku možemo preći samo 1 stepenicu.

#include <stdio.h>
#include <stdbool.h>

int countClimbWays(int, int, bool);

int main(int argc, char const *argv[])
{
    printf("Broj nacina: %d", countClimbWays(5, 0, true));
    return 0;
}

int countClimbWays(int n, int lastStep, bool lastStepRelevant)
{
    if (n == 1)
        return 1;
    if (n < 0)
        return 0;
    if (!n)
        return 1;

    if (lastStepRelevant)
    {
        if (lastStep <= 1)
            return countClimbWays(n - 1, 1, true) + countClimbWays(n - 2, 2, true) + countClimbWays(n - 3, 3, true);
        else
            return countClimbWays(n - 1, 1, true);
    }
    else
        return countClimbWays(n - 1, 1, false) + countClimbWays(n - 2, 2, false) + countClimbWays(n - 3, 3, false);
}

//
//
//
//
//

// 5 => (false)
// 1, 1, 1, 1, 1
// 2, 1, 1, 1
// 1, 2, 1, 1
// 1, 1, 2, 1
// 1, 1, 1, 2
// 2, 2, 1
// 1, 2, 2
// 2, 1, 2
// 3, 1, 1
// 1, 3, 1
// 1, 1, 3
// 3, 2
// 2, 3
//
//
