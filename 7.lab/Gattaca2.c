#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int provjeriGenom(char* genom, char* bolest, int* brojNepoznatih) {

	int brojacZvjezdica = strlen(bolest) + 1;

	char* nadenaBolest = NULL;

	int granica = strlen(genom) - strlen(bolest);

	char* pocetak = genom;

	while ((pocetak = strchr(pocetak, bolest[0])) != NULL) {

		int indeksPocetka = pocetak - genom;

		int brojacZvj = 0;
		int i = 1;
		for (; i < strlen(bolest); i++) {

			if (genom[indeksPocetka + i] == '*') {
				brojacZvj++;
			}
			else if (genom[indeksPocetka + i] != bolest[i]) {
				break;
			}
		}
		if (i == strlen(bolest)) {
			if (brojacZvj < brojacZvjezdica) {
				brojacZvjezdica = brojacZvj;
				nadenaBolest = pocetak;
			}
		}
		pocetak++;
	}

	if (brojacZvjezdica > 0) {

		pocetak = genom;

		while ((pocetak = strchr(pocetak, '*')) != NULL) {

			int indeksPocetka = pocetak - genom;

			int brojacZvj = 1;
			int i = 1;
			for (; i < strlen(bolest); i++) {

				if (genom[indeksPocetka + i] == '*') {
					brojacZvj++;
				}
				else if (genom[indeksPocetka + i] != bolest[i]) {
					break;
				}
			}
			if (i == strlen(bolest)) {
				if (brojacZvj < brojacZvjezdica) {
					brojacZvjezdica = brojacZvj;
					nadenaBolest = pocetak;
				}
			}
			pocetak++;
		}
	}

	*brojNepoznatih = brojacZvjezdica;

	if (nadenaBolest == NULL) {
		return -1;
	}
	
	int pozicija = nadenaBolest - genom;

	return pozicija + 1;
}

int main() {

	char trazenaBolest[50] = { 0 };
	char upisaniGenom[500] = { 0 };
	int brojNepoznatih = 0;

	scanf("%s", trazenaBolest);
	scanf("%s", upisaniGenom);

	int rezultat = provjeriGenom(upisaniGenom, trazenaBolest, &brojNepoznatih);

	if (rezultat == -1) {
		printf("Bolest nije detektirana!\n");
	}
	else {
		printf("Bolest detektirana na %d. slovu, uz %d nepoznanica.", rezultat, brojNepoznatih);
	}

	return 0;
}