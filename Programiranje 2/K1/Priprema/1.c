// Neka je dat tip predmet; Napisati funkciju koja prihvata nesortiran niz od n podataka
// o predmetima te naziv izlazne tekstualne datoteke. Funkcija treba da u izlaznu tekstualnu
// datoteku upiše podatke o predmetima sortirane u rastućem redoslijedu prema nazivu
// (primjenom insert-sort algoritma), pri čemu originalni niz podataka ne smije biti promijenjen.
// Prototip funkcije je void sortiraj(PREDMET *niz, int n, const char *dat)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct predmet
{
    char id[15];
    char naziv[64];
    int ects;
} PREDMET;

void sortiraj(PREDMET *, int, const char *);

int main(int argc, char const *argv[])
{
    const int n = 4;
    PREDMET niz[] = {
        {"AAAA", "Matematika I", 6},
        {"BBBB", "Programiranje I", 7},
        {"CCCC", "Filozofija", 3},
        {"DDDD", "Osnovi elektrotehnike 1", 7}};

    sortiraj(niz, n, "sortirano.dat");

    return 0;
}

void sortiraj(PREDMET *niz, int n, const char *dat)
{
    FILE *fp;
    PREDMET *towrite = (PREDMET *)malloc(n * sizeof(PREDMET));
    for (int i = 0; i < n; i++)
        towrite[i] = niz[i];

    if (fp = fopen(dat, "w"))
    {
        int i, j;
        PREDMET temp;

        for (i = 1; i < n; i++)
        {
            temp = towrite[i];
            for (j = i; j > 0 && towrite[j - 1].naziv[0] > temp.naziv[0]; j--)
                towrite[j] = towrite[j - 1];
            towrite[j] = temp;
        }

        for (int p = 0; p < n; p++)
        {
            printf("writing: %s", towrite[p].naziv);
            fprintf(fp, "%s | %s | %d\n", towrite[p].id, towrite[p].naziv, towrite[p].ects);
        }
        fclose(fp);
        free(towrite);
    }
    else
        printf("Neuspjesno otvaranje datoteke '%s'.", dat);
}