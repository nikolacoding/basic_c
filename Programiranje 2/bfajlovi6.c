// Napisati program u kojem treba sa standardnog ulaza učitati podatke za n studenata i
// formirati odgovarajući dinamički niz, a potom učitani niz podataka o studentima upisati
// u binarnom obliku u datoteku čiji je naziv prvi argument komandne linije. Podaci koji se
// vode o studentu su: broj indeksa, prezime, ime i prosječna ocjena.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char broj_indeksa[8], prezime[64], ime[64];
    double prosjek;
} STUDENT;

STUDENT ucitaj();

int main(int argc, char const *argv[])
{
    int n;
    char filename[64];
    FILE *fp;
    STUDENT *studenti;

    if (argc == 2)
    {
        strcpy(filename, argv[1]);
        if (fp = fopen(filename, "wb"))
        {
            do
            {
                printf("Unesi broj studenata: ");
                scanf("%d", &n);
            } while (n < 1);

            studenti = (STUDENT *)malloc(n * sizeof(STUDENT));
            for (int i = 0; i < n; i++)
                printf("Podaci o %d. studentu:\n", i + 1), studenti[i] = ucitaj();

            fwrite(studenti, sizeof(STUDENT), n, fp);

            fclose(fp);
            free(studenti);
        }
        else
            printf("Neuspjesno otvaranje datoteke '%s'.", filename);
    }
    else
        printf("Argumenti nisu pravilno navedeni.");

    return 0;
}

STUDENT ucitaj()
{
    STUDENT ret;

    printf("Broj indeksa: ");
    scanf("%s", ret.broj_indeksa);

    printf("Ime: ");
    scanf("%s", ret.ime);

    printf("Prezime: ");
    scanf("%s", ret.prezime);

    printf("Prosjecna ocjena: ");
    scanf("%lf", &ret.prosjek);

    return ret;
}