#include <stdio.h>

void pogodibroj(const int, const int);
void pogodibrojExp(const int, const int);

int main()
{
    pogodibrojExp(0, 20);
    return 0;
}

void pogodibroj(const int low, const int high)
{
    int begin = low, end = high, sredina;
    int odg;

    sredina = (begin + end) / 2;

    printf("Da li je %d tvoj broj? ", sredina);
    scanf("%d", &odg);
    if (odg)
    {
        printf("Zamislili ste broj %d!\n", sredina);
        return;
    }
    do
    {
        printf("Da li je broj veci od %d? ", sredina);
        scanf("%d", &odg);

        if (odg)
            begin = sredina + 1;
        else
            end = sredina;
        sredina = (begin + end) / 2;
    } while (begin != end);

    printf("Zamislili ste broj %d!\n", sredina);
}

void pogodibrojExp(const int low, const int high)
{
    int begin = low, end = high, sredina;
    int odg;

    sredina = (begin + end) / 2;

    printf("Da li je %d tvoj broj? ", end);
    scanf("%d", &odg);
    if (odg)
    {
        printf("Zamislili ste broj %d!\n", end);
        return;
    }
    while (1)
    {
        printf("Da li je broj veci od %d? ", end);
        scanf("%d", &odg);

        if (odg)
            begin = end, end *= 2;
        else
            break;
    }

    do
    {
        sredina = (begin + end) / 2;
        printf("Da li je broj veci od %d? ", sredina);
        scanf("%d", &odg);

        if (odg)
            begin = sredina + 1;
        else
            end = sredina;

    } while (begin != end);

    printf("Zamislili ste broj %d!\n", begin);
}