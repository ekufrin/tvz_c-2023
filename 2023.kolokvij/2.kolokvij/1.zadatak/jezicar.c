/*
TEKST: Upisuj rečenice dok se ne upiše riječ "KRAJ". Nakon toga upiši broj char znakova koje će se učitati i nakon toga toliko char
znakova. Rastavi rečenicu na pojedinačne riječi (riječi su sve što ne sadrži interpukcijske znakove) i ispiši sve riječi sadrže
upisane znakove pozivajući funkciju char** nadjiRijeci(char** tekst, int n, char c) gdje su:
tekst - polje sa rastavljenim riječima
n- broj riječi
c - znak koji se pretražuje u rečenici
funkcija vraća sve riječi koje sadrže taj znak i potrebno je ispisati sve te riječi u main funkciji.

Test caseovi: https://github.com/emanuelkufrin/tvz_c-2023/blob/14c864520c23f00c7ed6f83578b7ac6477aef1ca/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B2%5DJezicar.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char** nadjiRijeci(char** tekst, int n, char c);
int main()
{
    char* unos = malloc(sizeof(char) * 1000);
    char** kon = malloc(sizeof(char*) * 1000);
    int brojac = 0;
    for (int i = 0; i < 1000; i++) kon[i] = malloc(sizeof(char) * 30);
    kon[0] = '\0';
    scanf("%[^\n]%*c", unos);
    while (strcmp(unos, "KRAJ") != 0) {
        char* portion = malloc(sizeof(char) * 30);
        portion = strtok(unos, " -.!?,");
        while (portion != NULL) {
           // printf("%s\n", portion);
            kon[brojac] = malloc(sizeof(char) * 30);
            kon[brojac][0] = '\0';
            strcpy(kon[brojac], portion);
            brojac++;
            portion = strtok(NULL, " -.!?,");
        }
        scanf("%[^\n]%*c", unos);
    }
    int brojIteracija;
    scanf("%d", &brojIteracija);
    for (int i = 0; i < brojIteracija; i++) {
        int brojilo = 0;
        char zn;
        scanf(" %c", &zn);
        char** trazene = malloc(sizeof(char*) * 100);
        for (int j = 0; j < 100; j++) trazene[j] = malloc(sizeof(char) * 30);
        trazene = nadjiRijeci(kon, brojac, zn);


        for (int j = 0; j < brojac; j++) {
            if (strchr(kon[j], zn)) {
                brojilo++;
            }
        }


        printf("Rijeci koje sadrze slovo %c:\n", zn);
        for (int i = 0; i < brojilo; i++) {
            printf("%s\n", trazene[i]);
        }
    }
}
char** nadjiRijeci(char** tekst, int n, char c) {
    char** rijeci = malloc(sizeof(char*) * 100);
    for (int j = 0; j < 100; j++) rijeci[j] = malloc(sizeof(char) * 30);
    int brojac = 0;
    for (int i = 0; i < n; i++) {
        if (strchr(tekst[i], c)) {
            rijeci[brojac][0] = '\0';
            strcpy(rijeci[brojac], tekst[i]);
            brojac++;
        }
    }
    return rijeci;
}
