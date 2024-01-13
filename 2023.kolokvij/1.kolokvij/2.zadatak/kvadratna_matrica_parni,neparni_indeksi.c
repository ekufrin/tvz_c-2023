/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/dde9a0ea6b8dad32e89f3aeee7facb555d266452/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B1%5D%20Kvadratna%20matrica%2C%20parni%20i%20neparni%20indeksi.PDF
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	
	int n = 0;
	int polje[10][10] = { 0 };
	do {
		scanf("%d", &n);
	} while (n < 0);
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &polje[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + i == (n -1)) {
				if (i%2==0) {
					polje[i][j] = 0;
				}
				else {
					polje[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", polje[i][j]);
		}
		printf("\n");
	}



	return 0;
}
