#include <stdio.h>
#define MAX 20

int fib(int);

int main()
{
    int n;

    do
    {
        printf("Unesi broj cifara Fibonaccijevog niza: ");
        scanf("%d", &n);
    } while (n < 1 && n > MAX);

    for (int i = 0; i < n; i++)
        printf("%02d: %d\n", i + 1, fib(i));

    return 0;
}
int fib(int n)
{
    static int memo[MAX] = {1, 1};

    if (!memo[n])
        return memo[n] = fib(n - 1) + fib(n - 2);
    else
        return memo[n];
}