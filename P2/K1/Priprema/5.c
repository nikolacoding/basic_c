//  Napisati funkciju koja iz ulazne tekstualne datoteke učitava i vraća sve linije koje zadovoljavaju proizvoljan
//  uslov definisan drugim argumentom funkcije: char** linije(FILE *dat, int (*validiraj)(const char *));
//
//  Napisati funkciju procitaj koja prihvata prirodan broj n i n uređenih parova (2n argumenata), gdje
//  prvi element predstavlja datoteku iz koje se čita, dok drugi element predstavlja string koji ukazuje na
//  uslov koji treba proslijediti prilikom čitanja iz fajla. Ukoliko string ima vrijednost “recenica” potrebno
//  je provjeriti da li linija počinje sa velikim slovom, a završava sa tačkom. Za sve druge vrijednosti
//  stringa potrebno je vratiti sve linije iz fajla koje imaju manje od 100 karaktera.
//  Funkcija procitaj treba da vrati sve pročitane liinije iz svih fajlova koje zadovoljavaju svoje uslove.
//  Prototip funkcije procitaj: char* procitaj(int n, ...);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char **linije(FILE *dat, int (*validiraj)(const char *));
char *procitaj(int n, ...);

// pomocne funkcije:
int over50(const char *);

int main(int argc, char const *argv[])
{
    const char filename[] = "5.txt";
    const char filename2[] = "5_2.txt";
    const char validLines = 4; // u datoteci koja se ucitava ce biti 4 validne recenice

    char **valid;
    char *vararg = (char *)calloc(1024, sizeof(char));
    FILE *dat, *dat2;

    if (dat = fopen(filename, "r"))
    {
        valid = linije(dat, &over50);
        for (int i = 0; i < validLines; i++)
            printf("[%d] %s\n", i + 1, valid[i]), free(valid[i]);
        fclose(dat);
    }
    else
        printf("Datoteka '%s' se ne moze otvoriti.", filename);

    if (dat = fopen(filename, "r"))
    {
        if (dat2 = fopen(filename2, "r"))
            vararg = procitaj(2, dat, "blabla", dat2, "recenica");
        fclose(dat);
        fclose(dat2);
    }

    printf("%s\n", vararg);

    free(valid);
    free(vararg);
    return 0;
}

char *procitaj(int n, ...)
{
    int argn = n * 2, len;

    va_list args;
    va_start(args, n);

    char *string = (char *)calloc(64, sizeof(char));
    char buffer[1024];
    FILE *dat;

    char *ret = (char *)calloc(1024, sizeof(char));

    for (int i = 0; i < n; i++)
    {
        dat = va_arg(args, FILE *);
        strcpy(string, va_arg(args, char *));

        if (!(strcmp(string, "recenica")))
        {
            while (fgets(buffer, 1024, dat))
            {
                len = strlen(buffer);
                if (buffer[0] >= 'A' && buffer[0] <= 'Z' &&
                    (buffer[len - 1] == '.' || (buffer[len - 1] == '\n' && buffer[len - 2] == '.')))
                    strcat(ret, buffer);
            }
        }
        else
        {
            while (fgets(buffer, 1024, dat))
            {
                len = strlen(buffer);
                if (len < 50)
                    strcat(ret, buffer);
            }
        }
    }

    free(string);
    return ret;
}

char **linije(FILE *dat, int (*validiraj)(const char *))
{
    int n = 0, max = 100;
    char *buffer = (char *)calloc(1024, sizeof(char));
    char **ret = (char **)malloc(max * sizeof(char *));
    while (fgets(buffer, 1024, dat) && n < max)
    {
        if ((*validiraj)(buffer))
        {
            ret[n] = (char *)calloc(strlen(buffer) + 1, sizeof(char));
            strcpy(ret[n++], buffer);
        }
    }

    free(buffer);
    ret = (char **)realloc(ret, n * sizeof(char *));
    return ret;
}

int over50(const char *line)
{
    if (strlen(line) > 50)
        return 1;
    return 0;
}