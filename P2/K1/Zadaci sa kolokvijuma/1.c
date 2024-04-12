// Napisati rekurzivnu funkciju koja provjerava da li je proslijedjeni string palindrom. Palindrom je niz
// karaktera koji je jednak kada se cita sa lijeva na desno i obrnuto. Prototip funkcije:
// int palindrome(char *string, int i, int j);

#include <stdio.h>

int palindrome(char *string, int i, int j)
{
    if (i == j)
        return 1;

    if (string[i] == string[j])
    {
        if (i == (j - 1))
            return 1;
        else
            palindrome(string, i + 1, j - 1);
    }
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    printf("%d", palindrome("asdsa", 0, 4));   // jeste
    printf("%d", palindrome("asddsa", 0, 5));  // jeste
    printf("%d", palindrome("racecar", 0, 6)); // jeste
    printf("%d", palindrome("bakar", 0, 4));   // nije
    return 0;
}
