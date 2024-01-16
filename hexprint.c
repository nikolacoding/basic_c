#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf((a < 16) ? "#0%x" : "%x", a);
    printf((b < 16) ? "0%x" : "%x", b);
    printf((c < 16) ? "0%x" : "%x", c);

    return 0;
}