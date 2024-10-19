#include <stdio.h>

int main(){

    int n, k, temp;
    int nbE;

    int T = 0;

    do {
        if (T) printf("Brojevi nisu svi prirodni.\n\n");
        T = 1;

        printf("Unesi dva prirodna broja: ");
        scanf("%d %d", &n, &k);
    } while (n < 1 || k < 1);

    for (int i = 1; i <= n; i++){
        temp = i;
        nbE = 0;
        for (int j = 0; j <= sizeof(i) * 8; j++){
            if (temp & 0x01) nbE++;
            temp >>= 1;
        }

        if (nbE == k) printf("%d\n", i);
    }

    return 0;
}
