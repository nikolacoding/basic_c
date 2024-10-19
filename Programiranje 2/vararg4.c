#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define BUFF 1024

char **transformisi(char **a, int n, char *(*t)(char *))
{
    char **rez = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
        rez[i] = (*t)(a[i]);

    return rez;
}

char *inverz(char *s)
{
    int d = strlen(s);
    char *rez = (char *)calloc(d + 1, sizeof(char));

    for (int i = 0; i < d; i++)
        rez[i] = s[d - 1 - i];

    return rez;
}

int main(int argc, char const *argv[])
{
    char **a, **b;
    char rijec[BUFF];
    int n = 0;

    a = (char **)malloc(MAX * sizeof(char *));

    do
    {
        if (rijec[0] != '#')
        {
            printf("%d. rijec: ", n + 1);
            scanf("%s", rijec);

            a[n] = (char *)calloc(strlen(rijec) + 1, sizeof(char));
            strcpy(a[n], rijec);
            n++;
        }
    } while (rijec[0] != '#' || n == MAX);

    b = transformisi(a, n, &inverz);

    printf("Rezultat: ");
    for (int i = 0; i < n; i++)
    {
        printf("%s -> %s\n", a[i], b[i]);
        free(a[i]);
        free(b[i]);
    }
    free(a);
    free(b);

    return 0;
}
