#include <stdio.h>

typedef struct RAZLOMAK
{
    double brojilac;
    int imenilac;
} razl;

int main()
{
    razl r1;
    razl r2;
    razl rez;

    // Prvi razlomak
    printf("Prvi razlomak: \n");

    printf("Brojilac: ");
    scanf("%lf", &r1.brojilac);

    do
    {
        printf("Imenilac: ");
        scanf("%d", &r1.imenilac);
    } while (r1.imenilac == 0);

    // Drugi razlomak
    printf("Drugi razlomak: \n");

    printf("Brojilac: ");
    scanf("%lf", &r2.brojilac);

    do
    {
        printf("Imenilac: ");
        scanf("%d", &r2.imenilac);
    } while (r2.imenilac == 0);

    if (r1.imenilac == r2.imenilac)
    {
        rez.imenilac = r1.imenilac;
        rez.brojilac = r1.brojilac + r2.brojilac;
    }
    else
    {
        rez.imenilac = r1.imenilac * r2.imenilac;
        rez.brojilac = r2.imenilac * r1.brojilac + r1.imenilac * r2.brojilac;
    }

    for (int i = (rez.imenilac >= rez.brojilac) ? rez.imenilac : rez.brojilac; i > 0; i--)
    {
        if (rez.imenilac % i == 0 && (int)rez.brojilac % i == 0)
        {
            rez.imenilac /= i;
            rez.brojilac /= i;
        }
    }

    printf("Zbir: %.2lf/%d", rez.brojilac, rez.imenilac);

    return 0;
}