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
    char *filename;
    int n = 0, *niz = (int *)malloc(MAX * sizeof(int));

    if (argc == 2)
    {
        filename = (char *)calloc(BUFF + 1, sizeof(char));
        FILE *fp;
        strcpy(filename, argv[1]);

        int mode;
        enum modes
        {
            UNOS = 1,
            PRIKAZ = 2
        };

        if (filename[0] == '#')
            mode = PRIKAZ, filename++;
        else
            mode = UNOS;

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
    else
        printf("Argumenti nisu pravilno navedeni.");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortiraj(int *niz, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (niz[j] > niz[i])
                swap(&niz[i], &niz[j]);
}