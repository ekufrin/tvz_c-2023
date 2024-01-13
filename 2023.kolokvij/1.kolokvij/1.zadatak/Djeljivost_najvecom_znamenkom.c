/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/199fae7bbf387e82b2892fd7892470564dfc9783/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B1%5DDjeljivost%20najvecom%20znamenkom.jpg
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int P = 0;
	int broj = 0;
	int ostatak = 0;
	int najvecaZnam = 0;
	do {
		scanf("%d", &P);
		if (P < 10) {
			return 0;
		}
		broj = P;
		do {
			ostatak = broj % 10;
			broj /= 10;
			if (ostatak > najvecaZnam) {
				najvecaZnam = ostatak;
			}
		} while (broj > 0);

		if (P % najvecaZnam == 0) {
			printf("%d je djeljiv s %d.\n", P, najvecaZnam);
		}
		najvecaZnam = 0;
	} while (P > 10);

	return 0;
}
