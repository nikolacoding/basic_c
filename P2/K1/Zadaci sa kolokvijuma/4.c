// Neka je dat niz cjelobrojnih neoznacenih podataka koji su sortirani po vrijednosti. Implementirati funkciju:
// unsigned int* ucitajBajt(unsigned int niz[], int duzina, int *n, unsigned int pocetak, unsigned int kraj);
// U funkciji se nad nizom (parametar niz) vrsi binarna pretraga do segmenta vrijednosti koje pocinju ili su vece
// od vrijednosti parametra kraj. Nakon pretrage vraca se dinamicki niz koji predstavlja segment originalnog
// niza. U rezultujucem nizu su sve vrijednosti u opsegu izmedju parametara pocetak i kraj (ukljucujuci i njih),
// pri cemu je duzina novog niza parametar *n.
//
// Smatrati da je pocetak <= kraj te da je vrijednost parametra kraj
// jednaka ili manja od posljednje vrijednosti u nizu.

#include <stdio.h>
#include <stdlib.h>

unsigned int *ucitajBajt(unsigned int niz[], int duzina, int *n, unsigned int pocetak, unsigned int kraj)
{
    int p = 0, k = duzina - 1, s;
    unsigned int *ret = (unsigned int *)malloc(duzina * sizeof(unsigned int));

    do
    {
        s = (p + k) / 2;

        if (niz[s] >= pocetak)
        {
            while (niz[s - 1] >= pocetak && s - 1 >= 0)
                s--;
            break;
        }

    } while (p <= k);

    ret[0] = niz[s];
    int b = 1;

    while (niz[s + 1] <= kraj && s - 1 < duzina)
    {
        ret[b++] = niz[s + 1];
        s++;
    }

    *n = b;
    ret = (unsigned int *)realloc(ret, b * sizeof(unsigned int *));

    for (int i = 0; i < b; i++) // <- debug
        printf("%d ", ret[i]);

    return ret;
}

int main(int argc, char const *argv[])
{
    const int n = 8;
    unsigned int niz[8] = {1, 6, 7, 8, 9, 10, 11, 12};
    int d;
    unsigned int *retval;
    ucitajBajt(niz, n, &d, 2, 4);
    printf("\nlen: %d\n", d);

    return 0;
}
