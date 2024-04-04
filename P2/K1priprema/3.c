// Neka je definisan tip student kojim se reprezentuje jedan student.
// Napisati funkciju ciji je prototip: double calc(double(*f)(STUDENT), int n, ...);
// Funkcija kao neobavezne argumente prima podatke tipa STUDENT, pri čemu n predstavlja broj argumenata tog tipa.
// Funkcija treba da nad svakim neobaveznim argumentom primijeni transformaciju funkcijom f. Funkcija vraća
// aritmetičku sredinu svih transformisanih vrijednosti funkcijom f.
//
// U glavnom programu demonstrirati upotrebu funkcije na dva načina, pri čemu je potrebno kreirati
// minimalno tri neobavezna argumenta, te nakon poziva funkcije ispisati dobijenu vrijednost.
// U prvom slučaju funkcija za transformaciju vraća prosjek studenta, a u drugom slučaju ukupan broj
// karaktera imena i prezimena studenta.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define MAX 1000

typedef struct student
{
    char *ime, *prezime;
    double prosjek;
} STUDENT;

double getProsjek(STUDENT);
double getCharCount(STUDENT);
double calc(double (*f)(STUDENT), int, ...);

int main(int argc, char const *argv[])
{
    STUDENT studenti[3] = {{"Marko", "Markovic", 10.0}, {"Jovan", "Jovanovic", 8.5}, {"Ivan", "Ivanovic", 8.5}};

    printf("Prosjek prosjeka: %.2lf\n", calc(&getProsjek, 3, studenti[0], studenti[1], studenti[2]));
    printf("Prosjek slova: %.2lf\n", calc(&getCharCount, 3, studenti[0], studenti[1], studenti[2]));
    return 0;
}

double calc(double (*f)(STUDENT), int n, ...)
{
    double total = 0;

    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++)
    {
        STUDENT arg = va_arg(args, STUDENT);
        total += (*f)(arg);
    }
    va_end(args);

    return total / n;
}

double getProsjek(STUDENT st)
{
    return st.prosjek;
}

double getCharCount(STUDENT st)
{
    int i = 0, p = 0;

    while (st.ime[i])
        i++;

    while (st.prezime[p])
        p++;

    return i + p;
}