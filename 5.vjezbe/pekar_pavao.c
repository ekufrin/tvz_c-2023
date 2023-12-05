/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/2b134530c990bc073a0dd6073978c7ff9c55aa8b/tekstovi%20i%20test%20caseovi/%5B5%5DPekar%20pavao.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10

float hambi(int x);
float slapica(int x);
float sirTrokut(int x);


int main() {
	int N, rupa, opseg, grami, uAutomatu[3] = { 0 };
	float promjerPeciva, naBacanje = 0;
	char pecivo;
	scanf("%d", &N);
	if (N < 1 || N > 100) {
		printf("Nepravilan unos!\n");
		scanf("%d", &N);
	}
	scanf("%d", &rupa);
	while (rupa < 5 || rupa > 50) {
		printf("Nepravilan unos!\n");
		scanf("%d", &rupa);
	}



	for (int i = 0; i < N; i++) {
		scanf(" %c %d %d", &pecivo, &opseg, &grami);

		if (pecivo == 'H') {
			promjerPeciva = hambi(opseg);
			if (promjerPeciva > rupa) {
				naBacanje += (float)grami / 1000;
			}
			else
				uAutomatu[0]++;
		}
		else if (pecivo == 'S') {
			promjerPeciva = slapica(opseg);
			if (promjerPeciva > rupa) {
				naBacanje += (float)grami / 1000;
			}
			else
				uAutomatu[1]++;
		}
		else if (pecivo == 'T') {
			promjerPeciva = sirTrokut(opseg);
			if (promjerPeciva > rupa) {
				naBacanje += (float)grami / 1000;
			}
			else
				uAutomatu[2]++;
		}
		
	}
	printf("Poklonit ce %.3g kg peciva.\n", naBacanje);
	printf("U automatu ce biti %d hambi peciva, %d slapica i %d sir-trokuta.", uAutomatu[0], uAutomatu[1], uAutomatu[2]);

	return 0;
}
float hambi(int x) {
	float promjer;
	promjer = x / 3.1415;

	return promjer;
}
float slapica(int x) {
	float promjer;
	promjer = x / 6.;

	return promjer;
	
}
float sirTrokut(int x) {
	float promjer;
	promjer = (float)x / (sqrt(2) + 2);

	return promjer;

}
