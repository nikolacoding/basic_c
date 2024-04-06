// Napisati funkciju za sortiranje studenata koristeci QuickSort algoritam (kao i pomocnu funkciju split()).
// U glavnom programu korisnik na standardan ulaz unosi proizvoljan broj studenata koji se potom ispisuju
// iz dinamickog niza sortirani po prezimenu [A -> Z]. Svakog studenta karakterise ime, prezime, br. ind i prosjek.
// Ime i prezime studenta se unosi gramaticki ispravno (prvo veliko slovo itd).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char ime[64], prezime[64], indeks[64];
    double prosjek;
} STUDENT;

void quickSort(STUDENT *, int, int);
int split(STUDENT *, int, int);

char toLower(char);
int uporediImena(char *, char *); // uporedjuje imena slovo po slovo za alfanumericko sortiranje
// ^ vraca 1 ako je prvo ime "teze" od drugog, -1 ako je obrnuto i 0 ako su ista

void ucitaj(STUDENT *, int);
void ispisi(STUDENT *, int);

int main(int argc, char const *argv[])
{
    int n;

    do
        printf("Unesi broj studenata: "), scanf("%d", &n);
    while (n < 1 || n > MAX);
    STUDENT *studenti = (STUDENT *)malloc(n * sizeof(STUDENT));

    ucitaj(studenti, n);
    quickSort(studenti, 0, n - 1);
    ispisi(studenti, n);

    free(studenti);
    return 0;
}

void quickSort(STUDENT *niz, int begin, int end)
{
    if (begin < end)
    {
        int pivot = split(niz, begin, end);
        quickSort(niz, begin, pivot - 1);
        quickSort(niz, pivot + 1, end);
    }
}

int split(STUDENT *niz, int begin, int end) // sortira opadajuce
{
    int i = begin, j = end;
    STUDENT pivot = niz[begin];

    while (uporediImena(niz[i].ime, pivot.ime) >= 0 && i < j)
        i++;
    while (uporediImena(niz[j].ime, pivot.ime) < 0)
        j--;

    if (i < j)
    {
        STUDENT temp = niz[i];
        niz[i] = niz[j];
        niz[j] = temp;
    }
    niz[begin] = niz[j];
    niz[j] = pivot;
    return j;
}

int uporediImena(char *ime1, char *ime2)
{
    if (!(strcmp(ime1, ime2)))
        return 0;

    int len;

    if (strlen(ime1) < strlen(ime2))
        len = strlen(ime1);
    else
        len = strlen(ime2);

    for (int i = 0; i < len; i++)
        if (toLower(ime1[i]) < toLower(ime2[i]))
            return 1;
        else if (toLower(ime1[i]) > toLower(ime2[i]))
            return -1;
        else
            continue;
    return 0;
}

char toLower(const char c)
{
    if (c >= 'a' && c <= 'z')
        return c + 32;
    else
        return c;
}

void ucitaj(STUDENT *niz, int n)
{
    STUDENT st;

    for (int i = 0; i < n; i++)
    {
        printf("Podaci o %d. studentu:\n", i + 1);
        printf("Ime i prezime: "), scanf("%s %s", st.ime, st.prezime);
        printf("Broj indeksa: "), scanf("%s", st.indeks);
        printf("Prosjek: "), scanf("%lf", &st.prosjek);

        niz[i] = st;
    }
}

void ispisi(STUDENT *niz, int n)
{
    printf("===================================\n");
    for (int i = 0; i < n; i++)
        printf("[%02d] %s | %s %s - %.2lf\n", i + 1, niz[i].indeks, niz[i].ime, niz[i].prezime, niz[i].prosjek);
    printf("===================================\n");
}