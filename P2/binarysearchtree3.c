/*
* Napisati program u kojem treba sa standardnog ulaza učitati podatke za n artikala i binarno ih upisati u datoteku 
* artikli.dat. Atributi artikla su šifra (cijeli broj u opsegu 00000-99999, koji se uvijek ispisuje 
* kao 5-cifreni podatak), naziv, količina i cijena. Pored toga, potrebno je kreirati i održavati look-up tabelu 
* (stablo binarnog pretraživanja), koju, na kraju, treba binarno upisati u datoteku look-up.dat.
* 
* Napisati program u kojem treba u datoteci artikli.dat, pronaći podatke o artiklu čija se šifra unosi sa 
* standardnog ulaza, korištenjem odgovarajuće look-up tabele, te ispisati podatke o artiklu na standardni izlaz.
*
* ^ Oba ova cemo uraditi odjednom.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nullptr NULL

struct artikal{
    unsigned sifra;
    char naziv[21];
    double kolicina, cijena;
};

struct node{
    struct artikal info;
    struct node *left, *right;
};

struct artikal* definisi_artikle(unsigned n);
struct node* new_node(struct artikal info);
struct node* bst_add_one(struct node *root, struct artikal info);
void bst_add_array(struct node **root, struct artikal* array, unsigned n);
struct node* bst_find(unsigned key, struct node *root);
void tree_to_file(struct node *root, FILE *stream);
void file_to_tree(struct node **root, FILE *stream);
void bst_delete(struct node *root);

void print_one(struct artikal art);
void print_tree(struct node *root);

#define MAX 10
int main(void){
    unsigned n;
    const char filename[21] = "artikli.dat"; // binarno kodovana look-up tabela
    FILE *stream;

    if (stream = fopen(filename, "a")){
        do {
            printf("Unesi broj artikala za unos (0 - 10): ");
            scanf("%u", &n);
        } while (n > MAX);
        
        struct node *root = nullptr;
        struct artikal *niz = definisi_artikle(n);
        bst_add_array(&root, niz, n);
        tree_to_file(root, stream);
        printf("Upisali smo u datoteku.");

        free(niz);
        bst_delete(root);
        fclose(stream);
    } else printf("Datoteka '%s' se ne moze otvoriti pisanje.\n", filename);

    if (stream = fopen(filename, "r")){
        struct node *root = nullptr;
        struct node *search_res = nullptr;
        unsigned search_key;
        printf("Unesi sifru trazenog artikla: "); scanf("%u", &search_key);
        file_to_tree(&root, stream);
        print_tree(root);
        if (search_res = bst_find(search_key, root)){
            printf("Pronadjen je artikal sifre '%u': ", search_key);
            print_one(search_res->info);
        }
        else printf("U datoteci ne mozemo pronaci artikal sifre '%u'.\n", search_key);

        bst_delete(root);
        fclose(stream);
    } else printf("Datoteka '%s' se ne moze otvoriti za citanje.\n", filename);
    return 0;
}

struct artikal* definisi_artikle(unsigned n){
    struct artikal *ret = malloc(n * sizeof(struct artikal));
    if (!ret) return nullptr;

    for (unsigned i = 0; i < n; i++){
        struct artikal *curr = &ret[i];
        
        printf("\nPodaci o %u. artiklu:\n", i + 1);
        printf("    Sifra: "); scanf("%u", &curr->sifra);
        printf("    Naziv: "); scanf("%s", curr->naziv);
        printf("    Kolicina: "); scanf("%lf", &curr->kolicina);
        printf("    Cijena: "); scanf("%lf", &curr->cijena);
    }
    return ret;
}

struct node* new_node(struct artikal info){
    struct node *new = malloc(sizeof(struct node));
    if (!new) return nullptr;

    new->info = info;
    new->left = new->right = nullptr;
    return new;
}

struct node* bst_add_one(struct node *root, struct artikal info){
    if (!root) return new_node(info);

    if (info.sifra > root->info.sifra) root->right = bst_add_one(root->right, info);
    else if (info.sifra < root->info.sifra) root->left = bst_add_one(root->left, info);
    else return root;
}

void bst_add_array(struct node **root, struct artikal* array, unsigned n){
    for (unsigned i = 0; i < n; i++)
        *root = bst_add_one(*root, array[i]);
}

struct node* bst_find(unsigned key, struct node *root){
    if (!root) return nullptr;

    if (root->info.sifra == key) return root;
    else if (key > root->info.sifra) return bst_find(key, root->right);
    else if (key < root->info.sifra) return bst_find(key, root->left);
}

void tree_to_file(struct node *root, FILE *stream){
    if (root){
        tree_to_file(root->left, stream);
        fwrite(&root->info, 1, sizeof(struct artikal), stream);
        tree_to_file(root->right, stream);
    }
}

void file_to_tree(struct node **root, FILE *stream){
    struct artikal art;
    while (fread(&art, 1, sizeof(struct artikal), stream))
        *root = bst_add_one(*root, art);
}

void bst_delete(struct node *root){
    if (root){
        bst_delete(root->left);
        bst_delete(root->right);
        free(root);
    }
}

void print_one(struct artikal art){
    printf("%05u | %s %.1lf x %.2lf\n", art.sifra, art.naziv, art.kolicina, art.cijena);
}

void print_tree(struct node *root){
    if (root){
        print_tree(root->left);
        print_one(root->info);
        print_tree(root->right);
    }
}