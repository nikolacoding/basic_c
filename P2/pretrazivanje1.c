// Razni algoritmi za pretrazivanje primjenjeni na isti niz

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ispisiNiz(int *, int);

// Sekvencijalno pretrazivanje:
int seqSearch(int *, int, int);
int seqSearchU(int *, int, int);  // unaprijedjeno, bez nepotrebnih poredjenja
int MoveToFront(int *, int, int); // pomjera pronadjeni element na pocetka niza
int MoveToBack(int *, int, int);  // pomjera pronadjeni element na kraj niza

// Binarno pretrazivanje i varijante:
int binSearch(int *, int, int);       // iterativna/nerekurzivna implementacija
int binSearchR(int *, int, int, int); // rekurzivna implementacija
int interpSearch(int *, int, int);

int main(int argc, char const *argv[])
{
    int niz[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    const int kljuc = 8;
    const int n = sizeof(niz) / sizeof(niz[0]);

    int rez = interpSearch(niz, n - 1, kljuc);
    ispisiNiz(niz, n);

    if (rez != -1)
        printf("Kljuc %d je pronadjen na poziciji %d [%d].", kljuc, rez, niz[rez]);
    else
        printf("Kljuc %d nije pronadjen u nizu.", kljuc);

    return 0;
}

int seqSearch(int *niz, int n, int kljuc)
{
    for (int i = 0; i < n; i++)
        if (niz[i] == kljuc)
            return i;
    return -1;
}

int seqSearchU(int *niz, int n, int kljuc)
{
    int i = 0;
    while (niz[i] < kljuc && i < n)
        i++;

    if (niz[i] == kljuc && i < n)
        return i;
    else
        return -1;
}

int MoveToFront(int *niz, int n, int kljuc)
{
    for (int i = 0; i < n; i++)
        if (niz[i] == kljuc)
        {
            int temp = niz[i];
            for (; i > 0; i--)
                niz[i] = niz[i - 1];
            niz[0] = temp;
            return 0;
        }
    return -1;
}

int MoveToBack(int *niz, int n, int kljuc)
{
    for (int i = 0; i < n; i++)
        if (niz[i] == kljuc)
        {
            int temp = niz[i];
            for (; i < n - 1; i++)
                niz[i] = niz[i + 1];
            niz[n - 1] = temp;
            return n - 1;
        }
    return -1;
}

int binSearch(int *niz, int n, int kljuc)
{
    int begin = 0, end = n - 1, sredina;
    do
    {
        sredina = (begin + end) / 2;

        if (niz[sredina] == kljuc)
            return sredina;

        if (kljuc < niz[sredina])
            end = sredina - 1;
        else
            begin = sredina + 1;
    } while (begin <= end);
    return -1;
}

int binSearchR(int *niz, int kljuc, int begin, int end)
{
    int sredina = (begin + end) / 2;

    if (begin > end)
        return -1;

    if (niz[sredina] == kljuc)
        return sredina;
    else if (kljuc > niz[sredina])
        return binSearchR(niz, kljuc, sredina + 1, end);
    else
        return binSearchR(niz, kljuc, begin, sredina - 1);
}

int interpSearch(int *niz, int n, int kljuc)
{
    int begin = 0, end = n - 1, sredina, brojilac, imenilac;
    do
    {
        brojilac = (kljuc - niz[begin]) * (end - begin);
        imenilac = niz[end] - niz[begin];
        sredina = begin + brojilac / imenilac;

        if (niz[sredina] == kljuc)
            return sredina;
        if (kljuc < niz[sredina])
            end = sredina - 1;
        else
            begin = sredina + 1;

    } while (begin <= end);
    return -1;
}

int ispisiNiz(int *niz, int n)
{
    printf("Niz: ");
    for (int i = 0; i < n; i++)
        printf("%d ", niz[i]);
    printf("\n");
}