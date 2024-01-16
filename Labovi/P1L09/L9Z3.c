#include <stdio.h>
#include <math.h>
#define KV(x) (x) * (x)
#define MAX 100

typedef struct KOMPLEKS
{
    double re, im;
} cnum;

int main()
{
    int n;
    cnum kompleksni[MAX], temp;

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

    printf("== ===============\n");
    printf("##     BROJ\n");
    printf("== ===============\n");
    for (int i = 0; i < n; i++)
    {
        printf("%02d %.2lf", i + 1, kompleksni[i].re);
        printf((kompleksni[i].im < 0) ? " - %.2lfi\n" : " + %.2lfi\n", fabs(kompleksni[i].im));
    }
    printf("== ===============");

    return 0;
}