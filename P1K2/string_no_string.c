#include <stdio.h>
#include <stdlib.h>
#define strbuff 64

int len(char *);
char *podstr(char *s, int p, int d);
int startstr(char *, const char *);

int main()
{
    char string1[strbuff];
    char string2[strbuff];

    printf("Unesi string 1: ");
    scanf("%s", &string1);

    printf("Unesi string 2: ");
    scanf("%s", &string2);

    char *podStrStr = podstr(string1, 3, 4);
    printf("Duzina stringa %s je %d.\n", string1, len(string1));
    printf("Podstring: %s\n", podStrStr);
    printf("Da li %s pocinje sa %s - %s\n\n", string1, string2, startstr(string1, string2) ? "Da." : "Ne.");

    char compstring[strbuff];
    char string3[23] = "Banja Luka, 16.1.2024.";
    char string4[11] = "Banja Luka";

    printf("Unesi string za poredjenje: ");
    scanf("%s", &compstring);

    printf("Da li %s pocinje sa %s - %s\n\n", string4, compstring, startstr(string4, compstring) ? "Da." : "Ne.");

    free(podStrStr);
    podStrStr = NULL;
    return 0;
}

int len(char *str)
{
    int cnt = 0;
    char *strcopy = str;

    while (strcopy[cnt])
        cnt++;

    return cnt;
}

char *podstr(char *s, int p, int d)
{
    // redundantno je zbog len() ali len nisam imao na kolokvijumu pa pisem ovako

    int lenS = 0;
    while (s[lenS])
        lenS++;

    if (p > len(s) || p < 0 || d < 1 || p + d > len(s))
        return NULL;

    char *retStr = (char *)calloc(lenS, sizeof(char));
    int retStrIndex = 0;

    for (int i = p - 1; i < p + d - 1; i++)
    {
        retStr[retStrIndex++] = s[i];
    }

    return retStr;
}

int startstr(char *s, const char *t)
{
    int lenS = 0;
    int lenT = 0;

    while (s[lenS++])
        ;
    while (t[lenT++])
        ;

    if (lenT > lenS)
        return 0;

    for (int i = 0; i < lenT - 1; i++)
    {
        if (s[i] != t[i])
            return 0;
    }

    return 1;
}