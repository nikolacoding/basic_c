#include <stdio.h>
#define MASKA 0x01

int main(){
    int n;

    printf("Unesi broj: ");
    scanf("%d", &n);

    /*
    n 0 0 1 1 0 0 0 1
    M 0 0 0 0 0 0 0 1 (0x01)
    r 0 0 0 0 0 0 0 1 <- Ako je prvi bit 1, broj je sigurno neparan i obrnuto
    */

    (n & MASKA == 1) ? printf("Broj je neparan") : printf("Broj je paran");
    return 0;
}
