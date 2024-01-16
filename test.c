#include <stdio.h>

int paran(int br)
{
    return (br % 2) ? 0 : 1;
}

int main()
{
    int broj;

    printf("Unesi broj: ");
    scanf("%d", &broj);

    if (paran(broj))
    {
        printf("Broj %d je paran!", broj);
    }
    else
    {
        printf("Broj %d nije paran!", broj);
    }
    return 0;
}
