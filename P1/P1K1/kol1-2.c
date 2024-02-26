#include <stdio.h>

int main(){

    int s, s_init, t;
    int temp, tempInit, tempD;
    int sum;
    int T = 0;

    do {
        if (T) printf("Nepravilan unos. ");
        T = 1;

        printf("Unesi dva broja (s, t > 0), (t <= 10): ");
        scanf("%d %d", &s, &t);
    } while (s < 1 || t < 1 || t > 10);

    s_init = s;

    while (s){
        tempD = 0;
        temp = s % 10;

        for(int i = 2; i <= temp / 2; i++){
            if (temp % i == 0){
                if (temp != i) tempD++;
            }
        }

        if (!tempD){
            tempInit = temp;
            for (int i = 1; i <= (t-1); i++){
                temp *= tempInit;
            }

            sum += temp;
        }

        s /= 10;
    }

    printf("Data suma za s=%d i t=%d iznosi %d.", s_init, t, sum);

    return 0;
}
