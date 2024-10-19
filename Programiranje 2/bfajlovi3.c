// Napisati program u kojem treba iz datoteke, čiji je naziv prvi argument komandne linije,
// pročitati (binarno upisane) podatke o nepoznatom broju artikala i formatirano ih ispisati
// na standardni izlaz. Atributi artikla su naziv, količina i cijena.

// ^ ovo je bukvalno inverz prethodnog zadatka iz 'bfajlovi2.c'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char naziv[32];
    double kolicina, cijena;
} ARTIKAL;
void pisi(ARTIKAL *);
void header();
void footer();

int main(int argc, char const *argv[])
{
    ARTIKAL artikal;
    FILE *fp;
    char filename[64];

    int ind = 1;

    if (argc == 2)
    {
        strcpy(filename, argv[1]);
        header();
        if (fp = (fopen(filename, "rb")))
            while (fread(&artikal, sizeof(ARTIKAL), 1, fp))
                printf("%02d. ", ind++), pisi(&artikal), printf("\n");
        footer();
        fclose(fp);
    }
    else
        printf("Argumenti nisu pravilno navedeni.");

    return 0;
}

void header()
{
    printf("=== ================ ========= ======\n");
    // printf("BR. NAZIV     KOLICINA         CIJENA");
    printf("%-3s %-16s %-9s %-6s", "BR.", "NAZIV", "KOLICINA", "CIJENA\n");
    printf("=== ================ ========= ======\n");
}

void footer()
{
    printf("=== ================ ========= ======\n");
}

void pisi(ARTIKAL *a)
{
    printf("%-16s %-9.1lf %-6.1lf", a->naziv, a->kolicina, a->cijena);
}