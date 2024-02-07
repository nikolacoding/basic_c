#include <stdio.h>

typedef struct skup
{
    int a;      // sizeof = 4
    int b;      // sizeof = 4
    char c[23]; // sizeof = 22
    short d;    // sizeof = 2
    double e;   // sizeof = 8
} S;

union unija
{
    int a;
    char b;
} un;

int main()
{
    S skup1;
    un.b = 'C';

    printf("Velicina pojedinih podataka: %d, %d, %d, %d\n", sizeof(skup1.a),
           sizeof(skup1.b),
           sizeof(skup1.c),
           sizeof(skup1.d));
    printf("Ukupna velicina: %d\n\n", sizeof(skup1));

    printf("Unija int: %d\n", sizeof(un.a));
    printf("Unija char: %d\n", sizeof(un.b));
    printf("Velicina unije: %d\n", sizeof(un));

    return 0;
}