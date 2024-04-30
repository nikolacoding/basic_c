#include <stdio.h>

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i++){
        int jeProst = 1, vaziUslov = 0;
        for (int j = 2; j < i / 2; j++){
            if (i % j == 0) jeProst = 0;
        }
        if (jeProst){
            int dec = i;
            while (dec){
                if (dec % 3 == 2) vaziUslov = 1;
                dec /= 3;
            }
        }

        if (vaziUslov) printf("Broj %d zadovoljava uslov.\n", i);
    }
}