/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/d3c190ca70691ad94ec6009b7adc948c8a532e8c/tekstovi%20i%20test%20caseovi/%5B6%5DVideoteka.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void pronadjiFilm(char** polica, int n, int m);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char** polica = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        polica[i] = (char*)malloc(sizeof(char) * m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &polica[i][j]);
        }
    }

    int dostupno = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (polica[i][j] == 'N' &&
                polica[i][j + 1] == 'N' &&
                polica[i][j + 2] == 'N') {
                dostupno = 1;
            }
        }
    }

    if (dostupno) {
        printf("Posudba filmova:");
        pronadjiFilm(polica, n, m);
    }
    else {
        printf("Sve smo skoro gledali :(");
    }
    
    for (int i = 0; i < n; i++) {
        free(polica[i]);
    }
    free(polica);

    return 0;
}

void pronadjiFilm(char** polica, int n, int m) {
    int posudeni = 0;
    for (int i = n - 1; i > 0; i--) {
        for (int j = m - 1; j > 0; j--) {
            if (polica[i][j] == 'N' &&
                polica[i][j - 1] == 'N' &&
                polica[i][j - 2] == 'N' &&
                posudeni == 0) {
                printf(" [%d, %d], [%d, %d] i [%d, %d]", i + 1, j - 1, i + 1, j, i + 1, j + 1);
                posudeni = 1;
            }
        }
    }
}
