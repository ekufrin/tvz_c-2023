/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/4f162b207a62cea09b9b0e3a7a79be7ef871b34e/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B1%5DVelika%20i%20mala%20slova.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int br = 0;
	char polje[50];

	do {
		scanf("%c", &polje[br++]);
	} while (polje[br - 1] != '\n');

	printf("Rezultat: ");
	for (int i = 0; i < br && i<10; ++i) {
		if (polje[i + 1] == ' ' || polje[i-1] == ' ' || polje[i+1]=='\n') {
			polje[i] -= 32;
		}
		else if(i==0 || i==9) {
			polje[i] -= 32;
		}
		printf("%c", polje[i]);
	}


	return 0;
}
