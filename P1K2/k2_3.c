// Folder: 2021
// K2 – 27.01.2021. (A)
// Zadatak: 3

// NAPOMENA: traze se funkcije ciji prototip se definise u tekstu kao i int main()

#include <stdio.h>
#include <stdlib.h>
#define BUFFER 64

char *slova(const char *s);
void sortiraj(char *s);

int main()
{
    char string[BUFFER];

    printf("Unesi string: ");
    scanf("%s", &string);

    char *dS = slova(string);

    int index = 0;
}

char *slova(const char *s)
{
    int strIndex = 0;
    char *temp = (char *)malloc(BUFFER * sizeof(char));

    for (int i = 0; i < BUFFER; i++)
    {
        if (((int)s[i] >= 65 && (int)s[i] <= 90) || ((int)s[i] >= 97 && (int)s[i] <= 122))
        {
            temp[strIndex++] = s[i];
        }
    }

    return temp;

    // 65 - 90
    // 97 - 122
}