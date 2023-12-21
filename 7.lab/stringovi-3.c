/*
Napisati C program koji za unesenu rečenicu:

1) ispituje od koliko riječi je sačinjena

Funkcionalnost je potrebno realizirati u funkciji prototipa: int prebroji(char *s);

Funkcija prebroji glavnoj funkciji vrača broj pronađenih riječi koji se zatim ispisuje na ekran. 

Ako rečenica ima samo jednu riječ od korisnika je potrebno zatražiti unos nove rečenice. Ako rečenica ima više od jedne riječi potrebno je pozvati funkciju promijeni koja će promijeniti rečenicu tako da svaka riječ počinje velikim slovom. Ostali znakovi u rečenici ostaju nepromijenjeni!



2) mijenja sadržaj rečenice tako da svaka riječ počinje velikim slovom

Ova funkcija poziva se ukoliko se rečenica sastoji od više riječi. Prototip funkcije je: char *promijeni(char *s);

Nakon što se u funkciji promijeni napravi zamjena, povratkom u glavnu funkciju ispisuje se nova rečenica na ekran.



3) traži riječ s najviše samoglasnika

Napisati funkciju najvise_s koja u znakovnom nizu traži riječ s najviše samoglasnika i ispisuje ju na zaslon. Ako su dvije riječi jednako duge ispisati prvu. Ova funkcija poziva iz glavne funkcije nakon što se izvrše točke 1) i 2).

Prototip funkcije najvise_s je: void najvise_s(char *s);

Test case 1:

Ulaz:
Bok!
Bok, kako si?

Izlaz:
Unesi novu recenicu:
3
Bok, Kako Si?
Kako

Test case 2:

Ulaz:
Danas je jedan jako lijep dan.

Izlaz:
6
Danas Je Jedan Jako Lijep Dan.
Danas

Test case 3:

Ulaz:
Danas je jedan jako lijep dan za
programiranje!

Izlaz:
8
Danas Je Jedan Jako Lijep Dan Za
Programiranje!
Programiranje
*/

```
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int prebroji(char* s) {

    int len = strlen(s);
    int br = 0;

    for (int i = 0; i < len; i++) {
        if (i == 0 || s[i - 1] == ' ' || s[i - 1] == '\n') {
            br++;
        }
    }
    if (br == 1) {
        return 0;
    }

    return br;
}

char* promjeni(char* s) {

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (i == 0 || s[i - 1] == ' ' || s[i - 1] == '\n') {
            s[i] = toupper(s[i]);
        }
    }

    return s;
}

void najvise_s(char* s) {
    int len = strlen(s);

    char* rijec = NULL;
    int br = 0;
    int max = 0;

    char* temp = strtok(s, " .,!?\n");

    while (temp != NULL) {
        br = 0;
        len = strlen(temp);

        for (int i = 0; i < len; i++) {
            if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u') {
                br++;
            }
        }
        

        if (br > max) {
            max = br;
            rijec = _strdup(temp);
        }
        temp = strtok(NULL, " .,!?\n");
    }

    printf("%s\n", rijec);
}


int main()
{
    char buffer[1000];
    char znak;
    scanf("%[^.?!] %c%*c", buffer, &znak);
    char* s = _strdup(buffer);

    int rez = prebroji(s);

    while (rez == 0) {
        printf("Unesi novu recenicu:\n");
        scanf("%[^.!?] %c%*c", buffer, &znak);
        s = _strdup(buffer);
        rez = prebroji(s);
    }

    printf("%d\n", rez);

    s = promjeni(s);

    printf("%s%c\n", s, znak);

    najvise_s(s);

    return 0;
}
```
