/*
Mislav na vrlo ekstravagantan, pomalo i èudan naèin, bira koje èarape æe uzeti na put. On ima N (5,100] identiènih èarapa, pa je svejedno koja je kojoj par. No bez obzira na to, bira èarape na poseban naèin: posloži jednu kraj druge i numerira ih brojevima od 1 do N.

On æe uzeti èarapu oznaèenu brojem X ukoliko:
- zbroj znamenki do tada uzetih èarapa (oznaèimo ga Sz) zbrojen sa brojem djelitelja broja X (razlièitih od X i 1, oznaèimo ga Xd) ne premašuje broj X. Tj., ako je Sz+Xd <= X, tada se èarapa uzima na put.

Mislav kreæe od èarape oznaèene brojem A i redom evaluira gornju tvrdnju za svaku iduæu èarapu. Kada doðe do èarape oznaèene s N, ili kada skupi K èarapa, prestaje pakiranje i kreæe na put.

Potrebno je uèitati prirodni broj N i ponavljati unos dok god je N izvan intervala (5,100]. Takoðer, uèitati broj K koji oznaèava broj èarapa koje Mislav planira nositi na put (K mora biti 2<=K<=N - takoðer ponavljati unos dok ne bude ispravan). Potrebno je uèitati i broj A koji oznaèava èarapu od koje Mislav kreæe brojati.

Potrebno je ispisati koje sve èarape æe Mislav uzeti ako radi prema gornjem algoritmu.

Test case #1
Ima 29 èarapa, on treba izabrati 2 èarape, kreæe od èarape s brojem 7.
U 1. koraku X=7, zbroj znamenki do tad uzetih èarapa Sz=0, zbroj djelitelja broja X je Xd=0, Sz+Xd <= X -> Mislav uzima èarapu br.7
U 2. koraku X=8, Sz=7, Xd=2, Sz+Xd > X  -> ne uzima èarapu br. 8
U 3. koraku X=9, Sz=7, Xd=1, Sz+Xd <= X -> uzima èarapu br. 9 i staje s pakiranjem
Primjer ulaza:
29
2
7
Primjer izlaza:
Uzet ce carape broj 7, 9.
Test case #2
Primjer ulaza:
11
10
1
Primjer izlaza:
Uzet ce carape broj 1, 2, 3, 7.
Test case #3
Primjer ulaza:
74
1
2
74
Primjer izlaza:
Neispravni unos parametra K.
Uzet ce carape broj 74.
Test case #4
Primjer ulaza:
101
5
100
100
1
Primjer izlaza:
Neispravni unos parametra N.
Neispravni unos parametra N.
Uzet ce carape broj 1, 2, 3, 7, 13, 17, 27, 37, 46, 57, 67, 79, 97.
Test case #5
Primjer ulaza:
100
2
97
Primjer izlaza:
Uzet ce carape broj 97, 98.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int N=0, Sz=0,Xd=0,K=0,X=0,tempSz=0;
	int pogreskeN=-1, pogreskeK = -1, i=0;
	int carape[100]={0};
	
	do {
		scanf("%d", &N);
		pogreskeN++;
	} while (N <= 5 || N > 100);

	do {
		scanf("%d", &K);
		pogreskeK++;
	} while (K<2 || K>N);

	scanf("%d",&X);

	for (X; X <= N; X++) {
		for (int j = 2; j < X; j++) {
				if (X % j == 0) {
					Xd++;
				}
			
		}
		

		if (Sz + Xd <= X) {
			carape[i] = X;
			i++;
			tempSz = X / 10;
			Sz += tempSz + (X%10);
		}

		Xd = 0;

		if (i == K) {
			break;
		}
		
	}
	for (int y = 0; y < pogreskeK; y++) {
		printf("Neispravni unos parametra K.\n");
	}
	for (int y = 0; y < pogreskeN; y++) {
		printf("Neispravni unos parametra N.\n");
	}
	printf("Uzet ce carape broj ");
	for (int z = 0; z < i; z++) {
		printf("%d", carape[z]);
		if (z != i - 1) {
			printf(", ");
		}
		else {
			printf(".");
		}
	}
	return 0;
}