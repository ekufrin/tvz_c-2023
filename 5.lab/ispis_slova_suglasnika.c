/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/bfa3afe12e249181d0f660b04d81292996bced81/tekstovi%20i%20test%20caseovi/%5B5%5D%20Ispis%20slova%20-%20suglasnika.jpg
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int prebroji(char niz[100], char X, char Y,int N) {
    int brojac = 0;
    for (int i = 0; i <N; i++) {
        if (niz[i] >= X && niz[i] <= Y) {
            if (niz[i] != 'a' && niz[i] != 'e' && niz[i] != 'i' && niz[i] != 'o' && niz[i] != 'u') {
                brojac++;
            }
        }
       
    }

    return brojac;
}

int main()
{
    char X, Y;
    char niz[200];
    int N = 0;
    do {
        scanf(" %c", &X);
        scanf(" %c", &Y);
        if (X > Y) {
            printf("Neispravan unos!\n");
        }
    } while (X > Y);

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%c ", &niz[i]);
    }


     


     printf("Ukupno malih suglasnika: %d\n",prebroji(niz, X, Y,N));
     int brojacreda = 0;
     for (int i = 0; i < N; i++) {
         
             if (niz[i] >= X && niz[i] <= Y) {
                 if (niz[i] != 'a' && niz[i] != 'e' && niz[i] != 'i' && niz[i] != 'o' && niz[i] != 'u') {
                     printf("%c ", niz[i]);
                     brojacreda++;
                     
                 }
                 
             }
             if (brojacreda == 2) {
                 printf("\n");
                 brojacreda = 0;
             }
     }
     

    return 0;
}
