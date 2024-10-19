// copy binary file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char fin_name[64], fout_name[64];
    FILE *fin, *fout;

    if (argc == 3)
    {
        strcpy(fin_name, argv[1]);
        strcpy(fout_name, argv[2]);
        unsigned char buffer[8192];
        int p;

        if (fin = fopen(fin_name, "rb"))
        {
            if (fout = fopen(fout_name, "wb"))
            {
                do
                {
                    p = fread(buffer, 1, sizeof(buffer), fin);
                    if (p)
                        fwrite(buffer, 1, sizeof(buffer), fout);
                } while (p);
            }

            fclose(fout);
            fclose(fin);
        }
        else
            printf("Datoteka '%s' nije otvorena.", fin_name);
    }
    else
        printf("Argumenti nisu pravilno navedeni.");
    return 0;
}