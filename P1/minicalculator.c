#include <stdio.h>

float add(float a, float b){ return a + b; }
float subtract(float a, float b){ return a - b; }
float multiply(float a, float b){ return a * b; }
float divide(float a, float b){ return a / b; }

float exp(float a, float e){
    int e_i = (int)e;
    float output = 1;
    while (e--){
        output *= a;
    }
    return output;
}

void calculate(float *mainN, int index, char comm[5][32]){

    float temp;
    float (*op_func_arr[])(float, float) = {add, subtract, multiply, divide, exp};

    printf(comm[index]);
    scanf("%f", &temp);

    *mainN = (op_func_arr[index](*mainN, temp));
}

int main(){

    float n = 1, temp = 0;
    float *pN = &n;

    int done = 0;
    char choice[16];

    int choiceIndex;

    char comments[5][32] = {"Add: ", "Subtract: ", "Multiply by: ",
    "Divide by: ", "Exponentiate with: "};


    while (!done){
        printf("\n---> %.2f <---\n", n);
        printf("Choice: ");
        scanf("%s", &choice);

        switch(choice[0]){
            case 'a': choiceIndex = 0; break;
            case 's': choiceIndex = 1; break;
            case 'm': choiceIndex = 2; break;
            case 'd': choiceIndex = 3; break;
            case 'e': choiceIndex = 4; break;
            default: printf("Error. "); break;
        }
        if (choiceIndex >= 0 && choiceIndex < 5) calculate(pN, choiceIndex, comments);
    }
    return 0;
}

