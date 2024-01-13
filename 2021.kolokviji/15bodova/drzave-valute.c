/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/79306733a78875af2ac16776c85839d873b53339/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DDrzave-valute.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char ime_drzave[20 + 1];
    float br_stanovnika;
    int postotak_gr_stan;
    float postotak_rasta_stan;
}stanovnik;

typedef struct {
    char ime[30];
    char glavni_grad[30];
    int povrsina;
    char valuta[30];
}drzava;

void trazi_valutu(stanovnik popis_stanovnika[], drzava popis_drzava[], FILE* izlaz, int br, int vel, char trazena_valuta[]);

int main()
{
    FILE* stanovnistvo = fopen("stanovnistvo.dat", "rb");
    FILE* drzave = fopen("drzave.txt", "r");
    FILE* izlaz = fopen("valute.txt", "w");

    stanovnik popis_stanovnika[1000];
    drzava popis_drzava[1000];
    int br = 0;

    fseek(stanovnistvo, 0, SEEK_END);
    int vel = ftell(stanovnistvo) / sizeof(stanovnik);
    fseek(stanovnistvo, 0, SEEK_SET);

    fread(popis_stanovnika, sizeof(stanovnik), vel, stanovnistvo);

    while (fscanf(drzave, "%[^#]#%[^#]#%d#%[^\n]%*c", popis_drzava[br].ime, popis_drzava[br].glavni_grad, &popis_drzava[br].povrsina, popis_drzava[br].valuta) != EOF) {
        br++;
    }

    char zeljena_valuta[100];
    scanf("%[^\n]%*c", &zeljena_valuta);

    trazi_valutu(popis_stanovnika, popis_drzava, izlaz, br, vel, zeljena_valuta);

    if (ftell(izlaz) == 0) {
        fprintf(izlaz, "Nema takve drzave.");
    }

    fclose(stanovnistvo);
    fclose(drzave);
    fclose(izlaz);
   
    return 0;
}
void trazi_valutu(stanovnik popis_stanovnika[], drzava popis_drzava[], FILE* izlaz, int br, int vel, char trazena_valuta[]) {
    for (int i = 0; i < br; i++) {
        if (strstr(popis_drzava[i].valuta, trazena_valuta) != NULL) {
            for (int j = 0; j < vel; j++) {
                if (strcmp(popis_drzava[i].ime, popis_stanovnika[j].ime_drzave) == 0) {
                    fprintf(izlaz, "%s#%s#%.2f#%s\n", popis_drzava[i].ime, popis_drzava[i].glavni_grad, popis_stanovnika[j].br_stanovnika, popis_drzava[i].valuta);
                }
            }
        }
    }
}
