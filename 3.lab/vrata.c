/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/4edf233becdf26086c6d91749f8d50fc2ce7d1e7/tekstovi%20i%20test%20caseovi/%5B3%5D%20Vrata.PDF
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define SNAGA 100
int main() {

	int N, K;
	int Navijaci[50]={0};
	int steta = 0;
	int popravak = 0;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &Navijaci[i]);
		if (Navijaci[i] > 100) {
			steta += Navijaci[i] - SNAGA;
			if (steta >= K) {
				popravak++;
				steta = 0;
			}
		}
	}
	if (popravak == 0) {
		printf("Dody moze na godisnji.");
		return 0;
	}
	else {
		printf("Zadani redoslijed: %d popravka\n", popravak);
	}
	
	popravak = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (Navijaci[j] > Navijaci[j + 1]) {
				int temp = Navijaci[j];
				Navijaci[j] = Navijaci[j+1];
				Navijaci[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		
		if (Navijaci[i] > 100) {
			steta += Navijaci[i] - SNAGA;
			if (steta >= K) {
				popravak++;
				steta = 0;
			}
		}
	}
	printf("Sortirano: %d popravka\n", popravak);

	return 0;
}