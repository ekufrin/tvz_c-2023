/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/9e24f2255d6c5cfe59b6d72a173b8671534875be/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DEmail.pdf
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* adresa(char* ime, char* prezime) {
    char* string = (char*)malloc(sizeof(char) * (strlen(ime) + strlen(prezime) + 9));

    if (strlen(ime) + strlen(prezime) <= 10)
        sprintf(string, "%s.%s@tvz.hr", ime, prezime);
    else if (strlen(ime) + strlen(prezime) > 10 && strlen(prezime) > 6)
        sprintf(string, "%c.%c%c%c%c%c1@tvz.hr", ime[0], prezime[0], prezime[1], prezime[2], prezime[3], prezime[4]);
    else
        sprintf(string, "%c.%s@tvz.hr", ime[0], prezime);

    return string;
}

int main() {
    char ime[100], prezime[100];
    scanf("%[^ ] %s", ime, prezime);
    char* string = adresa(ime, prezime);
    printf("%s", string);

    return 0;
}
