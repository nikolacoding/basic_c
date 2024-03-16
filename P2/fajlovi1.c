#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    char f_ime[64], f_mode[4];
    int delete = 0;

    printf("Ime datoteke: ");
    scanf("%s", f_ime);
    printf("Rezim rada: ");
    scanf("%s", f_mode);

    if ((fp = fopen(f_ime, f_mode)) != NULL)
    {
        printf("Datoteka uspjesno otvorena!\n");
        fclose(fp);
        printf("Datoteka zatvorena.\n");
    }
    else
        printf("Greska pri otvaranju.\n");

    if (fp)
    {
        printf("Obrisati? ");
        scanf("%d", &delete);
    }

    if (delete)
    {
        remove(f_ime);
        printf("Obrisana.\n");
    }
    return 0;
}
