/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/06c9aabedd0b4601cba28756e3ab9d2d8d80070c/tekstovi%20i%20test%20caseovi/%5B8%5DBaza%20filmova.pdf
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char naziv[50 + 1];
	char redatelj[50 + 1];
	int godina;
	float ocjena;
	char zanr[50 + 1];
}film;


void sortiraj_po_ocjeni(film* s, int br);

int main() {
	
	FILE* ulaz = fopen("filmovi.txt", "r");
	FILE* izlaz = fopen("lista.txt", "w");

	film filmovi[100], temp;
	int br = 0;

	while (fscanf(ulaz, "%[^#]#%[^#]#%d#%f#%[^\n]%*c",&temp.naziv, &temp.redatelj, &temp.godina, &temp.ocjena, &temp.zanr) >= 0) {
			filmovi[br++] = temp;		
	}

	sortiraj_po_ocjeni(filmovi, br);

	for (int i = 0; i < br; i++) {
		if (filmovi[i].ocjena > 5.0) {
			fprintf(izlaz, "%s#%s#%d#%.1f#%s\n", filmovi[i].naziv, filmovi[i].redatelj, filmovi[i].godina, filmovi[i].ocjena, filmovi[i].zanr);
		}
	}

	fclose(ulaz);
	fclose(izlaz);

	return 0;
}
void sortiraj_po_ocjeni(film* s, int br){
	for (int i = 0; i < br-1; i++) {
		for (int j = 0; j < br-i-1; j++) {
			if (s[j].ocjena < s[j+1].ocjena) {
				film temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
}
