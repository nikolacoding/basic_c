#include <stdio.h>

int main(){
    /*
        primjeri:
        6 6
        220 284
        1184 1210
        63020 76084
    */
    int a, b, T = 0;

    do {
        if (T) printf("Neki od unesenih brojeva nisu prirodni. ");
        T = 1;

        printf("Unesi dva prirodna broja: ");
        scanf("%d %d", &a, &b);
    } while (a <= 0 || b <= 0);

    int sdA = 0, sdB = 0;

    for (int i = 1, j = 1; i < a && j < b; i++, j++){
        if (a % i == 0)
            sdA += i;

        if (b % j == 0)
            sdB += j;
    }

    /*
    uzeo sam da se sam broj ne svrstava kao vlastiti djelilac
    tako sto sam u petlji stavio da se djelioci traze broj po broj do broja prije
    (<) umjesto do datog broja (<=)
    */

    if (a == sdB && b == sdA)
        printf("\n----\nBrojevi su prijateljski.\n----\n");
    else
        printf("\n----\nBrojevi nisu prijateljski.\n----\n");

    return 0;
}
