#include <stdio.h>
#include <math.h>
#define PRECISION 1e-5

int main(){

    double x, n;
    double xi, xt;

    double e = 1;
    int temp;

    int nCalc = 0;

    do{
        printf("Unesi x i n (n > 0): ");
        scanf("%lf %lf", &x, &n);
    } while(n <= 0);

    xi = (x + 1) / n;

    do{
        e = 1;
        temp = n - 1;
        xt = xi;

        while (temp--){
            e *= xi;
        }

        xi = (1 / n) * ((n - 1) * xi + x / e);

        nCalc++;
    } while (fabs(xi - xt) > PRECISION);

    printf("%lf\n", xi);
    printf("Broj kalkulacija: %d", nCalc);

    return 0;
}
