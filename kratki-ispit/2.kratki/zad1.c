/*
TEKST ZADATKA:
U glavnoj funkciji definirano je polje i poziv funkcije arg.
Koju vrijednost vraća funkcija arg?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arg(int* b, int n) {    // int *b postaje polje+2 odnosno broj 17, dok n je broj 3
    int i = 0;
    int gg = *b;            //gg poprima vrijednost 17
    int* p = b;             //p poprima adresu b, odnosno broja 17;

    do {
        if (*p > gg) gg = *p; // Je li 17 > 17? Ne      |   Je li 14 > 17? Ne       | Je li 11 > 17? Ne
    } while (++i < n && p++); // i povecavamo za 1, adresu p povecavamo za 1 te je to sada broj 14      | i povecavamo za 1 opet, p opet povecavamo za 1, to je sada broj 11        |   i povecavamo za 1, 3 < 3 je neistina, zavrsavamo sa petljom.

    return gg;  // Pošto u sva 3 slučaja je p bio manji od gg, gg je ostao nepromijenjen, odnosno 17, te ga vraćamo u main
}

int main() {
    int polje[] = {13,18,17,14,11,60};
    int rezultat = arg(polje + 2, 3);    // polje+2 je treci element polja, odnosno broj 17
    printf("%d", rezultat); // ispisujemo broj 17
    return 0;
}
