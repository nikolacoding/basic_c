#include <stdio.h>

/* 1 1 2 3 5 8 13 21 34...*/

int main(){

    int a, b;

    scanf("%d %d", &a, &b);

    int x = 0, y = 1, z;
    /*
        X   Y   Z   OUT
        0   1   0 => 1 -> z
        1   1   1 => 2 -> z
        1   2   2 => 3 -> z
        2   3   3 => 5 -> z
        3   5   5 => 8 -> z
        5   8   8 => 13 -> z
        ...
    */
    if (a < 2) printf("1\n");
    for (int i = 0; i <= 1000; i++){
        if (x + y >= a && x + y <= b){
            printf("%s %d\n", ((x + y) % 2) ? "N: " : "P: ", x + y);
        }
        z = x + y;
        x = y;
        y = z;
    }

    return 0;
}
