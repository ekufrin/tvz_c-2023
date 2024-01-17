/*1. kolokvij, zadatak za 5 bodova: Ne vidim tekst zadatka ali išao je nešto kao: unesi broj A i B koji moraju biti u granicama <9, 99) i čija razlika mora biti barem 20. Ukoliko je neki broj krivo unesen ponovi unos samo za njega. Treba izračunati zbroj znamenki ta dva broja i prikazati članove niza A-B koji su djeljivi sa tim zbrojem znamenki.

Test caseovi: 
Ulaz: 100 
        9 
        9 
        99 
        30
Izlaz: 21
       42 63 84
       
Ulaz:   105 
        78
        12
Izlaz 18
        18 36 54 72

Ulaz: 50
    2
    31
    13
    45
Izlaz: 13
        13 26 39*/
#include <stdio.h>
#include <math.h>

int unesiBroj() {
    int broj;
    do {
        scanf("%d", &broj);
    } while (broj <= 9 || broj > 99);
    
    return broj;
}

int zbrojZnamenki(int broj) {
    int zbroj = 0;
    while (broj > 0) {
        zbroj += broj % 10;
        broj /= 10;
    }
    return zbroj;
}

int main() {
    
    int a, b;
    
    do {
       a = unesiBroj();
       b = unesiBroj();
    } while (abs(abs(a)-abs(b)) < 20);
    
    int zbrojSvihZnamenki = zbrojZnamenki(a) + zbrojZnamenki(b);
    
    printf("%d\n", zbrojSvihZnamenki);
    
    if (a > b) {
        for (int i = b; i <= a; i++) {
            if (i % zbrojSvihZnamenki == 0) {
                printf("%d ", i);
            }
        }
    }
    else if (a < b) {
        for (int i = a; i <= b; i++) {
            if (i % zbrojSvihZnamenki == 0) {
                printf("%d ", i);
            }
        }
    }

    return 0;
}
