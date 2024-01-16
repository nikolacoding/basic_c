#include <stdio.h>
#include <math.h>

typedef struct TROUGAO
{
    double a;
    double b;
    double c;
} trougao;

int main()
{
    trougao t;

    double obim, povrsina;
    double s;

    do
    {
        printf("Unesi stranice trougla: ");
        scanf("%lf %lf %lf", &t.a, &t.b, &t.c);
    } while ((t.a + t.b) <= t.c || (t.a + t.c) <= t.b || (t.b + t.c) <= t.a || t.a <= 0 || t.b <= 0 || t.c <= 0);

    obim = t.a + t.b + t.c;
    s = (t.a + t.b + t.c) / 2;
    povrsina = sqrt(s * (s - t.a) * (s - t.b) * (s - t.c));

    printf("========\nObim: %.2lf\nPovrsina: %.2lf\n========", obim, povrsina);

    return 0;
}