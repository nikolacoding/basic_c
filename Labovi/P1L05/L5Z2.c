#include <stdio.h>

int main(){
    int n, count = 0;
    int i = 0;

    do {
        if (i) printf("Unos nije validan. ");
        i = 1;

        printf("Koliko brojeva zelis da ucitas: ");
        scanf("%d", &n);
    } while (n <= 0);

    for (int i = 0; i < n; i++){
        int temp;
        printf("Unesi %d. broj: ", i + 1);
        scanf("%d", &temp);

        if (temp > 0) count++;
    }

    printf("\n----\nOd unesenih %d brojeva, %d je pozitivno.\n----\n", n, count);

    return 0;
}
