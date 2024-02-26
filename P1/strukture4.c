#include <stdio.h>
#define MAX 20

struct datum
{
    int dan, mjesec, godina;
};

typedef struct osoba
{
    char ime[16], prezime[16];
    struct datum rodjen;
} OSOBA;

int main()
{
    int n;
    OSOBA osobe[MAX], temp;

    do
    {
        printf("Unesi broj osoba: ");
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        printf("Unesi podatke o osobi %d: \n", i + 1);

        printf("Ime: ");
        scanf("%s", &osobe[i].ime);

        printf("Prezime: ");
        scanf("%s", &osobe[i].prezime);

        printf("Datum rodjenja: ");
        scanf("%d %d %d", &osobe[i].rodjen.dan, &osobe[i].rodjen.mjesec, &osobe[i].rodjen.godina);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if ((osobe[i].rodjen.godina > osobe[j].rodjen.godina) ||
                (osobe[i].rodjen.godina == osobe[j].rodjen.godina &&
                 osobe[i].rodjen.mjesec > osobe[j].rodjen.mjesec) ||
                (osobe[i].rodjen.godina == osobe[j].rodjen.godina &&
                 osobe[i].rodjen.mjesec == osobe[j].rodjen.mjesec &&
                 osobe[i].rodjen.dan > osobe[j].rodjen.dan))
            {
                temp = osobe[i];
                osobe[i] = osobe[j];
                osobe[j] = temp;
            }
        }
    }

    printf("=== =============== =============== ==========\n");
    printf("BR. PREZIME         IME             RODJEN\n");
    printf("=== =============== =============== ==========\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d. %-15s %-15s %02d.%02d.%d.\n", i + 1, osobe[i].prezime, osobe[i].ime,
               osobe[i].rodjen.dan, osobe[i].rodjen.mjesec, osobe[i].rodjen.godina);
    }
    printf("=== =============== =============== ==========");
    return 0;
}