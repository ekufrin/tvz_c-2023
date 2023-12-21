/*Napisati C program koji za uneseni znakovni niz :
1) ispituje koliko u nizu ima riječi koje počinju velikim slovom
Funkcionalnost je potrebno realizirati u funkciji prototipa : int prebroji(char* s);
Funkcija prebroji glavnoj funkciji vrača broj pronađenih riječi koje počinju velikim slovom, a koji se zatim ispisuje na ekran.
2) ispisuje niz tako da se svaka rečenica ispisuje u novom redu
Prototip funkcije je : void ispis(char* s);
Funkcija se poziva iz glavne funkcije.Ukoliko se niz sastoji samo od jedne rečenice umjesto te rečenice potrebno je ispisati poruku
"Niz se sastoji od samo jedne recenice."
Napomena: rečenica uvijek počinje velikim slovom.Rečenice su odvojene interpunkcijom.

Test case #1
Primjer ulaza:
Bok!
Primjer izlaza:
1
Niz se sastoji od samo jedne recenice.

Test case #2
Primjer ulaza:
Danas je jedan jako lijep dan. Zar NE?
Primjer izlaza:
3
Danas je jedan jako lijep dan.
Zar NE?

Test case #3
Primjer ulaza:
Danas Je jedAn jako Lijep DAN za programiranje! Zar ne? ProgramirajmO!
Primjer izlaza:
6
Danas Je jedAn jako Lijep DAN za programiranje!
Zar ne?
ProgramirajmO!

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int prebroji(char* s) {
    int brojac = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ' && isupper(s[i+1])) {
            brojac++;
        }
    }
    if (isupper(s[0])) {
        brojac++;
    }

    return brojac;
}

void ispis(char* s) {
    int brojac = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '!' || s[i] == '?' || s[i] == '.') {
            brojac++;
        }
    }

    if (brojac == 1) {
        printf("Niz se sastoji od samo jedne recenice.");
    }
    else {
        for (int i = 0; i < strlen(s); i++) {

            if (s[i-1] == '!' || s[i-1] == '?' || s[i-1] == '.') {
                printf("\n");
            }
            else {
                printf("%c", s[i]);
            }
        }
    }
}

int main()
{

    char* recenica = (char*)calloc(100, sizeof(char));

    scanf("%[^\n]%*c", recenica);
    printf("%d\n", prebroji(recenica));

    ispis(recenica);


    return 0;
}
