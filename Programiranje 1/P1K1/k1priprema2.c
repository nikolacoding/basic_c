#include <stdio.h>


int main(){

    int n = 0, k = 0, sum = 0, sp = 0, e = 1;

    do{
        scanf("%d %d", &n, &k);
    } while (n < 1 || k < 1 || k > 10);

    int k_i = k;

    for (int i = 1; i <= n; i++){
        k = k_i;
        e = 1;
        sp = 0;

        while (k--){
            e *= i;
        }

        while (e){
            if ((e % 10) % 2 == 0) sp += (e % 10);
            e /= 10;
        }

        sum += sp;
    }

    printf("Suma iznosi: %d", sum);
    return 0;
}
