#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = 0;

    for (int i = 0; i < 5; i++)
    {
        if (a < b && b++ > c)
            printf("Provjereno!\n");
    }

    printf("\n%d", b);

    return 0;
}