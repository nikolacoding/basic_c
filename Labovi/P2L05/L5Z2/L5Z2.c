// Napisati program kojim se vrši šifrovanje unesenog teksta korištenjem Cezarove šifre. Koristiti engleski
// alfabet. Cezarovom šifrom se vrši zamjena svakog slova otvorenog teksta sa slovom koje je pomjereno
// za određeni broj mjesta. Koristiti Cezarovu šifru sa desnim pomjerajem od tri mjesta:
// -> Otvoreno: ABCDEFGHIJKLMNOPQRSTUVWXYZ
// -> Šifra: DEFGHIJKLMNOPQRSTUVWXYZABC
// Napomena: uzeti u obzir i mala i velika slova.
//
// Nakon pokretanja programa bira se jedna od sljedeće dvije opcije:
// 1) unos novog teksta,
// 2) prikaz šifrovanog teksta koji se učitava iz binarne datoteke na standardnom izlazu.
//
// - Unos novih podataka:
// Nakon unosa proizvoljnog teksta isti se šifruje i snima u binarnu datoteku koja se prosljeđuje kao prvi
// argument komandne linije.
//
// - Čitanje podataka:
// Podaci se čitaju iz datoteke čiji se naziv unosi putem standardnog ulaza ili iz datoteke koja se
// prosljeđuje kao prvi argument komandne linije ukoliko se za naziv datoteke navede znak „#“

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF 64
#define POMJERAJ 3

int validno(char *);
int velSlova(char);
char *cezaruj(char *, int);

int main(int argc, char const *argv[])
{
    char *filename = (char *)calloc(BUFF, sizeof(char));
    char *cezar, choice[64];

    FILE *fp;
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
            char *sifra = (char *)calloc(BUFF, sizeof(char));
            do
                printf("Unesi sifru: "), scanf("%s", sifra);
            while (!validno(sifra));
            cezar = cezaruj(sifra, POMJERAJ);

            fwrite(cezar, sizeof(char), strlen(sifra), fp);
            printf("Uneseno.");

            free(sifra), free(cezar);
            fclose(fp);
        }
        else
            printf("Neuspjesno otvaranje datoteke '%s'.", filename);
    }
    else if (mode == PRIKAZ)
    {
        cezar = (char *)calloc(BUFF, sizeof(char));
        if (fp = fopen(filename, "rb"))
        {
            int p;
            char b;
            do
            {
                p = fread(&b, sizeof(char), 1, fp);
                if (p)
                    cezar[n++] = b;
            } while (p);

            cezar = (char *)realloc(cezar, BUFF * sizeof(char));
            printf("Sifra u datoteci '%s': %s\n", filename, cezar);

            free(cezar);
            fclose(fp);
        }
        else
            printf("Neuspjesno otvaranje datoteke '%s'.", filename);
    }

    free(filename);
    return 0;
}

int validno(char *sifra)
{
    int i = 0;
    char c = sifra[i];
    for (; i < strlen(sifra) + 1; c = sifra[i++])
        if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
            return 0;
    return 1;
}

int velSlova(char c)
{
    if (c >= 'a' && c <= 'z')
        return -1;
    else if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

char *cezaruj(char *sifra, int p)
{
    char *ret = (char *)calloc(strlen(sifra), sizeof(char));
    char c = sifra[0];

    enum velicina_slova
    {
        MALO = -1,
        VELIKO = 1
    };

    int diff = 0;
    for (int i = 0; i < strlen(sifra); c = sifra[++i])
    {
        if ((c + p > 'Z' && velSlova(c + p) != MALO) || (c + p > 'z' && velSlova(c + p) != VELIKO))
        {
            if (velSlova(c) == VELIKO)
            {
                diff = c + p - 'Z';
                ret[i] = 'A' - 1 + diff;
            }
            else if (velSlova(c) == MALO)
            {
                diff = c + p - 'z';
                ret[i] = 'a' - 1 + diff;
            }
        }
        else
            ret[i] = c + p;
    }

    return ret;
}