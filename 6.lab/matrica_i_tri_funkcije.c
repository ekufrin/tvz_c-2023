/*
TEKST ZADATKA
Napisati C program koji obavlja naredne funkcije:
U glavnoj funkciji od korisnika je potrebno zatražiti unos
dimenzija matrice (matrica mora biti dimenzija NxN;
memoriju je potrebno dinamički alocirati) i vrijednosti
elemenata matrice. Matricu je potrebno deklarirati kao
dvodimenzionalno polje naziva matrica.
Osim glavne funkcije program sadrži i funkcije ispisi,
zbroji i najveci.
Funkcija ispisi služi za ispis svih elemenata matrice.
Poziva se svaki put kada se želi ispisati sadržaj cijele
matrice. Ispis je potrebno obaviti barem jednom i to
nakon unosa elemenata preko tipkovnice.
Funkcija zbroji služi za zbrajanje vrijednosti svih
neparnih elemenata sporedne dijagonale. Funkcija zbroji
glavnoj funkciji vraća zbroj elemenata kojeg je potrebno
ispisati na zaslonu nakon poziva funkcije.
Funkcija najveci pronalazi najveci neparni element
matrice i u glavnoj funkciji ispisuje vrijednost tog
elementa i njegovu lokaciju.

TEST CASEOVI:
Ulaz :
2
45 33
14 2
Izlaz :
45   33
14    2
Zbroj neparnih elemenata sporedne dijagonale je 33.
Najveci neparni element matrice je 45, na lokaciji [1,1].

Ulaz:
4
45 33 14 2
77 8 10 12
10 20 30 40
8 2 13 14
Izlaz:
 45   33   14    2
 77    8   10   12
 10   20   30   40
 8    2	   13   14
Zbroj neparnih elemenata sporedne dijagonale je 0.
Najveci neparni element matrice je 77, na lokaciji [2,1].

Ulaz :

4
45 33 14 21
77 8 10 12
10 20 30 40
81 2 13 14
Izlaz:
 45   33   14   21
 77    8   10   12
 10   20   30   40
 81    2   13   14
Zbroj neparnih elemenata sporedne dijagonale je 102.
Najveci neparni element matrice je 81, na lokaciji [4,1].

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<stdlib.h>

void ispis(int** matrica, int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%5d", matrica[i][j]);
		}
		printf("\n");
	}
}

int zbroji(int** matrica, int n) {
	int zbroj = 0;
	int x = n;
	for (int i = 1; i <= n; i++,x--) {
		if (matrica[i][x] % 2 != 0) {
			zbroj += matrica[i][x];
		}
		
	}

	return zbroj;
}

int najveci(int** matrica, int n, int*x, int*y) {
	int najveci = 1;
	for (int i = 1; i <= n; i++) {
		for(int j=1;j<=n;j++){
			if (matrica[i][j] % 2 != 0) {
				if (matrica[i][j] >= najveci) {
				najveci = matrica[i][j];
				*x = i;
				*y = j;
			}
		}
		}
	}

	return najveci;
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
	printf("Zbroj neparnih elemenata sporedne dijagonale je %d.\n",zbroji(matrica, n));
	printf("Najveci neparni element matrice je %d, na lokaciji [%d,%d].\n", najveci(matrica, n,&x,&y),x,y);


	for (int i = 0; i < n; i++) {
		free(matrica[i]);
	}

	free(matrica);

	return 0;
}
