/*
*   Neka je dat tip 'node_t' kojim se reprezentuje cvor ulancane reprezentacije steka. 
*   
*   Napisati funkciju koja dodaje 
*   novi string na stek. Funkcija vraća adresu novog čvora ili NULL ako novi čvor nije dodan. Ignorisati pokušaj dodavanja 
*   stringa u sljedećim slučajevima: (1) ako je stek prazan, (2) ako parametar str ima vrijednost NULL, (3) ako je 
*   string prazan, (4) ako je string predugačak. Prototip funkcije je: node_t* str_add(node_t **tos, const char *str);
*   
*   Napisati funkciju koja vraća ukupnu dužinu svih stringova na steku, a čiji je prototip: int str_length(node_t **tos);
*   
*   Napisati funkciju koja vraća dinamičku kopiju najdužeg stringa na steku. Ako stek sadrži više stringova iste 
*   (najveće) dužine, funkcija treba da vrati kopiju prvog takvog stringa. Ako je stek prazan, funkcija treba da vrati 
*   vrijednost NULL. Prototip funkcije je: char* str_max_length(CVOR **tos);
*   
*   Napomena: Nakon poziva funkcija str_length i str_max_length stek mora biti prazan.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nullptr NULL

typedef struct node{
    char str[64];
    struct node *next;
} node_t;

// nemam pojma sta misle pod "ignorisati pokusaj dodavanja stringa ako je stek prazan" jer drugacije nema nacina da
// uopste pocnemo raditi sa stekom tako da cu ignorisati njihov apel za ignorisanje
node_t* str_add(node_t **tos, const char *str){
    const int max_size = 64;
    node_t *new = malloc(sizeof(node_t));
    if (!new || !str || !strlen(str) || (int)strlen(str) > max_size - 1) return nullptr;
    // ^ ako je neuspjesna alokacija, str == nullptr, strlen(str) == 0 ili strlen(str) >= 64

    strcpy(new->str, str);
    new->next = *tos;
    *tos = new;
    return new;
}

int pop(node_t **tos, char **info){
    if (!*tos) return 0; // ako je stek pun

    node_t *target = *tos;
    *tos = target->next;
    char *ret_str = calloc(strlen(target->str) + 1, sizeof(char));
    strcpy(ret_str, target->str);
    *info = ret_str;
    free(target);
    return 1;
}

int str_length(node_t **tos){
    int total = 0;
    char *curr_str;
    while (pop(tos, &curr_str)){
        total += strlen(curr_str);
        free(curr_str);
    }
    return total;
}

char* str_max_length(node_t **tos){
    char *curr_str, *max_str = nullptr;
    int curr_len, max_len = 0;
    while (pop(tos, &curr_str)){
        curr_len = (int)strlen(curr_str);
        if (curr_len > max_len){
            max_len = curr_len;
            if (max_str) free(max_str);
            max_str = curr_str;
        }
        else free(curr_str);
    }
    return max_str;
}

int main(void){
    node_t *tos = nullptr;
    char test1[64] = "123456";
    char test2[64] = "789123123123";
    char test3[64] = "123";
    char test4[64] = "43643666365466";
    char test5[64] = "5";
    str_add(&tos, test1); str_add(&tos, test2); str_add(&tos, test3); str_add(&tos, test4); str_add(&tos, test5);

    // printf("%d\n", str_length(&tos));
    printf("%s\n", str_max_length(&tos));

    return 0;
}