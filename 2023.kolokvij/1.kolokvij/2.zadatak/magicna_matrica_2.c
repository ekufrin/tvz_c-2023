/*
Potrebno je na početku učitati broj n, koji označava broj redaka i broj stupaca matrice (matrica je uvijek kvadratna - jednaki broj redaka i stupaca). Broj n mora biti u intervalu [2, 20] i mora biti djeljiv s 2. Ako neko od tih pravila nije ispoštovano, zahtjevati
ponovni unos uz ispis poruke (pogledati test primjere).
Nakon što se učita matricu, potrebno je matricu podijeliti na 4 jednaka dijela (gornji lijevi, gornji desni, donji lijevi i donji desni), te za 1. dio izračunati ukupan zbroj, za 2. dio izračunati prosjek, za 3.dio izračunati najveći broj i za 4. dio izračunati najmanji broj. Primjerice, ako je dana matrica:
1122
1122
4455
4455
1. dio je matrica:
11
11
2. dio je matrica:
22
22
3. dio je matrica:
44
44
4. dio je matrica:
55
55
55

TEST CASEOVI:

Test case #1
Za 1. dio se računa ukupni zbroj: 1+1+1+1 = 4
Za 2. dio se računa prosjek: (2+2+2+2)/4 = 2.000
Za 3. dio se traži najveći broj: to je broj 4
Za 4. dio se traži najmanji element: to je broj 5
Primjer ulaza:
4
1 1 2 2
1 1 2 2
4 4 5 5
4 4 5 5
Primjer izlaza:
1. dio: 4
2. dio: 2.000
3. dio: 4
4. dio: 5

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

    int n = 0, zbroj=0,maxbr=0,minbr=10,br=0;
    float prosjek = 0;
    int matrica[10][10] = { 0 };

    do {
        scanf("%d", &n);
        if (n < 2 || n>20 || n % 2 != 0) {
            printf("Ponoviti unos!\n");
        }
    } while (n < 2 || n>20 && (n % 2) != 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }

    for (int i = 0; i < (n / 2); i++) {
        for (int j = 0; j < (n / 2); j++) {
            zbroj += matrica[i][j];
        }
    }

    for (int i = 0; i < (n / 2); i++) {
        for (int j = (n / 2); j < n; j++) {
            prosjek += matrica[i][j];
            br++;
        }
    }

    prosjek /= br;

    for (int i = (n / 2); i < n; i++) {
        for (int j = 0; j < (n/2); j++) {
            if (matrica[i][j] > maxbr) {
                maxbr = matrica[i][j];
            }
        }
    }

    for (int i = (n / 2); i < n; i++) {
        for (int j = (n / 2); j < n; j++) {
            if (matrica[i][j] < minbr) {
                minbr = matrica[i][j];
            }
        }
    }

    printf("1. dio: %d\n", zbroj);
    printf("2. dio: %.3f\n", prosjek);
    printf("3. dio: %d\n", maxbr);
    printf("4. dio: %d\n", minbr);


    return 0;
}
