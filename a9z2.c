#include <stdio.h>
#define MAX 100

void formiraj(int[], int[], int);
int suma_cifara(int);
void ispis(int[], int);

int main()
{
    int n;

    do
    {
        printf("Unesi n: ");
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    int a[MAX], b[MAX];

    formiraj(a, b, n);
    ispis(b, n);

    return 0;
}

void formiraj(int niz1[], int niz2[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Unesi %d. clan niza a: ", i + 1);
        scanf("%d", &niz1[i]);

        niz2[i] = suma_cifara(niz1[i]);
    }
}

int suma_cifara(int num)
{
    int sum = 0;
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

void ispis(int niz[], int len)
{
    printf("Modifikovani niz: ");
    for (int i = 0; i < len; i++)
    {
        printf((i != len - 1) ? "%d, " : "%d.", niz[i]);
    }
}