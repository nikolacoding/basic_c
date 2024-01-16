#include <stdio.h>
#include <math.h>
#define MAX 100

typedef struct POLINOM
{
    int stepen;
    int koef[MAX];
    int len;
} POLINOM;

POLINOM citaj();
POLINOM saberi(POLINOM, POLINOM);
POLINOM pomnozi(POLINOM, POLINOM);
void ispisi(POLINOM);

int main()
{
    POLINOM p1 = citaj();
    POLINOM p2 = citaj();

    ispisi(saberi(p1, p2));

    return 0;
}

POLINOM citaj()
{
    static int index = 1;
    int e;

    POLINOM rez;

    do
    {
        printf("Unesi stepen %d. polinoma: ", index);
        scanf("%d", &e);
    } while (e < 1 || e > MAX);

    rez.len = e + 1;

    for (int i = e; i >= 0; i--)
    {
        printf("Unesi koeficijent od x^%d: ", i);
        scanf("%d", &rez.koef[i]);
    }

    index++;
    return rez;
}

POLINOM saberi(POLINOM p1, POLINOM p2)
{
    POLINOM zbir;

    POLINOM duzi;
    POLINOM kraci;

    if (p1.len >= p2.len)
    {
        duzi = p1;
        kraci = p2;
    }
    else
    {
        duzi = p2;
        kraci = p1;
    }

    zbir.stepen = duzi.stepen;

    for (int i = 0; i < kraci.len; i++)
    {
        zbir.koef[i] = duzi.koef[i] + kraci.koef[i];
    }

    zbir.len = duzi.len;
    return zbir;
}

void ispisi(POLINOM p)
{
    for (int i = p.len - 1; i >= 0; i--)
    {
        if (i == p.len - 1 && p.koef[i] < 0)
            printf("-");

        if (i == 1)
            printf("%dx", (int)fabs(p.koef[i]));
        else if (i == 0)
            printf("%d", (int)fabs(p.koef[i]));
        else
        {
            printf("%dx^%d", (int)fabs(p.koef[i]), i);
        }

        if (i != 0)
        {
            printf((p.koef[i - 1] < 0) ? " - " : " + ");
        }
    }
}