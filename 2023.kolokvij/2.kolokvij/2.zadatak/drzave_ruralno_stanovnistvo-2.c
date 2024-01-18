/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/5aabf009562dff54763863b3f93373a9239dcc26/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B2%5DDrzave%20-%20ruralno%20stanovnistvo%202.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char ime_drzave[20 + 1];
    float br_stanovnika;
    int posto_gradsko_stan;
    float posto_rast;
}stanovnistvo;


int main() {
    
    FILE* ulaz = fopen("stanovnistvo.dat", "rb");
    FILE* izlaz = fopen("ruralne.txt", "w");

    stanovnistvo popis[1000];
    stanovnistvo rezultat[1000];

    fseek(ulaz, 0, SEEK_END);
    int vel = ftell(ulaz) / sizeof(stanovnistvo);
    fseek(ulaz, 0, SEEK_SET);

    fread(popis, sizeof(stanovnistvo), vel, ulaz);

    int p = 0;
    int br = 0;

    scanf("%d", &p);

    for (int i = 0; i < vel; i++) {
        if (popis[i].posto_gradsko_stan < p) {
            rezultat[br++] = popis[i];
        }
    }

    for (int i = 0; i < br; i++) {
        for (int j = 0; j < br - i - 1; j++) {
            if (rezultat[j].posto_gradsko_stan > rezultat[j + 1].posto_gradsko_stan) {
                stanovnistvo temp = rezultat[j];
                rezultat[j] = rezultat[j + 1];
                rezultat[j + 1] = temp;
            }
            else if (rezultat[j].posto_gradsko_stan == rezultat[j + 1].posto_gradsko_stan) {
                if (rezultat[j].ime_drzave[0] > rezultat[j + 1].ime_drzave[0]) {
                    stanovnistvo temp = rezultat[j];
                    rezultat[j] = rezultat[j + 1];
                    rezultat[j + 1] = temp;
                }
            }
        }
    }

    for (int i = 0; i < br; i++) {
        fprintf(izlaz, "%s#%.2f#%d\n", rezultat[i].ime_drzave, rezultat[i].br_stanovnika, rezultat[i].posto_gradsko_stan);
    }

    if (ftell(izlaz) == 0) {
        fprintf(izlaz, "Nema takve drzave.");
    }

    fclose(ulaz);
    fclose(izlaz);
   
    return 0;
}
