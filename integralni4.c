#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RAZMAK 32 // ASCII razmak
#define MAX 100

int prebroji(const char *);
void sortiraj(char **, int);

int main()
{
    const int nStr = 3; // zadano u zadatku
    char **niz = (char **)calloc(nStr, sizeof(char *));
    // malloc() nam alocira memoriju sa smece vrijednostima gdje se moze potrefiti da je neka od tih vrijednosti razmak
    // i to bi nam pravilo problem sa radom jer strogo trazimo razmake, dok calloc() alocira memoriju sa vrijednostima '0'

    for (int i = 0; i < nStr; i++)
    {
        niz[i] = (char *)calloc(MAX, sizeof(char));
        printf("Unesi %d. string: ", i + 1);
        gets(niz[i]); // get string funkcija iz <string.h> koja omogucava unosenje stringova sa razmacima (scanf to ne dozvoljava)
    }

    sortiraj(niz, nStr);

    for (int i = 0; i < nStr; i++)
    {
        printf("%s\n", niz[i]);
    }

    return 0;
}

int prebroji(const char *s)
{
    int i = 0, cnt = 1;
    while (s[i])
    {
        if (s[i++] == RAZMAK)
            cnt++;
    }

    // s[0] - prvo slovo stringa, s[1] - drugo, itd.
    // ako nadjemo razmak povecamo brojac rijeci za jedan, njegovu finalnu vrijednost vracamo
    // usput povecavamo iterator i, ovako je kompaktnije ali se moze pored cnt++ staviti i i++ za preglednost ako te zbunjuje ovako

    return cnt;
}

void sortiraj(char **niz, int n)
{
    // selection sort

    char *temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (prebroji(niz[i]) > prebroji(niz[j]))
            {
                temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
}