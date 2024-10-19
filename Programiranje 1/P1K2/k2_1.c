// Folder: 2021
// K2 – 27.01.2021. (A)
// Zadatak: 1

// NAPOMENA: traze se samo funkcije ciji prototip se definise u tekstu, int main() je u cjelosti samo za provjeru

#include <stdio.h>
#include <stdlib.h>
#define MAXCIF 100

void saberi(int *b1, int *b2, int *r);
int uporedi(int *b1, int *b2);
void pisi(int *b);

int main()
{
    //   5 6 2 6 <- br1
    //   4 9 1 3 <- br2
    // 1 0 5 3 9 <<== ispis zbira

    // br1 > br2 ==>> 1

    int *br1, *br2;
    br1 = (int *)calloc(MAXCIF, sizeof(int));
    br2 = (int *)calloc(MAXCIF, sizeof(int));

    int *rez;

    br1[0] = 6;
    br1[1] = 2;
    br1[2] = 6;
    br1[3] = 5;

    br2[0] = 3;
    br2[1] = 1;
    br2[2] = 9;
    br2[3] = 4;

    rez = (int *)calloc(MAXCIF, sizeof(int));

    saberi(br1, br2, rez);
    pisi(rez);

    printf("\n%d", uporedi(br1, br2));

    return 0;
}

void saberi(int *b1, int *b2, int *r)
{
    int prenos = 0;
    for (int i = 0; i < MAXCIF; i++)
    {

        if ((b1[i] + b2[i] + prenos) > 9)
        {
            r[i] = (b1[i] + b2[i] + prenos) % 10;
            prenos = 1;
        }
        else
        {
            r[i] = (b1[i] + b2[i] + prenos);
            prenos = 0;
        }
    }
}

int uporedi(int *b1, int *b2)
{
    for (int i = MAXCIF - 1, n = 0; i >= 0; i--)
    {
        if (b1[i] == b2[i])
            continue;

        if (b1[i] > b2[i])
            return 1;

        if (b2[i] > b1[i])
            return -1;
    }
    return 0;
}

void pisi(int *b)
{
    for (int i = MAXCIF - 1, n = 0; i >= 0; i--)
    {
        if (b[i] == 0 && n == 0)
            continue;
        else
            n = 1;

        if (n)
        {
            printf("%d", b[i]);
        }
    }
}