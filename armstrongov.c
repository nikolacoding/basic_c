#include <stdio.h>
#include <math.h>

int main()
{
    int a, b;
    do
    {
        printf("Unesi brojeve a i b: ");
        scanf("%d %d", &a, &b);
    } while (a < 1 || b < 1 || b <= a);

    for (int i = a; i <= b; i++)
    {
        int i0 = i, i1 = i, cif = 1;
        double suma = 0;

        while (i0 /= 10)
            cif++;

        for (int j = 0; j < cif; j++)
            suma += pow((i1 /= (!j) ? 1 : 10) % 10, cif);

        if (suma == i)
            printf("Broj %d je Armstrongov.\n", i);
    }
    return 0;
}