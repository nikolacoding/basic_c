#include <stdio.h>
#include <stdlib.h>

#define BUFFMAX 6
#define NL "\n"

typedef struct kruzniBafer{
    char infos[BUFFMAX];
    int f, r;
} RED;

int isEmpty(RED *kb) { return kb->f == kb->r; }
int isFull(RED *kb) { return (kb->r + 1) % BUFFMAX == kb->f; }
void pisi(RED *kb);
void debug(RED *kb) { printf("f:%d | r:%d\n", kb->f, kb->r); }

int insertNoRewrite(RED *kb, char info){
    if (isFull(kb)) return 0;

    kb->infos[kb->r] = info;
    kb->r = (kb->r + 1) % BUFFMAX;
    return 1;
}

int insertRewrite(RED *kb, char info){
    if (isFull(kb))
        kb->f = (kb->f + 1) % BUFFMAX;
    
    kb->infos[kb->r] = info;
    kb->r = (kb->r + 1) % BUFFMAX;
    return 1;
}

int delete(RED *kb, char *info){
    if (isEmpty(kb)) return 0;

    *info = kb->infos[kb->f];
    kb->f = (kb->f + 1) % BUFFMAX;
    return 1;
}
 
int main(void)
{
    RED kb;
    kb.f = kb.r = 0;

    char retval;

    debug(&kb); // f:0, r:0
    insertNoRewrite(&kb, 'A');
    insertNoRewrite(&kb, 'B');
    insertNoRewrite(&kb, 'C');
    insertNoRewrite(&kb, 'D');
    insertNoRewrite(&kb, 'E');
    pisi(&kb); // f:0, r:5

    delete(&kb, &retval);
    pisi(&kb); // f:1, r:5
    printf("RV: %c\n", retval);

    delete(&kb, &retval);
    pisi(&kb); // f:2, r:5
    printf("RV: %c\n", retval);

    insertNoRewrite(&kb, 'F');
    insertNoRewrite(&kb, 'G');
    pisi(&kb); // f:2, r:1 <== susjedne lokacije sto znaci da je bafer pun

    insertNoRewrite(&kb, 'H'); // ne moze se upisati bez prepisa jer je bafer pun
    insertRewrite(&kb, 'I');
    pisi(&kb); // f:3, r:2
    
    delete(&kb, &retval);
    pisi(&kb);
    printf("RV: %c\n", retval);

    insertNoRewrite(&kb, 'J');
    insertRewrite(&kb, 'K');
    pisi(&kb);

    // _ _ _ _ _ _
    // 5 0 1 2 3 4

    // _ | A B C D E
    // r   f         
    // f:0, r:5

    // _ _ _ | C D E
    // r       f    
    // f:2, r:5

    // ->F G _ | C D E->
    //       r   f        
    // f:2, r:1

    // ->F G I _ | D E->
    //         r   f        
    // f:3, r:2

    // ->F G I _ _ | E->
    //         r     f        
    // f:4, r:2

    // ->F G I J _ | E->
    //           r   f        
    // f:4, r:3

    // -> | F G I J K _->
    //      f         r          
    // f:5, r:4

    return 0;
}

void pisi(RED *kb){
    int i = kb->f;
    int j = kb->r;

    while (i != j){
        printf("%c ", kb->infos[i]);
        i = (i + 1) % BUFFMAX;
    }
    printf(NL);
    debug(kb);
}