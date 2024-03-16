#include "funkcije.h"

#include <stdio.h>
#include <stdlib.h>
#define NFUNC 3

int main(int argc, char *argv[])
{
    if (argc <= 1)
        printf("Nema argumenata.");
    else
    {
        char choice;

        char ***argvModArray = (char ***)calloc(NFUNC, sizeof(char **));
        argvModArray[0] = transformisi(argv, argc, &skrati);
        argvModArray[1] = transformisi(argv, argc, &produzi);
        argvModArray[2] = transformisi(argv, argc, &invertuj);

        for (int i = 0; i < NFUNC; i++)
            free(argvModArray[i][0]); // zaostali prvi argumenti

        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; j < NFUNC; j++)
            {
                printf("argv[%d] == %s -> %s\n", i, argv[i], argvModArray[j][i]);
                free(argvModArray[j][i]);

                if (j == NFUNC - 1)
                {
                    free(argvModArray[j]);
                    printf("====================================\n");
                }
            }
        }

        free(argvModArray);
        argvModArray = NULL;
    }

    return 0;
}
