/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/02d45ac1b85cb7122ae9b5b4eb237fd583d0ded4/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B1%5DPuno%20pijuna.jpg
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	int n = 0;
	int brojacRed = 0, najveciRed = 0, pozicijaRed = 0;
	int brojacStupac = 0, najveciStupac = 0, pozicijaStupac = 0;
	char polje[20][20] = {0};

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &polje[i][j]);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (polje[i][j] == 'P') {
				brojacRed++;
			}
			if (brojacRed > najveciRed) {
				najveciRed = brojacRed;
				pozicijaRed = i;
			}		
		}
		brojacRed = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (polje[j][i] == 'P') {
				brojacStupac++;
			}
			if (brojacStupac > najveciStupac) {
				najveciStupac = brojacStupac;
				pozicijaStupac = i;
			}
		}
		brojacStupac = 0;
	}


	printf("%d. redak i %d. stupac imaju najvise pijuna: ukupno %d.", pozicijaRed, pozicijaStupac,najveciRed+najveciStupac);

	return 0;
}
