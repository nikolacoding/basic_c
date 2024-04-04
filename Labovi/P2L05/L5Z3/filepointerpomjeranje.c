#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void ispis(int *, int);
void swap(FILE *, int, int, size_t);
void insertionSort(FILE *);

int main(int argc, char const *argv[])
{
    int *niz = (int *)malloc(MAX * sizeof(int));
    int target1, target2;

    char filename[64];
    FILE *fp;

    printf("Unesi ime datoteke: ");
    gets(filename);

    if (fp = fopen(filename, "rb+"))
    {
        int p, temp, n = 0;

        // printf("Unesi indeks dva clana niza: ");
        // scanf("%d %d", &target1, &target2);
        // swap(fp, target1, target2, sizeof(int));
        insertionSort(fp);

        do
        {
            p = fread(&temp, sizeof(int), 1, fp);
            if (p)
                niz[n++] = temp;
        } while (p);

        niz = (int *)realloc(niz, sizeof(int) * n);

        ispis(niz, n);

        fclose(fp);
    }
    else
        printf("Datoteka '%s' se ne moze otvoriti.", filename);
    return 0;
}

void insertionSort(FILE *fp)
{
    int i, j, temp, prev, n;

    fseek(fp, 0, SEEK_END);
    n = ftell(fp) / sizeof(int);

    for (i = 1; i < n; i++)
    {
        fseek(fp, i * sizeof(int), SEEK_SET);
        fread(&temp, sizeof(int), 1, fp);

        fseek(fp, (i - 1) * sizeof(int), SEEK_SET);
        fread(&prev, sizeof(int), 1, fp);

        for (j = i; j > 0 && temp < prev;)
        {
            fseek(fp, j * sizeof(int), SEEK_SET);
            fwrite(&prev, sizeof(int), 1, fp);

            if (j > 0)
            {
                j--;
                fseek(fp, (j - 1) * sizeof(int), SEEK_SET);
                fread(&prev, sizeof(int), 1, fp);
            }
        }
        fseek(fp, j * sizeof(int), SEEK_SET);
        fwrite(&temp, sizeof(int), 1, fp);
    }

    rewind(fp);
}

void swap(FILE *dat, int i1, int i2, size_t typesize)
{
    // pretpostavljamo da su argumenti pravilno navedeni
    int n1, n2;

    fseek(dat, i1 * typesize, SEEK_SET);
    fread(&n1, typesize, 1, dat);

    fseek(dat, i2 * typesize, SEEK_SET);
    fread(&n2, typesize, 1, dat);

    fseek(dat, i1 * typesize, SEEK_SET);
    fwrite(&n2, typesize, 1, dat);

    fseek(dat, i2 * typesize, SEEK_SET);
    fwrite(&n1, typesize, 1, dat);

    rewind(dat);
}

void ispis(int *niz, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", niz[i]);
    printf("\n");
}