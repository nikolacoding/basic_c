#include <stdio.h>

int main(){

    int n, a, b;
    int pr = 1;

    do{
        scanf("%d %d %d", &n, &a, &b);
    } while (n < 1 || a < 1 || b < 1 || a > b);

    for (int i = 1; i < n; i++){
        pr = 1;

        for (int d = i; d > 0; d--){
            if (i % d == 0) pr *= d;
        }
        if (pr >= a && pr <= b){
            printf("%d....pr(%d)=%d....%d\n", a, i, pr, b);
        }
    }

    return 0;
}
