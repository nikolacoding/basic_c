#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    typedef union x
    {
        char c[4];
        float f;
        int i;
    } X;

    X x = {{[3] = 0xc1}};
    printf("%x:%x\n", 0, &x);
    printf("%x:%x\n", 1, sizeof(x));
    printf("%x:%x\n", 2, &x.f);
    printf("%x:%.2f\n", 3, x.f);
    printf("%x:%x\n", 4, *(int *)&x);
    x.c[2] = 0x40;
    printf("%x:%x\n", 5, *(int *)&x);
    printf("%x:%.2f\n", 6, x.f);
    printf("%x:%x\n", 7, &x.i);
    printf("%x:%x\n", 8, x.i);
    printf("%x:%x\n", 9, &x + 1);
    printf("%x:%x\n", 10, &x - 1);

    return 0;
}