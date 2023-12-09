/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/d458fd5e34a663d7765107cdedf6d6d890b280a4/tekstovi%20i%20test%20caseovi/%5B6%5DPlo%C4%8Da%20za%20dame.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<stdlib.h>

void upisi(char** niz,int n, int m) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < m; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					niz[i][j] = 'O';
				}
				else {
					niz[i][j] = 'C';
				}
			}
			else {
				if (j % 2 == 0) {
					niz[i][j] = 'C';
				}
				else {
					niz[i][j] = 'O';
				}
			}
		}
	}

	for (int i = 2; i < n - 2; i++) {
		for (int j = 0; j < m; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					niz[i][j] = 'O';
				}
				else {
					niz[i][j] = 'X';
				}
			}
			else {
				if (j % 2 == 0) {
					niz[i][j] = 'X';
				}
				else {
					niz[i][j] = 'O';
				}
			}
		}
	}

	for (int i = n-2; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					niz[i][j] = 'O';
				}
				else {
					niz[i][j] = 'B';
				}
			}
			else {
				if (j % 2 == 0) {
					niz[i][j] = 'B';
				}
				else {
					niz[i][j] = 'O';
				}
			}
		}
	}
}

void ispisi(char** niz,int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", niz[i][j]);
		}
		printf("\n");
	}
}

int main() {

	int n = 0, m = 0;
	char** niz;
	scanf("%d %d", &n, &m);

	niz=(char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++) {
		niz[i] = (char*)malloc(m * sizeof(char));
	}

	upisi(niz, n, m);
	ispisi(niz, n, m);

	for (int i = 0; i < n; i++) {
		free(niz[i]);
		niz[i] = NULL;
	}
	free(niz);
	niz = NULL;

	
	return 0;
}
