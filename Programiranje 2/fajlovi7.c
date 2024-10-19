// Napisati program koji u datoteci, čije se ime navodi kao argument komandne linije,
// pronalazi i ispisuje sve stringove koji su palindromi.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define BUFF 64

int jePalindrom(char *);

int main(int argc, char const *argv[])
{
    FILE *fp;
    int n = 0;

    if (argc == 2)
    {
        char filename[BUFF];
        strcpy(filename, argv[1]);

        char *buffer = (char *)calloc(BUFF, sizeof(char));
        char **palindromi = (char **)malloc(MAX * sizeof(char *));
        if (fp = fopen(filename, "r"))
        {
            while (fscanf(fp, "%s", buffer) != EOF && n < MAX)
                if (jePalindrom(buffer))
                    strcpy(palindromi[n++] = (char *)calloc(BUFF, sizeof(char)), buffer);

            palindromi = (char **)realloc(palindromi, n * sizeof(char *));

            printf("Lista palindroma iz '%s':\n", filename);
            for (int i = 0; i < n; i++)
            {
                printf("%s ", palindromi[i]);
                free(palindromi[i]);
            }

            free(palindromi);
            free(buffer);
            fclose(fp);
        }
        else
            printf("Greska pri otvaranju datoteke '%s'.", filename);
    }
    else
        printf("Argumenti nisu pravilno navedeni.");

    return 0;
}

int jePalindrom(char *str)
{
    int len = strlen(str);
    char *inverted = (char *)calloc(len + 1, sizeof(char));

    for (int i = 0; i < len; i++)
        inverted[i] = str[len - i - 1];

    int ret = !strcmp(str, inverted);
    free(inverted);

    return ret;
}