/*
*    Skicirati proizvoljan povezan neusmjeren graf sa najmanje 6 cvorova sa informacionim sadrzajem tipa 'char' i
*    napisati za njega matricu susjednosti. Prenijeti matricu susjednosti u kod i realizovati obuhvatno stablo.
*    Potrebno je napisati funkciju koja ispisuje matricu susjednosti i primjeniti je na oba grafa.
*    Potrebno je takodje napisati funkciju koja DFS obilaskom ispisuje informacioni sadrzaj oba grafa pocev od 'A'.
*/

/* Proizvoljan graf:
* 
*      C - D
*    / | / | \
*  A - B   E  G
*       \ | / 
*         F
*/

/* Ocekivano obuhvatno stablo grafa iznad realizovano standardnim algoritmom koji prolazi prvom povoljnom granom
 * na koju naidje:
* 
*      C - D
*      |   |
*  A - B   E  G
*         | / 
*         F
*/

/* Matrica susjednosti proizvoljnog grafa:
*        A   B   C   D   E   F   G
*    A   0   1   1   0   0   0   0
*    B   1   0   1   1   0   1   0
*    C   1   1   0   1   0   0   0
*    D   0   1   1   0   1   0   1
*    E   0   0   0   1   0   1   0
*    F   0   1   0   0   1   0   1
*    G   0   0   0   1   0   1   0
*/

/* Ocekivana matrica susjednosti obuhvatnog stabla originalnog grafa:
*        A   B   C   D   E   F   G
*    A   0   1   0   0   0   0   0
*    B   1   0   1   0   0   0   0
*    C   0   1   0   1   0   0   0
*    D   0   0   1   0   1   0   0
*    E   0   0   0   1   0   1   0
*    F   0   0   0   0   1   0   1
*    G   0   0   0   0   0   1   0
*/

#include <stdio.h>
#define MAX 10

typedef struct graph {
    int n;
    char nodes[MAX];
    int ms[MAX][MAX];
} GRAF;

void ispisi_ms(GRAF *graf){
    for (int i = 0; i < graf->n; i++){
        for (int j = 0; j < graf->n; j++){
            printf("%d ", graf->ms[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dfs_st_visit(int u, int visited[], GRAF *graf, GRAF *st){
    visited[u] = 1;
    for (int v = 0; v < graf->n; v++){
        if (!visited[v] && graf->ms[u][v]){
            st->ms[u][v] = st->ms[v][u] = 1;
            dfs_st_visit(v, visited, graf, st);
        }
    }
}

void dfs_st(GRAF *graf, GRAF *st){
    int visited[MAX] = {0};
    dfs_st_visit(0, visited, graf, st);
}

void dfs_putanja_visit(int u, int visited[], GRAF *graf){
    visited[u] = 1;
    printf("%c ", graf->nodes[u]);
    for (int v = 0; v < graf->n; v++){
        if (!visited[v] && graf->ms[u][v])
            dfs_putanja_visit(v, visited, graf);
    }
}

void dfs_putanja(GRAF *graf){
    int visited[MAX] = {0};
    dfs_putanja_visit(0, visited, graf);
}

int main(void){
    GRAF graf = {7, {'A', 'B', 'C', 'D', 'E', 'F', 'G'},
        {
            {0, 1, 1, 0, 0, 0, 0},
            {1, 0, 1, 1, 0, 1, 0},
            {1, 1, 0, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 1},
            {0, 0, 0, 1, 0, 1, 0},
            {0, 1, 0, 0, 1, 0, 1},
            {0, 0, 0, 1, 0, 1, 0}
        }
    };
    GRAF st = {7, {'A', 'B', 'C', 'D', 'E', 'F', 'G'}, {{0}}};
    dfs_st(&graf, &st);

    printf("Matrica susjednosti (originalan graf):\n");
    ispisi_ms(&graf);

    printf("Matrica susjednosti (obuhvatno stablo):\n");
    ispisi_ms(&st);

    printf("Putanja (originalan graf):\n");
    dfs_putanja(&graf); printf("\n\n");

    printf("Matrica susjednosti (obuhvatno stablo):\n");
    dfs_putanja(&st); printf("\n");

    // S obzirom da se isti algoritam koristi za dolazak do MST-a kao i ispis putanje, ispis obe putanje ce
    // uvijek biti identican

    return 0;
}