#include <stdio.h>
#include <stdlib.h>
#define BUFFER 1024

int main(int argc, char const *argv[])
{
    FILE *fp;
    char f_ime[64], f_mode[2];
    char *f_content = (char *)calloc(BUFFER, sizeof(char));

    printf("Unesi ime datoteke: ");
    gets(f_ime);

    printf("Unesi rezim rada: ");
    gets(f_mode);

    const char mode = f_mode[0];

    if (fp = fopen(f_ime, f_mode))
    {
        printf("Datoteka '%s' uspjesno otvorena.\n", f_ime);

        if (mode == 'w' || mode == 'a')
        {
            char iterations[16];
            int iterations_n;

            printf("Unesi broj upisa: ");
            gets(iterations);
            iterations_n = atoi(iterations);

            for (int i = 0; i < iterations_n; i++)
            {
                printf("Unesi sadrzaj datoteke (%d/%d): ", i + 1, iterations_n);
                gets(f_content);
                fprintf(fp, "%s\n", f_content);
            }

            fclose(fp);
            printf("Upisano i zatvoreno.");
        }
        else if (mode == 'r')
        {
            char procitano[BUFFER];
            printf("Procitano iz fajla:\n");
            while (fgets(procitano, 128, fp))
                printf("%s", procitano);

            fclose(fp);
        }
    }
    else
        printf("Greska pri otvaranju. ");

    free(f_content);
    return 0;
}
