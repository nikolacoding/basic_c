#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0;
    int repeats = 0;

    do
    {
        printf("Unesi broj kvadrata: ");
        scanf("%d", &n);
    } while (n < 1);

    for (int i = 1; i <= n; i++)
    {
        int iter = pow(i, 2); /* 169 */
        int temp = iter;

        while (iter)
        {
            while (temp)
            {
                if ((iter % 10) == (temp % 10))
            }
        }
    }
}