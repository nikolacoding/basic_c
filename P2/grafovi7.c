/*
    Skicirati proizvoljan povezan neusmjeren tezinski graf sa 7 cvorova sa informacionim sadrzajem tipa 'char'
    i napisati za njega matricu susjednosti. Prenijeti matricu susjednosti u kod i realizovati minimalno obuhvatno 
    stablo primjenom Primovog algoritma. Ispisati:
        1) matricu susjednosti originalnog grafa
        2) matricu susjednosti MST-a
        3) putanju od 'A' do 'G' originalnog grafa bez obzira na tezinu
        4) putanju od 'A' do 'G' MST-a
*/

/* Proizvoljan graf:
* 
*    A - B - D - E
*      \ | \ | 
*        C   F - G
*
*/

/* Minimalno obuhvatno stablo (MST) proizvoljnog grafa iznad:
* 
*    A   B - D - E
*      \ |   | 
*        C   F - G
*/

/* Matrica susjednosti proizvoljnog grafa:
*        AA  BB  CC  DD  EE  FF  GG
*    A   00  90  20  00  00  00  00
*    B   90  00  30  20  00  100 00
*    C   20  30  00  00  00  00  00
*    D   00  20  00  00  40  70  00
*    E   00  00  00  40  00  00  00
*    F   00  100 00  70  00  00  30
*    G   00  00  00  00  00  30  00
*/

/* Ocekivana matrica susjednosti minimalnog obuhvatnog stabla:
*        AA  BB  CC  DD  EE  FF  GG
*    A   00  00  20  00  00  00  00
*    B   00  00  30  20  00  00  00
*    C   20  30  00  00  00  00  00
*    D   00  20  00  00  40  70  00
*    E   00  00  00  40  00  00  00
*    F   00  00  00  70  00  00  30
*    G   00  00  00  00  00  30  00
*/

#include <stdio.h>
#include <limits.h>
#define MAX 10

typedef struct graph {
    int n;
    char nodes[MAX];
    int ms[MAX][MAX];
} GRAF;

int all_visited(int visited[], int n){
    for (int i = 0; i < n; i++)
        if (!visited[i]) return 0;
    return 1;
}

int mst_prim(GRAF *g, GRAF *mst){
    int visited[MAX] = {1}; // krecemo od 'A'
    while (!all_visited(visited, g->n)){
        int w_min = INT_MAX, u_min = -1, v_min = -1;
        for (int u = 0; u < g->n; u++){
            for (int v = 0; v < g->n; v++){
                if (visited[u] && !visited[v] && g->ms[u][v])
                    if (g->ms[u][v] < w_min)
                        w_min = g->ms[u][v], u_min = u, v_min = v;
            }
        }
        if (v_min > -1)
            visited[v_min] = 1, mst->ms[u_min][v_min] = mst->ms[v_min][u_min] = w_min;
    }
}

void ispisi_ms(GRAF *graf){
    for (int i = 0; i < graf->n; i++){
        for (int j = 0; j < graf->n; j++){
            printf("%03d ", graf->ms[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dfs_putanja_visit(int u, int visited[], GRAF *graf){
    visited[u] = 1;
    printf("%c ", graf->nodes[u]);
    for (int v = 0; v < graf->n; v++)
        if (!visited[v] && graf->ms[u][v])
            dfs_putanja_visit(v, visited, graf);
}

void dfs_putanja(GRAF *graf){
    int visited[MAX] = {0};
    dfs_putanja_visit(0, visited, graf);
}

int main(void){

    GRAF graf = {7, {'A', 'B', 'C', 'D', 'E', 'F', 'G'}, 
        {
            {0, 90, 20, 0, 0, 0, 0},
            {90, 0, 30, 20, 0, 100, 0},
            {20, 30, 0, 0, 0, 0, 0},
            {0, 20, 0, 0, 40, 70, 0},
            {0, 0, 0, 40, 0, 0, 0},
            {0, 100, 0, 70, 0, 0, 30},
            {0, 0, 0, 0, 0, 30, 0}
        }
    };

    GRAF mst = {7, {'A', 'B', 'C', 'D', 'E', 'F', 'G'}, {{0}} };

    mst_prim(&graf, &mst);

    printf("Matrica susjednosti (originalni graf)\n");
    ispisi_ms(&graf);

    printf("Matrica susjednosti (minimalno obuhvatno stablo)\n");
    ispisi_ms(&mst);

    printf("Putanja (originalni graf):\n");
    dfs_putanja(&graf); printf("\n");

    printf("Putanja (minimalno obuhvatno stablo):\n");
    dfs_putanja(&mst); printf("\n");

    // Putanje se razlikuju s obzirom da se grafovi fizicki razlikuju jer je podrazumijevana putanja razlicita
    // od one iz MST-a

    return 0;
}