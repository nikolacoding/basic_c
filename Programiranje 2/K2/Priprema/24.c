/*
*   Realizovati sljedece za binarno stablo pretrage informacionog sadrzaja tipa string (char *):
*   
*   1.1) funkciju koja dodaje cvor u BST u leksifografskom poretku
*   1.2) funkciju koja obilazi stablo po dubini (DFS) i ispisuje sadrzaj stabla u rastucem poretku
*   1.3) funkciju koja obilazi stablo po sirini (BFS) i ispisuje sav sadrzaj
*   2) funkciju koja DFS-om pronalazi (po inf. sadrzaju) i brise cvor iz BST-a
*   3) funkciju koja obilazi BST i prekida obilazenje kada naidje na prvi cvor ciji informacioni sadrzaj ispunjava
*   kriterijum druge funkcije ciji pokazivac je naveden kao argument ove funkcije, te vraca informacioni sadrzaj
*   (dakle ne pokazivac na cvor, vec string u njemu)
*   4) funkciju koja provjerava da li string pocinje velikim slovom
*   5) 'vrhovnu' funkciju koja objedinjuje funkcije navedene pod 2, 3 i 4 na sljedeci nacin:
*       - obilazi BST i pronalazi sve cvorove koje ispunjavaju uslov pod 4, te ih brise
*       - s obzirom da se obilazak vrsi do momenta kada je pronadjen prvi cvor koji ispunjava uslov,
*       obilazak treba vrsiti sve dok u BST-u jos uvijek postoje takvi cvorovi i prestati kada po prvi put
*       obilazak ne uspije da pronadje/vrati neki cvor koji ispunjava uslov
*   
*   6) glavnu funkciju u kojoj se kreira BST sa sljedecim informacionim sadrzajem: 
*       - "doboj", "Gradiska", "banja luka", "Sarajevo", "brcko", "bijeljina", "Jajce", "Vitez"
*       koriscenjem funkcijama pod 1.2 i 1.3 ispisuje se originalno stablo, te poziva funkcija pod 5, te se ispisuje
*       modifikovano stablo
*   
*   Napomene: 
*   - implementovati DFS i brisanje rekurzivno, BFS iterativno
*   - koristiti string literale za BST
*   - koristiti ulancanu reprezentaciju svih neophodnih struktura
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node{ // standardna implementacija binarnog stabla
    char info[64];
    struct tree_node *left, *right;
} tnode_t;

typedef struct queue_node{ // implementacija reda koristeci jednostruko ulancanu listu
    tnode_t *info;
    struct queue_node *next;
} qnode_t;

void enqueue(qnode_t **front, qnode_t **rear, tnode_t *info){
    qnode_t *new = malloc(sizeof(qnode_t));
    if (!new) return;
    new->info = info;

    if (!*rear) *front = *rear = new;
    else{
        (*rear)->next = new;
        *rear = new;
    }
}

int dequeue(qnode_t **front, qnode_t **rear, tnode_t **info){
    qnode_t *target = *front;
    if (!target) return 0;

    *info = target->info;
    if (*front == *rear) *front = *rear = NULL;
    else *front = target->next;
    free(target);
    return 1;
}

void ispisi_dfs(tnode_t *root){ // in-order DFS obilazak i ispis
    if (root){
        ispisi_dfs(root->left);
        printf("%s ", root->info);
        ispisi_dfs(root->right);
    }
}

void ispisi_bfs(tnode_t *root){ // BFS obilazak uz pomoc reda
    if (!root) printf("Stablo je prazno.\n");
    else{
        qnode_t *front = NULL, *rear = NULL;
        enqueue(&front, &rear, root);
        tnode_t *curr;

        while (dequeue(&front, &rear, &curr)){
            printf("%s ", curr->info);
            if (curr->left) enqueue(&front, &rear, curr->left);
            if (curr->right) enqueue(&front, &rear, curr->right);
        }
    }
}

tnode_t* new_node(const char *info){
    tnode_t *new = malloc(sizeof(tnode_t));
    if (!new) return NULL;
    strcpy(new->info, info);
    new->left = new->right = NULL;
    return new;
}

tnode_t* bst_add(tnode_t *root, const char *info){
    if (!root) return new_node(info);

    int cmp = strcmp(info, root->info);
    if (cmp > 0) root->right = bst_add(root->right, info);
    else if (cmp < 0) root->left = bst_add(root->left, info);
    
    return root;
}

tnode_t* bst_delete(tnode_t *root, const char *key){
    if (!root) return NULL;
    int cmp = strcmp(key, root->info);

    if (cmp > 0) root->right = bst_delete(root->right, key);
    else if (cmp < 0) root->left = bst_delete(root->left, key);
    else{
        if (!root->left && !root->right) { free(root); return NULL; }
        else if (!root->left) { tnode_t *target = root->right; free(root); return target; }
        else if (!root->right) { tnode_t *target = root->left; free(root); return target; }
        else{
            tnode_t *max = root->left;
            while (max->right) max = max->right;
            strcpy(root->info, max->info);
            root->left = bst_delete(root->left, max->info);
        }
    }
    return root;
}

void bst_find(tnode_t *root, int (*criteria)(const char *), char **ret, int *v){
    // *v mora biti nula na pocetku
    
    if (root && !*v){
        bst_find(root->left, criteria, ret, v);
        bst_find(root->right, criteria, ret, v);
        if ((*criteria)(root->info)){
            *ret = root->info;
            *v = 1;
        }
    }
}

int starts_with_upper(const char *string){ 
    return (string[0] >= 'A' && string[0] <= 'Z'); 
}

void filter_list(tnode_t **root){
    char *curr = calloc(64, sizeof(char));
    int v;
    while (1){
        v = 0;     
        bst_find(*root, starts_with_upper, &curr, &v);
        if (v) *root = bst_delete(*root, curr);
        else return;
    }

    free(curr);
}

int main(void){
    tnode_t *root = NULL;

    root = bst_add(root, "doboj");
    root = bst_add(root, "Gradiska");
    root = bst_add(root, "banja luka");
    root = bst_add(root, "Sarajevo");
    root = bst_add(root, "brcko");
    root = bst_add(root, "bijeljina");
    root = bst_add(root, "Jajce");
    root = bst_add(root, "Vitez");

    ispisi_dfs(root); printf("\n");
    ispisi_bfs(root); printf("\n");
    filter_list(&root);
    ispisi_dfs(root); printf("\n");
    ispisi_bfs(root); printf("\n");

    return 0;
}