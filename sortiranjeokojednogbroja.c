#include <stdio.h>
#define MAX 100

void napuni(int[], int);
void sortiraj(int[], int, int);
int postoji(int[], int, int);
void ispisi(int[], int, int);

int main()
{
    int glavniNiz[MAX];
    int n;
    int tg;

    do
    {
        printf("Unesi broj clanova niza: ");
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    printf("Unesi broj oko kojeg ce se niz sortirati: ");
    scanf("%d", &tg);

    napuni(glavniNiz, n);
    sortiraj(glavniNiz, n, tg);
    ispisi(glavniNiz, n, tg);

    return 0;
}

void ispisi(int niz[], int len, int tg)
{
    printf("\nDati niz glasi: ");

    for (int i = 0; i < len; i++)
    {
        printf((i != len - 1) ? (niz[i] == tg) ? ">%d<, " : "%d, " : (niz[i] == tg) ? ">%d<. "
                                                                                    : "%d.",
               niz[i]);
    }
}

void napuni(int niz[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Unesi %d. element niza: ", i + 1);
        scanf("%d", &niz[i]);
    }
}

int postoji(int niz[], int len, int elem)
{
    for (int i = 0; i < len; i++)
    {
        if (niz[i] == elem)
            return i;
    }

    return 0;
}

void sortiraj(int niz[], int len, int target)
{
    int temp;
    int targetIndex;

    if (!postoji(niz, len, target))
    {
        printf("U datom nizu ne postoji ciljani element, te ga necemo sortirati.");
    }
    else
    {
        targetIndex = postoji(niz, len, target);

        for (int i = 0; i < targetIndex - 1; i++)
        {
            for (int j = i; j < targetIndex; j++)
            {
                if (niz[i] > niz[j])
                {
                    temp = niz[i];
                    niz[i] = niz[j];
                    niz[j] = temp;
                }
            }
        }
    }
}