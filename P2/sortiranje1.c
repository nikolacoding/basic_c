// Razni algoritmi za sortiranje primjenjeni na isti niz

#include <stdio.h>
#include <stdlib.h>

void ispisi(int *, int);
int uporedi(int *, int *, int *, int);
void swap(int *, int *);

void selectionSort(int *, int);
void insertionSort(int *, int);
void shellSort(int *, int);
void bubbleSort(int *, int);
void mergeSort(int *, int, int);
void quickSort(int *, int, int);
int split(int *, int, int); // pomocna funkcija za quickSort

int main(int argc, char const *argv[])
{
    int cmp;
    int niz[] = {-1, 3, 5, -12, 4, 16, 9, -8, 7, 1, 2};
    int niz_asc[] = {-12, -8, -1, 1, 2, 3, 4, 5, 7, 9, 16};
    int niz_desc[] = {16, 9, 7, 5, 4, 3, 2, 1, -1, -8, -12};

    int n = sizeof(niz) / sizeof(niz[0]);

    ispisi(niz, n);
    selectionSort(niz, n);
    ispisi(niz, n);

    if (cmp = uporedi(niz, niz_asc, niz_desc, n))
    {
        if (cmp == 1)
            printf("Niz je sortiran u opadajucem redoslijedu.\n");
        if (cmp == -1)
            printf("Niz je sortiran u rastucem redoslijedu.\n");
    }
    else
        printf("Niz nije sortiran.");

    return 0;
}

void mergeSort(int *niz, int begin, int end)
{
    if (begin < end)
    {
        int sredina = (begin + end) / 2;
        mergeSort(niz, begin, sredina);
        mergeSort(niz, sredina + 1, end);
        int len = end - begin + 1;
        int temp[len];
        int i = begin, j = sredina + 1, k = 0;

        while (i <= sredina && j <= end)
            temp[k++] = (niz[i] <= niz[j]) ? niz[i++] : niz[j++];
        while (i <= sredina)
            temp[k++] = niz[i++];
        while (j <= end)
            temp[k++] = niz[j++];
        for (i = 0; i < len; i++)
            niz[begin + i] = temp[i];
    }
}

void quickSort(int *niz, int begin, int end)
{
    if (begin < end)
    {
        int pivot = split(niz, begin, end);
        quickSort(niz, begin, pivot - 1);
        quickSort(niz, pivot + 1, end);
    }
}

int split(int *niz, int begin, int end) // pomocna funkcija za quickSort
{
    int i = begin, j = end;
    int pivot = niz[begin];

    while (i < j)
    {
        while (niz[i] <= pivot && i < j)
            i++;
        while (niz[j] > pivot)
            j--;

        if (i < j)
        {
            int temp = niz[i];
            niz[i] = niz[j];
            niz[j] = temp;
        }
    }
    niz[begin] = niz[j];
    niz[j] = pivot;
    return j;
}

void bubbleSort(int *niz, int n)
{
    int i, j;

    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (niz[j + 1] > niz[j])
            {
                int temp = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = temp;
            }
}

void shellSort(int *niz, int n)
{
    int i, j, h;
    int temp;

    for (h = n / 2; h > 0; h /= 2)
        for (i = 1; i < n; i++)
        {
            temp = niz[i];
            for (j = i; j >= h && temp < niz[j - h]; j -= h)
                niz[j] = niz[j - h];
            niz[j] = temp;
        }
}

void insertionSort(int *niz, int n)
{
    int i, j;
    int temp;

    for (i = 1; i < n; i++)
    {
        temp = niz[i];
        for (j = i; j > 0 && temp > niz[j - 1]; j--)
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
        if (i != min)
        {
            int temp = niz[i];
            niz[i] = niz[min];
            niz[min] = temp;
        }
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

int uporedi(int *niz, int *nizasc, int *nizdesc, int n)
{
    // 0 - neuspjesno sortiran
    // 1 - sortiran opadajuce (od veceg ka manjem)
    // -1 - sortiran rastuce (od manjeg ka vecem)

    for (int i = 0; i < n; i++)
    {
        if (niz[i] - nizasc[i])
            break;

        if (i == n - 1)
            return -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (niz[i] - nizdesc[i])
            break;

        if (i == n - 1)
            return 1;
    }

    return 0;
}