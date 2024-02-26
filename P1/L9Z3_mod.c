#include <stdio.h>
#include <math.h>
#define KV(x) (x) * (x)
#define MAX 100

// MODIFIKACIJA 1: Izracunati sumu svih unesenih kompleksnih brojeva
// MODIFIKACIJA 2: Izracunati proizvod svih unesenih kompleksnih brojeva

typedef struct KOMPLEKS
{
    double re, im;
} cnum;

int main()
{
    int n;
    cnum kompleksni[MAX], temp;
    cnum suma;
    cnum proizvod, tempP;

    suma.re = 0;
    suma.im = 0;

    do
    {
        printf("Unesi broj kompleksnih brojeva: ");
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        printf("%d. broj od %d: \n", i + 1, n);

        printf("Re: ");
        scanf("%lf", &kompleksni[i].re);
        printf("Im: ");
        scanf("%lf", &kompleksni[i].im);
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i; j > -1; j--)
        {
            double mod1 = sqrt(KV(kompleksni[i].re) + KV(kompleksni[i].im));
            double mod2 = sqrt(KV(kompleksni[j].re) + KV(kompleksni[j].im));
            if (mod1 > mod2)
            {
                temp = kompleksni[i];
                kompleksni[i] = kompleksni[j];
                kompleksni[j] = temp;
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0)
        {
            proizvod.re = kompleksni[i].re * kompleksni[i + 1].re - kompleksni[i].im * kompleksni[i + 1].im;
            proizvod.im = kompleksni[i].re * kompleksni[i + 1].im + kompleksni[i].im * kompleksni[i + 1].re;
        }
        else
        {
            tempP.re = proizvod.re * kompleksni[i + 1].re - proizvod.im * kompleksni[i + 1].im;
            tempP.im = proizvod.re * kompleksni[i + 1].im + proizvod.im * kompleksni[i + 1].re;

            proizvod.re = tempP.re;
            proizvod.im = tempP.im;
        }
    }

    printf("== ===============\n");
    printf("##     BROJ\n");
    printf("== ===============\n");
    for (int i = 0; i < n; i++)
    {
        printf("%02d ", i + 1);
        printf("%.2lf", kompleksni[i].re);
        printf((kompleksni[i].im < 0) ? " - %.2lfi\n" : " + %.2lfi\n", fabs(kompleksni[i].im));
        suma.re += kompleksni[i].re;
        suma.im += kompleksni[i].im;
    }
    printf("===== ============\n");
    printf("Suma: ");
    printf("%.2lf", suma.re);
    printf((suma.im < 0) ? " - %.2lfi\n" : " + %.2lfi\n", fabs(suma.im));
    printf("===== ============\n");

    printf("Proizvod: ");
    printf("%.2lf", proizvod.re);
    printf((proizvod.im < 0) ? " - %.2lfi\n" : " + %.2lfi\n", fabs(proizvod.im));
    printf("========= ============");

    return 0;
}