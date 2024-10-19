/*
*   Izabrati i definisati najpogodnije tipove za rješavanje sljedećeg problema:
*   Studenti čekaju u koloni da dobiju ulaznicu za studentsku predstavu. Postoje dvije vrste predstave i na ulaznicama 
*   su označene oznakama 1 i 2. Ulaznice se nalaze u kutiji. Svaki student želi da gleda određenu predstavu i uzima 
*   ulaznicu sa vrha kutije. Ukoliko se oznaka ulaznice poklapa sa predstavom koju student želi da gleda, student uzima 
*   ulaznicu i napušta kolonu. U suprotnom, ne uzima ulaznicu (ostavlja je na vrhu kutije), a zatim se vraća na kraj 
*   kolone.
*   
*   Napisati funkciju koja računa koliko studenata će otići da gleda predstavu. Funkcija treba da vrši računanje sve dok 
*   svi studenti ne uzmu ulaznicu ili dok broj vraćanja ulaznice u kutiju ne bude jednak broju n proslijeđenom kao 
*   parametar funkcije.
*   
*   Koristiti ulančane reprezentacije odabranih tipova. 
*   Smatrati da je jednak broj studenata i ulaznica.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *next;
} qnode_t, snode_t;

void push(snode_t **tos, int info){
    snode_t *new = malloc(sizeof(snode_t));
    if (!new) return;

    new->next = NULL;
    new->info = info;

    if (!*tos) *tos = new;
    else{
        new->next = *tos;
        *tos = new;
    }
}

int pop(snode_t **tos, int *info){
    if (!*tos) return 0;
    
    snode_t *target = *tos;
    *info = target->info;
    *tos = target->next;
    free(target);
    return 1;
}

void enqueue(qnode_t **front, qnode_t **rear, int info){
    qnode_t *new = malloc(sizeof(qnode_t));
    if (!new) return;
    new->info = info;

    if (!*rear) *front = *rear = new;
    else{
        (*rear)->next = new;
        *rear = new;
    }
}

int dequeue(qnode_t **front, qnode_t **rear, int *info){
    if (!*front) return 0;

    qnode_t *target = *front;
    *info = target->info;
    
    if (*front == *rear) *front = *rear = NULL;
    else *front = target->next;
    free(target);
    return 1;
}

int ulaz(snode_t **ulaznice, qnode_t **studenti_f, qnode_t **studenti_r, int n){
    int curr_st, curr_ul, usluzeni = 0, neuspjesno = 0;
    while (dequeue(studenti_f, studenti_r, &curr_st) && pop(ulaznice, &curr_ul) && neuspjesno < n){
        if (curr_st == curr_ul) usluzeni++;
        else{
            neuspjesno++;
            enqueue(studenti_f, studenti_r, curr_st);
            push(ulaznice, curr_ul);
        }
    }

    return usluzeni;
}

int main(void){

    snode_t *ulaznice = NULL;
    qnode_t *studenti_f = NULL, *studenti_r = NULL;

    push(&ulaznice, 1);
    push(&ulaznice, 1);
    push(&ulaznice, 2);
    push(&ulaznice, 2);

    enqueue(&studenti_f, &studenti_r, 1);
    enqueue(&studenti_f, &studenti_r, 2);
    enqueue(&studenti_f, &studenti_r, 1);
    enqueue(&studenti_f, &studenti_r, 2);

    printf("Broj usluzenih studenata: %d\n", ulaz(&ulaznice, &studenti_f, &studenti_r, 3));

    return 0;
}