#include <stdio.h>

int main()
{
    int n = 0;

    int f1 = 0;
    int f2 = 1;
    int t = 0;

    do
    {
        printf("Unesi broj: ");
        scanf("%d", &n);
    } while (n < 1);

    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d\n", f1);
        t = f2;
        f2 += f1;
        f1 = t;
    }

    return 0;
}