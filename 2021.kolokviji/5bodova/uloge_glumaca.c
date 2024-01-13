/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/5deb2d58b29bb54e89382c09b6684bd0ad00d312/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DUloge%20glumaca.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int sifra;
    char naziv[54 + 1];
    char zanr[24 + 1];
}film;

typedef struct {
    char ime_prezime[30 + 1];
    int sifra;
    char uloga[8 + 1];
}glumac;

int main()
{
    FILE* filmovi = fopen("filmovi.dat", "rb");
    FILE* glumci = fopen("glumci.txt", "r");

    film popisfilmova[2000];
    glumac popisglumaca[2000];
    int br = 0;

    fseek(filmovi, 0, SEEK_END);
    int vel = ftell(filmovi) / sizeof(film);
    fseek(filmovi, 0, SEEK_SET);

    fread(popisfilmova, sizeof(film), vel, filmovi);

    while (fscanf(glumci, "%[^#]#%d#%[^\n]%*c", popisglumaca[br].ime_prezime, &popisglumaca[br].sifra, popisglumaca[br].uloga) != EOF) {
        br++;
    }

    char trazeniglumac[100];
    scanf("%[^\n]%*c", &trazeniglumac);

    int pronasaoGlumca = 0;

    for (int i = 0; i < br; i++) {
        if (strcmp(trazeniglumac, popisglumaca[i].ime_prezime) == 0) {
            pronasaoGlumca = 1;
            if (strcmp(popisglumaca[i].uloga, "glavna") == 0) {
                printf("Glavna uloga: %s\n", popisfilmova[popisglumaca[i].sifra-1].zanr);
            }
            else {
                printf("Sporedna uloga: %s\n", popisfilmova[popisglumaca[i].sifra-1].zanr);
            }
        }
    }
    if (pronasaoGlumca == 0) {
        printf("%s ne postoji", trazeniglumac);
    }

    fclose(filmovi);
    fclose(glumci);
   
    return 0;
}
