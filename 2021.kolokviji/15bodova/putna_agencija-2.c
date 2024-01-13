/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/00e6cb3ecce68a370f1c4ca259f977a305982285/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DPutna%20agencija%202.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char destinacija[30 + 1];
    int dan;
    int mj;
    int brdana;
    double cijena;
    int popust;
}let;

int main()
{
    FILE* ulaz = fopen("agencija.dat", "rb");
    FILE* izlaz = fopen("destinacija.txt", "w");

    let popis[1000];
    let rezultat[100];
    int br = 0;

    fseek(ulaz, 0, SEEK_END);
    int vel = ftell(ulaz) / sizeof(let);
    fseek(ulaz, 0, SEEK_SET);

    fread(popis, sizeof(let), vel, ulaz);

    char zeljena_destinacija[100];
    scanf("%[^\n]%*c", &zeljena_destinacija);

    for (int i = 0; i < vel; i++) {
        if (strcmp(zeljena_destinacija, popis[i].destinacija) == 0) {
            popis[i].cijena -= ((popis[i].cijena * popis[i].popust)/100);
            rezultat[br++] = popis[i];
        }
    }

    for (int i = 0; i < br; i++) {
        for (int j = 0; j < br - i - 1;j++) {
            if (rezultat[j].cijena > rezultat[j + 1].cijena) {
                let temp = rezultat[j];
                rezultat[j] = rezultat[j + 1];
                rezultat[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < br; i++) {
        fprintf(izlaz, "%s %d.%d. (%d dana) %.2f\n", rezultat[i].destinacija, rezultat[i].dan, rezultat[i].mj, rezultat[i].brdana, rezultat[i].cijena);
    }
    

    fclose(ulaz);
    fclose(izlaz);
   
    return 0;
}
