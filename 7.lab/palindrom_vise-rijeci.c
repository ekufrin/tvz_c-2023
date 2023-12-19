/*
Provjeravamo recenicu da li je polindrom (da li se pise isto i s lijeve i s desne strane). Detaljnije u test case-ovima.
Zanemarujemo interpunkcijeske znakove i velika i mala slova.

Test case-ovi:
Ulaz:
Ana voli: Milovana!
Izlaz:
Ana voli: Milovana! je polindrom.

Ulaz:
Star? Not I! Movie. I vomit on rats.
Izlaz;
Star? Not I! Movie. I vomit on rats. je polindrom.

Ulaz:
keks
Izlaz:
keks nije polindrom

Ulaz:
a N a V o l i m i l o v a na .
Izlaz:
a N a V o l i m i l o v a na . je polindrom.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int palindrom(char* cistString);

int main()
{
    char string[MAX] = { 0 }, cistString[MAX] = { 0 };

    // unosimo string dok ne unesemo znak za novi red (enter = \n)
    scanf("%[^\n]", string); 
    
    // pregledavamo string znak po znak i ako naidjemo na slovo pretvorimo ga u malo slovo i upisemo u cistString
    int j = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (isalpha((int)string[i])) {
            cistString[j] = tolower((int)string[i]);
            j++;
        }
    }
   
    if (palindrom(cistString)) {
        printf("%s je palindrom.", string);
    }
    else {
        printf("%s nije palindrom.", string);
    }

    return 0;
}

/* usporedujemo prvi znak sa zadnjim, drugu sa predzadnjim...itd. 
i ako nisu jednaki vracamo 0, a ako se petlja izvrsi do kraja vracamo 1 */

int palindrom(char* cistString) {
    for (int i = 0; i < strlen(cistString) / 2; i++) {
        if (cistString[i] != cistString[strlen(cistString) - i - 1]) {
            return 0;                                          //^ -1 je zato sto je uvijek zadnji znak u stringu \0
        }
    }
    return 1;
}
