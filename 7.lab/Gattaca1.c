/*
FALI TEKST ZADATKA
TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/17badbcc7384cbe31651404ba59d221d478ede32/tekstovi%20i%20test%20caseovi/%5B7%5DGattaca1.pdf
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n = 0;
int k = 0;
int pogreska; 

int provjeriGenom(char* genom, char* bolest, int* brojNepoznatih) {
	for (int i = 0; i < k; ++i) {
		if (*(genom + i) != *(bolest + i)) {
			(*brojNepoznatih)++; // vrijednost od broja povecat za 1 
			// pointer na varijablu iz main a jer ces to u main u koristit
			// pointer koji u mainu koristi povecavas
		}
	}
	if (*brojNepoznatih <= pogreska) {
		return 1;
	}
	return 0;
}

int main() {
	char* bolest;
	bolest = (char*)malloc(100 * sizeof(char));
	char* genom;
	genom = (char*)malloc(100 * sizeof(char));
	int rjesenje;


	scanf("%d\n", &pogreska);
	scanf("%[^\n]%*c", bolest);
	scanf("%[^\n]%*c", genom);

	while (*(bolest + k) != '\0') {
		k++;
	}
	while (*(genom + n) != '\0') {
		n++;
	}

	int indeks = -1;
	int min = 1e6;
	for (int i = 0; i < n - k + 1; ++i) {
		int br_pogresaka = 0;
		int good = provjeriGenom(genom + i, bolest, &br_pogresaka); // jel 1 il 0
		// prvi indeks od k kombinacije koja je dobra
		if (good == 1) {
			if (br_pogresaka < min) {
				min = br_pogresaka;
				indeks = i;
			}
		}
	}
	if (indeks == -1) {
		printf("Bolest nije detektirana!");
	}
	else {
		printf("Bolest detektirana na %d. slovu, uz pogresku %d.", indeks + 1, min);
	}
	return 0;
}
