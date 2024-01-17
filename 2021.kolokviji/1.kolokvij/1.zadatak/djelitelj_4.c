/*
Napisite C program koji ce traziti unos 2 prirodna broja A i B, gdje je broj A u intervalu [10, B], a broj B u intervalu [A, 1000000. Ukoliko neki od brojeva nisu u intervalu, potrebno je ponoviti unos oba broja.
Kao rezultat je potrebno ispisati sve brojeve u intervalu [A, B] koji su djeljivi sa zbrojem svoje prve i zadnje znamenke.
Test case-ovi:
Ulaz:
10 20
Izlaz:
19 12 18 20

Ulaz:
20 10
102 131
Izlaz:
Neispravan unos!
102 108 110 120 126 130

Ulaz:
5 1000
1000 1000001
9965 10014
Izlaz:
Neispravan unos!
Neispravan unos!
9984 9990 10000 10002 10008 10010
*/

#include <stdio.h>

int main() {
    
    int a, b;
    
    do {
        scanf("%d %d", &a, &b);
        if (a < 10 || a > b || b > 1000000) {
            printf("Neispravan unos!\n");
        }
    } while (a < 10 || a > b || b > 1000000);
    
    for (int i = a; i <= b; i++) {
        int temp = i;
        int zadnjaZnamenka = temp % 10;
        while (temp > 10) {
            temp /= 10;
        }
        int prvaZnamenka = temp;
        if (i % (prvaZnamenka + zadnjaZnamenka) == 0) {
            printf(" %d", i);
        }
    }
    
    return 0;
}
