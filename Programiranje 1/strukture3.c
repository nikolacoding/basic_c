#include <stdio.h>
#include <math.h>
#define KV(x) (x) * (x)

int main()
{
    struct tacka
    {
        double x, y;
    } poly[100];

    double obim = 0;
    int n;

    do
    {
        printf("Unesi broj vrhova poligona: ");
        scanf("%d", &n);
    } while (n < 3 || n > 100);

    for (int i = 0; i < n; i++)
    {
        printf("%d. vrh:\n", i + 1);

        printf("x = ");
        scanf("%lf", &poly[i].x);
        printf("y = ");
        scanf("%lf", &poly[i].y);
    }

    for (int i = 1; i < n; i++)
    {
        obim += sqrt(KV(poly[i].x - poly[i - 1].x) + KV(poly[i].y - poly[i - 1].y));
    }
    obim += sqrt(KV(poly[0].x - poly[n - 1].x) + KV(poly[0].y - poly[n - 1].y));

    printf("\n\nObim: %.2lf", obim);

    return 0;
}