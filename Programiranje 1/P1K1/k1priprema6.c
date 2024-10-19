#include <stdio.h>

int main(){

    int t = 0;

    do{
        printf("Unesi prirodan broj: ");
        scanf("%d", &t);
    } while (t < 1);

    int temp, comp, sum = 0, e = 1;

    while(t){
        temp = t % 10;
        e = 1;
        comp = 9 - temp;

        while(temp--){
            e *= comp;
        }
        sum += e;
        t /= 10;

        printf("+ %d\n", e);
    }
    printf("Suma: %d", sum);
    return 0;
}
