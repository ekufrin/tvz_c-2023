/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/2163367085c847659c95e624a1f21cae7e8d59b0/tekstovi%20i%20test%20caseovi/%5B5%5DZamjena%20vrijednosti%20u%20polju.PDF
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#define N 15

void zamijeni(int pa[], int pb[], int n) {
	for (int i = 0; i < n; i++) {
		int temp = pa[i];
		pa[i] = pb[n - i - 1];
		pb[n - i - 1] = temp;
	}
}

int main() {

	int pa[N] = { 0 };
	int pb[N] = { 0 };
	int n = 0;
	

	do {
		scanf("%d", &n);
	} while (n<3 || n>N);


	int i = 0;
	int j = 0;
	do {
		scanf("%d", &pa[i++]);
		scanf("%d", &pb[j++]);
		if (pa[i-1] < 5 || pa[i-1]>20) {
			i--;
		}
		if (pb[j-1] < 5 || pb[j-1]>20) {
			j--;
		}

	} while (i < n || j<n);

	for (int j = 0; j < n; j++) {
		printf("%3d", pa[j]);
	}
	printf("\n");

	for (int j = 0; j < n; j++) {
		printf("%3d", pb[j]);
	}
	printf("\n");
	zamijeni(pa, pb,n);


	for (int j = 0; j < n; j++) {
		printf("%3d", pa[j]);
	}
	printf("\n");

	for (int j = 0; j < n; j++) {
		printf("%3d", pb[j]);
	}
	

	return 0;

}
