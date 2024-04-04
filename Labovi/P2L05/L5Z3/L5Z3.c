// Napisati program koji omogućava unos proizvoljnog broja cjelobrojnih podataka putem standardnog
// ulaza, snimanje unesenih podataka sortiranih u opadajućem redoslijedu u binarnu datoteku i prikaz
// cjelobrojnih podataka iz binarne datoteke na standardnom izlazu.
// - Unos novih podataka:
// Podaci se snimaju u binarnu datoteku koja se prosljeđuje kao prvi argument komandne linije.
//
// - Čitanje podataka:
// Podaci se čitaju iz datoteke čiji se naziv unosi putem standardnog ulaza ili iz datoteke koja se
// prosljeđuje kao prvi argument komandne linije ukoliko se za naziv datoteke navede znak „#“.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF 64
#define MAX 100

void sortiraj(int *, int);
void swap(int *, int *);

int main(int argc, char const *argv[])
{
    char *filename = (char *)calloc(BUFF, sizeof(char));
    char choice[64];

    FILE *fp;
    int *niz = (int *)malloc(MAX * sizeof(int));
    int n = 0, mode;
    enum modes
    {
        UNOS = 1,
        PRIKAZ = 2
    };

    if (argc == 2)
        strcpy(filename, argv[1]), printf("Na komandnoj liniji je navedena datoteka '%s'.\n", filename);

    printf("Unesi ime datoteke%s: ", filename[0] ? " ('#' za citanje)" : "");
    scanf("%s", choice);

    if (strlen(choice) == 1 && choice[0] == '#')
        mode = PRIKAZ;
    else
        mode = UNOS, strcpy(filename, choice);

    if (mode == UNOS)
    {
        if (fp = fopen(filename, "wb"))
        {
            do
                printf("Unesi broj clanova: "), scanf("%d", &n);
            while (n < 1 || n > MAX);
            niz = (int *)realloc(niz, n * sizeof(int));

            for (int i = 0; i < n; i++)
                printf("[%d] n = ", i + 1), scanf("%d", &niz[i]);

            sortiraj(niz, n);

            fwrite(niz, sizeof(int), n, fp);

            fclose(fp);
        }
        else
            printf("Greska pri otvaranju datoteke '%s'.", filename);
    }
    else if (mode == PRIKAZ)
    {
        if (fp = fopen(filename, "rb"))
        {
            int p, t;
            do
            {
                p = fread(&t, sizeof(int), 1, fp);
                if (p)
                    niz[n++] = t;
            } while (p);

            niz = (int *)realloc(niz, n * sizeof(int));

            printf("Cijeli brojevi iz datoteke '%s': ", filename);
            for (int i = 0; i < n; i++)
                printf("%d ", niz[i]);

            fclose(fp);
        }
    }

    free(niz);
    free(filename);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortiraj(int *niz, int n)
{
    // shell-sort
    int i, j, h, temp;

    for (h = n / 2; h > 0; h /= 2)
    {
        for (i = 1; i < n; i++)
        {
            temp = niz[i];
            for (j = i; j >= h && niz[j - h] > temp; j -= h)
                niz[j] = niz[j - h];
            niz[j] = temp;
        }
    }
}