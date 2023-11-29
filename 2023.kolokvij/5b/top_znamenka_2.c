/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/576b1a3f9349539c72312041a1b7592998196c64/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B1%5DTop%20znamenka%202.jpg
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	
	char polje[9];
	int br = 0;
	char min = '2';
	char max = '2';

	do {
		scanf("%c", &polje[br++]);
	} while (polje[br - 1] != '\n');

	for (int i = 2; i < br-1; i++) {
		if (polje[i] < min) {
			min = polje[i];
		}

		if (polje[i] > max) {
			max = polje[i];
		}
	}

	printf("%c+%c=%c", min, max, (min + max)-'0');

	return 0;
}
