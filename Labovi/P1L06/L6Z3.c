#include <stdio.h>

int main(){

    int n, sum;
    int p = 0, temp, tempSum, tempFact;
    int done = 0;

    do {
        printf("Unesi prirodan broj n: ");
        scanf("%d", &n);
    } while (n < 1);

    p = n;

    while (!done){
        p--; tempSum = 0; tempFact = 0;
        temp = p;

        while (temp){
            tempFact = temp % 10;
            for (int i = ((temp % 10) - 1); i > 0; i--){
                tempFact *= i;
            }
            tempSum += tempFact;
            temp /= 10;
            tempFact = 0;
        }

        if (tempSum == p){
            printf("Najveci broj manji od n koji je jednak sumi faktorijela sopstvenih cifara je %d!", p);
            done = 1;
        }
    }

    return 0;
}
