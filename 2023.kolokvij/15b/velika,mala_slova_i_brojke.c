/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/610ba773cdb1d33a16cac076819227ac74902567/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B1%5DVelika%2Cmala%20slova%20i%20brojke.PDF
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	
	char polje[30];
	int n = 1;
	int znamenka = 0;

	do {
		scanf("%c", &polje[n++]);
	} while (polje[n-1] != '\n');

	scanf("%d", &znamenka);

	if (znamenka+1 > n-1) {
		printf("Neispravna pozicija");
		return 0;
	}

	for (int i = 1; i < znamenka; i++) {
		printf("%c", polje[i]);
	}

	for (int i = znamenka+1; i < n-1; i++) {
		if (polje[i] >= 'A' && polje[i] <= 'Z') {
			polje[i] += 32;
		}
		else if (polje[i] >= '0' && polje[i] <= '9') {
			polje[i] = 'X';
		}
		printf("%c", polje[i]);
	}

	return 0;
}
