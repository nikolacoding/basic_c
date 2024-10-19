#include <stdio.h>
#include <math.h>
#define KV(x) (x) * (x)

int main()
{
    struct tacka
    {
        double x, y;
    } a, b;
    double dist;

    printf("A:\n");
    printf("x = ");
    scanf("%lf", &a.x);
    printf("y = ");
    scanf("%lf", &a.y);

    printf("B:\n");
    printf("x = ");
    scanf("%lf", &b.x);
    printf("y = ");
    scanf("%lf", &b.y);

    dist = sqrt(KV(a.x - b.x) + KV(b.x - b.y));

    printf("Udaljenost tacaka je: %.2lf", dist);

    return 0;
}