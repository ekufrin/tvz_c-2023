/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/f5f4b14e53e908626793179ecffde9f761ced947/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DKarte%202.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char naziv_koncerta[40 + 1];
	double cijena_koncerta;
	int broj_reda;
	int broj_sjedala;
	char datum[11 + 1];
	char vrijeme[5 + 1];
	int status; // 1-slobodna,2-prodana,3-rezervirana
}KarteBinary;

int main() {

	FILE* ulaz_karte = fopen("karte.dat", "rb");
	FILE* izlaz_podatci = fopen("podaci.txt", "w");

	int broj;
	scanf("%d", &broj);
	char datum[11 + 1];
	char vrijeme[5 + 1];
	char naziv[40 + 1];

	KarteBinary koncert;

	for (int i = 0; i < broj; i++) {
		long double ukupna_cijena = 0;
		scanf("%*c%[^ ]%*c%[^ ]%*c%[^\n]", datum, vrijeme, naziv);

		while (fread(&koncert, sizeof(KarteBinary), 1, ulaz_karte) == 1) {
			if (strcmp(naziv, koncert.naziv_koncerta) == 0 && strcmp(vrijeme, koncert.vrijeme) == 0 && strcmp(datum, koncert.datum) == 0 && koncert.status == 2) {
				ukupna_cijena += koncert.cijena_koncerta;
			}
		}
		printf("%s %s %s: %.2lf\n", naziv, datum, vrijeme, ukupna_cijena);
		fseek(ulaz_karte, 0, SEEK_SET);
		ukupna_cijena = 0;
	}

	return 0;
}
