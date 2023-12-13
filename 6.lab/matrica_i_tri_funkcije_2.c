/*
TEKST ZADATKA
Napisati C program koji obavlja naredne funkcije:
U glavnoj funkciji od korisnika je potrebno zatražiti unos
dimenzija matrice (matrica mora biti dimenzija NxN;
memoriju je potrebno dinamički alocirati) i vrijednosti
elemenata matrice. Matricu je potrebno deklarirati kao
dvodimenzionalno polje naziva matrica.
Osim glavne funkcije program sadrži i funkcije ispisi,
zbroji i najmanji.
Funkcija ispisi služi za ispis svih elemenata matrice.
Poziva se svaki put kada se želi ispisati sadržaj cijele
matrice. Ispis je potrebno obaviti barem jednom i to
nakon unosa elemenata preko tipkovnice.
Funkcija zbroji služi za zbrajanje vrijednosti svih
neparnih elemenata glavne dijagonale. Funkcija zbroji
glavnoj funkciji vraća zbroj elemenata kojeg je potrebno
ispisati na zaslonu nakon poziva funkcije.
Funkcija najmanji pronalazi najmanji neparni element
matrice i u glavnoj funkciji ispisuje vrijednost tog
elementa i njegovu lokaciju.

TEST CASEOVI:
Ulaz :
2
45 33
14 2
Izlaz :
45	33
14	2

Zbroj neparnih elemenata glavne dijagonale je 45.
Najmanji neparni element matrice je 33, na lokaciji [1,2].

Ulaz:
4
45 33 14 2
77 8 10 12
10 20 30 40
8 2 13 14
Izlaz:
45	33	14	2
77	8	10	12
10	20	30	40
8	2	13	14

Zbroj neparnih elemenata glavne dijagonale je 45.
Najmanji neparni element matrice je 13, na lokaciji [4,3].

Ulaz :

4
45 33 14 2
77 8 10 12
10 20 31 40
8 2 13 13
Izlaz:
45	33	14	2
77	8	10	12
10	20	31	40
8	2	13	13

Zbroj neparnih elemenata glavne dijagonale je 89.
Najmanji neparni element matrice je 13, na lokaciji [4,4].

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<stdlib.h>

void ispis(int** matrica, int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", matrica[i][j]);
		}
		printf("\n");
	}
}

int zbroji(int** matrica, int n) {
	int zbroj = 0;
	for (int i = 1; i <= n; i++) {
		if (matrica[i][i] % 2 != 0) {
			zbroj += matrica[i][i];
		}
		
	}

	return zbroj;
}

int najmanji(int** matrica, int n, int*x, int*y) {
	int najmanji = 100;
	for (int i = 1; i <= n; i++) {
		for(int j=1;j<=n;j++){
			if (matrica[i][j] % 2 != 0) {
				if (matrica[i][j] <= najmanji) {
				najmanji = matrica[i][j];
				*x = i;
				*y = j;
			}
		}
		}
	}

	return najmanji;
}

int main() {

	int n = 0;
	int x = 0, y = 0;


	scanf("%d", &n);

	int** matrica = (int**)malloc(n * sizeof(int*));
	for (int i = 1; i <= n; i++) {
		matrica[i] = (int*)malloc(n * sizeof(int));
	}

	for(int i=1;i<=n;i++){
		for (int j = 1; j <= n; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}

	ispis(matrica, n);
	printf("Zbroj neparnih elemenata glavne dijagonale je %d.\n",zbroji(matrica, n));
	printf("Najmanji neparni element matrice je %d, na lokaciji [%d,%d].\n",najmanji(matrica, n,&x,&y),x,y);


	for (int i = 0; i < n; i++) {
		free(matrica[i]);
	}

	free(matrica);

	return 0;
}
