/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/decd7a21ec2dd72c2ae1d65bdceef2973f1f7f55/tekstovi%20i%20test%20caseovi/%5B8%5DAutomobili-brzi_i_skupi.zip

ULAZ JE KOMPLETNA automobili.txt datoteka, a izlaz je:

Mercedes SL 63 AMG kabriolet 6208 525 5 250 1456262
Porsche 911 Turbo Coupe coupe 3600 480 4 310 1403739
Mercedes CL 500 coupe 5461 388 5 250 1119382
Ferrari F430 coupe 4307 490 4 315 1074177
BMW M6 coupe 2V 4999 507 5 250 1170963
Mercedes SL 500 kabriolet 5461 388 5 250 1075319

najbrzi je 911 Turbo Coupe, ubrzanje 4
najskuplji je SL 63 AMG, cijena 1456262
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char proizvodjac[40];
    char model[40];
    char karoserija[40];
    int volumen;
    int snagaKW;
    int ubrzanje;
    int brzina;
    int cijenaKN;
}auti;

int main()
{
    FILE* ulaz = fopen("automobili.txt", "r");
    FILE* izlaz = fopen("brzi.txt", "w");

    auti popis[1000];
    int br = 0;

    while (fscanf(ulaz, "%[^#]#%[^#]#%[^#]#%d#%d#%d#%d#%d%*c", popis[br].proizvodjac, popis[br].model, popis[br].karoserija, &popis[br].volumen, &popis[br].snagaKW, &popis[br].ubrzanje, &popis[br].brzina, &popis[br].cijenaKN) !=EOF) {
        br++;
    }


    auti najbrzi = { 0 };
    najbrzi.ubrzanje = 5;
    auti najskuplji = { 0 };
    najskuplji.cijenaKN = 1000001;

    for (int i = 0; i < br; i++) {
        if (popis[i].ubrzanje < 6 && popis[i].cijenaKN>1000000) {
            fprintf(izlaz, "%s %s %s %d %d %d %d %d\n", popis[i].proizvodjac, popis[i].model, popis[i].karoserija, popis[i].volumen, popis[i].snagaKW, popis[i].ubrzanje, popis[i].brzina, popis[i].cijenaKN);
            if (popis[i].ubrzanje < najbrzi.ubrzanje) {
                najbrzi = popis[i];
            }
            if (popis[i].cijenaKN > najskuplji.cijenaKN) {
                najskuplji = popis[i];
            }
        }
    }

    fprintf(izlaz, "\nnajbrzi je %s, ubrzanje %d\nnajskuplji je %s, cijena %d", najbrzi.model,najbrzi.ubrzanje,najskuplji.model,najskuplji.cijenaKN);

    fclose(ulaz);
    fclose(izlaz);
   
    return 0;
}
