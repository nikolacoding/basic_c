#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#define BUFF 1000

char *formiraj(int, ...);

int main(int argc, char const *argv[])
{
    char *str;
    str = formiraj(3, 123, 456, 789);

    printf("%s", str);
    free(str);

    return 0;
}

char *formiraj(int n, ...)
{
    char *ret = (char *)calloc(n, BUFF);
    va_list args;
    va_start(args, n);

    char *temp = (char *)calloc(BUFF, sizeof(char));
    for (int i = 0; i < n; i++)
    {
        int arg = va_arg(args, int);
        itoa(arg, temp, 10);
        strcat(ret, temp);
    }
    free(temp);

    va_end(args);
    return ret;
}