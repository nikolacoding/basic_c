#include <stdio.h>

void poduplaj(int *a){
    *a *= 2;
}

int main(){

    int n = 5;
    int *pN = &n;

    poduplaj(pN);

    printf("%d", n);

    return 0;
}
