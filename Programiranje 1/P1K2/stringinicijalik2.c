#include <stdio.h>
#include <stdlib.h>

typedef struct OSOBA
{
    char *ime;
    char *prezime;
} OSOBA;

char *inic(OSOBA *o)
{
    char *str = (char *)malloc(5 * sizeof(char));

    str[0] = o->ime[0];
    str[1] = '.';
    str[2] = o->prezime[0];
    str[3] = '.';
    str[4] = '\0';

    return str;
}

int main()
{
    OSOBA nikola;
    nikola.ime = "Nikola";
    nikola.prezime = "Markovic";
    char *inicijali = inic(&nikola);

    printf("%s", inicijali);

    return 0;
}