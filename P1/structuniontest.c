#include <stdio.h>

int add(int a, int b){
    return a+b;
}

int subtract(int a, int b){
    return a-b;
}

int multiply(int a, int b){
    return a*b;
}

int divide(int a, int b){
    return a/b;
}

int main(){

    int (*op_fun_arr[])(int, int) = {add, subtract, multiply, divide};

    int x, y;
    char choice;
    char choiceN;
    scanf("%d %d %c", &x, &y, &choice);

    switch(choice){
    case 'a': choiceN = 0; break;
    case 's': choiceN = 1; break;
    case 'm': choiceN = 2; break;
    case 'd': choiceN = 3; break;
    default: choiceN = 0;break;
    }

    printf("%d", (*op_fun_arr[choiceN])(x, y));

    return 0;
}
