/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/cba0dd88f951550deebea67e2180f52fc4ec78b6/tekstovi%20i%20test%20caseovi/%5B7%5DProfesor%20Ivan.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convertToLower(char recenica[][100], int x);
void ispis(char kopijaRecenice[][100], int niz, int brojac);
int main() {
	const char* prof = "Profesor";
	char* provjeraProf;
	char recenica[80][100];
	char rijec[50];
	int k = 0;
	int nizImena[50];
	char kopijaRecenice[80][100];
	do {
		scanf("%[^\n]%*c", recenica[k]);
		strcpy(kopijaRecenice[k], recenica[k]);
		provjeraProf = strstr(recenica[k++], prof);
	} while (provjeraProf == NULL);
	convertToLower(recenica, k);
	strcpy(rijec, recenica[k - 1]);
	
	k--;
	char* pRijec = strtok(rijec, "::");
	while (pRijec != NULL) {
		strcpy(rijec, pRijec);
		pRijec = strtok(NULL, "::");
	} 
	int brojac = 0;
	int h = 0;
	char (*pRecenica)[100] = recenica;
	for (int i = 0; i < k; i++) {
		if (strstr(pRecenica[i], rijec)) {
			brojac++;
			nizImena[h++] = i;
		}
	}
	int b;
	char(*pKopijaRecenice)[100] = kopijaRecenice;
	if (brojac == 0 && k == 0) {
		printf("Vise srece drugi put!");
		return 0;
	}
	printf("Broj studenata koji su pogodili zivotinju: %d od %d.\n\n", brojac, k);
	if (brojac == 0) {
		printf("Vise srece drugi put!");
		return 0;
	}
	else
		printf("Studenti koji su pogodili zivotinju:\n");
	for (int i = 0; i < brojac; i++) {
		ispis(kopijaRecenice, nizImena[i], brojac);
		printf("\n");
	}
}
void convertToLower(char recenica[][100], int x) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < 100; j++){
			recenica[i][j] = tolower(recenica[i][j]);
		}
	}
}
void ispis(char kopijaRecenice[][100], int niz, int brojac) {
	for (int i = 0; i < brojac; i++) {
		for (int j = 8; j < 100; j++) {
			if (kopijaRecenice[niz][j] == ':')
				return 1;
			printf("%c", kopijaRecenice[niz][j]);
		}
		
	}

	
}
