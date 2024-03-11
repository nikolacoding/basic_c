#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF 1024

char *transformisi(char *rijec, char *(*f)(char *)) { return (*f)(rijec); };
char *invertuj(char *);
char *skrati(char *);
char *produzi(char *);

int main(int argc, char const *argv[])
{
    char choice;
    char **rez = (char **)malloc(argc * sizeof(char *));
    for (int i = 1; i < argc; i++)
    {
        do
        {
            printf("Sta uraditi sa parametrom '%s': ", argv[i]);
            scanf("%c", &choice);
        } while (choice != 'i' && choice != 's' && choice != 'p');

        rez[i - 1] = (char *)malloc(BUFF * sizeof(char));

        if (choice == 'i')
            rez[i - 1] = transformisi(argv[i], &invertuj);
        else if (choice == 's')
            rez[i - 1] = transformisi(argv[i], &skrati);
        else if (choice == 'p')
            rez[i - 1] = transformisi(argv[i], &produzi);
        choice = ' ';
    }

    printf("\nTransformisani argumenti: ");
    for (int i = 1; i < argc; i++)
    {
        printf("\nargv[%d] ==> %s -> %s", i, argv[i], rez[i - 1]);
        free(rez[i - 1]);
    }

    free(rez);
    rez = NULL;

    return 0;
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
        printf("Skrati za koliko: ");
        scanf("%d", &s);
    } while (s < 1 || s >= len);

    int newlen = len - s;
    char *ret = (char *)calloc(newlen + 1, sizeof(char));

    for (int i = 0; i < newlen; i++)
        ret[i] = rijec[i];

    return ret;
}

char *produzi(char *rijec)
{
    int len = strlen(rijec);
    const int maxlen = 100;
    char *prod = (char *)calloc(maxlen - len + 1, sizeof(char));
    int s;

    do
    {
        printf("Produzi za koliko: ");
        scanf("%d", &s);
    } while (s < 1 || s >= maxlen - len);

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