/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/00e6ff5e9b203cb4369ef9c874a7e5d59f5b43a0/tekstovi%20i%20test%20caseovi/%5B2%5D%20Brojevi%201.PDF
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	int N, MIN, MAX, zbroj = 0;

	scanf("%d %d %d", &MIN, &MAX, &N);
	if (MIN < 1 || MAX >5000 || MIN > MAX) {
		printf("Krive granice intervala!");
	}
	else {
		for (int i=MIN+MIN; i < MAX; i++) {
			if (i % N == 0) {
				zbroj += i;
			}
		}
	}
	printf("Zbroj je: %d", zbroj);
	return 0;
}