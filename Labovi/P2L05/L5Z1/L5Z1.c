// Napisati program koji omogućava unos podataka u imenik, kao i prikaz postojećih podataka iz imenika.
// Nakon pokretanja programa bira se jedna od sljedeće dvije opcije:
// 1) unos novih podataka,
// 2) prikaz postojećih podataka iz binarne datoteke na standardnom izlazu.
//
// - Unos novih podataka:
// Podaci se unose za proizvoljan broj osoba. Za svaku osobu se čuvaju sljedeći podaci: ime, prezime i
// broj telefona. Nakon unosa podataka o osobama vrši se snimanje podataka u binarnu datoteku koja se
// prosljeđuje kao prvi argument komandne linije. Podaci se unose u sljedećem formatu:
// >>> ime prezime broj_telefona
//
// - Čitanje podataka:
// Podaci se čitaju iz datoteke čiji se naziv unosi putem standardnog ulaza ili iz datoteke koja se
// prosljeđuje kao prvi argument komandne linije ukoliko se za naziv datoteke navede znak „#“.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF 64
#define MAX 100

typedef struct
{
    char ime[32], prezime[32], telefon[32];
} OSOBA;

void unesi(OSOBA *);
void pisi(OSOBA);

int main(int argc, char const *argv[])
{
    char *filename = (char *)calloc(BUFF, sizeof(char));
    char choice[64];

    FILE *fp;
    OSOBA *osobe;
    int n = 0, mode;
    enum modes
    {
        UNOS = 1,
        PRIKAZ = 2
    };

    if (argc == 2)
        strcpy(filename, argv[1]), printf("Na komandnoj liniji je navedena datoteka '%s'.\n", filename);

    printf("Unesi ime datoteke%s: ", filename[0] ? " ('#' za citanje)" : "");
    scanf("%s", choice);

    if (strlen(choice) == 1 && choice[0] == '#')
        mode = PRIKAZ;
    else
        mode = UNOS, strcpy(filename, choice);

    if (mode == UNOS)
    {
        if (fp = fopen(filename, "wb"))
        {
            do
                printf("Unesi broj osoba: "), scanf("%d", &n);
            while (n < 1 || n > MAX);

            osobe = (OSOBA *)malloc(n * sizeof(OSOBA));

            for (int i = 0; i < n; i++)
                printf("[%d] Ime Prezime Telefon: ", i + 1), unesi(&osobe[i]);

            fwrite(osobe, sizeof(OSOBA), n, fp);
        }
    }
    else if (mode == PRIKAZ)
    {
        if (fp = fopen(filename, "rb"))
        {
            OSOBA osoba;
            osobe = (OSOBA *)malloc(MAX * sizeof(OSOBA));
            int p;

            do
            {
                p = fread(&osoba, sizeof(OSOBA), 1, fp);
                if (p)
                    osobe[n++] = osoba;
            } while (p);

            osobe = (OSOBA *)realloc(osobe, n * sizeof(OSOBA));

            for (int i = 0; i < n; i++)
                pisi(osobe[i]);
        }
        else
            printf("Datoteka '%s' nije pronadjena.", filename);
    }

    free(osobe), free(filename);
    fclose(fp);

    return 0;
}

void unesi(OSOBA *o)
{
    char ime[32], prezime[32], telefon[32];
    scanf("%s %s %s", ime, prezime, telefon);

    strcpy(o->ime, ime);
    strcpy(o->prezime, prezime);
    strcpy(o->telefon, telefon);
}

void pisi(OSOBA o)
{
    printf("%s %s %s\n", o.ime, o.prezime, o.telefon);
}