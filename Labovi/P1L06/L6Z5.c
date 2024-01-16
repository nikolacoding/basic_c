#include <stdio.h>

int main(){

    int n, T = 0;
    const int gap = 2;

    do {
        if (T) printf("Uneseni broj nije izmedju 1 i 30.\n\n");
        T = 1;

        printf("Unesi broj izmedju 1 i 30: ");
        scanf("%d", &n);

    } while (n < 1 || n > 30);

        n += 1;

    for (int i = 1; i < n; i++){

        for (int s = 0; s <= (n-i) - gap; s++){
            printf(" ");
        }

        for (int j = 1; j <= i; j++){
            printf("%d", j % 10);
        }

        for (int k = (i - 1); k > 0; k--){
            printf("%d", k % 10);
        }

        printf("\n");

    }

    return 0;
}
