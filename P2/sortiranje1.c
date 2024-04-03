// Svi moguci algoritmi primjenjeni na isti niz

#include <stdio.h>
#include <stdlib.h>

void ispisi(int *, int);
int uporedi(int *, int *, int);
void swap(int *, int *);

void selectionSort(int *, int);
void insertionSort(int *, int);
void shellSort(int *, int);
void bubbleSort(int *, int);

int main(int argc, char const *argv[])
{
    int niz[] = {-1, 3, 5, -12, 4, 16, 9, -8, 7, 1, 2};
    int niz_sortiran[] = {-12, -8, -1, 1, 2, 3, 4, 5, 7, 9, 16};

    int n = sizeof(niz) / sizeof(niz[0]);

    ispisi(niz, n);
    bubbleSort(niz, n);
    ispisi(niz, n);

    printf("\n%sspjesno sortirano!", uporedi(niz, niz_sortiran, n) ? "U" : "Neu");

    return 0;
}

void bubbleSort(int *niz, int n)
{
    int i, j;

    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (niz[j + 1] < niz[j])
                swap(niz + j + 1, niz + j);
}

void shellSort(int *niz, int n)
{
    int i, j, h, temp;
    for (h = n / 2; h > 0; h /= 2)
    {
        for (i = 1; i < n; i++)
        {
            temp = niz[i];
            for (j = i; j >= h && niz[j - h] > temp; j -= h)
                niz[j] = niz[j - h];
            niz[j] = temp;
        }
    }
}

void insertionSort(int *niz, int n)
{
    int i, j, temp;

    for (i = 1; i < n; i++)
    {
        temp = niz[i];
        for (j = i; j > 0 && niz[j - 1] > temp; j--)
            niz[j] = niz[j - 1];
        niz[j] = temp;
    }
}

void selectionSort(int *niz, int n)
{
    int i, j, min;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1, min = i; j < n; j++)
        {
            if (niz[j] < niz[min])
                min = j;
        }
        if (min != i)
            swap(niz + min, niz + i);
    }
}

void swap(int *n1, int *n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void ispisi(int *niz, int n)
{
    printf("Niz: ");
    for (int i = 0; i < n; i++)
        printf("%d ", niz[i]);
    printf("\n");
}

int uporedi(int *niz1, int *niz2, int n)
{
    for (int i = 0; i < n; i++)
        if (niz1[i] - niz2[i])
            return 0;
    return 1;
}