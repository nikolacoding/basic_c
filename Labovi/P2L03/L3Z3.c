#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF 1024

void spoji_saberi(int, char *[], char *(*)(char *, char *),
                  int (*)(int, int));
char *dodaj(char *, char *);
int saberi(int a, int b) { return a + b; }

int main(int argc, char *argv[])
{
    if (argc >= 2)
        spoji_saberi(argc, argv, &dodaj, &saberi);
    else
        printf("Argumenti nisu pravilno zadani.");

    return 0;
}

void spoji_saberi(int argc, char *argv[], char *(*dodaj)(char *, char *),
                  int (*saberi)(int, int))
{
    int sum = 0;
    int summed = 0; // provjera da li je radjeno sa sumom uopste kako bi se po potrebi ispisivalo i '0'
    char *str = (char *)calloc(BUFF, sizeof(char));

    enum modes
    {
        STR = 0,
        SUM = 1
    };

    int mode;
    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-s"))
            mode = STR;
        else if (!strcmp(argv[i], "-b"))
            mode = SUM;
        else
        {
            if (mode == STR)
                (*dodaj)(str, argv[i]);
            else if (mode == SUM)
            {
                sum = (*saberi)(sum, atoi(argv[i]));
                summed = 1;
            }
        }
    }

    if (strlen(str))
        printf("String je '%s'. ", str);
    if (summed)
        printf("Suma brojeva je %d.", sum);

    free(str);
}

char *dodaj(char *strmain, char *str)
{
    int cnt = 0;
    int ind = strlen(strmain);

    while (str[cnt])
        strmain[ind++] = str[cnt++];

    return strmain;
}