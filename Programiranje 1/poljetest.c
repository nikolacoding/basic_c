#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Player
{
    int locationX;
    int locationY;
} player;

struct Field
{
    int height;
    int width;
} field;

struct Coin
{
    int locationX;
    int locationY;
    int collected;
} coin;

void move(struct Player *p, struct Field *f, struct Coin *c, char choice, int *quit)
{
    switch (choice)
    {
    case 'd':
        p->locationX += 1;
        break;
    case 'a':
        p->locationX -= 1;
        break;
    case 's':
        p->locationY += 1;
        break;
    case 'w':
        p->locationY -= 1;
        break;
    case 'q':
        *quit = 1;
        break;
    }

    if (p->locationX < 0)
        p->locationX = f->width - 1;

    if (p->locationX > f->width - 1)
        p->locationX = 0;

    if (p->locationY < 0)
        p->locationY = f->height - 1;

    if (p->locationY > f->height - 1)
        p->locationY = 0;

    if (p->locationX == c->locationX && p->locationY == c->locationY)
    {
        c->collected++;
        while (p->locationX == c->locationX || p->locationY == c->locationY)
        {
            c->locationX = rand() % f->width;
            c->locationY = rand() % f->height;
        }
    }
}

void drawField(struct Player *p, struct Field *f, struct Coin *c)
{
    static int runtime = 0;

    if (!runtime)
        printf("      w - up\na - left  d - right\n      s - down\n\nq - quit\n");
    else
    {
        for (int i = 0; i < 64; i++)
        {
            printf("\n");
        }
    }

    for (int y = 0; y < f->height; y++)
    {
        printf("\n");

        for (int x = 0; x < f->width; x++)
        {
            if (p->locationX == x && p->locationY == y)
                printf("X ");
            else if (c->locationX == x && c->locationY == y)
                printf("+ ");
            else
                printf(". ");
        }
    }

    runtime++;
}

int main()
{
    srand(time(NULL));

    int done = 0;
    char choice;

    int fieldWidthInit;
    int fieldHeightInit;

    struct Player *ptrP = &player;
    struct Field *ptrF = &field;
    struct Coin *ptrC = &coin;

    ptrP->locationX = 0;
    ptrP->locationY = 0;

    do
    {
        printf("Unesi polje: ");
        scanf("%d %d", &fieldWidthInit, &fieldHeightInit);
    } while (fieldWidthInit < 1 || fieldWidthInit < 1);

    ptrF->width = fieldWidthInit;
    ptrF->height = fieldHeightInit;
    ptrC->locationX = rand() % ptrF->width;
    ptrC->locationY = rand() % ptrF->height;
    ptrC->collected = 0;
    drawField(ptrP, ptrF, ptrC);

    while (!done)
    {

        printf("\nCoins: %d", ptrC->collected);
        printf("\nMove: ");
        scanf("%s", &choice);

        move(ptrP, ptrF, ptrC, choice, &done);
        drawField(ptrP, ptrF, ptrC);
    }
}