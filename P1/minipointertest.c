#include <stdio.h>

int square(int *n, int e){

    int output = 1;

    while (e--){
        output *= *n;
    }

    return output;
}

int main(){

    int a = 2;
    int *pA = &a;

    printf("%d", square(pA, 6));

    return 0;
}
