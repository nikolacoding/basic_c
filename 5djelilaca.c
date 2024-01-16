#include <stdio.h>

int main(){

    int a = 0, b = 0, t = 0;

    int nD = 0;

    do {
        printf("Unesi dva razlicita prirodna broja: ");
        scanf("%d %d", &a, &b);
    }
    while (a < 1 || b < 1 || a == b);

    if (a > b){
        t = b;
        b = a;
        a = t;
    }

    for (int i = a; i <= b; i++){
        nD = 0;

        for (int k = 2; k < i; k++){
            if (i % k == 0) nD++;
        }

        if (nD >= 5) printf("%d\n", i);
    }

    return 0;
}
