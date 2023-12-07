/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/f059a2402ec87b0adc611c88b5496cb77cba7f5d/tekstovi%20i%20test%20caseovi/%5B5%5DOdron.jpg
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void odron(int smece[], int a, int b, int Z) {
	if (Z / 2 == 1) {
		Z = Z;
	}
	else {
		Z /= 2;
	}
	
	
	if (smece[a] > smece[b]) {
			smece[b] += Z;
			smece[a] -= Z;
	}
	else {
		smece[b] -= Z;
		smece[a] += Z;
	}


}


int main() {

	int n = 0, Z = 0;
	int brojac = 0;
	int NajveceBrdo = 0;
	int a = 0, b = 0;
	int smece[100] = { 0 };

	scanf("%d %d", &n, &Z);

	for (int i = 0; i < n; i++) {
		scanf("%d", &smece[i]);
	}

	for (int i = 0; i < n-1; i++) {
		if (abs(smece[i] - smece[i + 1]) >= Z) {
			if (abs(smece[i] - smece[i + 1]) > NajveceBrdo) {
				NajveceBrdo = abs(smece[i] - smece[i + 1]);
				a = i;
				b = i + 1;
			}
			brojac++;
		}
	}

	odron(smece, a, b, NajveceBrdo);

	if (brojac == 0) {
		printf("Zrak je cist, samo smrdi.");
		return 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			printf("%d ", smece[i]);
		}
	}



	return 0;
}
