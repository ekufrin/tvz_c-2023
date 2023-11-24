/*1. Napisite C program koji ce traziti unos 2 prirodna broja A i B, gdje je broj A u intervalu [10, B] a broj B u intervalu [A, 100000]. Ukoliko neki od brojeva nisu u zadanom intervalu, potrebno je ponoviti unos oba broja.

Kao rezultat je potrebno ispisati sve brojeve u intervalu [A, B] koji su djeljivi sa zbrojem svoje prve i zadnje znamenke.

Nema test case-ova
*/

#include <stdio.h>

int main() {
    
    int a, b;
    
    do {
        scanf("%d %d", &a, &b);
        
    } while (a < 10 || a > b || b < a || b > 10000);
    
    for (int i = a; i <= b; i++) {
        int zadnjaZnamenka = i % 10;
        int temp = i;
        while (temp > 10) {
            temp /= 10;
        }
        int prvaZnamenka = temp;
        if (i % (prvaZnamenka + zadnjaZnamenka) == 0) {
            printf("%d je djeljiv sa %d\n", i, prvaZnamenka+ zadnjaZnamenka);
        }
    }

    return 0;
}
