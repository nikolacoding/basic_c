// Napisati program koji kreira negativ BMP slike (nekompresovana, 24 bpp)
// čiji je naziv prvi argument komandne linije. Naziv izlazne datoteke je drugi argument komandne linije.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(1)
#define BMP 0x4D42

typedef struct
{
    unsigned short file_type; // tip fajla
    unsigned int file_size;   // velicina fajla
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset; // pocetak vrijednosti piksela
} BMP_FILE_HEADER;

typedef struct
{
    unsigned int size; // velicina ovog zaglavlja
    long width;        // sirina u px
    long height;       // visina u px
    unsigned short planes;
    unsigned short bpp;       // broj bita po pikselu
    unsigned int compression; // kompresija
    unsigned int img_size;
    long x_px_m;
    long y_py_m;
    unsigned int clr_used;
    unsigned int clr_important;
} BMP_INFO;

int main(int argc, char const *argv[])
{
    FILE *fin, *fout;
    char fin_name[64], fout_name[64];

    if (argc == 3)
    {
        strcpy(fin_name, argv[1]);
        strcpy(fout_name, argv[2]);

        if (fin = fopen(fin_name, "rb"))
        {
            BMP_FILE_HEADER header;
            BMP_INFO info;
            unsigned char *buffer;
            int size;

            fread(&header, sizeof(BMP_FILE_HEADER), 1, fin);
            fread(&info, sizeof(BMP_INFO), 1, fin);

            if (header.file_type != BMP)
                printf("Tip datoteke nije bmp.");
            else if (info.compression)
                printf("Datoteka je kompresovana.");
            else if (info.bpp != 24)
                printf("Datoteka nije 24-bitni bmp.");
            else
            {
                size = header.file_size - header.offset;
                buffer = (unsigned char *)calloc(size, 1);

                fread(buffer, 1, size, fin);

                for (int i = 0; i < size; i++)
                    buffer[i] = 255 - buffer[i]; // negativ logika

                if (fout = fopen(fout_name, "wb"))
                {
                    fwrite(&header, sizeof(BMP_FILE_HEADER), 1, fout);
                    fwrite(&info, sizeof(BMP_INFO), 1, fout);
                    fwrite(buffer, 1, size, fout);
                    fclose(fout);
                }
                else
                    printf("Datoteka '%s' se ne moze otvoriti.", fout_name);

                free(buffer);
            }
        }
        else
            printf("Datoteka '%s' se ne moze otvoriti.", fin_name);
    }
    else
        printf("Argumenti nisu pravilno navedeni.");

    return 0;
}