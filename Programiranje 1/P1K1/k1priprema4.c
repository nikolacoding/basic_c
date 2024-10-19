#include <stdio.h>

int main(){

    int d;
    do {
        printf("Unesi broj: ");
        scanf("%d", &d);
    } while (d < 1);

    int sum = 0, temp, temp_i, e = 1, d_i = d;

    while (d){

        temp = d % 10; temp_i = temp; e = 1;

        if (temp != 0){
            while (temp--){
                e *= temp_i;
            }
        } else e = 1;
        sum += e;
        d /= 10;

        printf("Trenutno stanje sume: %d\nDodano u zadnjoj iteraciji: %d\n", sum, e);
    }

    printf("d: %d | Suma: %d\n", d_i, sum);
    printf("Uslov %sje ispunjen!", (d_i == sum) ? "" : "ni");

    return 0;
}
