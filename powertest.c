#include <stdio.h>


int main(){

    int x, y;
    int power;

    scanf("%d %d", &x, &y);

    power = x;

    for (int i = 1; i < y; i++){
        power *= x;
    }

    printf("%d", power);

    return 0;
}
