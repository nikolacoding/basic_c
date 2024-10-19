#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int n;

    printf("n = ");
    scanf("%d", &n);
    int niz[n];
    int niz2[n];
    int nizog[n];

    int bogosorted = 0;
    int checks;
    long bogosortAttempts = 0;
    int doneTimes = 0;
    const int tryTimes = 100;

    for (int i = 0; i < n; i++)
    {
        int temp;
        printf("element %d: ", i);
        scanf("%d", &temp);
        niz[i] = temp;
        niz2[i] = temp;
    }

    printf("Originalni niz: ");
    for (int i = 0; i < n; i++)
    {
        nizog[i] = niz[i];
        printf((i != n - 1) ? "%d, " : "%d.\n", niz[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (niz[i] > niz[j])
            {
                int temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }

    printf("Sortirani niz: ");
    for (int i = 0; i < n; i++)
    {
        printf((i != n - 1) ? "%d, " : "%d.\n", niz[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        while (!bogosorted)
        {
            for (int i = 0; i < n; i++)
            {
                int random1 = rand() % n;
                int random2 = rand() % n;
                checks = 0;

                int temp = niz2[random1];
                niz2[random1] = niz2[random2];
                niz2[random2] = temp;
                bogosortAttempts++;
            }

            for (int j = 0; j < n; j++)
            {
                if (niz[j] == niz2[j])
                {
                    checks++;
                }
            }

            if (checks == n)
            {
                doneTimes++;
            }

            for (int b = 0; b < n; b++)
            {
                niz2[b] = nizog[b];
            }

            if (doneTimes == tryTimes)
                bogosorted = 1;
        }
    }

    printf("Bogo-sortirani niz (%.1f pokusaja po iteraciji): ", (float)bogosortAttempts / tryTimes);
    for (int i = 0; i < n; i++)
    {
        printf((i != n - 1) ? "%d, " : "%d.\n", niz2[i]);
    }
}
