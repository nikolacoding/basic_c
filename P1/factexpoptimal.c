#include <stdio.h>

int exp (int a, int b){

    int a;
    int b;

    int e = 1;     /* trazimo a^b (a na b-ti stepen)     */

    while (b--){
        e *= a;    /*  e = a^b                             */
    }

    return e;
}

int fact(int a){

    int a;

    int a_pocetno = a;    /*  trazimo "a!" */
    int f = a;

    while (--a_pocetno){
        f *= a_pocetno;   /* f = a!                */
    }

    return f;
}

int main(){

    int x = 1, n = 1;
    scanf("%d %d", &x, &n);

    printf("%d %d", fact(x), exp (x, n));

    return 0;
}


