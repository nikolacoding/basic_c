#include <stdio.h>

int main(){
    int x = 1, y = 1, z = 0;
    int L = 1;
    char separator[10] = "----";

    printf("Unesi broj clanova Fibonnacijevog niza koje zelis da budu ispisani: ");
    scanf("%d", &L);

    if (L == 1)
        printf("%d", 1);
    else if (L == 2)
        printf("%d\n%d", 1, 1);
    else if (L <= 0){
        printf("Invalid input.");
        return 0;
    }
    else{
        printf("\n%s\n%d\n%d\n", separator, 1, 1);
        for(int i = 0; i < L; i++){
            z = x + y;
            printf("%d\n", z);
            x = y;
            y = z;

            if (i == L - 1){
                printf("%s\n", separator);
            }
        }
    }
}

