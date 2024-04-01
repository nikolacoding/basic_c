// Napisati program koji iz datoteke čiji je naziv prvi argument komandne linije, čita podatke o krugovima,
// a zatim pronalazi i, na standardni izlaz, ispisuje podatke o krugu koji ima najveću površinu. Ulazna
// datoteka u kojoj su upisani podaci o krugovima formatirana je tako da je u svakom redu datoteke upisan
// podatak o jednom krugu u obliku:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.141
#define SQ(x) (x) * (x)

typedef struct
{
    double x, y, r;
} KRUG;

double PK(KRUG);
void formiraj(KRUG *, double, double, double);

int main(int argc, char const *argv[])
{
    char filename[64];
    FILE *fp;

    if (argc == 2)
    {
        strcpy(filename, argv[1]);
        double xBuff, yBuff, rBuff, pMax = 0;
        KRUG k, kMax;

        if (fp = fopen(filename, "r"))
        {
            while (fscanf(fp, "(%lf,%lf,%lf)\n", &xBuff, &yBuff, &rBuff) != EOF)
                if (formiraj(&k, xBuff, yBuff, rBuff), PK(k) > pMax)
                    kMax = k, pMax = PK(k);
            printf("Najvecu povrsinu (P = %.2lf) ima krug (%.2lf, %.2lf, %.2lf).",
                   PK(kMax), kMax.x, kMax.y, kMax.r);

            fclose(fp);
        }
        else
            printf("Neuspjesno otvaranje datoteke '%s'.", filename);
    }
    else
        printf("Argumenti nisu pravilno navedeni.");

    return 0;
}

double PK(KRUG k)
{
    return SQ(k.r) * PI;
}
void formiraj(KRUG *k, double x, double y, double r)
{
    k->x = x;
    k->y = y;
    k->r = r;
}
