/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/3d942f58053cff89a40ad6595e9e733f86ba56c4/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B2%5D%20Portugalska%20imena.pdf
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* skrati(char* puno_ime);

int main() {
    
    char puno_ime[100];

    scanf("%[^\n]%*c", puno_ime);
    printf("%s", skrati(puno_ime));
    return 0;
}
char* skrati(char* puno_ime) {
    char* token = strtok(puno_ime, " ");
    char rezultat[10][100];
    int br = 0;
    strcpy(rezultat[0], token);
    while (token!=NULL) {
        strcpy(rezultat[br++], token);
        token = strtok(NULL, " ");
    }
    strcpy(puno_ime, rezultat[0]);
    strcat(puno_ime, " ");
    strcat(puno_ime, rezultat[br - 1]);
  
    return puno_ime;
}
