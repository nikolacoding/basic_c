// Napisati program koji broji riječi u datoteci i pronalazi i ispisuje najdužu riječ i broj slova u njoj.
// Ukoliko postoji vise najduzih rijeci, ispisati ih sve, kao i ukupan broj rijeci.
// Naziv datoteke se navodi kao argument komandne linije (pretpostaviti da će argumenti biti pravilno navedeni).

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFF 128

int main(int argc, char const *argv[])
{
    FILE *fp;

    char read[BUFF];
    char max[BUFF][BUFF];

    int maxlen;
    int count = 0;
    int times = 1;

    if (argc != 2)
        printf("Argumenti nisu pravilno navedeni.");
    else
    {
        if ((fp = fopen(argv[1], "r")) != NULL)
        {
            printf("Lista rijeci u datoteci:\n");
            while (fscanf(fp, "%s", read) != EOF)
            {
                printf("%s\n", read);
                if (strlen(read) > strlen(max[times - 1]))
                {
                    strcpy(max[times - 1], read);
                    maxlen = strlen(max[times - 1]);
                    times = 1;
                }
                else if (strlen(read) == strlen(max[times - 1]))
                {
                    times++;
                    strcpy(max[times - 1], read);
                }

                count++;
            }

            printf("Najduza rijec: ");
            if (times > 1)
            {
                for (int i = 0; i < times; i++)
                    printf("%s ", max[i]);

                printf("[%d slova]\n", maxlen);
            }
            else
                printf("%s [%d slova]\n", max[0], maxlen);

            printf("Ukupno rijeci: %d\n", count);
            fclose(fp);
        }
        else
            printf("Datoteka '%s' nije pronadjena.", argv[1]);
    }

    return 0;
}

// odvratno ali radi