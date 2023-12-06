/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/4ff23dcd5bf6b8d26aee541d4f432060aba8a185/tekstovi%20i%20test%20caseovi/%5B5%5DProsjek_prosjeka.jpg
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

float prosjek(int br) {
	float znamenka = 0;
	int brojac = 0;
	while (br != 0) {
		znamenka += br % 10;
		br /= 10;
		brojac++;
	}

	return znamenka / brojac;
}

int main() {

	int n = 0;
	int polje[100] = { 0 };
	float polje2[100] = { 0 };
	float zbrojprosjeka = 0;

	do {
		scanf("%d", &n);
		if (n < 1 || n>100) {
			printf("Nepravilan unos!\n");
		}
	} while (n < 1 || n>100);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &polje[i]);
		polje2[i]=prosjek(polje[i]);
		zbrojprosjeka += polje2[i];
	}

	printf("Prosjek prosjeka: %.2f\n", zbrojprosjeka / n);
	printf("Prosjeci brojeva:");
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (polje2[i] < polje2[j]) {
				float temp = polje2[i];
				polje2[i] = polje2[j];
				polje2[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf(" %.2f", polje2[i]);
	}

	return 0;

}
