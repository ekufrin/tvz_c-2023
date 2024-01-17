/*1. kolokvij, zadatak za 15 bodova: Ne vidim tekst.
Treba unijeti n i m od matrice i char matricu. nakon toga unijeti broj znakova uzorka kao i uzorak.
Cilj je ispisati koliko puta se taj uzorak ponavlja u osnovnoj matrici.

Test case:
Ulaz:
3 5
.*..-
--..-
***..
3
*..
Izlaz:
Broj ponavljanja uzorka: 2

Ulaz:
2 10
-..--.
--.-...*
5
--.-.
Izlaz:
Broj ponavljanja uzorka: 1

Ostali test caseovi: https://github.com/emanuelkufrin/tvz_c-2023/blob/71ae093b2cfa4bcccddbd9fd293dbba9d5f7f866/tekstovi%20i%20test%20caseovi/%5B2021.kol%5DUzorak%20u%20matrici.png
P.S. ne treba ispisivat matricu ni uzorak, al ja sam stavio ko provjeru
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    char matrica[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &matrica[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", matrica[i][j]);
        }
        printf("\n");
    }

    int k;
    scanf("%d", &k);
    char uzorak[MAX];

    for (int i = 0; i < k; i++) {
        scanf(" %c", &uzorak[i]);
    }
    for (int i = 0; i < k; i++) {
        printf(" %c", uzorak[i]);
    }
    printf("\n");

    int brojPonavljanja = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int brojac = 0;
            if (matrica[i][j] == uzorak[0]) {
                for (int z = j; z < m; z++) {
                    if (matrica[i][z] == uzorak[brojac]) {
                        brojac++;
                    }
                }
                if (brojac == k) {
                    brojPonavljanja++;
                    break;
                }
            }
        }
    }

    printf("Broj ponavljanja uzorka: %d", brojPonavljanja);

    return 0;
}
