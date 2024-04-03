// Napisi funkciju koja provjerava da li su dva stringa anagrami (npr. 'kosa', 'sako' su anagrami).
// Napisi program u kom korisnik unosi dva dinamicka stringa i dobija odgovor da li su anagrami.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int jeAnagram(const char *, const char *);
void insertionSort(char *, int);
int main(int argc, char const *argv[])
{
    char *str1 = (char *)calloc(MAX, sizeof(char));
    char *str2 = (char *)calloc(MAX, sizeof(char));

    printf("Unesi dva stringa: "), scanf("%s %s", str1, str2);

    str1 = (char *)realloc(str1, strlen(str1) + 1);
    str2 = (char *)realloc(str2, strlen(str2) + 1);

    printf("Stringovi '%s' i '%s' %ssu anagrami.", str1, str2, jeAnagram(str1, str2) ? "" : "ni");

    free(str1), free(str2);

    return 0;
}

int jeAnagram(const char *str1, const char *str2)
{
    if (strlen(str1) != strlen(str2))
        return 0;

    int l = strlen(str1);

    char *str1copy = (char *)calloc(l + 1, sizeof(char));
    char *str2copy = (char *)calloc(l + 1, sizeof(char));

    strcpy(str1copy, str1);
    strcpy(str2copy, str2);

    insertionSort(str1copy, l);
    insertionSort(str2copy, l);

    int ret = !(strcmp(str1copy, str2copy));
    free(str1copy), free(str2copy);

    return ret;
}

void insertionSort(char *str, int len)
{
    int i, j, temp;

    for (i = 1; i < len; i++)
    {
        temp = str[i];
        for (j = i; j > 0 && str[j - 1] > temp; j--)
            str[j] = str[j - 1];
        str[j] = temp;
    }
}