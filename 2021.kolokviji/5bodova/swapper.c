/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/f43e337fd171093c4b94935f0889bb744e2f9ecc/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DSwapper.pdf
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 100

char* rotate(char* a, char* b);

int main() {

    char prvi[MAX] = { 0 }, drugi[MAX] = { 0 };

    scanf("%s", prvi);
    scanf("%s", drugi);

    printf("%s", rotate(prvi, drugi));

    return 0;
}

char* rotate(char* a, char* b) {
    for (int i = 0; i < strlen(b) / 2; i++) {
        char temp = b[i];
        b[i] = b[strlen(b) - i - 1];
        b[strlen(b) - i - 1] = temp;
    }

    strcat(b, a);

    char podString[MAX] = {0};
    int j = 0;
    for (int i = 0; i < strlen(b); i++) {
        if (i % 2 != 0) {
            podString[j] = b[i];
            j++;
        }
    }

    int k = 0;
    for (int i = 0; i < strlen(b); i++) {
        if (b[i] == podString[k]) {
            char temp = b[i];
            for (int j = i; j < strlen(b); j++) {
                b[j] = b[j + 1];
            }
            b[strlen(b)] = temp;
            k++;
        }
    }

    return b;
}
