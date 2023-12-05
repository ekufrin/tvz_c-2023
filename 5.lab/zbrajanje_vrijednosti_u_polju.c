/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/ff5e726eb51b6caf6c26ba2876622e2bfbaff7a4/tekstovi%20i%20test%20caseovi/%5B5%5DZbrajanje%20vrijednosti%20u%20polju.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#define N 25

void zamijeni(int ap[], int bp[],int cp[], int M,int*brojac) {
	int temp[N] = { 0 };
	for (int i = 0; i < M; i++) {
			temp[i] = ap[i] + bp[M - i - 1];
			if (temp[i] % 2 == 0) {
				cp[*brojac] = temp[i];
				*brojac += 1;
			}
			
		}

}

int main() {

	int ap[N] = { 0 };
	int bp[N] = { 0 };
	int cp[N] = { 0 };
	int M = 0;
	int brojac = 0;
	

	do {
		scanf("%d", &M);
	} while (M<3 || M>N);


	for (int i = 0; i < M; i++) {
		scanf("%d", &ap[i]);
	}

	for (int i = 0; i < M; i++) {
		scanf("%d", &bp[i]);
	}

	
	zamijeni(ap, bp,cp,M,&brojac);

	for (int j = 0; j < M; j++) {
		printf("%3d", ap[j]);
	}
	printf("\n");

	for (int j = 0; j < M; j++) {
		printf("%3d", bp[j]);
	}
	printf("\n");

	for (int j = 0; j < brojac; j++) {
		printf("%3d", cp[j]);
	}

	

	return 0;

}
