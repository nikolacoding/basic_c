// formiranje MST neusmjerenog grafa primjenom Primovog algoritma

#include <stdio.h>
#include <limits.h>
#define MAX 10

typedef struct graph{
    int n;
    char nodes[MAX];
    int ms[MAX][MAX];
} GRAF;

int allVisited(int visited[], int n){
    for (int i = 0; i < n; i++)
        if (!visited[i]) return 0;
    return 1;
}

void mst_prim(GRAF *g, GRAF *mst){
    int visited[MAX] = {1};

    // dok nisu svi spojeni (pretpostavljamo da nema odsjecenih cvorova)
    while (!allVisited(visited, g->n)){
        // pratimo najmanju tezinu ivice kao i indekse cvorova izmedju kojih ona stoji
        int mg = INT_MAX, mu = -1, mv = -1;
        // iterativno prolazimo cijelu matricu susjednosti
        for (int u = 0; u < g->n; u++){
            for (int v = 0; v < g->n; v++){
                // ako je jedan cvor posjecen, drugi nije, i postoji veza/ivica izmedju njih
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