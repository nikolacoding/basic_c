#include <stdio.h>

int main(){


    /* Primjer: 2534 => 154 */

    int n1, n2;
    int nC = 0;
    int sum = 0, temp;

    do {
        printf("Unesi prirodan broj: ");
        scanf("%d", &n1);
    }
    while (n1 < 1);

    n2 = n1;

    while (n1){
        nC++;
        n1 /= 10;
    }

    for (int i = 1; i <= nC; i++){
        temp = n2 % 10;
        for (int k = 0; k < i-1; k++){
            temp *= (n2 % 10);
        }
        sum += temp;
        n2 /= 10;
    }

    printf("Suma iznosi: %d", sum);

    return 0;
}
