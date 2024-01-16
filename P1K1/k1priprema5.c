#include <stdio.h>

int main(){

    int x = 0, y = 0, sD;
    int t;

    int najveca[2] = {0, 0};

    do{
        printf("Unesi dva prirodna broja: ");
        scanf("%d %d", &x, &y);
    }while (x < 1 || y < 1);

    if (x > y){
        t = x;
        x = y;
        y = t;
    }

    for (int i = x; i <= y; i++){
        sD = 0;
        for (int d = i / 2; d > 0; d--){
            if (!(i % d)) sD += d;
        }

        if (sD > i) printf("sdiv(%d) = %d > %d\n", i, sD, i);

        if (sD > najveca[1])
        {
            najveca[0] = i;
            najveca[1] = sD;
        }
    }

    printf("Broj %d ima najvecu sumu djelilaca - %d", najveca[0], najveca[1]);

    return 0;
}
