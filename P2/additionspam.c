// isto kao 'ifspam.c' samo za sabiranje ili oduzimanje

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define LIMIT 1e7             // 10.000.000
#define WARNING_THRESHOLD 1e4 // 10.000

static void header(FILE *, long, const char *, const char *);
static void footer(FILE *);
static void start(FILE *fp, long n, const char *varid1, const char *varid2);

static char operacija[11];

int main(void)
{
    long n;
    bool respectLimit = false; // za uklanjanje ogranicenja
    
    char filename[32];
    char varname1[32], varname2[32];

    do
    {
        fprintf(stdout, "Ime datoteke za upis: ");
        fscanf(stdin, "%s", filename);
    } while (!strcmp(__FILE__, filename));

    fprintf(stdout, "Identifikatori promjenljivih za sabiranje: ");
    fscanf(stdin, "%s %s", varname1, varname2);

    FILE *fp;

    do
        fprintf(stdout, "Broj operacija [0 - n] + [0 - n]: "), scanf("%li", &n);
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
        start(fp, n, varname1, varname2);
        fprintf(stdout, "Uspjesno ispisano %li linija u '%s'.\n", n, filename);
        fclose(fp);
    }
    else
        fprintf(stdout, "Neuspjesno otvaranje datoteke '%s'.\n", filename);

    return 0;
}

static void header(FILE *fp, long n, const char *varid1, const char* varid2)
{
    fprintf(fp, "// Operacija %s sa %li uslova\n", operacija, n);
    fprintf(fp, "#include <stdio.h>\n");
    fprintf(fp, "int main()\n{\n");
    fprintf(fp, "   int %s = 0, %s = 0;\n", varid1, varid2);
}

static void footer(FILE *fp)
{
    fprintf(fp, "   return 0;\n");
    fprintf(fp, "}\n");
}

static void start(FILE *fp, long n, const char *varid1, const char *varid2)
{
    header(fp, n, varid1, varid2);      
    for (int i = 0, j = 0; i < n;){
        fprintf(fp, "  %s ((%s == %d && %s == %d) || (%s == %d && %s == %d)) printf(\"%d\");\n", 
        (!i && !j) ? "if" : "else if", varid1, i, varid2, j, varid2, i, varid1, j, i + j);
        
        if ((i + j) % 2) i++;
        else j++;
    }
    footer(fp);
}