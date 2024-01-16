#include <stdio.h>

int main(){

    unsigned int n, n_init;
    int temp, sum = 0;

    int cifrearr[10]; /*v*/
    int cifre = 0;

    printf("Unesi neki cijeli broj: ");
    scanf("%d", &n);
    n_init = n;

    for (int i = 1; i <= 10; i++){
        temp = n % 10;
        n /= 10;

        sum += temp;
        cifrearr[i - 1] = temp; /*v*/
    }

    printf("\n----\nSuma cifara unesenog broja %d je %d.\n", n_init, sum);

    for (int i = 0; i <= 10; i++){
        if (cifrearr[10 - i] != 0){
            if (i != 10){
                printf("%d + ", cifrearr[10 - i]);
            }
        }
        if (i == 10) printf("%d = %d\n----\n", cifrearr[0], sum);
    }

    return 0;
}
