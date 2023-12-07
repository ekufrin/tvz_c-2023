/*
Upisati pocetnu i krajnju granicu, zatim unesti broj N, te niz od N brojeva.
Prebrojiti koliko brojeva unesenih u nizu je između početne i krajnje granice, te ispisati rezultat.

TEST CASE #1
Ulaz:
30.0
12.0
12.0
30.0
5
4.0 15.1 30.0 2.5 17.6
Izlaz:
Neispravan unos granica!
U polju postoji 3 brojeva koji
zadovoljavaju uvjet.

TEST CASE #2
Ulaz:
12.0
30.0
150
5
4.0 15.1 30.0 2.5 17.6
Izlaz:
Broj N je neispravno zadan!
U polju postoji 3 brojeva koji
zadovoljavaju uvjet.

TEST CASE #3
Ulaz:
12.5
30.4
4
2.3 3.4 15.5 22.4 
Izlaz:
U polju postoji 2 brojeva koji
zadovoljavaju uvjet.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int provjera(int a, int b, float lista[1000], int n) {
    int rez = 0;
    for (int i = 0; i < n; i++) {
        if (lista[i] >= a && lista[i] <= b) {
            rez++;
        }
    }
    return rez;
}
int main()
{
    int n, greskaA=0, greskaB=0;
    float a, b;
    float lista[1000];

    do {
        scanf("%f", &a);
        scanf("%f", &b);
        if (b <= a) {
            greskaA++;
        }
    } while (b <= a);

    do {
        scanf("%d", &n);
        if (n > 100) {
            greskaB++;
        }
    } while (n > 100);

    for (int i = 0; i < n; i++) {
        scanf("%f", &lista[i]);
    }

    int rezultat = provjera(a, b, lista, n);
    for (int i = 0; i < greskaA; i++) {
        printf("Neispravan unos granica!\n");
    }
    for (int i = 0; i < greskaB; i++) {
        printf("Broj N je neispravno zadan!\n");
    }

    printf("U polju postoji %d brojeva koji zadovoljavaju uvjet.", rezultat);

}
