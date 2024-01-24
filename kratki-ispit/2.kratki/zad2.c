/*
TEKST ZADATKA:
Dovršite sljedeći program kojim ćete prihvatiti argumente s komandne linije, ako komandna linija glasi:
C:>prog 333 nadnoknada 2

Brojeve pridružite cjelobrojnim varijablama, a stringove pokazivačima odgovarajućeg tipa.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(int argc, char* argv[]) {
    char* p1, * p2;
    int b1, b2;

    p1 = argv[0];
    p2 = argv[2];
    b1 = atoi(argv[1]);     // svi ulazi s komandne linije se spremaju kao stringovi, stoga je potrebno koristiti funkciju atoi
    b2 = atoi(argv[3]);     // atoi pretvara string u int;


    //argc je broj elemenata koji se upisuje u komandnu liniju +1, u ovom slucaju 4+1=5
    //argv krece od 0 i to je niz elemenata po redu koji su upisani u komandnu liniju
    //isprintajte p1,p2,b1,b2 za više informacija
}
