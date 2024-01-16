#include <stdio.h>

int exponent(int input, int e){

    if (e == 0) return 1;
    if (e == 1) return input;
    else{
        int output;
        output = input;

        for (int i = 0; i < e-1; i++){
            output *= input;
        }

        return output;
    }
}

int fact(int input){

    int output;
    output = input;

    for (int i = input - 1; i > 1; i--){
        output *= i;
    }

    return output;
}

int main(){

    printf("2^5: %d\n", exponent(2, 5));
    printf("4!: %d\n", fact(4));
}
