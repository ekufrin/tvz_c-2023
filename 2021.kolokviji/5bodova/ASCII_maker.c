/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/eed8701fe9482f04924781d070228821127f9573/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DASCII%20maker.pdf
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void maxASCII(char* recenica);

int main() {

    char recenica[MAX] = { 0 };

    scanf("%[^.]*c", recenica);
    recenica[strlen(recenica)] = '.';

    maxASCII(recenica);

    return 0;
}

void maxASCII(char* recenica) {
    int maxSuma = 0, j = 0, suma = 0;
    char rijec[MAX] = { 0 }, maxRijec[MAX] = { 0 };
    for (int i = 0; i < strlen(recenica); i++) {
        if (recenica[i] != ' ' && recenica[i] != '\n' && recenica[i] != '.') {
            rijec[j] = recenica[i];
            suma += (int)recenica[i];
            j++;
        }
        else {
            if (suma > maxSuma) {
                maxSuma = suma;
                strcpy(maxRijec, rijec);
            }
            else if (suma == maxSuma) {
                for (int k = 0; k < strlen(maxRijec); k++) {
                    if ((int)tolower(rijec[i]) < (int)tolower(maxRijec[i])) {
                        maxSuma = suma;
                        strcpy(maxRijec, rijec);
                        break;
                    }
                    else if ((int)tolower(rijec[i]) > (int)tolower(maxRijec[i])) {
                        break;
                    }
                }
            }
            rijec[0] = '\0';
            j = 0;
            suma = 0;
        }
    }

    printf("%s: %d", maxRijec, maxSuma);
}
