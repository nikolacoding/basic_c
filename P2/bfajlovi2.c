// Napisati program u kojem treba sa standardnog ulaza učitati podatke za n artikala i
// formirati odgovarajući dinamički niz, a potom učitani niz podataka o artiklima
// upisati u binarnom obliku u datoteku čiji je naziv prvi argument komandne linije.
// Atributi artikla su naziv, količina i cijena.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char naziv[32];
    double kolicina, cijena;
} ARTIKAL;
void ucitaj(ARTIKAL *);

int main(int argc, char const *argv[])
{
    int n;
    char filename[64];
    ARTIKAL *artikli;
    FILE *fp;

    if (argc == 2)
    {
        strcpy(filename, argv[1]);

        do
        {
            printf("Unesi broj artikala: ");
            scanf("%d", &n);
        } while (n < 1);

        artikli = (ARTIKAL *)malloc(n * sizeof(ARTIKAL));

        for (int i = 0; i < n; i++)
            ucitaj(&artikli[i]);

        if (fp = fopen(filename, "wb"))
            fwrite(artikli, sizeof(ARTIKAL), n, fp);
        fclose(fp);
        free(artikli);

        return 0;
    }
    else
        printf("Argumenti nisu pravilno navedeni.");
}

void ucitaj(ARTIKAL *a)
{
    static int ind = 1;

    printf("Podaci o %d. artiklu:\n", ind++);

    printf("Naziv: ");
    scanf("%s", a->naziv);

    printf("Kolicina: ");
    scanf("%lf", &a->kolicina);

    printf("Cijena: ");
    scanf("%lf", &a->cijena);
}
