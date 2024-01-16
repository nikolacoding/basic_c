#include <stdio.h>

typedef struct DATUM
{
    int dan;
    int mjesec;
    int godina;
} datum;

typedef struct STUDENT
{
    char brojIndeksa[16];
    char ime[16];
    char prezime[16];
    datum datumRodjenja;
    float prosjek;
} student;

int main()
{
    int n;

    do
    {
        printf("Unesi broj studenata: ");
        scanf("%d", &n);
    } while (n < 1);

    student studenti[n], temp;

    for (int i = 0; i < n; i++)
    {
        printf("Podaci o %d. studentu:\n", i + 1);

        printf("Broj indeksa: ");
        scanf("%s", &studenti[i].brojIndeksa);

        printf("Ime: ");
        scanf("%s", &studenti[i].ime);

        printf("Prezime: ");
        scanf("%s", &studenti[i].prezime);

        printf("Datum rodjenja: ");
        scanf("%d %d %d", &studenti[i].datumRodjenja.dan,
              &studenti[i].datumRodjenja.mjesec,
              &studenti[i].datumRodjenja.godina);

        printf("Prosjek: ");
        scanf("%f", &studenti[i].prosjek);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if ((studenti[i].datumRodjenja.godina > studenti[j].datumRodjenja.godina) ||
                (studenti[i].datumRodjenja.godina == studenti[j].datumRodjenja.godina &&
                 studenti[i].datumRodjenja.mjesec > studenti[j].datumRodjenja.mjesec) ||
                (studenti[i].datumRodjenja.godina == studenti[j].datumRodjenja.godina &&
                 studenti[i].datumRodjenja.mjesec == studenti[j].datumRodjenja.mjesec &&
                 studenti[i].datumRodjenja.dan > studenti[j].datumRodjenja.dan))
            {
                temp = studenti[i];
                studenti[i] = studenti[j];
                studenti[j] = temp;
            }
        }
    }

    printf("RB. PREZIME          IME              DATUM RODJ. PROSJEK\n");
    printf("=== ================ ================ =========== =======\n");
    for (int i = 0; i < n; i++)
    {
        printf("%2d.", i + 1);
        printf(" %-16s", studenti[i].prezime);
        printf(" %-16s", studenti[i].ime);
        printf(" %02d.%02d.%d", studenti[i].datumRodjenja.dan,
               studenti[i].datumRodjenja.mjesec,
               studenti[i].datumRodjenja.godina);
        printf(" %8.2f\n", studenti[i].prosjek);
    }
    printf("=== ================ ================ =========== =======\n");

    return 0;
}