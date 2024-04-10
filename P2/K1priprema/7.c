// Napisati funkciju formiraj sa promjenljivim brojem argumenata, koja prima naziv tekstualne datoteke dat,
// cijeli broj n i n pokazivača na funkcije koje primaju naziv tekstualne datoteke, a kreiraju i vraćaju
// (dinamički) string ili NULL, te kreira i vraća dinamički niz dinamičkih stringova, pri čemu je i-ti element
// niza rezultat poziva funkcije preko i-tog pokazivača na funkciju. Prototip funkcije je:
// char** formiraj(const char *dat, int n, ...);

// Napisati odgovarajuću funkciju najduza koja u tekstualnoj datoteci čiji je naziv zadat, pronalazi i vraća
// dinamički string koji predstavlja najdužu riječ. Ukoliko u datoteci nema riječi, funkcija treba da vrati prazan
// string. Ukoliko se desi greška pri otvaranju datoteke, funkcija treba da vrati NULL. U glavnom programu
// ilustrovati korištenje funkcije formiraj tako da se u tekstualnoj datoteci, čiji je naziv prvi argument komandne
// linije, pronađe i ispiše na standardni izlaz najduža riječ.
//
// Napomena: riječ je jedno ili više uzastopnih znakova, a od druge riječi je odvojena nekom bjelinom.
// Pretpostaviti da je maksimalna dužina riječi 100 znakova.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define MAX 101 // pretpostavljena maks. duzina + terminator

char **formiraj(const char *, int, ...);
char *najduza(const char *);
char *najkraca(const char *);
int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        char **niz = formiraj(argv[1], 2, &najduza, &najkraca);

        for (int i = 0; i < 2; i++)
            printf("S%d: %s\n", i + 1, niz[i]), free(niz[i]);
        free(niz);
    }
    else
        printf("Argumenti nisu pravilno navedeni.");

    return 0;
}

char **formiraj(const char *dat, int n, ...)
{
    char **ret = (char **)malloc(n * sizeof(char *));

    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++)
    {
        char *(*f)(const char *) = va_arg(args, void *);
        ret[i] = (*f)(dat);
    }
    va_end(args);
    return ret;
}

char *najduza(const char *dat)
{
    FILE *fp;
    int maxlen = 0;
    char buffer[MAX], maxbuffer[MAX], *ret;
    if (fp = fopen(dat, "r"))
    {
        while (fscanf(fp, "%s", buffer) != EOF)
            if (strlen(buffer) > maxlen)
            {
                maxlen = strlen(buffer);
                strcpy(maxbuffer, buffer);
            }
        fclose(fp);
    }
    else
    {
        printf("Datoteka '%s' se ne moze otvoriti.\n", dat);
        return NULL;
    }

    ret = (char *)calloc(maxlen + 1, sizeof(char));
    strcpy(ret, maxbuffer);

    return ret;
}

char *najkraca(const char *dat)
{
    FILE *fp;
    int minlen = MAX;
    char buffer[MAX], minbuffer[MAX], *ret;
    if (fp = fopen(dat, "r"))
    {
        while (fscanf(fp, "%s", buffer) != EOF)
            if (strlen(buffer) < minlen)
            {
                minlen = strlen(buffer);
                strcpy(minbuffer, buffer);
            }
        fclose(fp);
    }
    else
    {
        printf("Datoteka '%s' se ne moze otvoriti.\n", dat);
        return NULL;
    }

    ret = (char *)calloc(minlen + 1, sizeof(char));
    strcpy(ret, minbuffer);

    return ret;
}