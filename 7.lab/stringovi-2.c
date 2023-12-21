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

int prebroji(char* s);
char* promijeni(char* s);

int main()
{
    char* s = (char*)calloc(200, sizeof(char));
    char* s2 = (char*)calloc(200, sizeof(char));

    scanf("%[^\n]%*c", s);

    int broj = prebroji(s);
    while (broj == 1)
    {
        printf("Neispravan unos.\n");
        scanf("%[^\n]%*c", s2);
        broj = prebroji(s2);
        strcpy(s, s2);
    }

    printf("%d\n", broj);
    char* ss = promijeni(s);
    printf("%s", ss);

    return 0;
}

int prebroji(char* s)
{
    int br = 0;
    char* tmp2 = (char*)calloc(strlen(s) + 1, sizeof(char));
    strcpy(tmp2, s);
    char* tmp = strtok(tmp2, "!?.");
    while (tmp != NULL)
    {
        br++;
        tmp = strtok(NULL, "!?.");
    }
    return br;
}

char* promijeni(char* s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isupper(s[i]) && (i == 0 || s[i - 1] == ' '))
            s[i] = tolower(s[i]);
    }
    return s;
}
