#include <stdio.h>
#define MAX 12

int f(int);

int main()
{
    int n;
    do
    {
        printf("Unesi broj: ");
        scanf("%d", &n);
    } while (n < 1 || n > MAX);
    printf("Faktorijel broja %d je: %d", n, f(n));

    return 0;
}

int f(int n)
{
    if (!n)
        return 1;

    return n * f(n - 1);
}

// f(5)
// ^ ret: 5 * f(4)
//            ^ ret: 4 * f(3)
//                       ^ ret: 3 * f(2)
//                                  ^ ret: 2 * f(1)
//                                             ^ ret: 1 * f(0)
//                                                        ^ ret: 1