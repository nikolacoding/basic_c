#include <stdio.h>
#include <stdlib.h>

char* inicijali(const char *ime, const char *prezime){
    // N.M. <-- 4 karaktera + '\0' terminator = 5
    const int size = 5;
    char *ret = calloc(size, sizeof(char)); // <-- calloc inicijalizuje sve na nulu tako da ne moramo staviti terminator

    ret[1] = ret[3] = '.'; // '0.0.0'
    ret[0] = ime[0]; // N.0.0
    ret[2] = prezime[0]; // N.M.0
    return ret; 
}

int main(void){
    char ime[] = "Nikola";
    char prezime[] = "Markovic";
    char *in;

    printf("%s", in = inicijali(ime, prezime));
    free(in);
    return 0;
}
