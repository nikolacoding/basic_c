#include "funkcije.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **transformisi(char **niz, int n, char *(*f)(char *))
{
    char **ret = (char **)calloc(n, sizeof(char *));

    for (int i = 1; i < n; i++)
        ret[i] = (*f)(niz[i]);

    return ret;
}

char *invertuj(char *rijec)
{
    int len = strlen(rijec);
    char *ret = (char *)calloc(len + 1, sizeof(char));

    for (int i = 0; i < len; i++)
        ret[len - 1 - i] = rijec[i];

    return ret;
}

char *skrati(char *rijec)
{
    int len = strlen(rijec);
    int s;

    do
    {
        printf("Skrati '%s' za koliko: ", rijec);
        scanf("%d", &s);
    } while (s < 0 || s >= len);

    if (s)
    {
        int newlen = len - s;
        char *ret = (char *)calloc(newlen + 1, sizeof(char));

        for (int i = 0; i < newlen; i++)
            ret[i] = rijec[i];

        return ret;
    }
    else // ako se ne skracuje
    {
        char *ret = (char *)calloc(len + 1, sizeof(char));
        strcpy(ret, rijec);

        return ret;
    }
}

char *produzi(char *rijec)
{
    int len = strlen(rijec);
    const int maxlen = 100;
    char *prod = (char *)calloc(maxlen - len + 1, sizeof(char));
    int s;

    do
    {
        printf("Produzi '%s' za koliko: ", rijec);
        scanf("%d", &s);
    } while (s < 0 || s >= maxlen - len);

    if (s)
    {
        do
        {
            printf("Unesi produzetak: ");
            scanf("%s", prod);
        } while (strlen(prod) < 1 || strlen(prod) > s);

        int newlen = len + s;
        char *ret = (char *)calloc(newlen + 1, sizeof(char));
        strcpy(ret, rijec);

        for (int i = len, k = 0; i < newlen; i++, k++)
            ret[i] = prod[k];

        free(prod);
        return ret;
    }
    else // ako se ne produzava
    {
        char *ret = (char *)calloc(len + 1, sizeof(char));
        strcpy(ret, rijec);

        return ret;
    }
}
