// Napisati program koji ucitava broj n te n studenata od kojih se potom pravi ulancana lista. Svaki student
// se sastoji od unikatnog identifikatora [1, n], imena, prezimena i prosjeka. Lista studenata se potom ispisuje
// na standardan izlaz nakon cega se korisniku nude sljedece opcije u zavisnosti od unesenog karaktera:
// 'x' (remove) - uklanjanje studenta sa liste
// 'r' (replace) - zamjena jednog studenta
// 'n' (append) - dodavanje studenta na kraj liste
// 'a' (add) - dodavanje jednog studenta
// '0' (exit) - kraj rada

// Pri izboru opcija 'remove' i 'replace' se od korisnika trazi da unese validan identifikator postojeceg studenta
// nakon cega se taj student uklanja ili mijenja, respektivno. Opcija 'replace' takodje treba da zahtijeva unos
// drugog studenta na mjesto uklonjenog.

// Pri izboru opcije 'append', treba da se trazi unos podataka o novom studentu koji se potom dodaje na kraj liste.

// Pri izboru opcije 'add', treba da se trazi da li se student dodaje prije ili poslije (0/1) studenta ciji
// se identifikator takodje unosi.

// Pri izboru opcije 0, zavrsava se rad.

// Poslije svake radnje, lista studenata treba iznova da se ispise na standardni izlaz.

// Ogranicenja: maksimalno studenata - 15; nije dozvoljeno ucitavati studente u niz bilo kakve vrste.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

typedef struct student {
    int id;
    char ime[21], prezime[21];
    double prosjek;
} STUDENT;

typedef struct node{
    STUDENT info;
    struct node *next;
} NODE;

static int ispisiStudente(const NODE *);
static int wipe();
static int appendNode(NODE **, STUDENT);

static STUDENT unesiStudenta(STUDENT *, const int);

int main(void)
{
    STUDENT st;
    int n, id = 0;
    char choice[64], poruka[64]; strcpy(poruka, "");
    int choice_conv;
    NODE *list = NULL;

    do { fprintf(stdout, "Unesi broj studenata: "); fscanf(stdin, "%d", &n); } while (n < 1 || n > MAX);
    
    fprintf(stdout, "Format: Ime Prezime Prosjek\n");
    for (int i = 0; i < n; i++){
        unesiStudenta(&st, ++id);
        appendNode(&list, st);
    }
    
    enum choices { EXIT = '0', ADD = 'a', REMOVE = 'x', APPEND = 'n', REPLACE = 'r' };

    while (1){
        wipe();
        ispisiStudente(list);
        fprintf(stdout, "Poruka: %s\n", poruka);
        fprintf(stdout, "\nAdd - 'a'\nRemove - 'x'\nAppend - 'n'\nReplace - 'r'\nExit - '0'\n");
        fgets(choice, 64, stdin);

        choice_conv = (int)choice[0];
        if (choice_conv == EXIT) break;
        else if (choice_conv == ADD){
            strcpy(poruka, "Added");
        }
        else if (choice_conv == REMOVE){
            strcpy(poruka, "Removed");
        }
        else if (choice_conv == APPEND){
            unesiStudenta(&st, ++id); appendNode(&list, st);
            strcpy(poruka, "Student uspjesno unesen na kraj liste.");
        }
        else if (choice_conv == REMOVE){
            strcpy(poruka, "Replaced");
        }
        else{
            strcpy(poruka, "Nije validno.");
        }
    }
    return 0;
}

static STUDENT unesiStudenta(STUDENT *st, const int id){
    fprintf(stdout, "[%d] Podaci o studentu: ", id);
    st->id = id;
    fscanf(stdin, "%s %s %lf", st->ime, st->prezime, &st->prosjek);
}

static int appendNode(NODE **list, STUDENT info){
    NODE *tail = (NODE *)malloc(sizeof(NODE)); 
    if (!tail) return 0;
    tail->info = info;
    tail->next = NULL;

    if (!*list) *list = tail;
    else{
        NODE *temp = *list;
        while (temp->next) temp = temp->next;
        temp->next = tail;
    }
    return 1;
}

static int ispisiStudente(const NODE *head){
    do{
        fprintf(stdout, "[%d] %s %s - %.2lf\n", 
        head->info.id, 
        head->info.ime, 
        head->info.prezime,
        head->info.prosjek);
    } while (head, head = head->next);
}

static int wipe(){
    const int n = 100;
    for (int i = 0; i < n; i++) fprintf(stdout, "\n");
}