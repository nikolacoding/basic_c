#include <stdio.h>

int main(){

    int n, najmanji;
    int T = 0;

    do {
        if (T) printf("Unos nije validan. ");
        T = 1;

        printf("Koliko brojeva zelis da ucitas: ");
        scanf("%d", &n);
    } while (n <= 0);

    for (int i = 0; i < n; i++){
        int temp;

        printf("Unesi %d. broj: ", i + 1);
        scanf("%d", &temp);

        if (i == 0) najmanji = temp;
        if (temp < najmanji) najmanji = temp;

    }

    printf("\n----\nNajmanji uneseni broj je %d.\n----\n", najmanji);
}
