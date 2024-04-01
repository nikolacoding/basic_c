// Napisati program koji učitava prirodan broj n te podatke (šifra – string od pet znakova, naziv – string od
// najviše 20 znakova, i cijena – realan broj) o n artikala, a zatim učitane podatke upisuje u tekstualnu
// datoteku čiji je naziv prvi argument komandne linije. Podaci treba da budu upisani u formatiranom
// obliku kako je dato u primjeru.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF 128

typedef struct
{
    char sifra[6], naziv[21];
    double cijena;
} ARTIKAL;

ARTIKAL def_art(char *, char *, double);
void pisi(FILE *, ARTIKAL *, int);

int main(int argc, char const *argv[])
{
    char filename[BUFF];
    FILE *fp;

    int n;
    char sifra[BUFF], naziv[BUFF];
    double cijena;

    if (argc == 2)
    {
        strcpy(filename, argv[1]);

        if (fp = fopen(filename, "w"))
        {
            do
            {
                printf("Unesi broj artikala: ");
                scanf("%d", &n);
            } while (n < 1);

            ARTIKAL *artikli = (ARTIKAL *)malloc(n * sizeof(ARTIKAL));

            for (int i = 0; i < n; i++)
                do
                {
                    printf("%d. artikal:\n", i + 1), scanf("%s %s %lf", sifra, naziv, &cijena);
                    artikli[i] = def_art(sifra, naziv, cijena);
                } while (strlen(sifra) != 5 || strlen(naziv) > 20 || cijena < 0);

            pisi(fp, artikli, n);

            fclose(fp), free(artikli);
        }
        else
            printf("Neuspjesno otvaranje datoteke '%s'.", filename);
    }
    else
        printf("Argumenti nisu pravilno navedeni.");
    return 0;
}

ARTIKAL def_art(char *sifra, char *naziv, double cijena)
{
    ARTIKAL ret;

    strcpy(ret.sifra, sifra);
    strcpy(ret.naziv, naziv);
    ret.cijena = cijena;

    return ret;
}

void pisi(FILE *fp, ARTIKAL *niz, int n)
{
    ARTIKAL a;

    fprintf(fp, "=== ===== ==================== ======\n");
    fprintf(fp, "%3s %-5s %-20s %-6s\n",
            "RB.", "SIFRA", "NAZIV", "CIJENA");
    fprintf(fp, "=== ===== ==================== ======\n");
    for (int i = 0; i < n; i++)
        a = niz[i], fprintf(fp, "%-3d %-5s %-20s %-6.2lf\n", i + 1, a.sifra, a.naziv, a.cijena);
    fprintf(fp, "=== ===== ==================== ======\n");
}