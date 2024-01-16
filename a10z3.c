#include <stdio.h>
#include <stdlib.h>

typedef struct TIM
{
    char naziv[16];
    int GF;
    int GA;
    int bodovi;

} TIM;

void ucitaj(TIM *);
TIM *formiraj(int *);
void sortiraj(TIM *, int);
void ispisi(TIM *, int);

int main()
{
    int n;
    TIM *timovi;
    do
    {
        printf("Unesi broj timova: ");
        scanf("%d", &n);
    } while (n < 1);

    timovi = formiraj(&n);
    sortiraj(timovi, n);
    ispisi(timovi, n);

    free(timovi);
    return 0;
}

void ucitaj(TIM *tim)
{
    static int index = 1;

    printf("Unesi ime tima %d: ", index);
    scanf("%s", &tim->naziv);

    printf("Unesi postignute golove tima %d: ", index);
    scanf("%d", &tim->GF);

    printf("Unesi primljene golove tima %d: ", index);
    scanf("%d", &tim->GA);

    printf("Unesi broj bodova tima %d: ", index);
    scanf("%d", &tim->bodovi);

    index++;
}

TIM *formiraj(int *nTimova)
{
    TIM *timovi = (TIM *)malloc(*nTimova * sizeof(TIM));

    for (int i = 0; i < *nTimova; i++)
    {
        ucitaj(timovi + i);
    }

    return timovi;
}

void sortiraj(TIM *timovi, int len)
{
    TIM temp;
    TIM *iTim, *jTim;

    for (int i = 0; i < len - 1; i++)
    {
        iTim = timovi + i;
        for (int j = i; j < len; j++)
        {
            jTim = timovi + j;
            if ((*(iTim)).bodovi < (*(jTim)).bodovi ||
                (*(iTim)).bodovi == (*(jTim)).bodovi &&
                    ((*(iTim)).GF - (*(iTim)).GA) <
                        ((*(jTim)).GF - (*(jTim)).GA))
            {
                temp = *(iTim);
                *(iTim) = *(jTim);
                *(jTim) = temp;
            }
        }
    }
}

void ispisi(TIM *timovi, int len)
{
    printf("=========================================\n");
    printf("RB.    NAZIV           GPO  GPR  GR  BOD\n");
    printf("==     ============    ===  ===  ==  ====");

    for (int i = 0; i < len; i++)
    {
        printf("\n");
        printf("%02d", i + 1);
        printf("     %-15s", (*(timovi + i)).naziv);
        printf("%4d", (*(timovi + i)).GF);
        printf("%5d", (*(timovi + i)).GA);
        printf("%4d", (*(timovi + i)).GF - (*(timovi + i)).GA);
        printf("%5d", (*(timovi + i)).bodovi);
    }
}