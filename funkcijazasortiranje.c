#include <stdio.h>
#define MAX 100

void sort(int[], int, int);
void unesi(int[], int);
void ispisi(int[], int);

int main()
{
    int n;
    int niz[MAX];

    do
    {
        printf("Unesi n: ");
        scanf("%d", &n);
    } while (n < 1 || n > MAX);

    unesi(niz, n);
    sort(niz, n, 1);
    ispisi(niz, n);

    return 0;
}

void unesi(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Unesi %d. clan niza: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void sort(int arr[], int len, int invert)
{
    int temp;
    if (!invert)
    {
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i; j < len; j++)
            {
                if (arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    else
    {
        for (int i = len - 1; i > 0; i--)
        {
            for (int j = i; j > -1; j--)
            {
                if (arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

void ispisi(int arr[], int len)
{
    printf("\nNiz: ");
    for (int i = 0; i < len; i++)
    {
        printf((i != len - 1) ? "%d, " : "%d.", arr[i]);
    }
}