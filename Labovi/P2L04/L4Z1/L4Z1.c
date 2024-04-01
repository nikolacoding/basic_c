// Napisati program koji iz datoteke čiji je naziv prvi argument komandne linije, čita riječi i upisuje ih
// (svaku riječ u zasebnom redu) u datoteku čiji je naziv drugi argument komandne linije. Pored toga,
// program treba da na standardni izlaz ispiše najdužu riječ. Riječ je jedno ili više uzastopnih slova od
// drugih riječi odvojena znakom koje nije slovo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF 1024

int jeRijec(char *);

int main(int argc, char const *argv[])
{
    char fin_name[64], fout_name[64];
    FILE *fin, *fout;

    if (argc == 3)
    {
        strcpy(fin_name, argv[1]);
        strcpy(fout_name, argv[2]);
        char *buffer = (char *)calloc(BUFF, sizeof(char));

        int max = 0;
        char str_max[BUFF];

        if (fin = fopen(fin_name, "r"))
        {
            if (fout = fopen(fout_name, "w"))
            {
                while (fscanf(fin, "%s", buffer) != EOF)
                {
                    if (jeRijec(buffer))
                    {
                        fprintf(fout, "%s\n", buffer);
                        if (strlen(buffer) > max)
                            max = strlen(buffer), strcpy(str_max, buffer);
                    }
                }
                printf("Najduza rijec: %s\n", str_max);
                fclose(fin), fclose(fout);
                free(buffer);
            }
            else
                printf("Greska pri otvaranju datoteke '%s'.", fout_name);
        }
        else
            printf("Greska pri otvaranju datoteke '%s'.", fin_name);
    }
    else
        printf("Argumenti nisu pravilno navedeni.");

    return 0;
}

int jeRijec(char *rijec)
{
    int i = 0;
    char c = rijec[i];
    for (; i < strlen(rijec); c = rijec[i++])
        if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
            return 0;
    return 1;
}