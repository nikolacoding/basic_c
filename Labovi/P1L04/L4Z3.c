#include <stdio.h>

int main(){
    int mjesec, godina;
    int i = 0;

    int dani[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char imena[12][10] = {"Januar", "Februar", "Mart", "April", "Maj", "Jun", "Jul", "Avgust", "Septembar",
                          "Oktobar", "Novembar", "Decembar"};

    do {
        if (i) printf("Neispravan unos. ");
        i = 1;
        printf("Unesi dan i godinu: ");
        scanf("%d %d", &mjesec, &godina);
    } while (mjesec <= 0 || mjesec > 12 || godina <= 0);

    if (mjesec == 2 && ((godina % 100 == 0) && (godina % 400 == 0) || (godina % 4 == 0)))
        printf("Februar %d. godine ima 29 dana.", godina);
    else{
        printf("%s %d. godine ima %d dana.", imena[mjesec - 1], godina, dani[mjesec - 1]);
    }
    return 0;
}
