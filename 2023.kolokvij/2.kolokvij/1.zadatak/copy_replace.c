/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/847128c0ec0c99043bbad9ce1ce483b936d5dcb5/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B2%5DCopy_replace.pdf

KOD RADI SAMO ZA 1.TEST CASE !!!
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void replace(char* recenica, char* nadi, char* zamjeni) {
    char* token;

    token = strstr(recenica, nadi);
    while (token != NULL) {
        strncpy(recenica + (strlen(recenica) - strlen(token)), zamjeni, strlen(zamjeni));
        token = strstr(recenica, nadi);
    }
}

int main()
{

    char recenica[100];
    char nadi[20];
    char zamjeni[20];
    scanf("%[^KRAJ]KRAJ%*c", recenica);
    scanf("%[^\n]%*c", nadi);
    scanf("%[^\n]%*c", zamjeni);

    replace(recenica, nadi, zamjeni);

    printf("%s", recenica);

    return 0;
}
