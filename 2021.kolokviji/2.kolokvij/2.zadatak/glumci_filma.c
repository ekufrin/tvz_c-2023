/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/3bb4e3fb23a57f318708cc256a763b0cd7a3bd0b/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DGlumci%20filma.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	int sifra;
	char naziv[54 + 1];
	char zanr[24 + 1];
}film;

typedef struct {
	char ime_prezime[30 + 1];
	int sifra;
	char uloga[8 + 1];
}glumac;

int main() {
	
	FILE* filmovi = fopen("filmovi.dat", "rb");
	FILE* glumci = fopen("glumci.txt", "r");

	film popisf[2000];
	glumac popisg[2000];
	int br = 0;

	char omiljeni_film[100];

	fseek(filmovi, 0, SEEK_END);
	int vel = ftell(filmovi) / sizeof(film);
	fseek(filmovi, 0, SEEK_SET);

	fread(popisf, sizeof(film), vel, filmovi);

	while (fscanf(glumci, "%[^#]#%d#%[^\n]%*c", popisg[br].ime_prezime, &popisg[br].sifra, popisg[br].uloga) != EOF) {
		br++;
	}
	
	scanf("%[^\n]%*c", omiljeni_film);

	int postojiFilm = 0;
	for (int i = 0; i < vel; i++) {
		
		if (strcmp(omiljeni_film, popisf[i].naziv) == 0) {
			postojiFilm = 1;
			for (int j = 0; j < br; j++) {
				if (popisf[i].sifra == popisg[j].sifra) {
					printf("%s\n", popisg[j].ime_prezime);
				}
			}
		}
	}

	if (postojiFilm == 0) {
		printf("%s ne postoji", omiljeni_film);
	}

	return 0;
}
