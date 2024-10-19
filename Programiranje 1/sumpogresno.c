#include <stdio.h>

int main(){

    int s, t, suma = 0, n;

    do {
        printf("Unesi: ");
        scanf("%d %d", &s, &t);
    } while (s < 1 || t < 1 || t > 10);

    for (int i = 1; i <= s; i++){
        n = 1;
        for (int j = 1; j <= t; j++){
            n *= i;
        }
        for ( ; n; n /= 10){
            if (n % 2 == 1) suma += n % 10;
        }
    }

    printf("Suma: %d", suma);
    return 0;
}
