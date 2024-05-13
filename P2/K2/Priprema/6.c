// Izabrati i definisati najpogodnije tipove za rješavanje sljedećeg problema:
// Studenti čekaju u koloni da dobiju ulaznicu za studentsku predstavu. Postoje dvije vrste predstave i na ulaznicama 
// su označene oznakama 1 i 2. Ulaznice se nalaze u kutiji. Svaki student želi da gleda određenu predstavu i uzima 
// ulaznicu sa vrha kutije. Ukoliko se oznaka ulaznice poklapa sa predstavom koju student želi da gleda, student uzima 
// ulaznicu i napušta kolonu. U suprotnom, ne uzima ulaznicu (ostavlja je na vrhu kutije), a zatim se vraća na kraj 
// kolone. Napisati funkciju koja računa koliko studenata će otići da gleda predstavu. Funkcija treba da vrši računanje
// sve dok svi studenti ne uzmu ulaznicu ili dok broj vraćanja ulaznice u kutiju ne bude jednak broju n proslijeđenom 
// kao parametar funkcije. Koristiti ulančane reprezentacije odabranih tipova. 
// Smatrati da je jednak broj studenata i ulaznica.

// Za ovo cemo koristiti stek i red.

#include <stdio.h>
#include <stdlib.h>

typedef struct node{ // jednostruko ulancana lista za reprezentaciju steka i reda
    int val;
    struct node *next;
} NODE;

// Stek
void push(NODE **tos, int val){
    NODE *new = malloc(sizeof(NODE));
    new->val = val;
    new->next = *tos;
    *tos = new;
}

int pop(NODE **tos, int *val){
    if (!*tos) return 0;
    NODE *target = *tos;
    *val = target->val;
    *tos = target->next;
    free(target);
    return 1;
}

// Red
void put(NODE **qf, NODE **qr, int val){
    NODE *new = malloc(sizeof(NODE));
    new->val = val;
    new->next = NULL;

    if (!*qf) *qf = *qr = new;
    else{
        (*qr)->next = new;
        *qr = new;
    }
}

int get(NODE **qf, NODE **qr, int *val){
    if (!*qf) return 0;
    NODE *target = *qf;
    *val = target->val;
    if (*qf == *qr) *qf = *qr = NULL;
    else *qf = target->next;
    free(target);
    return 1;
}

int uvesti_studente(NODE **line_front, NODE **line_rear, NODE **tos, int n){
    int sval, qval, uslo = 0, vracanja = 0;

    while (get(&line_front, &line_rear, &qval) && vracanja < n){
        pop(&tos, sval);
        if (qval == sval){
            uslo++;
        }
        else{
            put(&line_front, &line_rear, qval);
            push(&tos, sval);
            vracanja++;
        }
    }

    return uslo;
}

int main(void){
    
}