/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/d94bbe7685afc7473eb3e73a1bae97c9f7968f5a/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B1%5DMatrica%20sa%20negativnim%20elementima.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	
	int n = 0, m = 0;
	int polje[10][10] = { 0 };

	do {
		scanf("%d", &n);
	} while (n < 0);

	do {
		scanf("%d", &m);
	} while (m < 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &polje[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
				if (polje[j][i] > 0 && j % 2 == 0) {
					polje[j][i] = 0;
				}
				else if(polje[j][i] >= 0 && j%2!=0) {
					polje[j][i] = 1;
				}
			}
	}

	printf("Rezultat:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d", polje[i][j]);
		}
		printf("\n");
	}

	return 0;
}
