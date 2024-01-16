#include <stdio.h>

int main(){

    int a, b;
    int iter;
    int T = 0;

    do {
        if (T) printf("Uneseni brojevi nisu svi prirodni. ");
        T = 1;

        printf("Unesi dva prirodna broja: ");
        scanf("%d %d", &a, &b);
    } while (a <= 0 || b <= 0);

    if (a > b) iter = a;
    else iter = b;

    for (int i = iter; i > 0; i--){
        if (a % i == 0 && b % i == 0){
            printf("\nNajveci zajednicki sadrzalac brojeva %d i %d je broj %d.\n", a, b, i);
            return 0;
        }
    }
}
