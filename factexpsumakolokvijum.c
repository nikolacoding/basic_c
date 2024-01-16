#include <stdio.h>

int main(){

    float x = 0;
    int n = 0;

    float sum;

    int tempSign;
    float tempExp = 0;
    float tempFact = 0;
    float tempSum = 0;

    do {
        printf("Unesi x(R) i n(N): ");
        scanf("%f %d", &x, &n);
    } while (n <= 0);


    for (int i = 0; i < n + 1; i++){
        tempSign = -1;
        tempExp = x;
        tempFact = i;
        tempSum = 0;

        if (i != 0){
            for (int s = 1; s < i; s++){
                tempSign *= -1;
            }

            for (int e = 1; e < i; e++){
                tempExp *= x;
            }

            for (int f = (i - 1); f > 1; f--){
                tempFact *= f;
            }

        }
        else
            {
                tempSign = 1;
                tempExp = 1;
                tempFact = 1;
            }


        tempSum = tempSign * (tempExp / tempFact);
        sum += tempSum;

        printf("za i = %d\n", i);
        printf("tS: %d\n", tempSign);
        printf("tE: %f\n", tempExp);
        printf("tF: %f\n", tempFact);
        printf("tSum: %f\n", tempSum);
        printf("SUMA: %f\n", sum);
        printf("-----\n");
    }

    return 0;
}
