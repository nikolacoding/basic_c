#include <stdio.h>
#include <math.h>

int main()
{

    int n;
    int closest, closestIndex;
    float as = 0;
    float diff;

    do
    {
        printf("Unesi duzinu niza: ");
        scanf("%d", &n);
    } while (n < 1);

    int niz[n];

    for (int i = 0; i < n; i++)
    {
        printf("Unesi %d. element niza: ", i + 1);
        scanf("%d", &niz[i]);
        as += niz[i];
        if (i == n - 1)
            as /= n;
    }

    for (int i = 0; i < n; i++)
    {
        double d = fabs(as - niz[i]);
        if (d < diff)
        {
            diff = d;
            closest = niz[i];
            closestIndex = i;
        }
    }
    printf("================\n");
    printf("Aritmeticka sredina: %.1lf\n", as);
    printf("Najblizi element: %d\n", closest);
    printf("Originalni niz: ");
    for (int i = 0; i < n; i++)
    {
        printf((i != n - 1) ? "%d, " : "%d.", niz[i]);
    }

    for (int i = 0; i < closestIndex - 1; i++)
    {
        for (int j = i + 1; j < closestIndex; j++)
        {
            if (niz[i] > niz[j])
            {
                int temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }

    for (int i = closestIndex + 1; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (niz[i] < niz[j])
            {
                int temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }

    printf("\nModifikovani niz: ");
    for (int i = 0; i < n; i++)
    {
        printf((i != n - 1) ? "%d, " : "%d.", niz[i]);
    }
    printf("\n================");

    return 0;
}