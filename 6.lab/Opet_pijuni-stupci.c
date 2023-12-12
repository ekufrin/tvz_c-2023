/*
SLIČAN ZADATAK KAO: https://github.com/emanuelkufrin/tvz_c-2023/blob/62ec5faa6dba9f795c55ee7c0deba1335250bd1b/tekstovi%20i%20test%20caseovi/%5B6%5DOpet%20pijuni%20-%20retci%20.pdf
SAMO JE POTREBNO PREBROJATI STUPCE, UMJESTO REDAKA!
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<stdlib.h>

void ispis(char** polje, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (polje[i][j] != 'P') {
				polje[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", polje[i][j]);
		}
		printf("\n");
	}
}

void prebroji(char** polje, int n, int m, int* novo_polje) {
	for (int i = 0; i < m; i++) {
		novo_polje[i] = 0;
		for (int j = 0; j < n; j++) {
			if (polje[j][i] == 'P') {
				novo_polje[i] += 1;
			}

		}
	}
}

int main() {

	int n = 0, m = 0, k = 0;
	int* novo_polje = (int*)malloc(m * sizeof(int));

	scanf("%d %d %d", &n, &m, &k);
	char** polje = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++) {
		polje[i] = (char*)malloc(m * sizeof(char));
	}

	while (k) {
		int x = 0, y = 0;
		scanf("%d %d", &x, &y);
		polje[x - 1][y - 1] = 'P';
		k--;
	}

	ispis(polje, n, m);
	prebroji(polje, n, m, novo_polje);

	printf("Broj pijuna po stupcima:");
	for (int i = 0; i < m; i++) {
		printf(" %d", novo_polje[i]);
	}

	for (int i = 0; i < n; i++) {
		free(polje[i]);
	}
	for (int i = 0; i < m; i++) {
		free(novo_polje[i]);
	}

	free(polje);
	free(novo_polje);


	return 0;
}
