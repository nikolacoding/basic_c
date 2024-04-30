#include <stdio.h>
#include <stdlib.h>

typedef struct datum{
    int d, m, g;
} DATUM;

typedef struct artikal {
    int id;
    char naziv[21];
    DATUM vazi_do;
    double kol;
    double cijena;
} ARTIKAL;

ARTIKAL *ucitaj(int *pn);
ARTIKAL *pronadji(ARTIKAL *niz, int n, int id);
ARTIKAL *pronadji_bin(ARTIKAL *niz, int n, int id);
void sortiraj(ARTIKAL *niz, int n);
void ispisi(ARTIKAL *niz, int n);

int main(void)
{
    int n;
    ARTIKAL *artikli = ucitaj(&n);
    ARTIKAL *trazeni;
    sortiraj(artikli, n);
    trazeni = pronadji_bin(artikli, n, 69);
    ispisi(artikli, n);
    
    if (trazeni){
        printf("\n\nRezultat pretrage:\n");
        printf("%s", trazeni->naziv);
    }

    free(trazeni);
    return 0;
}

ARTIKAL *ucitaj(int *pn){


    int n;

    do{
        printf("Unesi broj artikala: ");
        scanf("%d", &n);
    } while (n < 1);

    ARTIKAL *niz = malloc(n * sizeof(ARTIKAL));

    for (int i = 0; i < n; i++){
        printf("> Podaci o %d. artiklu: ", i + 1);

        printf(">> ID: ");
        scanf("%d", &niz[i].id);

        printf(">> Naziv: ");
        scanf("%s", niz[i].naziv);
        
        printf(">> Vazi do: ");
        scanf("%d %d %d", &niz[i].vazi_do.d, &niz[i].vazi_do.m, &niz[i].vazi_do.g);

        printf(">> Kolicina: ");
        scanf("%lf", &niz[i].kol);

        printf(">> Cijena: ");
        scanf("%lf", &niz[i].cijena);
    }

    *pn = n;
    return niz;
}

void sortiraj(ARTIKAL *niz, int n){
    int i, j, h;
    ARTIKAL temp;
    
    for (h = n / 2; h > 0; h /= 2){
        for (i = 1; i < n; i++){
            temp = niz[i];
            for (j = i; j >= h && niz[j - h].id < temp.id; j -= h)
                niz[j] = niz[j - h];
            niz[j] = temp;
        }
    }
}

ARTIKAL *pronadji(ARTIKAL *niz, int n, int id){
    ARTIKAL *ret = malloc(sizeof(ARTIKAL));
    for (int i = 0; i < n; i++){
        if (niz[i].id == id){
            *ret = niz[i];
            return ret;
        }
    }
    return NULL;
}

void ispisi(ARTIKAL *niz, int n){
    for (int i = 0; i < n; i++){
        ARTIKAL a = niz[i];
        printf("%d | %s (rok: %d %d %d) %.1lf %.2lf\n", a.id, a.naziv, 
        a.vazi_do.d, a.vazi_do.m, a.vazi_do.g, a.kol, a.cijena);
    }
}

ARTIKAL *pronadji_bin(ARTIKAL *niz, int n, int id){
    int pocetak = 0, kraj = n - 1, sredina;
    ARTIKAL *kopija = malloc(sizeof(ARTIKAL));

    do {
        sredina = (pocetak + kraj) / 2;

        if (niz[sredina].id == id){
            *kopija = niz[sredina];
            return kopija;
        }

        if (niz[sredina].id > id)
            pocetak = sredina + 1;
        
        if (niz[sredina].id < id)
            kraj = sredina - 1;
            
    } while (pocetak <= kraj);
    return NULL;
}