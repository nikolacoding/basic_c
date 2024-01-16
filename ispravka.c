#include <stdio.h>

int main(){

    int s, t, suma = 0;
    int e = 1, bD = 0;
    int zadnjaCifra = 0;

    do{
        printf("Unesi: ");
        scanf("%d %d", &s, &t);
    } while (s < 1 || t < 1 || t > 10);

    for (int i = 1; i <= s; i++){
        int t_i = t;
        e = 1;

        while (t_i--){
            e *= i;
        }

        while (e){
            bD = 0;
            zadnjaCifra = e % 10;
            for (int j = zadnjaCifra / 2; j > 1; j--){
                if (zadnjaCifra % j == 0) bD++;
            }

            if (bD == 0 && zadnjaCifra != 1) {
                suma += zadnjaCifra;
            }
            e /= 10;
        }
    }

    printf("Suma: %d", suma);
    return 0;
}
