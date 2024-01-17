/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/e4cc14f0ab4d527e7d235a43fa15ec439201e3fb/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DVelicina%20gradova.PDF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char drzava[20];
    char grad[20];
    int br_stanovnika;
    float povrsina;
    int glavni_grad;
}grad;

int main() {

    FILE* ulaz = fopen("Gradovi.txt", "r");
    FILE* izlaz = fopen("Rezultati.txt", "w");

    grad popis[100];
    grad rezultat[100];
    int br = 0;
    int rez = 0;
    int ukupan_br_stanovnika = 0;

    while (fscanf(ulaz, "%[^ ] %[^ ] %d %f %d%*c",popis[br].drzava,popis[br].grad,&popis[br].br_stanovnika,&popis[br].povrsina,&popis[br].glavni_grad) != EOF) {
        br++;
    }

    char drzava[20];
    scanf("%[^\n]%*c", drzava);

    for (int i = 0; i < br; i++) {
        if (strcmp(drzava, popis[i].drzava) == 0) {
            rezultat[rez++] = popis[i];
            ukupan_br_stanovnika += popis[i].br_stanovnika;
        }
    }

    for (int i = 0; i < rez; i++) {
        for (int j = 0; j < rez - i - 1; j++) {
            if (rezultat[j].br_stanovnika < rezultat[j + 1].br_stanovnika) {
                grad temp = rezultat[j];
                rezultat[j] = rezultat[j + 1];
                rezultat[j + 1] = temp;
            }
        }
    }

    if (rez == 0) {
        fprintf(izlaz, "Nema podataka.");
    }
    else {
        fprintf(izlaz, "%s ima ukupno: %d stanovnika.\n", drzava, ukupan_br_stanovnika);
        for (int i = 0; i < rez; i++) {
            fprintf(izlaz, "%s ima %d stanovnika.\n", rezultat[i].grad, rezultat[i].br_stanovnika);
        }
    }


    return 0;
}
