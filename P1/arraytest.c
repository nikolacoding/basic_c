#include <stdio.h>

#define L 5
int main(void){
    int array1[L] = {1, 2, 3, 4, 5};

    for (int i = 0; i < L; i++)
        printf("%d ", array1[i]);
    printf("\n");

    for (int i = 0; i < L; i++)
        printf("%d ", i[array1]);
    printf("\n");
    
    for (int i = 0; i < L; i++){
        int curr = *(array1 + i);
        printf("%d ", curr);
    }

    return 0;
}