/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/ef7f5d95e23e0e60f1836aade88956cfcb5315cd/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B1%5DMatricno%20prociscenje%202.jpg
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	int s=0, r = 0, iteracija=0;
	int brojacTocaka = 0;
	char polje[20][20] = { 0 };

	scanf("%d %d %d", &s, &r, &iteracija);

	// Ucitavanje matrice
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < r; j++) {
			scanf(" %c", &polje[i][j]);
		}
	}

	while (iteracija) {


	// Provjera redaka
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < r; j++) {
			if (polje[i][j] == '.') {
				brojacTocaka++;
			}
		}
		if (brojacTocaka == 1) {
			for (int j = 0; j < r; j++) {
				if (polje[i][j] == '.') {
					polje[i][j] = '*';
				}
			}
		}
		brojacTocaka = 0;
	}

	// Provjera stupaca
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < r; j++) {
			if (polje[j][i] == '.') {
				brojacTocaka++;
			}
		}
		if (brojacTocaka == 1) {
			for (int j = 0; j < r; j++) {
				if (polje[j][i] == '.') {
					polje[j][i] = '*';
				}
			}
		}
		brojacTocaka = 0;
	}


	iteracija--;
	}

	//Ispis matrice
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < r; j++) {
			printf("%c", polje[i][j]);
		}
		printf("\n");
	}


	return 0;
}
