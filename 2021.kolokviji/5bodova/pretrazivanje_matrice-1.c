/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/18bc1117040c5b7e971705d0d15a03e43ad7e81e/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DPretrazivanje%20matrice%201.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void najveci(int** polje, int n, int m, int *maxR, int *iznos);

int main()
{
    
    int n=0, m=0;
    int maxR=0, iznos=0;
    do {
        scanf("%d %d", &n,&m);
        if (n < 2 || n>100 || m<2 || m>100) {
            printf("Krivi unos.\n");
        }
    } while (n < 2 || n>100 || m < 2 || m>100);

    
    int** polje = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        polje[i] = (int*)malloc(m * sizeof(int));
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &polje[i][j]);
        }
    }

    najveci(polje, n, m, &maxR, &iznos);

    printf("Zbroj elemenata je najveci u %d. retku i iznosi %d.", maxR, iznos);

    return 0;
}
void najveci(int** polje, int n, int m, int* maxR, int* iznos) {
    int tempZbroj = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tempZbroj += polje[i][j];
        }
        if (tempZbroj > *iznos) {
            *iznos = tempZbroj;
            *maxR = i+1;
        }
        tempZbroj = 0;
    }
}
