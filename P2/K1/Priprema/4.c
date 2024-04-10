// Neka je dat tip KOSARKAS kojim se reprezentuju podaci o jednom kosarkasu.
//
// Napisati funkciju koja prima binarnu datoteku, te sortira košarkaše u datoj datoteci upotrebom
// insertion sort algoritma u opadajućem redoslijedu na osnovu prosjeka poena. Ukoliko dva igrača
// imaju jednak prosječni broj poena, koristiti prosječni broj asistencija za uslov sortiranja.
// Nije dozvoljeno učitavati cijeli niz u memoriju. Potrebno je sortirati košarkaše u mjestu
// (modifikovati postojeću binarnu datoteku). Prototip funkcije je sljedeći: void sortiraj(FILE *dat);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char ime[50];
    char prezime[50];
    double prosjek_poena;
    double prosjek_asistencija;
} KOSARKAS;

void insertionSort(FILE *dat);

int main(int argc, char const *argv[])
{
    char filename[64];
    FILE *fp;

    int n;
    KOSARKAS *niz;

    printf("Unesi ime datoteke: ");
    gets(filename);

    if (fp = fopen(filename, "r+b"))
    {
        insertionSort(fp);

        n = 5;
        niz = (KOSARKAS *)malloc(n * sizeof(KOSARKAS));

        fread(niz, sizeof(KOSARKAS), n, fp);
        for (int d = 0; d < n; d++)
        {
            printf("%s %s | %.1lf / %.1lf\n",
                   niz[d].ime,
                   niz[d].prezime,
                   niz[d].prosjek_poena,
                   niz[d].prosjek_asistencija);
        }
        free(niz);

        fclose(fp);
    }

    return 0;
}

void insertionSort(FILE *fp)
{
    int i, j, n;
    KOSARKAS temp, prev;

    fseek(fp, 0, SEEK_END);
    n = ftell(fp) / sizeof(KOSARKAS);

    for (i = 1; i < n; i++)
    {
        fseek(fp, i * sizeof(KOSARKAS), SEEK_SET);
        fread(&temp, sizeof(KOSARKAS), 1, fp);

        fseek(fp, (i - 1) * sizeof(KOSARKAS), SEEK_SET);
        fread(&prev, sizeof(KOSARKAS), 1, fp);

        for (j = i; j > 0 &&
                    (temp.prosjek_poena > prev.prosjek_poena ||
                     (temp.prosjek_poena == prev.prosjek_poena && temp.prosjek_asistencija > prev.prosjek_asistencija));)
        {
            fseek(fp, j * sizeof(KOSARKAS), SEEK_SET);
            fwrite(&prev, sizeof(KOSARKAS), 1, fp);

            if (j > 0)
            {
                j--;
                fseek(fp, (j - 1) * sizeof(KOSARKAS), SEEK_SET);
                fread(&prev, sizeof(KOSARKAS), 1, fp);
            }
        }
        fseek(fp, j * sizeof(KOSARKAS), SEEK_SET);
        fwrite(&temp, sizeof(KOSARKAS), 1, fp);
    }

    rewind(fp);
}