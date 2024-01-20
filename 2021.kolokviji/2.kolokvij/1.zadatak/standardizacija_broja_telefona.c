/*
TEKST ZADATKA:
Unosi se broj telefona i pomocu funkcije char* standardiziraj(char* mob) potrebno je ispisati standardizirani zapis broja telefona.

TEST CASEOVI:
https://github.com/emanuelkufrin/tvz_c-2023/blob/06bd88d7b2829aba1b149a5aef09f8a76632399e/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DStandardizacija%20broja%20telefona.pdf
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* standardiziraj(char* mob) {

    char broj1[11] = {};
    char newNum[16] = "+385 ";
    char* pBr = newNum;
    int brojac = 0, i, j, trig = 0;

    for (i = 0; i < strlen(mob); i++) {
        if (mob[i] == '9') {
            for (j = i; j < strlen(mob); j++) {
                if (mob[j] >= '0' && mob[j] <= '9') {
                    broj1[brojac] = mob[j];
                    brojac++;
                    if (brojac == 2) {
                        broj1[brojac] = ' ';
                        brojac++;
                    }
                    if (brojac == 6) {
                        broj1[brojac] = '-';
                        brojac++;
                    }
                }
            }
        }
        if (j == strlen(mob)) break;
    }

    strcat(newNum, broj1);
    printf("%s", newNum);
}


int main()
{
    char mob[100] = {};

    scanf("%[^\n]%*c", &mob);
    standardiziraj(mob);

}
