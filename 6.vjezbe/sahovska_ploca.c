/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/f24b30d493a55feb36d1d78db074299fe386d9fd/tekstovi%20i%20test%20caseovi/%5B6%5DSahovskaPloca.pdf
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void upisi(char** niz, int n, int m);
void ispisi(char** niz, int n, int m);

int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    char** niz = (char**)malloc(N * sizeof(char*));

    for (int i = 0; i < N; i++) {
        niz[i] = (char*)malloc(M * sizeof(char));
    }

    upisi(niz, N, M);
    ispisi(niz, N, M);

    for (int i = 0; i < N; i++) {
        free(niz[i]);
    }
    free(niz);

    return 0;
}

void upisi(char** niz, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < 2) {
                niz[i][j] = 'C';
            } else if (i >= n - 2) {
                niz[i][j] = 'B';
            } else {
                if (i % 2 == 0) {
                    if (j % 2 == 0) {
                        niz[i][j] = 'O';
                    } 
                    else {
                        niz[i][j] = 'X';
                    }
                }
                else {
                    if (j % 2 == 1) {
                        niz[i][j] = 'O';
                    } 
                    else {
                        niz[i][j] = 'X';
                    }
                }
            }
        }
    }
}

void ispisi(char** niz, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", niz[i][j]);
        }
        printf("\n");
    }
}
