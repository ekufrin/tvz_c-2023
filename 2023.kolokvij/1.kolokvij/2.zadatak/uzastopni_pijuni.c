/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/d56335ba9276afaa409f05d05b0bfe546f827c1d/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B1%5DUzastopni%20pijuni.PDF
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
			else {
				brojacRed = 0;
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
			else {
				brojacStupac = 0;
			}
			if (brojacStupac > najveciStupac) {
				najveciStupac = brojacStupac;
				pozicijaStupac = i;
			}
		}
		brojacStupac = 0;
	}


	printf("%d. redak ima %d uzastopnih pijuna\n%d. stupac ima %d uzastopnih pijuna", pozicijaRed, najveciRed,pozicijaStupac,najveciStupac);

	return 0;
}
