/*
* Neka je dat tip 'FILM'. Potrebno je definisati tip CVOR kojim se reprezentuje čvor stabla binarne pretrage, kod kojeg je
* informacioni sadržaj podatak tipa FILM. Neophodno je implementirati sljedeće funkcije za binarno stablo pretrage:
*     - dodavanje podataka o novom filmu u binarno stablo pretrage, tako da je kriterijum pri
*     dodavanju novog filma u stablo naziv filma (ukoliko film sa navedenim nazivom već postoji u
*     binarnom stablu pretrage vrši se ažuriranje svih atributa postojećeg sa vrijednostima novog
*     filma)
* 
*     - pretraživanje binarnog stabla pretrage po nazivu filma (ukoliko čvor sa određenim nazivom
*     filma ne postoji u binarnom stablu pretrage vratiti vrijednost 0, a u suprotnom vratiti adresu
*     informacionog sadržaja tj. filma koji odgovara po nazivu)
* 
*     - brisanje čvora binarnog stabla pretrage po nazivu filma (ukoliko čvor sa određenim nazivom
*     filma ne postoji u binarnom stablu pretrage vratiti vrijednost 0, a u suprotnom vratiti vrijednost
*     1 ukoliko je čvor uspješno obrisan)
* 
*     - formatirani ispis podataka o svim filmovima na standardni izlaz, ali tako da su filmovi sortirani
*     po nazivu u rastućem redoslijedu
* 
*     - brisanje svih čvorova binarnog stabla pretrage
* 
* Korisniku se u glavnom programu prikazuje meni putem kojeg može da testira rad prethodno navedenih
* funkcionalnosti.
* 
* Napomena: naziv filma može biti case insensitive (pri tome nazivi “Artificial Intelligence” i
* “ARTIFICIAL INTELLIGENCE” predstavljaju isti naziv filma).
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define nullptr NULL
#define WIPE_ROWS 100

typedef struct film{
    char naziv[64];
    char zanr[16];
    char reziser[32];
    char glumci[512];
    int godina;
} FILM;

typedef struct node{
    FILM info;
    struct node *left, *right;
} NODE;

// Funkcije iz zadatka:
NODE* bst_add(NODE *root, FILM info);
NODE* bst_search(NODE *root, const char *key);
NODE* bst_delete(NODE *root, const char *key);
void write(NODE *root, FILE *stream, void (*write_one)(FILM, FILE *));
void delete_tree(NODE *root);

// Meni funkcije:
void showmenu(char *input);
void wipe(unsigned n);
void write_handler(NODE *root);
void add_handler(NODE **root_ptr);
void delete_handler(NODE **root_ptr);
void find_handler(NODE *root);

// Pomocne funkcije:
NODE* new_node(FILM info);
void write_one(FILM film, FILE *stream);
int ci_strcmp(const char *string1, const char *string2); // case-insensitive strcmp

/* Testkejsovi
    FILM f1 = {"Film1", "Komedija", "Quentin Tarantino", "A.D, B.J, K.H, J.J.", 2014};
    FILM f2 = {"Film3", "Triler", "Steven Spielberg", "R.N, J.I, I.I.", 2014};
    FILM f3 = {"Film2", "Horor", "Jason Blum", "N.N, J.K, R.R.", 1998};
    FILM f4 = {"Film9", "Drama", "Clint Eastwood", "V.V, I.N.", 1954};
    FILM films[4] = {f1, f2, f3, f4};
    for (int i = 0; i < 4; i++) root = bst_add(root, films[i]);
*/

int main(void){
    NODE *root = nullptr;
    char user_input[16];

    do{
        showmenu(user_input);
        switch(user_input[0]){
            case 'i': write_handler(root); break;
            case 'd': add_handler(&root); break;
            case 'b': delete_handler(&root); break;
            case 'p': find_handler(root); break;
            default: break;
        }
    } while (user_input[0] != '0');

    delete_tree(root);
    printf("Kraj rada.\n");
    return 0;
}

NODE* bst_add(NODE *root, FILM info){
    if (!root) return new_node(info);

    int cmp = ci_strcmp(info.naziv, root->info.naziv);
    if (cmp < 0) root->left = bst_add(root->left, info);
    else if (cmp > 0) root->right = bst_add(root->right, info);
    else{ // ako smo naisli na isti
        root->info = info;
        return root;
    }
}

NODE* bst_search(NODE *root, const char *key){
    if (!root) return nullptr;

    int cmp = ci_strcmp(key, root->info.naziv);
    if (!cmp) return root;
    else{
        if (cmp < 0) return bst_search(root->left, key);
        if (cmp > 0) return bst_search(root->right, key);
    }
}

NODE* bst_delete(NODE *root, const char *key){
    if (!root) return nullptr;

    int cmp = ci_strcmp(key, root->info.naziv);
    if (cmp < 0) root->left = bst_delete(root->left, key);
    else if (cmp > 0) root->right = bst_delete(root->right, key);
    else{ // cvor pronadjen
        if (!root->left && !root->right) { free(root); return nullptr; } // cvor za brisanje nema djece
        else if (!root->left) { NODE *child = root->right; free(root); return child; } // nedostaje mu samo lijevo dijete
        else if (!root->right) { NODE *child = root->left; free(root); return child; } // nedostaje mu samo desno dijete
        else{ // ima oba djeteta
            NODE *max = root->left;
            while (max->right) max = max->right;
            root->info = max->info;
            root->left = bst_delete(root->left, max->info.naziv);
        }
    }
    return root;
}

void write(NODE *root, FILE *stream, void (*write_one)(FILM, FILE *)){
    if (root){
        write(root->left, stream, (*write_one));
        (*write_one)(root->info, stream);
        write(root->right, stream, (*write_one));
    }
}

void delete_tree(NODE *root){
    if (root){
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}

void showmenu(char *input){
    printf("Opcije:\n");
    printf("    [i] Ispisi\n");
    printf("    [d] Dodaj\n");
    printf("    [b] Brisi\n");
    printf("    [p] Pronadji\n");
    printf("    [0] Kraj\n");
    printf("Izbor: "); scanf("%s", input);
    wipe(WIPE_ROWS);
}

void wipe(unsigned n) { for (unsigned i = 0; i < n; i++) printf("\n"); }

void write_handler(NODE *root){
    if (!root) {
        printf("\nLista je prazna.\n");
        return;
    }
    printf("\nLista filmova:\n");
    write(root, stdout, write_one);
}

void add_handler(NODE **root_ptr){
    FILM f;
    printf("Unesi podatke o filmu:\n");
    printf("    Naziv: "); scanf("%s", f.naziv);
    printf("    Zanr: "); scanf("%s", f.zanr);
    printf("    Reziser: "); scanf("%s", f.reziser);
    printf("    Glumci: "); scanf("%s", f.glumci);
    printf("    Godina: "); scanf("%d", &f.godina);
    *root_ptr = bst_add(*root_ptr, f);
}

void delete_handler(NODE **root_ptr){
    char key[64];
    printf("    \nNaziv filma za brisanje: "); scanf("%s", key);

    int exists = bst_search(*root_ptr, key) != nullptr;
    if (!exists) printf("Film '%s' nije pronadjen.\n", key);
    else{
        *root_ptr = bst_delete(*root_ptr, key);
        printf("Uspjesno obrisano.\n");
    }
}

void find_handler(NODE *root){
    char key[64];
    printf("    \nNaziv filma za pretragu: "); scanf("%s", key);

    NODE* search_res = bst_search(root, key);
    if (!search_res) printf("Film '%s' ne postoji na listi.\n", key);
    else{
        printf("Pronadjeni film:\n");
        write_one(search_res->info, stdout);
    }
}

NODE* new_node(FILM info){
    NODE *new = malloc(sizeof(NODE));
    if (!new) return nullptr;

    new->info = info;
    new->left = new->right = nullptr;
    return new;
}

void write_one(FILM film, FILE *stream){
    fprintf(stream, "[%d] %s (%s) - %s | %s\n", film.godina, film.naziv, film.zanr, film.reziser, film.glumci);
}

void string_tolower(char *string){
    int i = 0;
    char *c;
    while(c = &string[i], string[i]){
        *c = tolower(*c);
        i++;
    }
}

int ci_strcmp(const char *string1, const char *string2){
    char *string1_lower = calloc(strlen(string1) + 1, sizeof(char));
    char *string2_lower = calloc(strlen(string2) + 1, sizeof(char));
    strcpy(string1_lower, string1);
    strcpy(string2_lower, string2);
    string_tolower(string1_lower); string_tolower(string2_lower);
    int ret = strcmp(string1_lower, string2_lower);
    free(string1_lower);
    free(string2_lower);
    return ret;
}