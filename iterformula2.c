#include <stdio.h>
#include <math.h>
#define PRECISION 1e-5

int main(){

    double x, n;
    double xi, xt;

    int nCalc = 0;

    do {
        printf("Unesi x i n (n > 0): ");
        scanf("%lf %lf", &x, &n);
    } while (n <= 0);

    xi = (x + 1) / n;

    do {

        xt = xi;
        xi = (1 / n) * ((n - 1) * xt + (x / pow(xt, n - 1)));
        nCalc++;

    } while (fabs(xt - xi) > PRECISION);

    printf("%.0lf. korijen od %.2lf je: %.5lf\nBroj kalkulacija: %d", n, x, xi, nCalc);

    return 0;
}
