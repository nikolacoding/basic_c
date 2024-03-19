#include <stdio.h>
#include <stdlib.h>

int suma(int *, int);

int main(int argc, char const *argv[])
{
    int *niz, n;

    do
    {
        printf("Unesi broj clanova niza: ");
        scanf("%d", &n);
    } while (n < 1);

    niz = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Unesi clan niza (%d/%d): ", i + 1, n);
        scanf("%d", &niz[i]);
    }

    printf("Suma: %d", suma(niz, n));

    free(niz);
    return 0;
}

int suma(int *niz, int n)
{
    if (n == 1)
        return niz[0];
    else
        return niz[n - 1] + suma(niz, n - 1);
}

// 2, 3, 4, 5; n=4
// niz[3] + suma(niz, 3)
//          2, 3, 4; n=3
//          niz[2] + suma(niz, 2)
//                   2, 3; n=2
//                   niz[1] + suma(niz, 1)
//                            2; n=1
//                            => 2
//                   => 3 + 2
//         => 4 + (3 + 2)
// => 5 + (4 + (3 + (2)))