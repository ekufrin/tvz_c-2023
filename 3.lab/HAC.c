#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int N = 0,ulaz=0,izlaz=0,ukupno=0;
	int km[10] = { 0 }, cijena[10]={0};

	scanf("%d", &N);
	if (N < 2 || N>100) {
		printf("Broj mora biti veci od 2 i manji od 100");
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		scanf("%d", &km[i]);
		if (km[i] < 1) {
			printf("Broj kilometara ne smije biti manji od 1");
			return 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &cijena[i]);
		if (cijena[i] < 1) {
			printf("Prejeftino");
			return 0;
		}
	}
	scanf("%d %d", &ulaz, &izlaz);
	if (ulaz < 1) {
		printf("Ulaz ne moze biti manji od 1!");
		return 0;
	}
	if (izlaz > N) {
		printf("Izlaz ne moze biti veci od ukupnog broja dionica!");
		return 0;
	}
	for (ulaz; ulaz <= izlaz; ulaz++) {
		ukupno += km[ulaz] * cijena[ulaz];
	}
	printf("Ukupno: %dkn", ukupno);

	return 0;
}
