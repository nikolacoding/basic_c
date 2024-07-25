// Napisati program koji uzima naziv valute (do 2 karaktera) i cjelobrojnu novcanu vrijednost, te je dijeli u
// skladu sa postojecim novcanicama (apoenima) u iznosima od 1, 2, 5, 10, 20 i 50. Program treba da prioritizuje
// vece novcanice te se spusta ka manjima po potrebi.

/*
    Primjer trazenog izvrsavanja:
    > Valuta:
    >> KM
    > Novac:
    >> 88

    Novac dijelimo na sljedeci nacin: 50 20 10 5 2 1
*/
#include <stdio.h>
#include <stdlib.h>
#define BROJ_APOENA 6
int main(void){
    const int apoeni[BROJ_APOENA] = {50, 20, 10, 5, 2, 1};
    char valuta[3];
    int novac;

    printf("Valuta: "); gets(valuta);
    printf("Novac: "); scanf("%d", &novac);
    int max_ind = 0;
    printf("Ukupan novac (%d%s) dijelimo na sljedeci nacin: ", novac, valuta);
    while (novac){
        int max_ap = apoeni[max_ind];
        if (novac >= max_ap){
            novac -= max_ap;
            printf("%d ", max_ap);
        }
        else max_ind++;
    }
    return 0;
}