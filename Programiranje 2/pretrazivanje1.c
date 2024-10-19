// Razni algoritmi za pretrazivanje primjenjeni na isti niz

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ispisiNiz(int *, int);

// Sekvencijalno pretrazivanje:
int seq_search(int *, int, int);
int seq_search_s(int niz[], int kljuc);
int seq_search_u(int *, int, int);           // unaprijedjeno, bez nepotrebnih poredjenja
int move_to_front(int *, int, int);          // pomjera pronadjeni element na pocetka niza
int move_to_back(int *, int, int);           // pomjera pronadjeni element na kraj niza
int MoveToFrontBinR(int *, int, int, int); // MTF uz dodatak binarne rekurzivne pretrage

// Binarno pretrazivanje i varijante:
int bin_search(int *, int, int);       // iterativna/nerekurzivna implementacija
int bin_search_rec(int *, int, int, int); // rekurzivna implementacija
int interp_search(int *, int, int);
int exp_search(int niz[], int k);

int main(int argc, char const *argv[])
{

    return 0;
}

int seq_search(int *niz, int n, int kljuc){
    for (int i = 0; i < n; i++)
        if (niz[i] == kljuc)
            return i;
    return -1;
}

int seq_search_u(int *niz, int n, int kljuc)
{
    int i = 0;
    while (niz[i] < kljuc && i < n)
        i++;

    if (niz[i] == kljuc && i < n)
        return i;
    else
        return -1;
}

int move_to_front(int *niz, int n, int kljuc)
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
}

int move_to_back(int *niz, int n, int kljuc)
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
}

int MoveToFrontBinR(int *niz, int kljuc, int begin, int end)
{
    int sredina = (begin + end) / 2;

    if (kljuc == niz[sredina])
    {
        int temp = niz[sredina], i = sredina;
        for (; i > 0; i--)
            niz[i] = niz[i - 1];
        niz[0] = temp;
        return 0;
    }

    if (begin > end)
        return -1;

    if (kljuc > niz[sredina])
        return MoveToFrontBinR(niz, kljuc, sredina + 1, end);
    else if (kljuc < niz[sredina])
        return MoveToFrontBinR(niz, kljuc, begin, sredina - 1);
}

int bin_search(int *niz, int n, int kljuc)
{
    int begin = 0, end = n - 1, sredina;

    do
    {
        sredina = (begin + end) / 2;
        if (kljuc == niz[sredina])
            return sredina;

        if (kljuc > niz[sredina])
            begin = sredina + 1;
        else if (kljuc < niz[sredina])
            end = sredina - 1;

    } while (begin <= end);
    return -1;
}

int bin_search_rec(int *niz, int kljuc, int begin, int end)
{
    int sredina = (begin + end) / 2;

    if (kljuc == niz[sredina])
        return sredina;

    if (begin > end)
        return -1;

    if (kljuc > niz[sredina])
        return bin_search_rec(niz, kljuc, sredina + 1, end);
    else if (kljuc < niz[sredina])
        return bin_search_rec(niz, kljuc, begin, sredina - 1);
}

int exp_search(int niz[], int kljuc){
    int begin = 0, end = 1;
    // uzimamo sigurnu gornju i donju granicu
    // jer bolje ne mozemo procijeniti
    while (end < kljuc){
        begin = end;
        end *= 2;
    }
    // kada smo pronasli interval, pozivamo binarnu
    // pretragu nad njim i vracamo rezultat

    // koristimo rekurzivnu b.p. jer smo u njene argumente
    // uveli granice koje ovdje koristimo takodje
    return bin_search_rec(niz, kljuc, begin, end);
}

// KNBEB
// NENB
int interp_search(int *niz, int n, int kljuc)
{
    int begin = 0, end = n - 1, brojilac, imenilac, sredina;
    do
    {
        brojilac = (kljuc - niz[begin]) * (end - begin);
        imenilac = niz[end] - niz[begin];
        sredina = begin + brojilac / imenilac;

        if (kljuc == niz[sredina])
            return sredina;

        if (kljuc > niz[sredina])
            begin = sredina + 1;
        else if (kljuc < niz[sredina])
            end = sredina - 1;
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