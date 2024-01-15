/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/e5185117cb79d5328e6b6a5f9488b5a906273796/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DPretrazivanje%20matrice%202.jpeg
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void najmanji(int** polje, int n, int m, int *maxS, int *iznos);

int main()
{
    
    int n=0, m=0;
    int maxS=0, iznos=100;
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

    najmanji(polje, n, m, &maxS, &iznos);

    printf("Zbroj elemenata je najmanji u %d. stupcu i iznosi %d.", maxS, iznos);

    return 0;
}
void najmanji(int** polje, int n, int m, int* maxS, int* iznos) {
    int tempZbroj = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tempZbroj += polje[j][i];
        }
        if (tempZbroj < *iznos) {
            *iznos = tempZbroj;
            *maxS = i+1;
        }
        tempZbroj = 0;
    }
}
