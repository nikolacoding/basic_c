// U ulaznoj binarnoj datoteci upisani su podaci istog (nepoznatog) tipa. Napisati funkciju read sa promjenljivim
// brojem argumenata koja prihvata naziv ulazne binarne datoteke (name), velicinu (s) jednog podatka u datoteci,
// broj n te n pozicija (neobavezni argumenti). Funkcija read treba da ucita u dinamicku zonu memorije (tj. ucita
// i formira dinamicki niz) n podataka iz ulazne binarne datoteke koji se nalaze na zadatim pozicijama. Funkcija
// vraca adresu formiranog niza. Prototip funkcije je void *read(const char *name, int s, int n, ...);

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

void *read(const char *name, int s, int n, ...)
{
    FILE *fp;
    void *ret;

    if (fp = fopen(name, "rb"))
    {
        ret = (void *)malloc(n * s);
        va_list args;
        va_start(args, n);

        for (int i = 0; i < n; i++)
        {
            int adr = va_arg(args, int);
            fseek(fp, adr, SEEK_SET);
            fread(ret + i * s, s, 1, fp); // ovo ne kompajluje jbg
        }
    }

    return ret;
}