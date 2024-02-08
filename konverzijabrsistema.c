#include <stdio.h>
#define MAX 1e6

int main()
{
    int n, n_init;
    int conv = 0, stepen = 1, baza;
    enum baze
    {
        BIN = 2,
        TER = 3,
        QTR = 4,
        OCT = 8
    };

    do
    {
        printf("Unesi prirodan broj (< 10000): ");
        scanf("%d", &n);
    } while (n < 1 || n > MAX - 1);

    n_init = n;

    do
    {
        printf("Unesi bazu br. sistema za konverziju (2, 3, 4, 8): ");
        scanf("%d", &baza);
    } while (baza != BIN && baza != TER && baza != QTR && baza != OCT);

    while (n)
    {
        conv += ((n % baza) * stepen);
        n /= baza;
        stepen *= 10;
    }

    printf("Konvertovano: %d(10) -> %d(%d)", n_init, conv, baza);

    return 0;
}