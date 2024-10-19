#include <stdio.h>


int main(){

    float x = 0;
    int n = 0;
    float sum = 0;

    int tempSign = -1;
    int tempFact = 0, factIter = 0;
    float tempExp = 1, expIter = 0;;
    float tempSum = 0;

    scanf("%f %d", &x, &n);

    for (int i = 0; i <= n; i++){
        tempSign = (i % 2 == 0) ? 1 : -1;

        tempSum = 0;

        tempFact = i;
        factIter = i;

        tempExp = 1;
        expIter = i;

        if (!i){
            tempFact = 1;
            tempExp = x;
        }
        else{
            while (--factIter){
                tempFact *= factIter;
            }

            while (expIter--){
                tempExp *= x;
            }
        }

        tempSum = tempSign * tempExp / tempFact;
        sum += tempSum;

        printf("-----i(%d)\ntE: %f\n", i, tempExp);
        printf("tF: %d\n", tempFact);
        printf("tSign: %d\n", tempSign);
        printf("tSum: %f\n\n", tempSum);
    }

    printf("\nTrazena suma je: %f\n----\n", sum);

    return 0;
}
