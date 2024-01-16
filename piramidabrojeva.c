#include <stdio.h>

int main(){

    int n;

    do{
        printf("Unesi n (n <= 30): ");
        scanf("%d", &n);
    } while (n > 1000 || n <= 0);

    for (int i = 1; i < n + 1; i++){

        for (int r = n - i; r > 0; r--){
            printf(" ");
        }

        for (int j = 1; j < i; j++){
            printf("%d", j % 10);
        }

        for (int k = i; k > 0; k--){
            printf("%d", k % 10);
        }

        printf("%\n");
    }

    return 0;
}
