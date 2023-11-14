/*
ako je broj prost i zbroj znamenki mu je prost ispisi optimus prime, ako nije prost ili mu zbroj znamenki nije prost ispisi n nije optimus prime
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int N = 0,broj=0;
	int brojac=0,brojac2=0;
	int zadnjaZnamenka = 0, zbrajac = 0;

	do {
		scanf("%d", &N);
	} while (N <= 10 || N >= 1000000000);


	broj = N;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			brojac++;
		}
	}
	
	for (int i = 0; i < N; i++) {
		zadnjaZnamenka = N % 10;
		zbrajac += zadnjaZnamenka;
		N = N/10;
	}
	
	for (int i = 1; i <= broj; i++) {
		if (zbrajac % i == 0) {
			brojac2++;
		}
	}

	if (brojac == 2 && brojac2 == 2) {
		printf("Broj %d je optimus prime.", broj);
	}
	else {
		printf("Broj %d nije optimus prime.", broj);

	}

	return 0;
}
