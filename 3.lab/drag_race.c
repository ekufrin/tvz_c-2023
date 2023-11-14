/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/00e6ff5e9b203cb4369ef9c874a7e5d59f5b43a0/tekstovi%20i%20test%20caseovi/%5B3%5D%20Drag_race.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int brDana = 0, pozLijevo = 0, pozDesno = 0, pozicijaKarte = 0, brojacL = 0,brojacD=0;
	int prodanekarteL[20] = { 0 };
	int prodanekarteD[20] = { 0 };

	scanf("%d", &brDana);
	for (int i = 0; i < brDana; i++) {
		scanf("%d", &pozLijevo);
		for (int j = 0; j < pozLijevo; j++) {
			scanf("%d", &pozicijaKarte);
			prodanekarteL[pozicijaKarte - 1] = 1;
		}
		scanf("%d", &pozDesno);
		for (int z = 0; z < pozDesno; z++) {
			scanf("%d", &pozicijaKarte);
			prodanekarteD[pozicijaKarte - 1] = 1;
		}
	}

	printf("Pregled zauzeca staze:\n");

	for (int i = 0; i < 20; i++) {
		if (i % 5 == 0 && i!=0) {
			printf(" ");
			printf("%d", prodanekarteL[i]);
		}
		else {
			printf("%d", prodanekarteL[i]);
		}
			
		
		
		

	}
	printf("\n");
	for (int i = 0; i < 20; i++) {
		if (i % 5 == 0 && i != 0) {
			printf(" ");
			printf("%d", prodanekarteD[i]);
		}
		else {
			printf("%d", prodanekarteD[i]);
		}

	}

	return 0;
}