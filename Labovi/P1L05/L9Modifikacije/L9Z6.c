#include <stdio.h>

typedef struct ARTIKAL
{
    int ID;
    char naziv[16];
    float kolicina;
    float cijena;
} artikal;

int main()
{
    int n;
    float ukupnacijena = 0;

    do
    {
        printf("Unesi broj artikala: ");
        scanf("%d", &n);
    } while (n < 1);

    artikal artikli[n], temp;

    for (int i = 0; i < n; i++)
    {
        printf("%d. artikal:\n", i + 1);

        printf("ID: ");
        scanf("%d", &artikli[i].ID);

        printf("Naziv: ");
        scanf("%s", &artikli[i].naziv);

        printf("Kolicina: ");
        scanf("%f", &artikli[i].kolicina);

        printf("Cijena: ");
        scanf("%f", &artikli[i].cijena);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (artikli[i].ID > artikli[j].ID)
            {
                temp = artikli[i];
                artikli[i] = artikli[j];
                artikli[j] = temp;
            }
        }
    }

    printf("===== =============== ====== ====== =========\n");
    printf("ID    NAZIV           CIJENA   KOL.    UKUPNO\n");
    printf("===== =============== ====== ====== =========\n");
    for (int i = 0; i < n; i++)
    {
        printf("%5d ", artikli[i].ID);
        printf("%-15s", artikli[i].naziv);
        printf("%6.2f", artikli[i].cijena);
        printf("%6.2f", artikli[i].kolicina);
        printf("%12.2f\n", artikli[i].cijena * artikli[i].kolicina);

        ukupnacijena += artikli[i].cijena * artikli[i].kolicina;
    }
    printf("=============================================\n");
    printf("                               UKUPNO: %6.2f", ukupnacijena);

    return 0;
}