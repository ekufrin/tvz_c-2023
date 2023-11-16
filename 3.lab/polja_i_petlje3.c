/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/92a5d90264424334962c0119db021350590b9802/tekstovi%20i%20test%20caseovi/%5B3%5D%20Polja%20i%20petlje%203.PDF
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
int main()
{
	int n = 10, poljeA[MAX],poljeB[MAX], poljeC[MAX], temp[MAX], odabir, br_negativnih = 0, j = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &poljeA[i]);
	}
	scanf("%d", &odabir);
	switch (odabir) {
	case 1:
		for (int i = 0; i < n; i++) {
			if (poljeA[i] < 0)
				br_negativnih++;

		}
		printf("U polju poljeA negativnih brojeva ima: %d", br_negativnih);
		break;
	case 2:
		printf("PoljeA (nesortirano): ");
		for (int i = 0; i < n; i++) {
			printf("%d ", poljeA[i]);
		}
		printf("\nPoljeB (sortirano): ");
		
		for (int i = 0; i < n; i++) {
			if (poljeA[i] % 2 == 0) {
				poljeB[j] = poljeA[i];
				j++;
			}	
		}
		
		for (int i = 0; i < j - 1; i++) {
			for (int k = i + 1; k < j; k++) {
				if (poljeB[i] < poljeB[k]) {
					int temp = poljeB[i];
					poljeB[i] = poljeB[k];
					poljeB[k] = temp;
				}
			}
		}
		for (int i = 0; i < j; i++) {
			printf("%d ", poljeB[i]);
		}
		break;
	case 3:
		printf("PoljeA: ");
		for (int i = 0; i < n; i++) {
			printf("%d ", poljeA[i]);
		}
		
		printf("\nPoljeC: ");
		for (int i = 0; i < n; i++) {
			poljeC[i] = poljeA[i];
			int temp = poljeC[i];
			int zbroj = 0;
			while (temp != 0) {
				zbroj += temp % 10;
				temp /= 10;
			}

			if (zbroj <= 10) {
				printf("%d ", poljeC[i]);
			}
		}
		break;
	default:
		break;
	}
}

