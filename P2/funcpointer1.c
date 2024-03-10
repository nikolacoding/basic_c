// Napisati program sa dvije funkcije inc i mul koje inkrementuju i dupliraju zadati cijeli broj, respektivno.
// Potom napisati funkciju za mapiranje koja uzima kao argumente inicijalizovan niz brojeva, prazan niz brojeva,
// broj clanova niza kao i funkciju za manipulaciju tih brojeva. Funkcija potom svaki clan prvog niza uzima,
// provlaci kroz funkciju iz argumenta i mapira na drugi niz. Konacno, napisati glavnu funkciju koja funkciji
// za mapiranje salje proizvoljan niz cijelih brojeva, jedan prazan niz cijelih brojeva kao i duzinu i ispisuje
// inkrementovane i duplirane clanove tog niza uz pomoc prve dvije funkcije.

#include <stdio.h>

int inc(int x) { return ++x; }
int mul(int x) { return x * 2; }

void map(int a[], int b[], int n, int (*f)(int))
{
    for (int i = 0; i < n; i++)
        b[i] = (*f)(a[i]);
}

void ispis(int niz[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", niz[i]);
    printf("\n");
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5}, b[5];
    int (*fniz[])(int) = {inc, mul};

    for (int i = 0; i < 2; i++)
    {
        map(a, b, 5, fniz[i]);
        ispis(b, 5);
    }

    return 0;
}