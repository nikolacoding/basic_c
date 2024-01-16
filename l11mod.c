#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define sq(X) (X) * (X)

typedef struct TACKA
{
    char s;
    double x;
    double y;
} TACKA;

typedef struct TROUGAO
{
    TACKA A;
    TACKA B;
    TACKA C;
} TROUGAO;

void citaj(TACKA *);
int provjera(TACKA *);
TROUGAO trougao(TACKA *);
double obim(TROUGAO);

int main()
{
    TACKA a, b, c;
    TACKA *niz;
    TROUGAO tr;
    int pr;

    niz = (TACKA *)malloc(3 * sizeof(TACKA));

    citaj(&a);
    citaj(&b);
    citaj(&c);

    niz[0] = a;
    niz[1] = b;
    niz[2] = c;

    pr = provjera(niz);

    if (!pr)
    {
        printf("Trougao se ne moze konstruisati.");
        return 0;
    }
    else
    {
        tr = trougao(niz);
        printf("Obim trougla je %.2lf", obim(tr));
    }

    double AB = sqrt(sq(tr.A.x - tr.B.x) + sq(tr.A.y - tr.B.y));
    double BC = sqrt(sq(tr.B.x - tr.C.x) + sq(tr.B.y - tr.C.y));
    double CA = sqrt(sq(tr.C.x - tr.A.x) + sq(tr.C.y - tr.A.y));

    if ((sq(AB) + sq(BC) == sq(CA)) ||
        (sq(AB) + sq(CA) == sq(BC)) ||
        (sq(CA) + sq(BC) == sq(AB)))
    {
        printf("\nTrougao je pravougli.");
    }
    else
        printf("\nTrougao nije pravougli.");

    free(niz);
    niz = NULL;

    return 0;
}

void citaj(TACKA *tacka)
{
    static char L = 'a';

    printf("Unesi koordinate tacke %c: ", L);
    scanf("%lf %lf", &tacka->x, &tacka->y);
    tacka->s = L++;
}

int provjera(TACKA *niz)
{
    TACKA a, b, c;
    double AB, BC, CA;
    double s, p;

    a.x = niz[0].x;
    a.y = niz[0].y;

    b.x = niz[1].x;
    b.y = niz[1].y;

    c.x = niz[2].x;
    c.y = niz[2].y;

    AB = sqrt(sq(a.x - b.x) + sq(a.y - b.y));
    BC = sqrt(sq(b.x - c.x) + sq(b.y - c.y));
    CA = sqrt(sq(c.x - a.x) + sq(c.y - a.y));

    s = (AB + BC + CA) / 2;
    p = sqrt(s * (s - AB) * (s - BC) * (s - CA));

    return p ? 1 : 0;
}

TROUGAO trougao(TACKA *niz)
{
    TROUGAO temp;

    temp.A.x = niz[0].x;
    temp.B.x = niz[1].x;
    temp.C.x = niz[2].x;

    temp.A.y = niz[0].y;
    temp.B.y = niz[1].y;
    temp.C.y = niz[2].y;

    return temp;
}

double obim(TROUGAO trougao)
{
    double o = 0;
    double AB, BC, CA;

    AB = sqrt(sq(trougao.A.x - trougao.B.x) + sq(trougao.A.y - trougao.B.y));
    BC = sqrt(sq(trougao.B.x - trougao.C.x) + sq(trougao.B.y - trougao.C.y));
    CA = sqrt(sq(trougao.C.x - trougao.A.x) + sq(trougao.C.y - trougao.A.y));

    o += AB;
    o += BC;
    o += CA;

    return o;
}