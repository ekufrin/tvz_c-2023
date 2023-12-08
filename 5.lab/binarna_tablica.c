/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/e98171123105b661f2dfbc055e65f126803c4f1d/tekstovi%20i%20test%20caseovi/%5B5%5D%20Binarna%20tablica.PDF
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include<stdio.h>
int main() {
	long long int a[MAX][MAX], i, j, n, m, b[MAX][MAX] = { 0 }, najv1=0, najv2=0;
	scanf("%lld%lld", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	for(i = 0; i < n; i++) {
		for (j = 0; j < m; j++) { 
			b[i][j] = bin(a[i][j]);
		}
	}
	najv1 = b[0][0];
	najv2 = a[0][0];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (b[i][j] > najv1) {
				najv1 = b[i][j];
				najv2 = a[i][j];
			}
			else if (b[i][j] == najv1 && a[i][j] > najv2) {
				najv2 = a[i][j];
				najv1 = b[i][j];
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%lld ", b[i][j]); 
		}
		printf("\n");
	}
	printf("Najvise jedinica u pocetnoj: %lld", najv2);
	return 0;
}
int bin(long long int x) {
	int brojac = 0;
	while (x != 0) {
		if (x % 2 == 1) {
			brojac++;
		}
		x /= 2;
	}
	return brojac;
}
