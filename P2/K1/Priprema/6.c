// Neka je dat tip TAKMICAR kojim se reprezentuju podaci o jednom takmičaru na nekom takmičenju.
// Napisati funkciju koja prihvata i sortira niz od n podataka o takmičarima u rastućem redoslijedu prema rezultatu.
// Sortiranje realizovati merge-sort algoritmom. Napisati funkciju koja prihvata naziv izlazne binarne datoteke
// (parametar dat) i (neuređen) niz od n podataka o takmičarima. Funkcija treba da, korištenjem prethodno
// definisane funkcije, sortira podatke o takmičarima, a zatim da sortirane podatke upiše u izlaznu binarnu datoteku.
// Prototip funkcije je: void pisi(const char *dat, TAKMICAR *niz, int n);
//
// U ulaznoj binarnoj datoteci upisan je nepoznat broj podataka o takmičarima. Podaci o takmičarima nisu uređeni.
// Napisati funkciju koja u ulaznoj binarnoj datoteci čiji je naziv parametar dat, pronalazi i vraća podatke o
// takmičaru sa zadatim identifikatorom. Ukoliko u datoteci nema podataka o takmičaru sa zadatim identifikatorom,
// funkcija treba da vrati NULL. Nije dozvoljeno učitavanje kompletne datoteke u memoriju. Prototip funkcije je:
// TAKMICAR* find(const char *dat, int identifikator);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int identifikator;
    char ime[50];
    char prezime[50];
    int rezultat;
} TAKMICAR;

void quickSort(TAKMICAR *, int, int);
int split(TAKMICAR *, int, int);

void pisi(const char *, TAKMICAR *, int);
TAKMICAR *find(const char *, int);

int main(int argc, char const *argv[])
{
    const int n = 5;
    const char filename[] = "6.dat";
    int targetID = 124;
    TAKMICAR *target;
    TAKMICAR takmicari[5] = {{124, "Nikola", "Markovic", 2},
                             {125, "Jovan", "Jovanovic", 5},
                             {126, "Ivan", "Ivanovic", 2},
                             {127, "Marko", "Markovic", 3},
                             {128, "Grozdivoje", "Grozdjic", 1}};
    pisi(filename, takmicari, n);
    if (target = find(filename, targetID))
    {
        printf("Pronadjen je takmicar:\n");
        printf("    ID: %d\n    Ime: %s\n    Prezime: %s\n    Rezultat: #%d\n",
               target->identifikator, target->ime, target->prezime, target->rezultat);
    }
    else
        printf("Takmicar [%d] nije pronadjen.\n", targetID);
    return 0;
}

TAKMICAR *find(const char *dat, int identifikator)
{
    FILE *fp;
    TAKMICAR *t;
    int p = 0;
    if (fp = fopen(dat, "rb"))
    {
        do
        {
            p = fread(t, sizeof(TAKMICAR), 1, fp);
            if (p)
            {
                if (t->identifikator == identifikator)
                {
                    fclose(fp);
                    return t;
                }
            }
        } while (p);
        return NULL;
    }
    else
        printf("Datoteka '%s' se ne moze otvoriti.\n", dat);
}

void pisi(const char *dat, TAKMICAR *niz, int n)
{
    FILE *fp;
    quickSort(niz, 0, n - 1);

    if (fp = fopen(dat, "wb"))
        fwrite(niz, sizeof(TAKMICAR), n, fp);
    else
        printf("Datoteka '%s' se ne moze otvoriti.\n", dat);
    fclose(fp);
}

int split(TAKMICAR *niz, int begin, int end)
{
    int i = begin, j = end;
    TAKMICAR pivot = niz[begin];

    while (i < j)
    {
        while (niz[i].rezultat <= pivot.rezultat && i < j)
            i++;
        while (niz[j].rezultat > pivot.rezultat)
            j--;

        if (i < j)
        {
            TAKMICAR temp = niz[i];
            niz[i] = niz[j];
            niz[j] = temp;
        }
    }
    niz[begin] = niz[j];
    niz[j] = pivot;
    return j;
}

void quickSort(TAKMICAR *niz, int begin, int end)
{
    if (begin < end)
    {
        int pivot = split(niz, begin, end);
        quickSort(niz, begin, pivot - 1);
        quickSort(niz, pivot + 1, end);
    }
}