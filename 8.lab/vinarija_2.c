/* TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/f7be5eb5e26691f04fc8201123bc73d538ea1456/tekstovi%20i%20test%20caseovi/%5B8%5DVinarija%201.zip
Razlika je što se sortira po proizvođaču, a za upis se unosi sorta vina.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>


typedef struct {
	char sorta[20 + 1];
	char proizvodjac[20 + 1];
	char boja[7 + 1];
	char kvaliteta[15 + 1];
	float zapremnina;
	float cijena;
}vino;


void vina(FILE* fout, vino rez[], int br) {
	if (br == 0) {
		fprintf(fout, "Nema trazene sorte");
		printf("Nema trazene sorte");
	}
	else {

		for (int i = 0; i < br; i++) {
			for (int j = 0; j < br - 1 - i;j++) {
				if (strcmp(rez[j].proizvodjac,rez[j + 1].proizvodjac)>0) {
					vino temp;
					temp = rez[j];
					rez[j] = rez[j + 1];
					rez[j + 1] = temp;
				}
			}
		}


		for (int i = 0; i < br; i++) {
			fprintf(fout, "%s#%.2f#%s#%s\n", rez[i].sorta, rez[i].zapremnina, rez[i].kvaliteta, rez[i].proizvodjac);
			printf("%s#%.2f#%s#%s\n", rez[i].sorta, rez[i].zapremnina, rez[i].kvaliteta, rez[i].proizvodjac);
		}
	}
}



int main() {
	FILE* fin = fopen("vinski_podrum.dat", "rb");
	FILE* fout = fopen("vino.txt", "w");

	vino popis[1000];
	vino rez[1000];
	int br = 0;



	fseek(fin, 0, SEEK_END);
	int vel = ftell(fin) / sizeof(vino);
	fseek(fin, 0, SEEK_SET);

	fread(popis, sizeof(vino), vel, fin);

	char unos[20];
	scanf("%s", unos);

	for (int i = 0; i < vel; i++) {
		if (strstr(popis[i].sorta, unos) != NULL) {
			rez[br++] = popis[i];
		}
	}

	vina(fout,rez,br);

	return 0;

}
