/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/e4cc14f0ab4d527e7d235a43fa15ec439201e3fb/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DVelicina%20gradova.PDF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char drzava[MAX];
    char grad[MAX];
    long int brojStanovnika;
    float povrsina;
    int glavniGrad;
} popis;

int main() {
    char trazenaDrzava[MAX] = { 0 };
    scanf("%s", trazenaDrzava);

    FILE* ulaz = fopen("gradovi.txt", "r");
    FILE* izlaz = fopen("rezultati.txt", "w");

    if (ulaz == NULL || izlaz == NULL) {
        printf("Neuspješno otvaranje datoteke.");
        return 1;
    }

    popis gradovi[MAX];
    int br = 0;
    int ukupnoStanovnika = 0;

    while (fscanf(ulaz, "%s %s %ld %f %d", gradovi[br].drzava, gradovi[br].grad, &gradovi[br].brojStanovnika, &gradovi[br].povrsina, &gradovi[br].glavniGrad) != EOF) {
        if (strcmp(trazenaDrzava, gradovi[br].drzava) == 0) {
            ukupnoStanovnika += gradovi[br].brojStanovnika;
        }
        br++;
    }

    if (ukupnoStanovnika == 0) {
        fprintf(izlaz, "Nema podataka.");
    }
    else {
        fprintf(izlaz, "%s ima ukupno: %d stanovnika\n", trazenaDrzava, ukupnoStanovnika);

        for (int i = 0; i < br; i++) {
            if (strcmp(trazenaDrzava, gradovi[i].drzava) == 0) {
                fprintf(izlaz, "%s ima %ld stanovnika\n", gradovi[i].grad, gradovi[i].brojStanovnika);
            }
        }
    }

    fclose(ulaz);
    fclose(izlaz);

    return 0;
}
