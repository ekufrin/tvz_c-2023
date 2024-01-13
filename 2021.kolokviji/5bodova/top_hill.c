/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/e23a92eedea82857fd0424601ad46fbd11ae4125/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DTop%20hill.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 10

void funkcija(int matrica[][MAX], int n, int m);

int main() {

    int matrica[MAX][MAX] = { 0 }, n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }

    funkcija(matrica, n, m);

    return 0;
}

void funkcija(int matrica[][MAX], int n, int m)
{
    int maxBroj = 0, red, stupac, k = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrica[i][j] > matrica[i - 1][j] && matrica[i][j] > matrica[i + 1][j] &&
                matrica[i][j] > matrica[i][j - 1] && matrica[i][j] > matrica[i][j + 1]) {
                if (matrica[i][j] > maxBroj) {
                    maxBroj = matrica[i][j];
                    red = i;
                    stupac = j;
                }
                k++;
            }
        }
    }

    if (k == 0)
        printf("Ne postoji trazeni element.");
    else 
        printf("Najveci je %d, na lokaciji [%d, %d]", maxBroj, red, stupac);
    
}
