// Napisati funkciju koja sortira u rastućem redoslijedu (po nekom kriterijumu) niz od n stringova. Sortiranje
// treba izvršiti insert-sort algoritmom. Prototip funkcije je:
// void sortiraj(char **niz, int n, int (*cmp)(const char *, const char *));
//
// Napisati nerekurzivnu funkciju koja binarno pretražuje (po nekom kriterijumu) niz od n stringova, pri čemu je
// ključ pretrage zadat kao parametar funkcije (kljuc). U slučaju uspješne pretrage funkcija vraća indeks pronađenog
// elementa, a u slučaju neuspješne pretrage funkcija vraća -1. Prototip funkcije je:
// int pretrazi(char **niz, int n, int (*cmp)(const char *, const char *), const char *kljuc);
//
// U glavnom programu treba formirati niz od pet proizvoljnih stringova, a zatim ga sortirati (korištenjem
// funkcije sortiraj). Na kraju, provjeriti (korištenjem funkcije pretrazi) i ispisati da li se u sortiranom
// nizu nalazi proizvoljan string. Kao kriterijum za poređenje koristiti dužinu stringa.
//
// Napomena: U funkcijama sortiraj i pretrazi, parametar cmp predstavlja pokazivač na funkciju koja vrši poređenje
// dva stringa prema nekom kriterijumu. Funkcija za poređenje vraća negativnu vrijednost ako je prvi string manji
// od drugog, vrijednost 0 ako su stringovi jednaki te pozitivnu vrijednost ako je prvi string veći od drugog.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortiraj(char **, int, int (*)(const char *, const char *));
int pretrazi(char **, int, int (*)(const char *, const char *), const char *);

int uporediDuzinu(const char *, const char *);

int main(int argc, char const *argv[])
{
    char **niz = (char **)malloc(5 * sizeof(char *));
    const int n = 5;

    for (int i = 0; i < n; i++)
        niz[i] = (char *)calloc(100, sizeof(char));
    strcpy(niz[0], "Pas");
    strcpy(niz[1], "Macka");
    strcpy(niz[2], "Drvo");
    strcpy(niz[3], "Grozdje");
    strcpy(niz[4], "Livada");

    sortiraj(niz, n, &uporediDuzinu);
    for (int i = 0; i < n; i++)
        printf("%s\n", niz[i]);
    int d = pretrazi(niz, n, &uporediDuzinu, "Grozdje");

    for (int i = 0; i < n; i++)
        free(niz[i]);
    free(niz);

    printf("Clan niza %s uspjesno pronadjen na indeksu %d.\n", niz[d], d);

    return 0;
}

int pretrazi(char **niz, int n, int (*cmp)(const char *, const char *), const char *kljuc)
{
    int begin = 0, end = n - 1;
    do
    {
        int sredina = (begin + end) / 2;
        if (!strcmp(niz[sredina], kljuc))
            return sredina;

        if ((*cmp)(kljuc, niz[sredina]) > 0)
            begin = sredina + 1;
        if ((*cmp)(kljuc, niz[sredina]) < 0)
            end = sredina - 1;
    } while (begin <= end);
    return -1;
}

void sortiraj(char **niz, int n, int (*cmp)(const char *, const char *))
{
    int i, j;
    char *temp = (char *)calloc(100, sizeof(char));

    for (i = 1; i < n; i++)
    {
        strcpy(temp, niz[i]);
        for (j = i; j > 0 && (*cmp)(temp, niz[j - 1]) < 0; j--)
            strcpy(niz[j], niz[j - 1]);
        strcpy(niz[j], temp);
    }
    free(temp);
}

int uporediDuzinu(const char *str1, const char *str2)
{
    return strlen(str1) - strlen(str2);

    // ako je str1 duzi, retval > 0
}