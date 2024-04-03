// Sortiranje niza cijelih brojeva unesenih u binarnu datoteku bez ucitavanja istih direktno u memoriju.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char filename[64];
    FILE *fp;

    printf("Unesi ime datoteke: ");
    gets(filename);

    if (fp = fopen(filename, "rb"))
    {
        }
    else
        printf("Datoteka '%s' ne moze da se otvori.", filename);
    return 0;
}