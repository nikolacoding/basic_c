#include <stdio.h>


int main(){

    int divisible[] = {3, 5};
    char outputs[][16] = {"Fizz", "Buzz"};

    char output[64] = "";
    char empty[64] = "";

    int arrayLength = sizeof(divisible) / sizeof(divisible[0]);

    printf("%s\n\n", output[0]);

    for (int i = 0; i <= 100; i++){
        output = empty;

        for (int k = 0; k < arrayLength; k++){
            if (i % divisible[k] == 0){
                output += outputs[k];
            }
        }

        printf("%s", output);
        printf("\n");
    }

    return 0;
}
