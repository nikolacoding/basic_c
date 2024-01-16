#include <stdio.h>

int main(){

    int a, b , bD, t;

    a = 0, b = 0;

    scanf("%d %d", &a, &b);

    if (a > b){
        t = a;
        a = b;
        b = t;
    }

    for (int i = a; i <= b; i++){
        bD = 0;
        for (int k = i - 1; k > 1; k--){
            if (i % k == 0) bD++;
        }

        if (bD >= 5) printf("Broj %d zadovoljava uslov!\n", i);
    }
    return 0;
}
