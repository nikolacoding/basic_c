#include <stdio.h>

struct Person{
    int age;
    int kids;
    char birthDate[10];
};

void updatePerson(struct Person *p, char updateType){
    switch(updateType){
    case 'a':
        printf("Unesi nove godine: ");
        int tempAge;
        scanf("%d", &tempAge);
        p->age = tempAge;
        break;
    case 'p':
        printf("Zoki ima %d godina i %d djece.", p->age, p->kids);
        break;
    default:
        printf("Error. ");
        break;
    }
}

int main(){

    struct Person Zoki;
    int done = 0;
    char uT;

    while (!done){

        printf("Sta hoces da izmjenis Zokiju: ");
        scanf("%s", &uT);
        updatePerson(&Zoki, uT);
    }


    return 0;
}
