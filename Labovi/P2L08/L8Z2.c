// Potrebno je definisati strukturu kružni bafer koja služi za smještanje prirodnih brojeva, pri čemu je potrebno 
// koristiti sekvencijalnu reprezentaciju bafera bez prepisivanja. U baferu se može nalaziti maksimalno pet elemenata.
//
// Korisniku se prikazuje meni putem kojeg može da vrši:
//    - dodavanje novog elementa u bafer,
//    - uklanjanje elementa iz bafera i
//    - ispis svih elemenata iz bafera na standardnom izlazu.
// Unosom broja 0 korisnik prekida izvršavanje programa, nakon čega se na standardnom izlazu ispisuju svi elementi 
// koji su uneseni tokom izvršavanja programa, ali u obrnutom redoslijedu. Za čuvanje i ispis svih unesenih elemenata 
// koristiti ulančanu reprezentaciju steka (LIFO disciplina pristupa).
//
// Napomena: ukoliko korisnik pokuša da doda novi element u pun bafer ili da ukloni element iz praznog
// bafera potrebno je ispisati poruku upozorenja na standardni izlaz.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6
typedef struct kruzni_bafer{ // kruzni bafer
    int info[MAX];
    int f, r;
} KB;

typedef struct node{ // ulancana reprezentacija steka
    int val;
    struct node *next;
} NODE;

// Operacije sa kruznim baferom
int is_empty(KB *kb){ return kb->f == kb->r; }
int is_full(KB *kb){ return (kb->r + 1) % MAX == kb->f; }
int pisi(KB *kb, int val){
    if (is_full(kb)) return 0;

    kb->info[kb->r] = val;
    kb->r = (kb->r + 1) % MAX;
    return 1;
}

int brisi(KB *kb, int *val){
    if (is_empty(kb)) return 0;

    *val = kb->info[kb->f];
    kb->f = (kb->f + 1) % MAX;
    return 1;
}

// Operacije nad stekom
void push(NODE **tos, int val){
    NODE *new = malloc(sizeof(NODE));
    if (!new) return;
    new->val = val;

    if (!*tos) new->next = NULL;
    else new->next = *tos;

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

// Meni
void showmenu();
void wipe(const int n){ for (int i = 0; i < n; i++) printf("\n"); }

void add_handler(KB *kb, NODE **tos);
void info_handler(KB *kb);
void delete_handler(KB *kb);
void exit_handler(NODE **tos);

#define WIPE_ROWS 100
int main(void){
    KB kb = {{0}, 0, 0};
    NODE *tos = NULL;

    char inputbuffer[8] = "";
    while (inputbuffer[0] != '0'){
        wipe(WIPE_ROWS);
        showmenu();
        fflush(stdin); // ciscenje stdin-a kako unosi iz "unesi bilo sta da nastavis" ne bi curili 
        scanf("%s", inputbuffer);

        char c = inputbuffer[0];
        switch (c){
            case '0': break;
            case 'i': info_handler(&kb); break;
            case 'a': add_handler(&kb, &tos); break;
            case 'd': delete_handler(&kb); break;
            default: printf("Opcija nije validna.\n");
        }
    }

    exit_handler(&tos);
    return 0;
}

void showmenu(){
    printf("Opcije:\n");
    printf("    [i] ispisi\n");
    printf("    [a] dodaj broj\n");
    printf("    [d] obrisi broj\n");
    printf("    [0] izlaz\n");
    printf("Izbor: ");
}

void add_handler(KB *kb, NODE **tos){
    int n;
    do{
        printf("\nUnesi prirodan broj za dodati: ");
        scanf("%d", &n);
    } while(n < 1);
    
    if (pisi(kb, n)) {
        printf("Broj %d uspjesno dodan u bafer. ", n);
        push(tos, n);
    }
    else printf("Nije moguc upis - bafer je pun. "); ;

    printf("Unesi bilo sta da nastavis: "); scanf("%d", &n);
}

void delete_handler(KB *kb){
    int n;
    if (brisi(kb, &n)) printf("Broj %d je uspjesno obrisan iz bafera. ", n);
    else printf("Nije moguce brisanje - bafer je prazan. ");

    printf("Unesi bilo sta da nastavis: "); scanf("%d", &n);
}

void info_handler(KB *kb){
    if (is_empty(kb)) printf("Ispis neuspjesan - bafer je prazan.\n");
    else{
        int curr = kb->f;
        printf("\nBrojevi u baferu: ");
        while (curr != kb->r){
            printf("%d ", kb->info[curr]);
            curr = (curr + 1) % MAX;
        }
        printf("\n");
    }
    int x;
    printf("Unesi bilo sta da nastavis: "); scanf("%d", &x);
}

void exit_handler(NODE **tos){
    if (!*tos) printf("Tokom rada, niti jedan element nije dodan.");
    else{
        int curr;

        printf("Tokom rada su dodani sljedeci elementi: ");
        while (pop(tos, &curr)) printf("%d ", curr);
    }
    printf("\nKraj rada.");
}