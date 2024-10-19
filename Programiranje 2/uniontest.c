#include <stdio.h>
#include <stdlib.h>

typedef union item{
    struct {
        unsigned char id;
        unsigned char type;
        unsigned char value;
    };
    unsigned int code;
} ITEM;

int main(void)
{
    ITEM i;
    i.id = 0x10;
    i.type = 0x11;
    i.value = 0x12;

    printf("%x\n", i.code);
    i.code = 0x707172;
    printf("%x %x %x\n", i.id, i.type, i.value);
    return 0;
}
