/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/29c22e713f8fdb6a055c01a4bbd56e3674343414/tekstovi%20i%20test%20caseovi/%5B8%5DVozacke%20dozvole%201.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char grad[100];
	char reg[9];
	char name[100];
	char surname[100];
	char street[200];
	int month;
	int day;
	int year;
	char category[3];
}vozac;

int main(){

	FILE* ulaz = fopen("car-data.dat", "rb");
	FILE* izlaz = fopen("rezultat.out", "w");

	char grad[100];
	vozac rezultat[100];
	int velicina = 0;
	int br = 0;
	vozac vozaci[1000];

	scanf("%[^\n]%*c", &grad);

	fseek(ulaz, 0, SEEK_END);
	velicina = ftell(ulaz) / sizeof(vozac);
	fseek(ulaz, 0, SEEK_SET);

	fread(vozaci, sizeof(vozac), velicina, ulaz);

	for (int i = 0; i < velicina; i++) {
		if (strcmp(grad, vozaci[i].grad) == 0) {
			rezultat[br++] = vozaci[i];
		}
	}

	if (br == 0) {
		fprintf(izlaz, "Nepoznati grad!");
	}

	for (int i = 0; i < br; i++) {
		for (int j = 0; j < br - 1-i; j++) {
			if (strcmp(rezultat[j].reg, rezultat[j + 1].reg) == 1) {
				vozac temp = rezultat[j];
				rezultat[j] = rezultat[j + 1];
				rezultat[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < br; i++) {
		fprintf(izlaz,"%s %s %s\n", rezultat[i].reg, rezultat[i].name, rezultat[i].surname);
	}
	

	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
