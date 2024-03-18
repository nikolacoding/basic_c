// Program ucitava broj rijeci, te ih unosi u dinamicki niz, pa iz njega u tekstualnu datoteku i na kraju
// iz te datoteke iscitava svaku rijec i ispisuje na standardni izlaz. Svaka rijec mora biti odvojena
// od naredne sa '/n' koje se datoj rijeci dodaje uz pomoc odvojene funkcije *concat(char *, char *).
// Funkcija za konkatenaciju mora da radi sa bilo kojom kombinacijom dva stringa, dakle ne smije biti
// namijenjena iskljucivo za dodavanje '\n', iako ce se za to koristiti u datom programu.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFF 128

char *concat(char *, char *);

int main(int argc, char const *argv[])
{
    FILE *fp;

    char choice[8];
    char **rijeci;

    printf("Unesi broj rijeci: ");
    gets(choice);
    const int n = atoi(choice);

    rijeci = (char **)calloc(n, sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        char raw[BUFF];
        rijeci[i] = (char *)calloc(BUFF, sizeof(char));

        printf("Unesi rijec (%d/%d): ", i + 1, n);
        gets(raw);
        strcpy(rijeci[i], concat(raw, "\n"));
    }

    if ((fp = fopen("f3.txt", "w")) != NULL)
    {
        for (int i = 0; i < sizeof(rijeci) * n / sizeof(rijeci[0]); i++)
        {
            fputs(rijeci[i], fp);
            free(rijeci[i]);
        }

        fclose(fp);

        if ((fp = fopen("f3.txt", "r")) != NULL)
        {
            char str[BUFF];
            printf("Sadrzaj datoteke:\n");

            while (fgets(str, BUFF, fp) != NULL)
                printf("%s", str);
            fclose(fp);
        }
        else
            printf("Greska kod otvaranja datoteke za citanje.\n");
    }
    else
        printf("Greska kod otvaranja datoteke za pisanje.\n");

    free(rijeci);
    return 0;
}

char *concat(char *s1, char *s2)
{
    int retlen = strlen(s1) + strlen(s2) + 1;
    char *ret = (char *)calloc(retlen, sizeof(char));

    int k = 0;
    for (int i = 0, j = 0; k < retlen - 1; k++)
        ret[k] = (s1[i] ? s1[i++] : (s2[j] ? s2[j++] : '0'));

    return ret;
}