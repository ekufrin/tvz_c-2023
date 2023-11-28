/*
Napisati program u C koji sa tipkovnice ucitava dobitnu kombiniciju od 7 brojeva (brojevi su od 1 do 39) na igri Loto 7 od 39. Nakon toga unijeti broj uplacenih brojeva N (n >= 7, N <= 10), a zatim unijeti N brojeva od 1 do 39.
Pretraziti i pronaci koliko je brojeva pogodeno
Ispisati koliko je brojeva pogodeno i ispisati te brojeve
Primjer - Pogodaka je 4: 4 8 9 13
Ako nema niti jednog pogodenog broja napisati "Nema pogodaka"

Test case-ovi:
Ulaz:
1 4 7 9 12 14 34
11
9
3 5 7 9 13 23 33 34 37
Izlaz:
Neispravan broj
Pogodaka je 3: 7 9 34

Ulaz:
4 5 7 9 24 29
7
3 4 55 9 12 24
Izlaz:
Pogodaka je 4: 4 5 9 24

Ulaz:
2 4 6 8 13 25 33
8
3 5 7 9 14 26 32 34
Izlaz:
Nema pogodaka
*/

#include <stdio.h>

int main() {
    
    int brojevi[7];
    
    for (int i = 0; i < 7; i++) {
        do {
            scanf("%d", &brojevi[i]);
        } while (brojevi[i] < 1 || brojevi[i] > 39);
    }
    
    int brojUplacenihBrojeva;
    do {
        scanf("%d", &brojUplacenihBrojeva);
        if (brojUplacenihBrojeva < 7 ||
             brojUplacenihBrojeva > 10) {
                 printf("Neispravan broj\n");
             }
    } while (brojUplacenihBrojeva < 7 ||
             brojUplacenihBrojeva > 10);
    
    int uplaceniBrojevi[10];
    for (int i = 0; i < brojUplacenihBrojeva; i++) {
        scanf("%d", &uplaceniBrojevi[i]);
    }
    
    int dobitniBrojevi[7], brojac = 0;
    for (int i = 0; i < brojUplacenihBrojeva; i++) {
        for (int j = 0; j < 7; j++) {
            if (uplaceniBrojevi[i] == brojevi[j]) {
                dobitniBrojevi[brojac] = uplaceniBrojevi[i];
                brojac++;
                break;
            }
        }
    }
    
    if (brojac != 0) {
        printf("Pogodaka je %d:", brojac);
        for (int i = 0; i < brojac; i++) {
            printf(" %d", dobitniBrojevi[i]);
        }
    } else {
        printf("Nema pogodaka");
    }
    

    return 0;
}
