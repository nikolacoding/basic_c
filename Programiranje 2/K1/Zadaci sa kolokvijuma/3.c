// Napisati funkciju sortiraj koja prihvata niz od n naziva tekstualnih datoteka (stringova). Funkcija treba da
// u rastucem redoslijedu sortira nazive datoteka prema velicini datoteke (broju karaktera u njoj). Sortiranje
// treba izvrsiti shell-sort algoritmom. Prototip funkcije je: void sortiraj(char *naziviDatoteka[], int n);

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortiraj(char *naziviDatoteka[], int n) // samo ova funkcija je bila na kolokvijumu, ne i main
{
    int nchar[n];
    FILE *fp;

    for (int i = 0; i < n; i++)
    {
        if (fp = fopen(naziviDatoteka[i], "r"))
        {
            nchar[i] = 0;
            while (fgetc(fp) != EOF)
                nchar[i]++;
        }
        fclose(fp);
    }

    int i, j, h;
    char temp[64];

    for (h = n / 2; h > 0; h /= 2)
        for (i = 1; i < n; i++)
        {
            strcpy(temp, naziviDatoteka[i]);
            int tempn = nchar[i];
            for (j = i; j >= h && tempn < nchar[j - h]; j -= h)
            {
                strcpy(naziviDatoteka[j], naziviDatoteka[j - h]);
                nchar[j] = nchar[j - h];
            }
            strcpy(naziviDatoteka[j], temp);
            nchar[j] = tempn;
        }
}

int main(int argc, char const *argv[])
{
    const int n = 2;
    char **nd = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
        nd[i] = (char *)calloc(100, sizeof(char));

    strcpy(nd[0], "3_1.txt");
    strcpy(nd[1], "3_2.txt");

    sortiraj(nd, n);

    for (int i = 0; i < n; i++)
        printf("%d: %s\n", i + 1, nd[i]), free(nd[i]);
    free(nd);
    return 0;
}