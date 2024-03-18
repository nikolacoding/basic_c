#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char *, char *);

int main(int argc, char const *argv[])
{
    char str1[6] = "Banja";
    char str2[5] = "luka";

    char *str;
    strcpy(str, concat(str1, str2));

    printf("Concatenated string: %s\n", str);
    printf("strlen(str) -> %d\n", strlen(str));

    free(str);

    return 0;
}

char *concat(char *s1, char *s2)
{
    int retlen = strlen(s1) + strlen(s2) + 1;
    char *ret = (char *)calloc(retlen, sizeof(char));

    int k = 0;
    for (int i = 0, j = 0; k < retlen - 1; k++)
        ret[k] = (s1[i] ? s1[i++] : (s2[j] ? s2[j++] : '0'));

    // ja se izvinjavam na ovom ^, moze se napisati sa dva kratka 'if' bloka

    return ret;
}