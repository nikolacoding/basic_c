#include <stdio.h>
#include <math.h>
#define sq(x) (x) * (x)

// MODIFIKACIJA: Ispisati da li je trougao pravougli ili ne

typedef struct BOOL
{

#define TRUE 1
#define FALSE 0

} bool;

typedef struct TROUGAO
{
    double a;
    double b;
    double c;
    int jePravougli;
} trougao;

int main()
{
    trougao t;
    t.jePravougli = FALSE;

    double obim, povrsina;
    double s;

    do
    {
        printf("Unesi stranice trougla: ");
        scanf("%lf %lf %lf", &t.a, &t.b, &t.c);
    } while ((t.a + t.b) <= t.c || (t.a + t.c) <= t.b || (t.b + t.c) <= t.a || t.a <= 0 || t.b <= 0 || t.c <= 0);

    if (t.a == sqrt(sq(t.b) + sq(t.c)) || t.b == sqrt(sq(t.a) + sq(t.c)) || t.c == sqrt(sq(t.a) + sq(t.b)))
        t.jePravougli = 1;

    obim = t.a + t.b + t.c;
    s = (t.a + t.b + t.c) / 2;
    povrsina = sqrt(s * (s - t.a) * (s - t.b) * (s - t.c));

    printf("========\nObim: %.2lf\nPovrsina: %.2lf\n========\n", obim, povrsina);

    printf("Trougao ABC %sje pravougli.", (t.jePravougli) ? "" : "ni");

    return 0;
}