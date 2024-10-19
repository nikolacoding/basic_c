// Korisnik definise ime datoteke za upis, ime promjenljive (tipa int), vrijednost promjenljive i broj if-uslova (n)
// za provjeru parnosti. Program potom kreira (ili otvara vec kreiranu) datoteku u koju u jeziku C upisuje
// najosnovnije zaglavlje kao i funkciju main() u koji smjesta if uslove za poredjenje parnosti promjenljive
// sa zadatom vrijednoscu. Broj uslova (n) oznacava koliko ce if-provjera parnosti biti u funkciji main
// nad zadatom cjelobrojnom vrijednoscu. Provjere se vrse za svaku cifru pojedinacno u intervalu [0, n].
// Osnovno ogranicenje broja provjera jeste 1e7 (10 miliona), ali se ovo ogranicenje moze obrisati ili povecati
// sve do ogranicenja 32-bitnih cjelobrojnih signed (integer) vrijednosti (2^32) / 2 ili 2147483647. Ovo se vrsi
// promjenom bool vrijednosti 'respectLimits'.

// Napomena: ovaj program je parodija

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define LIMIT 1e7             // 10.000.000
#define WARNING_THRESHOLD 1e4 // 10.000

static void header(FILE *, long, const char *, int);
static void footer(FILE *);
static void start(FILE *, long, const char *, int, const char const *, const char const *);

int main(void)
{
    long n;
    bool respectLimit = false; // za uklanjanje ogranicenja
    char filename[32];

    char varname[32];
    int varvalue;

    do
    {
        fprintf(stdout, "Ime datoteke za upis: ");
        gets(filename);
    } while (!strcmp(__FILE__, filename)); // preventivno, da ne napisemo sve preko *ovog* fajla
    fprintf(stdout, "Identifikator promjenljive za poredjenje: "),
        gets(varname);
    fprintf(stdout, "Broj koji se poredi: "), fscanf(stdin, "%d", &varvalue);

    const char const even_statement[32] = "printf(\"Broj je paran.\");";
    const char const odd_statement[32] = "printf(\"Broj je neparan.\");";
    FILE *fp;

    do
        fprintf(stdout, "Broj uslova: "), scanf("%li", &n);
    while (n >= LONG_MAX || n < 1 || (respectLimit && n > LIMIT)); // LONG_MAX: 2147483647

    if (fp = fopen(filename, "w"))
    {
        if (n >= WARNING_THRESHOLD - 1)
        {
            int choice;
            printf("Ispis %li linija je jako intenzivan i moze da potraje. Da li ste sigurni?\n1 - da\n0 - ne\n", n);
            fscanf(stdin, "%d", &choice);
            if (!choice)
            {
                fprintf(stdout, "Prekid...\n");
                return 1;
            }
        }
        fprintf(stdout, "Pocinje ispis %li linija u '%s'. Ovo moze da potraje...\n", n, filename);
        start(fp, n, varname, varvalue, even_statement, odd_statement);
        fprintf(stdout, "Uspjesno ispisano %li linija  poredjenja u '%s'.\n", n, filename);
        fclose(fp);
    }
    else
        fprintf(stdout, "Neuspjesno otvaranje datoteke '%s'.\n", filename);

    return 0;
}

static void header(FILE *fp, long n, const char *varid, int vardefaultvalue)
{
    fprintf(fp, "// Provjera parnosti sa %li uslova\n", n);
    fprintf(fp, "#include <stdio.h>\n");
    fprintf(fp, "int main()\n{\n");
    fprintf(fp, "   int %s = %d;\n", varid, vardefaultvalue);
}

static void footer(FILE *fp)
{
    fprintf(fp, "   return 0;\n");
    fprintf(fp, "}\n");
}

static void start(FILE *fp, long n, const char *varid, int vardefaultvalue,
                  const char const *even_statement, const char const *odd_statement)
{
    header(fp, n, varid, vardefaultvalue);
    for (int i = 0; i < n; i++)
        fprintf(fp, "   if (%s == %d) %s\n", varid, i,
                (i % 2) ? odd_statement : even_statement);
    footer(fp);
}