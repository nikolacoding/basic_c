#include <stdio.h>

int main(){

    int n, d, db = 0;
    int done = 0;


    do {
        printf("Unesi broj: ");
        scanf("%d", &n);
    } while (n < 1);

    d = n;

    while (!done){
        d++; db = 0;
        for (int i = 2; i <= d/2; i++){
            if (d % i == 0) db++;
        }
        if (!db){
            printf("Trazeni prost broj je %d.", d);
            done = 1;
        }
    }

    return 0;
}
