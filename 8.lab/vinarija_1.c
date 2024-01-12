/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/f7be5eb5e26691f04fc8201123bc73d538ea1456/tekstovi%20i%20test%20caseovi/%5B8%5DVinarija%201.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char sorta[20 + 1];
    char proizvodac[20 + 1];
    char boja[7 + 1];
    char kvaliteta[15 + 1];
    float zapremnina;
    float cijena;
}vino;


void vina(FILE* izlaz,vino rez[], int br) {
    if (br == 0) {
        fprintf(izlaz, "Nema trazenog proizvodjaca!");
    }
    else {
        for (int i = 0; i < br; i++) {
            for (int j = 0; j < br - i - 1; j++) {
                if (rez[j].cijena > rez[j + 1].cijena) {
                    vino temp;
                    temp = rez[j];
                    rez[j] = rez[j + 1];
                    rez[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < br; i++) {
            fprintf(izlaz, "%s#%.2f#%s#%s\n", rez[i].proizvodac, rez[i].cijena, rez[i].sorta, rez[i].kvaliteta);
        }
    }
    
}

int main()
{
    FILE* ulaz = fopen("vinski_podrum.dat", "rb");
    FILE* izlaz = fopen("vino.txt", "w");

    vino popis[100];
    vino rez[100];
    int br = 0;


    fseek(ulaz, 0, SEEK_END);
    int vel = ftell(ulaz) / sizeof(vino);
    fseek(ulaz, 0, SEEK_SET);

    fread(popis, sizeof(vino), vel, ulaz);

    char recenica[20 + 1];
    scanf("%[^\n]%*c", &recenica);

    for (int i = 0; i < vel; i++) {
        if (strstr(popis[i].proizvodac, recenica) != NULL) {
            rez[br++] = popis[i];
        }
    }

    vina(izlaz, rez, br);
   
    return 0;
}
