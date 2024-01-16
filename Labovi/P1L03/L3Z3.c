#include <stdio.h>
#define MASKA 0x01

int main(){

    int n;

    printf("Unesi broj: ");
    scanf("%d", &n);

    printf("Broj %d %sje paran.", n, (n & MASKA) ? "ni" : "");

    return 0;
}
