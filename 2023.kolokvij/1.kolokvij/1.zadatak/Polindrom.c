/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/4f162b207a62cea09b9b0e3a7a79be7ef871b34e/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B1%5DVelika%20i%20mala%20slova.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	int a, b, i, j;
	int brojevi[200] = { 0 };
	int PrvaZn = 0, DrugaZn = 0, CetvrtaZn = 0, PetaZn = 0;
	int brojac = 0;

	scanf("%d", &a);
	scanf("%d", &b);


	for (i = a; i <= b; i++) {
		PrvaZn = i / 10000;
		DrugaZn = (i / 1000) % 10;
		CetvrtaZn = (i / 10) % 10;
		PetaZn = i % 10;
		if (PrvaZn == PetaZn && DrugaZn == CetvrtaZn && PrvaZn > 0 && DrugaZn > 0 && PrvaZn!=DrugaZn) {
			brojevi[brojac] = i;
			brojac++;
		}
	}
	if (brojac > 1) {
		printf("%d %d", brojevi[0], brojevi[brojac - 1]);
		printf(" %d", brojac);
	}
	else if (brojac == 0) {
		printf("Nema takvog broja");
	}
	else {
		printf("%d %d %d", brojevi[0],brojevi[brojac],brojac);
	}

    return 0;
}
