// formiranje MST neusmjerenog grafa primjenom Primovog algoritma

#include <stdio.h>
#include <limits.h>

#define MAX 10 // maks. broj cvorova (i dimenzija m.s)
// uvijek mora biti ili literal ili pretprocesorska konstanta
// (ako je obicna globalna promjenljiva, nece se kompajlovati)
typedef struct graph{
    // broj cvorova
    int n;

    // inf. sadrzaj cvorova
    // po indeksima
    char nodes[MAX];
    
    // matrica susjednosti
    int ms[MAX][MAX];
} GRAF;

int allVisited(int visited[], int n){
    for (int i = 0; i < n; i++)
        if (!visited[i]) return 0;
    return 1;
}

void mst_prim(GRAF *g, GRAF *mst){
    // niz posjecenosti
    // inicijalizujemo sve na nulu
    // ali nulti indeks na 1:
    // int visited[MAX] = {}; visited[0] = 1;
    int visited[MAX] = {1};

    // izvrsavanje prestaje kad su svi cvorovi povezani u MST
    while (!allVisited(visited, g->n)){
        // INT_MAX zahtijeva zaglavlje <limits.h> i sluzi nam kao indikator
        // beskonacnosti tj. najvece (ne)moguce vrijednosti
        // pratimo najmanju tezinu grane kao i indekse cvorova izmedju kojih ona stoji
        int mg = INT_MAX, mu = -1, mv = -1;
        // iterativno prolazimo cijelu matricu susjednosti
        for (int u = 0; u < g->n; u++){
            for (int v = 0; v < g->n; v++){
                // ako je jedan cvor posjecen, drugi nije, i postoji veza izmedju njih...
                if (visited[u] && !visited[v] && g->ms[u][v]){
                    // ako je tezina njihove veze manja od najmanje zabiljezene, cinimo je novom najmanjom
                    if (g->ms[u][v] < mg)
                        mg = g->ms[u][v], mu = u, mv = v;
                }
            }
        }
        // ako smo nasli najmanje tesku vezu u prethodnoj petlji, indeks cvora DO kog ona vodi stavljamo na listu
        // posjecenih, a u matrici susjednosti minimalnog obuhvatnog stabla "spajamo" dva najpogodnija pronadjena
        // cvora koje smo takodje upratili i za vrijednost njihove veze postavljamo upravo najnizu pronadjenu koja
        // im i odgovara u originalnom grafu
        if (mv > -1)
            visited[mv] = 1, mst->ms[mu][mv] = mst->ms[mv][mu] = mg;
    }
}

int main(){
    // graf sa primjera
    GRAF g = {6, {'A', 'B', 'C', 'D', 'E', 'F'}, 
        {
            {0, 70, 50, 80, 0, 0},
            {70, 0, 0, 60, 0, 0},
            {50, 0, 0, 50, 20, 0},
            {80, 60, 50, 0, 20,0},
            {0, 0, 20, 20, 0, 30},
            {0, 0, 0, 0, 30, 0}
        }
    };
    GRAF MST = {6, {'A', 'B', 'C', 'D', 'E', 'F'}, {{0}}};
    mst_prim(&g, &MST);

    // ispis matrice
    for (int i = 0; i < g.n; i++){
        for (int j = 0; j < g.n; j++)
            printf("%02d ", g.ms[i][j]);
        printf("\n");
    }
    printf("\n\n");
    for (int i = 0; i < MST.n; i++){
        for (int j = 0; j < MST.n; j++)
            printf("%02d ", MST.ms[i][j]);
        printf("\n");
    }

    return 0;
}