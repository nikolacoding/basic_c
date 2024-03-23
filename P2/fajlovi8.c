#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF 128
#define MAX 100

typedef struct
{
    char indeks[16], ime[24], prezime[24];
    double prosjek;
} STUDENT;

STUDENT create_student(char *, char *, char *, double);
STUDENT *get_all_students(FILE *, FILE *, int *);
void header(FILE *);
void footer(FILE *);
void write(STUDENT *, int, FILE *, void (*header)(FILE *), void (*footer)(FILE *));

int main(int argc, char const *argv[])
{
    FILE *fm, *fz, *fs;
    char filename_m[BUFF], filename_z[BUFF], filename_s[BUFF];

    int n;
    STUDENT *studenti;

    if (argc == 4)
    {
        strcpy(filename_m, argv[1]);
        strcpy(filename_z, argv[2]);
        strcpy(filename_s, argv[3]);

        fm = fopen(filename_m, "r");
        fz = fopen(filename_z, "r");
        fs = fopen(filename_s, "w");

        if (fm && fz && fs)
        {
            studenti = get_all_students(fm, fz, &n);
            write(studenti, n, fs, &header, &footer);
            free(studenti);
        }
        else
            printf("Greska pri otvaranju datoteka.");
    }
    else
        printf("Argumenti nisu pravilno navedeni.");

    return 0;
}

STUDENT create_student(char *indeks, char *prezime, char *ime, double prosjek)
{
    STUDENT ret;
    strcpy(ret.indeks, indeks);
    strcpy(ret.prezime, prezime);
    strcpy(ret.ime, ime);
    ret.prosjek = prosjek;

    return ret;
}

STUDENT *get_all_students(FILE *f1, FILE *f2, int *n)
{
    char imeBuffer[BUFF], prezimeBuffer[BUFF], indeksBuffer[BUFF];
    double prosjekBuffer;

    int cnt = 0;

    STUDENT *all = (STUDENT *)malloc(MAX * sizeof(STUDENT));

    while (fscanf(f1, "%s %s %s %lf", indeksBuffer, prezimeBuffer, imeBuffer, &prosjekBuffer) != EOF)
        all[cnt++] = create_student(indeksBuffer, prezimeBuffer, imeBuffer, prosjekBuffer);

    while (fscanf(f2, "%s %s %s %lf", indeksBuffer, prezimeBuffer, imeBuffer, &prosjekBuffer) != EOF)
        all[cnt++] = create_student(indeksBuffer, prezimeBuffer, imeBuffer, prosjekBuffer);

    all = (STUDENT *)realloc(all, cnt * sizeof(STUDENT));
    *n = cnt;

    return all;
}

void write(STUDENT *niz, int n, FILE *fp, void (*header)(FILE *), void (*footer)(FILE *))
{
    (*header)(fp);

    for (int i = 0; i < n; i++)
        fprintf(fp, "%7s %-16s %-16s %-7.1lf\n", niz[i].indeks, niz[i].prezime, niz[i].ime, niz[i].prosjek);

    (*footer)(fp);
}

void header(FILE *fp)
{
    fprintf(fp, "======= ================ ================ ======= ===\n");
    fprintf(fp, "BR.IND. PREZIME          IME              PROSJEK POL\n");
    fprintf(fp, "======= ================ ================ ======= ===\n");
}

void footer(FILE *fp)
{
    fprintf(fp, "======= ================ ================ ======= ===\n");
}