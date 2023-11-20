
/*

RIJESEN ZADATAK NA MALO LAKSI NACIN 

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int i=0, j = 0,i2=0,j2=0;
	int matrica1[10][10] = { 0 };
	int matrica2[10][10] = { 0 };
	int mnozenje[10][10] = { 0 };

	do {
		scanf("%dx%d", &i, &j);
		if (i < 2 || i>10 && j < 2 || j>10) {
			printf("Unesena je nedozvoljena dimenzija prve matrice!\n");
		}
	} while (i < 2 || i>10 && j < 2 || j>10);

	do {
		scanf("%dx%d", &i2, &j2);
		if (i2 < 2 || i2>10 && j2 < 2 || j2>10) {
			printf("Unesena je nedozvoljena dimenzija druge matrice!\n");
		}
		
	} while (i2 < 2 || i2>10 && j2 < 2 || j2>10);

	if (i != j2 || i2 != j) {
		printf("Matrice nisu ulancane!\n");
		scanf("%dx%d", &i2, &j2);

	}

	for (int z = 0; z < i; z++) {
		for (int y = 0; y < j; y++) {
			scanf("%d", &matrica1[z][y]);
		}
	}

	for (int z = 0; z < i2; z++) {
		for (int y = 0; y < j2; y++) {
			scanf("%d", &matrica2[z][y]);
		}
	}


	if(i==j2){
		printf("Suma matrica:\n");
		for (int z = 0; z < i; z++) {
			for (int y = 0; y < j; y++) {
				printf("%4d", matrica1[z][y] + matrica2[z][y]);
			}
			printf("\n");
		}
	}
	else {
		printf("Matrice nisu istih dimenzija, ne mogu se zbrojiti!\n");
	}
	
	if (i == j2) {
		printf("Razlika matrica:\n");
		for (int z = 0; z < i; z++) {
			for (int y = 0; y < j; y++) {
				printf("%4d", matrica1[z][y] - matrica2[z][y]);
			}
			printf("\n");
		}
	}
	else {
		printf("Matrice nisu istih dimenzija, ne mogu se oduzimati!\n");
	}

	printf("Transponirana prva matrica:\n");
	for (int z = 0; z < j; z++) {
		for (int y = 0; y < i; y++) {
			printf("%4d", matrica1[y][z]);
		}
		printf("\n");
	}
	
	printf("Transponirana druga matrica:\n");
	for (int z = 0; z < j2; z++) {
		for (int y = 0; y < i2; y++) {
			printf("%4d", matrica2[y][z]);
		}
		printf("\n");
	}


	printf("Umnozak matrica:\n");
	for (int z = 0; z < i; z++) {
		for (int y = 0; y < j2; y++) {
			for (int k = 0; k < j; k++) {
				mnozenje[z][y] += matrica1[z][k] * matrica2[k][y];
				
			}
			printf("%4d", mnozenje[z][y]);
		}
		
		printf("\n");
	}




	return 0;
}
