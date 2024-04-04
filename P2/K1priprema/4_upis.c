// Program za upisivanje podataka o kosarkasima u binarnu datoteku kako bi se zadatak iz '4.c' mogao provjeriti.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char ime[50];
    char prezime[50];
    double prosjek_poena;
    double prosjek_asistencija;
} KOSARKAS;

int main(int argc, char const *argv[])
{
    char filename[64];
    FILE *fp;

    KOSARKAS *niz;
    int n;

    printf("Unesi ime datoteke: ");
    gets(filename);

    if (fp = fopen(filename, "wb"))
    {
        do
            printf("Unesi broj kosarkasa: "), scanf("%d", &n);
        while (n > MAX || n < 1);

        niz = (KOSARKAS *)malloc(n * sizeof(KOSARKAS));

        for (int i = 0; i < n; i++)
            printf("Podaci o %d. kosarkasu: ", i + 1), scanf("%s %s %lf %lf",
                                                             niz[i].ime, niz[i].prezime,
                                                             &niz[i].prosjek_poena,
                                                             &niz[i].prosjek_asistencija);

        fwrite(niz, sizeof(KOSARKAS), n, fp);
        printf("Uneseno.");
        fclose(fp);
        free(niz);
    }
    else
        printf("Datoteka '%s' se ne moze otvoriti.", filename);

    return 0;
}