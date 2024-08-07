// Prepisivanje algoritma iz '12.c'

#include <stdio.h>
#include <limits.h>
#include <string.h>

// Strukture
typedef struct grad{
    char naziv[101];
} GRAD;

typedef struct graf{
    int n;
    GRAD gradovi[100];
    int ms[100][100];
} GRAF;

// Pomocne funkcije
int grad_index(GRAF gf, GRAD gr){
    // vraca indeks nekog grada u sklopu grafa
    for (int i = 0; i < gf.n; i++)
        if (!strcmp(gr.naziv, gf.gradovi[i].naziv)) return i;
    return -1;
}

int min_dist(GRAF gf, int distances[], int visited[]){
    // vraca indeks najmanje grane koja vodi ka
    // neposjecenom cvoru u skladu sa Dijkstra logikom
    int min = INT_MAX;
    int min_i;

    for (int v = 0; v < gf.n; v++)
        if (!visited[v] && distances[v] <= min)
            min = distances[v], min_i = v;
    return min_i;
}

void dostupni(GRAF gf, GRAD gr){
    int visited[100] = {};
    int distances[100];
    int start = grad_index(gf, gr);

    for (int i = 0; i < gf.n; i++)
        distances[i] = INT_MAX;
    distances[start] = 0;

    for (int i = 0; i < gf.n; i++){
        int u = min_dist(gf, distances, visited);
        visited[u] = 1;

        for (int v = 0; v < gf.n; v++){
            if (!visited[v] && gf.ms[u][v] && distances[u] != INT_MAX && distances[u] + gf.ms[u][v] < distances[v])
                distances[v] = distances[u] + gf.ms[u][v];
        }
    }

    printf("Najmanje udaljenosti od grada '%s' do gradova:\n", gr.naziv);
    for (int i = 0; i < gf.n; i++)
        if (i != start) printf("%s [%d]\n", gf.gradovi[i].naziv, distances[i]);
}

int main(void){
    GRAD BLK = {"Banja Luka"}, BIJ = {"Bijeljina"}, JAJ = {"Jajce"};
    GRAD SIP = {"Sipovo"}, SPL = {"Split"}, TRE = {"Trebinje"};

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

    dostupni(g, TRE);

    return 0;
}