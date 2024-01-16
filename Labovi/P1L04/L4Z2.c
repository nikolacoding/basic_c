#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c, obim;
    int i = 0;
    float s, p;

    do {
        if (i) printf("Neispravan unos. ");
        i = 1;
        printf("Unesi stranice (a, b, c): ");
        scanf("%d %d %d", &a, &b, &c);
    } while (a <= 0 || b <= 0 || c <= 0);

    if (a + b <= c){
        printf("Trougao se ne moze konstruisati.");
        return 0;
    }
    else if (a + c <= b){
        printf("Trougao se ne moze konstruisati.");
        return 0;
    }
    else if (b + c <= a){
        printf("Trougao se ne moze konstruisati.");
        return 0;
    }

    /* Moze se konstruisati */

    obim = a + b + c;
    s = obim/2;
    p = sqrt(s * (s-a) * (s-b) * (s-c));

    printf("\n----\nPovrsina: %.2f\nObim: %d\n", p, obim);

    if (a == b && a == c && b == c)
    {
        printf("Trougao je jednakostranicni.\n----");
        return 0;
    }

    if (a != b && b != c && a != c){
        printf("Trougao je raznostranicni.\n----");
        return 0;
    }

    if ((a == b || a == c) || (b == a || b == c) || (c == a || c == b)){
        printf("Trougao je jednakokraki.\n----");
        return 0;
    }

}
