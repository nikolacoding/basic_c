// Napisati program koji iz formatiranih datoteka 'studenti_m.dat' i 'studenti_z.dat' spaja muske i zenske
// studente u zajednicku datoteku 'studenti_svi.dat'. Format tabele u koju se upisuju studenti u zajednicku
// datoteku je nalik na format u pojedinim datotekama, samo sto se jos dodaje i kolona za pol ("M"/"Z").
// U glavnu funkciju se pravi dinamicki niz studenata ciji je tip struktura STUDENT koja sadrzi sve podatke
// o jednom studentu. Dati niz uzima povratnu vrijednost funkcije '*get_all_students(FILE *, FILE *, int *)'
// koja uzima muske i zenske fajlove i adresu promjenljive n preko koje vraca ukupan broj studenata iz
// dva fajla. Studenti iz niza se zatim sortiraju funkcijom 'sort(STUDENT *, int)' i na kraju se u zajednicku
// datoteku funkcijom 'write(STUDENT *, int, FILE *, void (*header)(FILE *), void (*footer)(FILE *))' ispisuju
// u prethodno pomenutom formatu, uz jos 4 parametra izvan tabele: prosjek muskih studenata, najbolji muski
// student, prosjek zenskih studenata, najbolji zenski prosjek student. Za najbolje studente se ispisuje ime,
// prezime i prosjek.
//
// Pomocne funkcije koje se trebaju koristiti u sklopu glavne tri:
// 'header(FILE *)' - upis vrha/headera tabele u datoteku
// 'footer(FILE *)' - upis dna/footera tabele u datoteku
// 'skiplines(FILE *, int)' - pomjeranje pokazivaca datoteke n redova nadole (preskakanje redova)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF 128
#define MAX 100

typedef struct
{
    char indeks[16], ime[24], prezime[24], pol[2];
    double prosjek;
} STUDENT;

// Glavne funkcije:
STUDENT *get_all_students(FILE *, FILE *, int *);
void sort(STUDENT *, int);
void write(STUDENT *, int, FILE *, void (*header)(FILE *), void (*footer)(FILE *));

// Pomocne funkcije:
STUDENT create_student(char *, char *, char *, double, char *);
void header(FILE *);
void footer(FILE *);
void skiplines(FILE *, int);

static int toSkip = 3; // broj linija za preskociti

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
            sort(studenti, n);
            write(studenti, n, fs, &header, &footer);

            free(studenti);
            fclose(fm);
            fclose(fz);
            fclose(fs);
        }
        else
            printf("Greska pri otvaranju datoteka.");
    }
    else
        printf("Argumenti nisu pravilno navedeni.");

    return 0;
}

STUDENT create_student(char *indeks, char *prezime, char *ime, double prosjek, char *pol)
{
    STUDENT ret;
    strcpy(ret.indeks, indeks);
    strcpy(ret.prezime, prezime);
    strcpy(ret.ime, ime);
    strcpy(ret.pol, pol);
    ret.prosjek = prosjek;

    return ret;
}

STUDENT *get_all_students(FILE *f1, FILE *f2, int *n)
{
    char imeBuffer[BUFF], prezimeBuffer[BUFF], indeksBuffer[BUFF], polBuffer[BUFF];
    char skipBuffer[BUFF];
    double prosjekBuffer;

    int cnt = 0;

    skiplines(f1, toSkip);
    skiplines(f2, toSkip);

    STUDENT *all = (STUDENT *)malloc(MAX * sizeof(STUDENT));

    while (fscanf(f1, "%s %s %s %lf", indeksBuffer,
                  prezimeBuffer,
                  imeBuffer,
                  &prosjekBuffer) != EOF &&
           fgetc(f1) != '=')
        all[cnt++] = create_student(indeksBuffer, prezimeBuffer, imeBuffer, prosjekBuffer, "M");

    while (fscanf(f2, "%s %s %s %lf", indeksBuffer,
                  prezimeBuffer,
                  imeBuffer,
                  &prosjekBuffer) != EOF &&
           fgetc(f2) != '=')
        all[cnt++] = create_student(indeksBuffer, prezimeBuffer, imeBuffer, prosjekBuffer, "Z");

    all = (STUDENT *)realloc(all, cnt * sizeof(STUDENT));
    *n = cnt;

    return all;
}

void skiplines(FILE *fp, int n)
{
    char skipBuffer[1024];
    for (int i = 0; i < n; i++)
        fgets(skipBuffer, BUFF, fp);
}

void write(STUDENT *niz, int n, FILE *fp, void (*header)(FILE *), void (*footer)(FILE *))
{
    enum pol_indeksi
    {
        M = 0,
        Z = 1
    };

    // M, Z
    int total[2] = {0, 0};
    double prosjeci[2] = {0, 0};
    STUDENT *top = (STUDENT *)malloc(2 * sizeof(STUDENT));

    (*header)(fp);

    for (int i = 0; i < n; i++)
    {
        STUDENT current = niz[i];

        fprintf(fp, "%7s %-16s %-16s %-7.2lf %3s\n",
                current.indeks,
                current.prezime,
                current.ime,
                current.prosjek,
                current.pol);

        if (!strcmp(current.pol, "M"))
        {
            prosjeci[M] += current.prosjek;
            total[M]++;

            if (current.prosjek > top[M].prosjek)
                top[M] = current;
        }
        else
        {
            prosjeci[Z] += current.prosjek;
            total[Z]++;

            if (current.prosjek > top[Z].prosjek)
                top[Z] = current;
        }
    }

    (*footer)(fp);

    fprintf(fp, "Muski prosjek: %.2lf\n", prosjeci[M] / total[M]);
    fprintf(fp, "Najbolji muski student: %s %s (%.2lf)\n", top[M].ime, top[M].prezime, top[M].prosjek);

    fprintf(fp, "Zenski prosjek: %.2lf\n", prosjeci[Z] / total[Z]);
    fprintf(fp, "Najbolji zenski student: %s %s (%.2lf)\n", top[Z].ime, top[Z].prezime, top[Z].prosjek);

    free(top);
}

void sort(STUDENT *niz, int n)
{
    STUDENT temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (niz[i].prosjek < niz[j].prosjek)
            {
                temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
}

void header(FILE *fp)
{
    fprintf(fp, "======= ================ ================ ======= ===\n");
    fprintf(fp, "BR.IND. PREZIME          IME              PROSJEK POL\n");
    fprintf(fp, "======= ================ ================ ======= ===\n");
}

void footer(FILE *fp)
{
    fprintf(fp, "======= ================ ================ ======= ===\n\n");
}