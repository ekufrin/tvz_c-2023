/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/4ba87b89dac5cc75bd6263d64d2623638c42436b/tekstovi%20i%20test%20caseovi/%5B8%5DStanovi%20-%20veliki%20i%20jeftini.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char kvart[25];
    float kvadratura;
    int cijenaEUR;
    int sobnost;
    int kat;
}stan;

int main()
{
    FILE* ulaz = fopen("stanovi.txt", "r");
    FILE* izlaz = fopen("preporuka.txt", "w");

    stan popis[1000];
    int br = 0;

    while (fscanf(ulaz, "%[^#]#%f#%d#%d#%d%*c", popis[br].kvart, &popis[br].kvadratura, &popis[br].cijenaEUR, &popis[br].sobnost, &popis[br].kat) !=EOF) {
        br++;
    }

    stan najjeftiniji={0};
    najjeftiniji.cijenaEUR = 1000000;

    for (int i = 0; i < br; i++) {
        if ((popis[i].cijenaEUR / popis[i].kvadratura) < 1500 && popis[i].sobnost >= 3) {
            fprintf(izlaz, "%d#%s#%.2f#%d\n", popis[i].cijenaEUR, popis[i].kvart, popis[i].kvadratura, popis[i].sobnost);
            if (popis[i].cijenaEUR < najjeftiniji.cijenaEUR) {
                najjeftiniji = popis[i];
            }
        }
    }

    fprintf(izlaz, "\n\n\nNajjeftiniji stan kosta %.f EUR po kvadratu.", najjeftiniji.cijenaEUR / najjeftiniji.kvadratura);

    fclose(ulaz);
    fclose(izlaz);
   
    return 0;
}
