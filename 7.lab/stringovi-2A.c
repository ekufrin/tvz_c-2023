/*Napisati C program koji za uneseni znakovni niz :
1) ispituje od koliko rečenica je sačinjen
Funkcionalnost je potrebno realizirati u funkciji prototipa : int prebroji(char* s);
Funkcija prebroji glavnoj funkciji vrača broj pronađenih rečenica koji se zatim ispisuje na ekran.
Napomena: pretpostavite da rečenica uvijek započinje velikim slovom i završava nekim od znakova interpunkcije.Rečenice su
odvojene razmacima.
Ako niz ima samo jednu rečenicu od korisnika je potrebno zatražiti unos novog niza uz ispis poruke "Neispravan unos.".Ako niz
ima više od jedne rečenice potrebno je pozvati funkciju promijeni koja će promijeniti niz tako da svaka riječ počinje malim slovom.
Ostali znakovi u rečenici ostaju nepromijenjeni!
2) mijenja sadržaj niza tako da svaka riječ počinje malim slovom
Ova funkcija poziva se ukoliko se niz sastoji od više rečenica.Prototip funkcije je : char* promijeni(char* s);
Nakon što se u funkciji promijeni napravi zamjena, povratkom u glavnu funkciju ispisuje se novi niz na ekran.

Primjer ulaza:
Bok! Bok, kako si?
Primjer izlaza:
2
bok! bok, kako si?

Primjer ulaza:
Danas je jedan jako lijep dan.
Danas je jedan jako lijep dan. Zar NE?
Primjer izlaza:
Neispravan unos.
2
danas je jedan jako lijep dan. zar nE?

Primjer ulaza:
Danas Je jedAn jako Lijep DAN za programiranje! Zar ne? ProgramirajmO!
Primjer izlaza:
3
danas je jedAn jako lijep dAN za programiranje! zar ne? programirajmO!
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
        if (s[i] == '!' || s[i] == '?' || s[i] == '.') {
            brojac++;
        }
    }

    return brojac;
}

char* promijeni(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if (isupper(s[0])) {
            s[0] = tolower(s[0]);
        }
        else if (s[i] == ' ') {
            s[i + 1] = tolower(s[i + 1]);
        }
    }

    return s;
}

int main()
{
   
    char* recenica=(char*)calloc(100,sizeof(char));

    do {
        scanf("%[^\n]%*c", recenica);
        if (prebroji(recenica) == 1) {
            printf("Neispravan unos.\n");
        }
        else {
            printf("%d\n", prebroji(recenica));
            break;
        }
    } while (1);
   
    printf("%s", promijeni(recenica));


    return 0;
}
