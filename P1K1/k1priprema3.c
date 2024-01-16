#include <stdio.h>

int main(){

    int x = 0, y = 0;
    scanf("%d %d", &x, &y);

    int sum = 0;
    int t;

    if (x > y){ t = x; x = y; y = t;}

    for (int i = x; i <= y; i++){
        sum = 0;

        for (int k = i/2; k > 0; k--){
            if (i % k == 0) sum += k;
        }

        if (sum > i) printf("Broj %d zadovoljava dati uslov!\n", i);
    }

    return 0;
}
