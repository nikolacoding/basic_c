// Napisati funkciju konkatenacija koja prima promjenljiv broj stringova, te ih spaja (konkatenuje) i vraca
// rezultantni (spojeni) string
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char *konkatenacija(int n, ...)
{
    char *rezultat = "", *next;

    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++)
    {
        int j, k;

        next = va_arg(args, char *);
        int len = strlen(rezultat) + strlen(next) + 1;
        char *temp = (char *)malloc(len);

        for (j = 0; rezultat[j]; j++)
            temp[j] = rezultat[j];
        for (k = 0; temp[j + k] = next[k]; k++)
            ;

        if (i)
            free(rezultat);
        rezultat = temp;
    }

    va_end(args);
    return rezultat;
}

int main(int argc, char const *argv[])
{
    char *str = konkatenacija(3, "Ja ", "sam ", "kralj.");
    printf("%s", str);

    return 0;
}
