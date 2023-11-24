/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/76fa8c1c27e61a2d697981185a4f9970554c27b6/tekstovi%20i%20test%20caseovi/%5B4%5DProsjek%20kolegija.jpeg
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0;
    int br = 0;
    float ocjene[50][50] = { 0 };

    do {
        scanf("%d", &n);
        if (n < 2 || n>10) {
            printf("Pogresan unos broja. Unesite ponovno broj studenata.\n");
        }
    } while (n < 2 || n>10);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%f", &ocjene[i][j]);
        }
    }


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            if (ocjene[j][i] >= 50) {
                ocjene[n][br]++;
            }
        }
        ocjene[n][br] *= (float)100 / (float)n;
        br++;
        
    }
    printf("Prolaznost:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%.f\t", ocjene[i][j]);
        }
        printf("\n");
    }

    return 0;
}
