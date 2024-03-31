#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fin, *fout;
    char filename_in[64], filename_out[64];

    if (argc == 3)
    {
        strcpy(filename_in, argv[1]);
        strcpy(filename_out, argv[2]);
        if (fin = (fopen(filename_in, "rb")))
        {
            if (fout = (fopen(filename_out, "wb")))
            {
                int c;
                while ((c = fgetc(fin)) != EOF)
                    fputc(c, fout);
                fclose(fout);
            }
        }
        else
            printf("Greska pri ucitavanju ulazne datoteke");
        fclose(fin);
    }
    else
        printf("Argumenti nisu pravilno uneseni.");
    return 0;
}