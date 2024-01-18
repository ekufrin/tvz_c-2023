/*
Skoro sve isto ko zadatak "Kokteli 1",
ali unosi se naziv sastojka, ako neko od pića iz datoteke ima taj sastojak potrebno je ispisati naziv pića i sva 3 sastojka tog pića,
s time da nazivi pića moraju biti sortirani abecedno (od a do z)

TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/4591610b8b534e32ca7f76fa2d9885af6558f7ac/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DKokteli%201.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char imekoktela[20 + 1];
	float kolicina1;
	char ime1[20 + 1];
	float kolicina2;
	char ime2[20 + 1];
	float kolicina3;
	char ime3[20 + 1];

}koktel;

int main() {
	
	FILE* ulaz = fopen("kokteli.dat", "rb");
	FILE* izlaz = fopen("opcije.txt", "w");

	char sastojak[100];
	koktel popis[1000];
	koktel rezultat[100];
	int br = 0;

	fseek(ulaz, 0, SEEK_END);
	int vel = ftell(ulaz) / sizeof(koktel);
	fseek(ulaz, 0, SEEK_SET);

	fread(popis, sizeof(koktel), vel, ulaz);


	scanf("%[^\n]%*c", sastojak);

	for (int i = 0; i < vel; i++) {
		if (strcmp(sastojak, popis[i].ime1) == 0 || strcmp(sastojak, popis[i].ime2) == 0 || strcmp(sastojak, popis[i].ime3) == 0) {
			rezultat[br++] = popis[i];
		}
	}

	for (int i = 0; i < br; i++) {
		for (int j = 0; j < br - i - 1; j++) {
			if (rezultat[j].imekoktela[0] > rezultat[j + 1].imekoktela[0]) {
				koktel temp = rezultat[j];
				rezultat[j] = rezultat[j+1];
				rezultat[j + 1] = temp;
			}
		}
	}

	for(int i=0;i<br;i++){
		fprintf(izlaz, "%s (%s, %s, %s)\n", rezultat[i].imekoktela, rezultat[i].ime1, rezultat[i].ime2, rezultat[i].ime3);
	}

	return 0;
}
