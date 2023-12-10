/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/a47f897441c1c2f63607d56b7e0519c705a1c31c/tekstovi%20i%20test%20caseovi/%5B6%5DHacijenda.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int brPodjela = 0;
int vodoravno[1000] = { 0 };
int counterV = 0;
int okomito[1000] = { 0 };
int counterO = 0;
void provjeraVodoravno(char* imanje, int redak, int stupac, int redProvjere) {
    int M1 = 0, P1 = 0, G1 = 0;
    int M2 = 0, P2 = 0, G2 = 0;
    for (int i = 0; i < redProvjere; i++) {
        for (int j = 0; j < stupac; j++) {
            if (*(imanje + i * stupac + j) == 'M')
                M1++;
            else if (*(imanje + i * stupac + j) == 'P')
                P1++;
            else if (*(imanje + i * stupac + j) == 'G')
                G1++;
        }
    }
    for (int i = redProvjere; i < redak; i++) {
        for (int j = 0; j < stupac; j++) {
            if (*(imanje + i * stupac + j) == 'M')
                M2++;
            else if (*(imanje + i * stupac + j) == 'P')
                P2++;
            else if (*(imanje + i * stupac + j) == 'G')
                G2++;
        }
    }
    if (M1 == M2 && P1 == P2 && G1 == G2) {
        brPodjela++;
        vodoravno[counterV++] = redProvjere;
    }
}
void provjeraOkomito(char* imanje, int redak, int stupac, int stupacProvjere) {
    int M1 = 0, P1 = 0, G1 = 0;
    int M2 = 0, P2 = 0, G2 = 0;
    for (int i = 0; i < redak; i++) {
        for (int j = 0; j < stupacProvjere; j++) {
            if (*(imanje + i * stupac + j) == 'M')
                M1++;
            else if (*(imanje + i * stupac + j) == 'P')
                P1++;
            else if (*(imanje + i * stupac + j) == 'G')
                G1++;
        }
    }
    for (int i = 0; i < redak; i++) {
        for (int j = stupacProvjere; j < stupac; j++) {
            if (*(imanje + i * stupac + j) == 'M')
                M2++;
            else if (*(imanje + i * stupac + j) == 'P')
                P2++;
            else if (*(imanje + i * stupac + j) == 'G')
                G2++;
        }
    }
    if (M1 == M2 && P1 == P2 && G1 == G2) {
        brPodjela++;
        okomito[counterO++] = stupacProvjere;
    }
}
int main() {
    int redak = 0, stupac = 0;
    scanf("%d%d", &redak, &stupac);
    char* imanje = (char*)malloc(redak * stupac * sizeof(char));
    for (int i = 0; i < redak; i++) {
        for (int j = 0; j < stupac; j++) {
            scanf(" %c", (imanje + i * stupac + j));
        }
    }
    for (int i = 0; i < redak; i++) {
        provjeraVodoravno(imanje, redak, stupac, i);
    }
    for (int i = 0; i < stupac; i++) {
        provjeraOkomito(imanje, redak, stupac, i);
    }
    if (brPodjela != 0) {
        int zadnji = 0;
        printf("Broj mogucih podjela: %d\n", brPodjela);
        for (int i = 0; i < counterV; i++) {
            printf("%d. Vodoravno, izmedju retka br. %d i br. %d\n", i + 1, vodoravno[i], vodoravno[i] + 1);
            zadnji = i + 1;
        }
        for (int i = 0; i < counterO; i++) {
            printf("%d. Okomito, izmedju stupca br. %d i br. %d\n", zadnji + i + 1, okomito[i], okomito[i] + 1);
        }
    }
    else {
        printf("Nemoguce podijeliti 50-50.");
    }
    return 0;
}
