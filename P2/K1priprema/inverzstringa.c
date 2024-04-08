// Napisati rekurzivnu funkciju invert koja kao parametre prima niz stringova (parametar niz) i
// cijeli broj n koji predstavlja broj stringova u nizu. Funkcija invert invertuje svaki string u nizu i vraća na
// istu poziciju u niz. Invertovani string ne smije da sadržic ifre. Obradu svakog stringa potrebno je vršiti u
// odvojenom rekurzivnom pozivu. Prototip funkcije invert je: void invert(char **niz, int n);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invert(char **, int);

int main(int argc, char const *argv[])
{
    char string[] = "Jabuka";
    char **stringovi;
    const int n = 6;

    stringovi = (char **)calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++)
        stringovi[i] = (char *)calloc(16, sizeof(char));

    strcpy(stringovi[0], "Macka");
    strcpy(stringovi[1], "Pas");
    strcpy(stringovi[2], "Kornjaca");
    strcpy(stringovi[3], "Zirafa");
    strcpy(stringovi[4], "Krokodil");
    strcpy(stringovi[5], "Antilopa");

    invert_string(string);

    printf("%s\n", string);
    return 0;

    invert(stringovi, n);
    for (int i = 0; i < n; i++)
        printf("%s\n", stringovi[i]);
    return 0;
}

void invert(char **niz, int n)
{
    char *temp = (char *)calloc(100, sizeof(char));
    int len = strlen(niz[n - 1]);
    strcpy(temp, niz[n - 1]);

    for (int i = 0; i < len; i++)
    {
        char swap = temp[len - 1 - i];
        niz[n - 1][i] = swap;
    }

    free(temp);

    if (n > 1)
        invert(niz, n - 1);
}

void invert_string(char *string)
{
    char temp;
    int duz = strlen(string) - 1;
    if (string == '\0')
    {
        return;
    }

    char kraj = string;
    do
    {
        kraj++;
    } while (kraj != '\0');

    temp = *string;
    string = kraj;
    *(string + duz) = temp;

    if (*string - duz != kraj)
    {
        invert_string(string - duz);
    }
}