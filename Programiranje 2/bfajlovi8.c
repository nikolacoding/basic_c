// Napisati program koji rotira BMP sliku (nekompresovana, 24 bpp) kao da se
// gleda u ogledalu. Naziv ulazne datoteke je prvi argument komandne linije.
// Naziv izlazne datoteke (slika u ogledalu) je drugi argument komandne linije.

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
    unsigned int offset; // pocetak vrijednosti piksela, odstupanje
} BMP_FILE_HEADER;

typedef struct
{
    unsigned int size; // velicina ovog zaglavlja
    long width;        // sirina
    long height;       // visina
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
    char filename_in[64], filename_out[64];
    FILE *fin, *fout;

    if (argc == 3)
    {
        strcpy(filename_in, argv[1]);
        strcpy(filename_out, argv[2]);

        BMP_FILE_HEADER header;
        BMP_INFO info;

        if (fin = fopen(filename_in, "rb"))
        {
            fread(&header, sizeof(BMP_FILE_HEADER), 1, fin);
            fread(&info, sizeof(BMP_INFO), 1, fin);

            int size;
            unsigned char *pixels, *pixels_mir;

            if (header.file_type != BMP)
                printf("Tip datoteke nije bmp.");
            else if (info.compression)
                printf("Datoteka je kompresovana.");
            else if (info.bpp != 24)
                printf("Datoteka nije 24-bitni bpp.");
            else
            {
                size = header.file_size - header.offset;
                pixels = (unsigned char *)calloc(size, 1);
                pixels_mir = (unsigned char *)calloc(size, 1);

                fread(pixels, 1, size, fin);

                for (int i = 0; i < info.width; i++)
                    for (int j = 0; j < info.height; j++)
                        for (int k = 0; k < 3; k++)
                        {
                            int i1 = i * info.height * 3 + j * 3 + k;                       // prvi element
                            int i2 = i * info.height * 3 + info.height * 3 - j * 3 - k - 1; // zadnji element

                            pixels_mir[i1] = pixels[i2];
                        }

                if (fout = fopen(filename_out, "wb"))
                {
                    fwrite(&header, sizeof(BMP_FILE_HEADER), 1, fout);
                    fwrite(&info, sizeof(BMP_INFO), 1, fout);
                    fwrite(pixels_mir, 1, size, fout);
                    fclose(fout);
                }
                else
                    printf("Nije moguce otvoriti datoteku '%s'.", filename_out);

                free(pixels);
                free(pixels_mir);
            }
        }
        else
            printf("Nije moguce otvoriti datoteku '%s'.", filename_in);
    }
    else
        printf("Argumenti nisu pravilno navedeni.");
    return 0;
}