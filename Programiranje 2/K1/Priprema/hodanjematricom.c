// Neka je data matrica dimenzija mxn. Napisati rekurzivnu funkciju koja računa ukupan broj putanja kojima se može doći od
// posljednje (m-1, n-1) do prve ćelije u matrici (0, 0). Moguće putanje za naredni korak su lijevo i gore u odnosu
// na početnu ćeliju. Smatrati da iz prvog reda (0) ili prve kolone (0) postoji samo jedna putanja do prve ćelije.
// Prototip funkcije je: int izracunajPutanje(int currentRow, int currentColumn, int m, int n);

#include <stdio.h>
#include <stdlib.h>

int izracunajPutanje(int, int, int, int);
int countPaths(int currentRow, int currentColumn, int, int); // provjereno radi
int mcp(int, int);                                           // ChatGPT

int main(int argc, char const *argv[])
{
    const int m = 4, n = 4;
    printf("Putanja: %d\n", izracunajPutanje(m - 1, n - 1, m, n));
    printf("Putanja prava: %d\n", countPaths(0, 0, m, n));
    printf("ChatGPT: %d\n", mcp(m, n));

    return 0;
}

// 0 1 2
//
// X O O   0
// O O O   1
// O O I   2

// 0 1
//
// X O   0
// O I   1

// m red
// n kolona

int izracunajPutanje(int currentRow, int currentColumn, int m, int n)
{
    if (!currentRow || !currentColumn)
        return 1;

    if (currentRow > 0 && currentColumn > 0)
        return izracunajPutanje(currentRow - 1, currentColumn, m, n) +
               izracunajPutanje(currentRow, currentColumn - 1, m, n);

    if (currentRow > 0)
        return izracunajPutanje(currentRow - 1, currentColumn, m, n);
    if (currentColumn > 0)
        return izracunajPutanje(currentRow, currentColumn - 1, m, n);
}

int countPaths(int currentRow, int currentColumn, int m, int n)
{
    if (currentRow == m - 1 || currentColumn == n - 1)
    {
        return 1;
    }

    int down = countPaths(currentRow + 1, currentColumn, m, n);
    int right = countPaths(currentRow, currentColumn + 1, m, n);

    return right + down;
}

int mcp(int m, int n)
{
    // Base case: if either row or column becomes 1, there is only one path
    if (m == 1 || n == 1)
        return 1;

    // Recursive case: count paths moving upwards and leftwards
    return mcp(m - 1, n) + mcp(m, n - 1);
}