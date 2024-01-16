#include <stdio.h>
#include <string.h>

typedef struct Books{

    char title[50];
    char author[50];
    char subject[100];
    int id;

} Book;

void modifyBook(Book *b, char modType){

    char _content[20];
    int _num;

    switch(modType){

        case 't':
            printf("Mijenjas naslov na: ");
            scanf("%s", &_content);
            strcpy(b->title, _content);
            break;
        case 'a':
            printf("Mijenjas autora na: ");
            scanf("%s", &_content);
            strcpy(b->author, _content);
            break;
        case 's':
            printf("Mijenjas sadrzaj na: ");
            scanf("%s", &_content);
            strcpy(b->subject, _content);
            break;
        case 'i':
            printf("Mijenjas ID na: ");
            scanf("%d", &_num);
            b->id = _num;
            break;
        case 'p':
            printf("----\n,,%s''\n- %s\nKratak sadrzaj: %s\nID: %d\n----", b->title, b->author,
            b->subject, b->id);
            break;
        case 'q':
            printf("\nQuitting...\n");
            break;
        default:
            printf("Error. ");
            break;
    }
}

int main(){

    int done = 0;
    char temp[100];
    char sC;

    Book lektira;

    strcpy(lektira.title, "Jezeva kucica");
    strcpy(lektira.author, "Branko Copic");
    strcpy(lektira.subject, "Bilo jednom davno...");
    lektira.id = 1441;

    printf("p - print\nt - promijeni naslov\na - promijeni autora\ns - promijeni kratak sadrzaj\nq - quit\n\n");

    while (!done){
        printf("Select: ");
        scanf("%s", &sC);

        if (sC == 'q')
            done = 1;

        modifyBook(&lektira, sC);
        printf("\n\n\n");
    }
    return 0;
}
