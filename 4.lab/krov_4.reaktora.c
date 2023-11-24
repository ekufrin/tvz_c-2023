/*
RADI SAMO ZA PRVIH 7 TEST CASEOVA :(

TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/e9ff00b0f9d773acc6500f0c546aaa0369431985/tekstovi%20i%20test%20caseovi/%5B4%5DKrov%204.reaktora.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    // 1 pomak = 1 e
    // 1 blok = 1 e

    int s=0, r=0, e = 0;
    int br = 0;
    char krov[10][10] = { 0 };

    // Unos podataka
    scanf("%d %d %d", &s, &r, &e);
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < r; j++) {
            scanf(" %c", &krov[i][j]);
        }
    }

    // Pomicanje robota
        for (int j = 1; j <= e+1; j++) {
            if (krov[br][j] == '.' && e >=1) {
                krov[br][j]='#';
                krov[br][j-1] = '.';
                e-=1;
                //printf("Skinuo sam 1 energiju, ostalo je %d\n", e);
            }
            if (krov[br][j - 1] == '#' && krov[br][j] == 'x' && e >= 3) {
                krov[br][j] = '#';
                krov[br][j - 1] = '.';
                e -= 3;
                //printf("Skinuo sam 3 energije, ostalo je %d\n", e);
            }
            if (krov[br][j] == 'x' && e >= 2) {
                krov[br][j]='#';
                krov[br][j - 1] = '.';
                e-=2;
                //printf("Skinuo sam 2 energije, ostalo je %d\n", e);
             }
            if (krov[br][j] == '#' && j==r-1 && e<r-1) {
                krov[br][j] = '.';
                for (int z = e; z >= 0; z--) {
                    if (z == 0) {
                        krov[br][z] = '#';
                    }
                    else {
                        krov[br][z--] = '.';
                    }
                }
                e = 0;
            }
            else if (j == r-1  && e >= r-1) {
                //printf("NOVI RED!!!");
                krov[br][j] = '.';
                krov[br+1][j-r+1] = '#';
            }
            
        }
    //Ispis podataka
    printf("----------------------------------\n");
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < r; j++) {
            printf("%c", krov[i][j]);
        }
        printf("\n");
    }

    return 0;
}
