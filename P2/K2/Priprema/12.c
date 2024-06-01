/*
*   Neka je su dati tipovi 'GRAD' koji reprezentuje jedan grad i 'GRAF' koji reprezentuje neusmjeren tezinski graf
*   predstavljen matricom susjednosti gdje tezine izmedju povezanih cvorova oznacvaju udaljenost izmedju datih
*   gradova.
*   
*   Napisati funkciju koja za dati graf gf i grad gr ispisuje najkraće rastojanje od grada gr do svih dostupnih gradova. 
*   Za svaki dostupni grad ispisati naziv i koja je najkraća udaljenost od zadatog grada. 
*   Prototip funkcije je: void dostupni(GRAF gf, GRAD gr);
*/

#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef struct grad{
    char naziv[101];
} GRAD;

typedef struct graf{
    int n;
    GRAD gradovi[100];
    int ms[100][100];
} GRAF;

int minDist(GRAF *g, int dist[], int processed[]){
    int min = INT_MAX;
    int min_i;

    for (int v = 0; v < g->n; v++)
        if (!processed[v] && dist[v] <= min)
            min = dist[v], min_i = v;

    return min_i;
}

int get_index(GRAF *g, GRAD grad){
    for (int i = 0; i < g->n; i++)
        if (!strcmp(grad.naziv, g->gradovi[i].naziv))
            return i;
}

void dostupni(GRAF gf, GRAD gr){ // Dijkstra algoritam
    int start = get_index(&gf, gr);
    int dist[100];
    int processed[100] = {0};

    for (int i = 0; i < gf.n; i++)
        dist[i] = INT_MAX;

    dist[start] = 0;
    
    for (int i = 0; i < gf.n; i++){
        int u = minDist(&gf, dist, processed);

        for (int v = 0; v < gf.n; v++){
            if (!processed[v] && gf.ms[u][v] && dist[u] != INT_MAX && dist[u] + gf.ms[u][v] < dist[v])
                dist[v] = dist[u] + gf.ms[u][v];
        }
    }

    printf("Najkraca udaljenost od '%s' do svih ostalih gradova:\n", gr.naziv);
    for (int i = 0; i < gf.n; i++){
        if (i != start) printf("%s [%d]\n", gf.gradovi[i].naziv, dist[i]);
    }
}

/* Matrica susjednosti:

    BLK  BIJ  JAJ  SIP  SPL  TRE
BLK      240  072  080  000  000
BIJ 240       000  300  000  000
JAJ 072  000       021  190  000
SIP 080  300  021       200  282  
SPL 000  000  190  200       243
TRE 000  000  000  282  243  

*/

int main(void){
    GRAD BLK = {"Banja Luka"};
    GRAD BIJ = {"Bijeljina"};
    GRAD JAJ = {"Jajce"};
    GRAD SIP = {"Sipovo"};
    GRAD SPL = {"Split"};
    GRAD TRE = {"Trebinje"};

    GRAF g = {6, {BLK, BIJ, JAJ, SIP, SPL, TRE},
        {
            {0, 240, 72, 80, 0, 0},
            {240, 0, 0, 300, 0, 0},
            {72, 0, 0, 21, 190, 0},
            {80, 300, 21, 0, 200, 282},
            {0, 0, 190, 200, 0, 243},
            {0, 0, 0, 282, 243, 0}
        }
    };

    dostupni(g, JAJ);

    return 0;
}