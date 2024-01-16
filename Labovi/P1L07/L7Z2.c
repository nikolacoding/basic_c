#include <stdio.h>
#include <math.h>

int main()
{

    int d;
    double dist = 0;

    do
    {
        printf("Dimenzionalnost: ");
        scanf("%d", &d);
    } while (d < 1);

    int vec1[d];
    int vec2[d];

    for (int i = 0; i < d; i++)
    {
        printf("Unesi %d. tacku prvog vektora: ", i + 1);
        scanf("%d", &vec1[i]);
    }

    for (int i = 0; i < d; i++)
    {
        printf("Unesi %d. tacku drugog vektora: ", i + 1);
        scanf("%d", &vec2[i]);
    }

    for (int i = 0; i < d; i++)
    {
        double temp = pow(vec1[i] - vec2[i], 2);
        dist += temp;
    }

    printf("Rastojanje izmedju tacaka: %.2lf", sqrt(dist));

    return 0;
}