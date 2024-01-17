/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/37384856c88322f41261068a2ef0e4e5a11c5b6d/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B2%5DMatchMaker%202.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char ime[20 + 1];
    char prezime[20 + 1];
    int dob;
    int visina;
    int tezina;
    char bojaKose[10 + 1];
}osoba;


int main()
{
    FILE* ulaz = fopen("osobe.dat", "rb");
    FILE* izlaz = fopen("lista.txt", "w");

    osoba popis[1000];

    fseek(ulaz, 0, SEEK_END);
    int vel = ftell(ulaz) / sizeof(osoba);
    fseek(ulaz, 0, SEEK_SET);

    fread(popis, sizeof(osoba), vel, ulaz);

    int BMIx, BMIy;
    int visina;

    scanf("%d-%d", &BMIx, &BMIy);
    scanf("%d", &visina);


    for (int i = 0; i < vel; i++) {
        double BMI = popis[i].tezina / pow((double)popis[i].visina / 100, 2);
        if (popis[i].visina > visina && BMI >= BMIx && BMI <= BMIy) {
            fprintf(izlaz, "%s %s %.1f\n", popis[i].prezime, popis[i].ime, BMI);
        }
    }
    
    fclose(ulaz);
    fclose(izlaz);

    return 0;
}
