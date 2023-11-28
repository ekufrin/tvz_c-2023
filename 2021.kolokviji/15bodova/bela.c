/*
Napisite C program koji racuna pobjednika u kartaskoj igri Bela.

od korisnika se trazi unos rezultata svakog kruga po parovima,
pri cemu zbroj bodova u svakom krugu ne smije biti manji od 162.
U sluvaju krivog unosa, potrebno je unos ponoviti.
Rezultati svakog kruga spremaju se u dva polja - po jedno polje za svakog igraca.

Igra traje dok barem jedan od parova ne dode do 1001 bod.
U slucaju da u zadnjem krugu oba para imaju vise od 1001 bod, pobjednik je onaj par s vecim brojem bodova.
Polja je potrebno nakon svih unosa sortirati uzlazno i ispisati.
Program na kraju ispisuje koji od parova je pobijedio.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int bodoviPrvi[100] = { 0 }, bodoviDrugi[100] = { 0 }, ukupniBodoviPrvi = 0, ukupniBodoviDrugi = 0;
    int brojRundi = 0;

    while (ukupniBodoviPrvi < 1001 || ukupniBodoviDrugi < 1001) {
        do {
            scanf("%d %d", &bodoviPrvi[brojRundi], &bodoviDrugi[brojRundi]);
        } while (bodoviPrvi[brojRundi] + bodoviDrugi[brojRundi] < 162);

        ukupniBodoviPrvi += bodoviPrvi[brojRundi];
        ukupniBodoviDrugi += bodoviDrugi[brojRundi];

        brojRundi++;
    }

    for (int i = 0; i < brojRundi; i++) {
        for (int j = i + 1; j < brojRundi; j++) {
            if (bodoviPrvi[j] < bodoviPrvi[i]) {
                int temp = bodoviPrvi[i];
                bodoviPrvi[i] = bodoviPrvi[j];
                bodoviPrvi[j] = temp;
            }
        }
    }

    for (int i = 0; i < brojRundi; i++) {
        printf("%d\t", bodoviPrvi[i]);
    }

    printf("\n");

    for (int i = 0; i < brojRundi; i++) {
        for (int j = i + 1; j < brojRundi; j++) {
            if (bodoviDrugi[j] < bodoviDrugi[i]) {
                int temp = bodoviDrugi[i];
                bodoviDrugi[i] = bodoviDrugi[j];
                bodoviDrugi[j] = temp;
            }
        }
    }

    for (int i = 0; i < brojRundi; i++) {
        printf("%d\t", bodoviDrugi[i]);
    }

    if (ukupniBodoviPrvi > ukupniBodoviDrugi) {
        printf("\nPobjednik je 1. par");
    }
    else if (ukupniBodoviPrvi < ukupniBodoviDrugi) {
        printf("\nPobjednik je 2. par");
    }
    else {
        printf("Izjednaceno");
    }

    return 0;
}
