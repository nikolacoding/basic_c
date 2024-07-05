#include <stdio.h>
#include <string.h>

void callCity(char *cities[4], char *choices[4])
{
    char *choice;
    int arrayLength = sizeof(*cities) / sizeof(char);

    for (int i = 0; i <= arrayLength - 1; i++)
    {
        printf("%s je glavni grad koje drzave: ", cities[i]);
        gets(choice);

        if (choice == choices[i])
        {
            printf("Tacno!\n");
        }
    }
}

int main()
{
    char *cities[4] = {"Beograd", "Zagreb", "Sarajevo", "Skoplje"};
    char *choices[4] = {"srb", "hrv", "bih", "mkd"};
    callCity(cities, choices);
    return 0;
}