/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/0be9e074d0784dbbf3013864d294746f390144f8/tekstovi%20i%20test%20caseovi/%5B6%5DSnijeg%20u%20matrici.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void ucitaj_matricu(int n, int m, char** matrica) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			scanf(" %c", &matrica[i][j]);
		}
	}
}

void napadaj(char** matrica, int n, int m) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (i == n - 1 && matrica[i - 1][j] == '#' && matrica[i][j] == '.') {
				matrica[i][j] = '.';
			}
			else if (i != n - 1 && matrica[i][j] == '.' && (matrica[i + 1][j] == '#' || matrica[i + 1][j] == '*')) {
				matrica[i][j] = '*';
			}
			else if (i == n - 1 && matrica[i][j] == '.') {
				matrica[i][j] = '*';
			}
		}
	}
}


int main() {

	int n, m, sloj;
	scanf("%d%d%d", &n, &m, &sloj);

	char** matrica = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++) {
		matrica[i] = (char*)malloc(m * sizeof(char));
	}
	ucitaj_matricu(n, m, matrica);

	for (int i = 0;i < sloj;i++) {
		napadaj(matrica, n, m);
	}

	printf("\n");
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			printf("%c", matrica[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n;i++) {
		free(matrica[i]);
	}
	free(matrica);


	return 0;
}
