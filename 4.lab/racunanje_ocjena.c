/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/5c38fc02a86caa73384ad73aec7aa76546534bae/tekstovi%20i%20test%20caseovi/%5B4%5D%20Racunanje%20ocjena.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	int n = 0;
	int ocjene[20][20] = { 0 };
	int finalnaOcjena=0;
	do {
		scanf("%d", &n);
		if (n < 2 || n>10) {
			printf("Uneseni broj studenata nije u zadanim granicama. Unesite ponovno broj studenata.\n");
		}
	} while (n < 2 || n>10);
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &ocjene[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			finalnaOcjena += ocjene[j][i];
		}
		if (finalnaOcjena < 50) {
			finalnaOcjena = 1;
		}
		else if (finalnaOcjena >= 50 && finalnaOcjena < 60) {
			finalnaOcjena = 2;
		}
		else if (finalnaOcjena >= 60 && finalnaOcjena < 75) {
			finalnaOcjena = 3;
		}
		else if (finalnaOcjena >= 75 && finalnaOcjena < 90) {
			finalnaOcjena = 4;
		}
		else if (finalnaOcjena >= 90) {
			finalnaOcjena = 5;
		}

		ocjene[4][i] = finalnaOcjena; // Potrebno je dodati u novi red matrice finalne ocjene

	}
	printf("Konacne ocjene:\n");

	for (int i = 0; i < 4+1; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", ocjene[i][j]);
		}
		printf("\n");
	}


	return 0;
}

