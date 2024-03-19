#include <stdio.h>

int clan(int);

int main(int argc, char const *argv[])
{
    int n;

    do
    {
        printf("Unesi broj clana niza: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("%d. clan niza: %d", n, clan(n));

    return 0;
}

int clan(int n)
{
    static int memo[100] = {1, 2, 3};
    if (n <= 3)
        return n;

    if (memo[n])
        return memo[n];
    else
        return memo[n] = clan(n - 1) + clan(n - 2) + clan(n - 3);
}