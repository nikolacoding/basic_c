// - Napisati program u kojem treba:
//      definisati tip ARTIKAL kojim se reprezentuje artikal čiji su atributi: šifra (cijeli broj u opsegu 00000-99999, koji se uvijek ispisuje kao 5-cifreni podatak), naziv, količina i cijena,
//      definisati tip CVOR kojim se reprezentuje čvor dvostruko povezane liste,
//      definisati funkciju koja dodaje podatke o novom artiklu u listu tako da je poredak elemenata u listi uvijek u rastućem redoslijedu po šifri,
//      definisati funkciju koja omogućava pretraživanje liste po šifri,
//      definisati funkciju koja formatirano ispisuje podatke o svim artiklima,
//      definisati funkciju koja omogućava brisanje podataka o artiklu po šifri,
//      definisati funkciju koja briše listu,
//      definisati funkciju koja omogućava učitavanje podataka o artiklu,
//      - u glavnom programu prikazivati meni prema kojem korisnik može da vrši:
//           dodavanje podataka o novom artiklu,
//           ažuriranje podataka,
//           brisanje podataka,
//           prikaz podataka o svim artiklima,
//           pretraživanje podataka po šifri.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nullptr NULL // C++ navika
#define SIFRA_MAX 99999 // 00000 - 99999
#define WIPE_ROWS 100

#define STATE_RUNNING 1
#define STATE_EXIT 0

struct artikal{
    int sifra;
    char naziv[16];
    double kolicina, cijena;
};

struct node{ // dvostruko ulancana lista sa podatkom tipa ARTIKAL
    struct artikal info;
    struct node *left, *right;
};

// Rad sa (dvostruko ulancanom) listom artikala
int add_node_ordered(struct node **head, struct artikal info); // rastuce
int delete_node(struct node **head, int target);
struct node* find_node(struct node *head, int key); // sekvencijalna pretraga prema sifri
void delete_list(struct node **head);
void ispisi_listu(struct node *head, FILE *stream);
void definisi_artikal(struct artikal *artikal_ptr);
void azuriraj_artikal(struct node *head, int key);

// Meni
void ispisi_meni();
void wipe(unsigned n) { for (unsigned i = 0; i < n; i++) printf("\n"); }

int main(void){
    int choice;
    struct node *list = nullptr;
    
    enum state_e { RUNNING = 1, EXIT = 0 };
    int state = RUNNING;

    struct artikal art;
    int target;

    while (state == RUNNING){
        ispisi_meni();
        scanf("%d", &choice);
        wipe(WIPE_ROWS);
        switch(choice){
            case 1: // novi artikal
                definisi_artikal(&art);
                add_node_ordered(&list, art);
            break;
            case 2: // azuriraj postojeci artikal
                printf("Sifra artikla za azuriranje: ");
                scanf("%d", &target);
                azuriraj_artikal(list, target);
            break; 
            case 3: // obrisi artikal
                printf("Sifra artikla za brisanje: ");
                scanf("%d", &target);
                delete_node(&list, target);
            break;
            case 4: // detaljne informacije o svim artiklima
                ispisi_listu(list, stdout);
            break; 
            case 5: // pronadji artikal
                printf("Sifra artikla za pronaci: ");
                scanf("%d", &target);
                struct node *search_res = find_node(list, target);
                if (!search_res) printf("Artikal sa sifrom '%d' nije pronadjen.\n", target);
                else{
                    printf("Pronadjen je artikal sa sifrom '%d':\n", target);
                    printf("%05d %s | %.1lf x %.2lf\n", art.sifra, art.naziv, art.kolicina, art.cijena);
                }
            break;
            case 0: // kraj/izlaz
                state = EXIT;
            break; 
            default: printf("Opcija nije validna.\n");
        }
    }
    delete_list(&list);
    return 0;
}

int add_node_ordered(struct node **head, struct artikal info){
    struct node *new = malloc(sizeof(struct node));
    if (!new) return 0;

    new->info = info;
    new->left = new->right = nullptr;
    if (!*head){ *head = new; return 1; }

    struct node *curr = *head, *prev = nullptr;
    while (curr){
        struct artikal curr_art = curr->info;

        if (new->info.sifra <= curr_art.sifra){ // ako umecemo u sredinu ili na pocetak
            curr->left = new;
            new->right = curr;
            new->left = prev;
            if (prev) prev->right = new;
            else *head = new;
            return 1;
        }

        prev = curr;
        curr = curr->right;
    }
    // ako umecemo na kraj
    prev->right = new;
    new->left = prev;
    return 1;
}

int delete_node(struct node **head, int target){
    struct node *search_res = find_node(*head, target);
    if (!search_res) return 0;
    struct node *L = search_res->left, *R = search_res->right;
    if (L && R){
        L->right = search_res->right;
        R->left = search_res->left;
    }
    else if (L) L->right = nullptr; // ako brisemo posljednji element
    else if (R) R->left = nullptr, *head = R; // ako brisemo prvi element
    if (!L && !R) *head = nullptr; // ako brisemo zadnji element
    free(search_res);
    return 1;
}

void delete_list(struct node **head){
    if (!*head) return; // prazna lista
    while (*head){
        struct node *target = *head;
        *head = (*head)->right;
        free(target);
    }
}

struct node* find_node(struct node *head, int key){
    while (head){
        if (head->info.sifra == key) return head;
        head = head->right;
    }
    return nullptr;
    // sekvencijalna implementacija, moguca je i binarna ali mi se time nikako ne da baviti trenutno
}

void ispisi_listu(struct node *head, FILE *stream){
    if (!head){
        printf("Lista je prazna.\n");
        return;
    }
    
    fprintf(stream, "==========================================\n");
    fprintf(stream, "%-5s %16s | %-17s\n", "SIFRA", "NAZIV", "KOLICINA x CIJENA");
    while (head){
        struct artikal art = head->info;
        fprintf(stream, "%05d %16s | %.1lf x %.2lf\n", art.sifra, art.naziv, art.kolicina, art.cijena);
        head = head->right;
    }
    fprintf(stream, "==========================================\n");
}

void definisi_artikal(struct artikal *artikal_ptr){


    static int i = 1;

    printf("Podaci o %d. artiklu:\n", i++);
    printf("    Sifra: "); scanf("%d", &artikal_ptr->sifra);
    printf("    Naziv: "); scanf("%s", artikal_ptr->naziv);
    printf("    Kolicina: "); scanf("%lf", &artikal_ptr->kolicina);
    printf("    Cijena: "); scanf("%lf", &artikal_ptr->cijena);
}

void azuriraj_artikal(struct node *head, int key){
    struct node *target = find_node(head, key);
    if (!target) return;
    
    printf("Azuriranje podataka o artiklu sifre %d:\n", target->info.sifra);
    printf("    Naziv: "); scanf("%s", target->info.naziv);
    printf("    Kolicina: "); scanf("%lf", &target->info.kolicina);
    printf("    Cijena: "); scanf("%lf", &target->info.cijena);
}

void ispisi_meni(){
    printf("Opcije:\n");
    printf("    [1] novi artikal\n");
    printf("    [2] azuriraj postojeci artikal\n");
    printf("    [3] obrisi artikal\n");
    printf("    [4] detaljne informacije\n");
    printf("    [5] pronadji artikal\n");
    printf("    [0] kraj\n");
    printf("Izbor: ");
}