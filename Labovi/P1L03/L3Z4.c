#include <stdio.h>
#define PI 3.141

int main(){

    float u_deg, u_rad;

    printf("Unesi ugao u stepenima: ");
    scanf("%f", &u_deg);

    u_rad = u_deg * PI / 180;

    printf("Ugao od %.2f stepeni u radijanima iznosi ~%.3f.", u_deg, u_rad);

    return 0;
}
