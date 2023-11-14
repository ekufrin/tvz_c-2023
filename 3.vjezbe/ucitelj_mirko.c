/*
Srednjoškolski uèitelj Mirko zamolio vas je da mu napravite program pomoæu kojeg æe moæi napraviti statistiku zakljuèenih ocjena iz svog predmeta (Biologije) za više razlièitih razreda. Mirko bi htio za svaki razred unositi koliko je bilo uèenika s odreðenom ocjenom i da mu program u konaènici izraèuna prosjeènu ocjenu svih razreda,  te ispiše koliko je ukupno uèenika prošlo s kojom ocjenom.

U test caseovima vidjeti primjer izvoðenja programa.

Test case #1
Mirko u programu prvo unosi za koliko razreda radi statistiku, te nakon toga redom koliko je u razredu bilo jedinica, dvojki, trojki, èetvorki i petica, te koliki je prosjek (rijeèima).
Primjer ulaza:
1
0 7 7 15 1
Primjer izlaza:
Za 1 razred/razreda

bilo je:
0 nedovoljan, 7 dovoljan, 7 dobar, 15 vrlo dobar i 1 odlican

prosjecna ocjena je:
dobar
Test case #2
Primjer ulaza:
3
1 0 10 15 3
0 2 5 15 7
3 2 15 7 5
Primjer izlaza:
Za 3 razred/razreda

bilo je:
4 nedovoljan, 4 dovoljan, 30 dobar, 37 vrlo dobar i 15 odlican

prosjecna ocjena je:
vrlo dobar

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int N=0,prosjek=0,m=5;
	int ocjene[5] = {0};
	int zbrajac[5] = { 0 };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			if (j == 4) {
				scanf("%d", &ocjene[j]);
				zbrajac[j] += ocjene[j];
			}
			else {
				scanf("%d ", &ocjene[j]);
				zbrajac[j] += ocjene[j];
			}
		}
	}
	printf("Za %d razred/razreda\n\n", N);
	printf("bilo je:\n");
	for (int i = 1; i < 5+1; i++) {
		if (i == 1) {
			printf("%d nedovoljan, ", zbrajac[i - 1]);
		}
		else if (i == 2) {
			printf("%d dovoljan, ", zbrajac[i - 1]);
		}
		else if (i == 3) {
			printf("%d dobar, ", zbrajac[i - 1]);
		}
		else if (i == 4) {
			printf("%d vrlo dobar i ", zbrajac[i - 1]);
		}
		else if (i == 5) {
			printf("%d odlican\n", zbrajac[i - 1]);
		}
	}
	printf("prosjecna ocjena je: \n");
	for (int i = 0; i < m; i++) {
		if (zbrajac[i] == 0) {
			m--;
		}
			prosjek += zbrajac[i];
			prosjek /= 5;
			
			
	}
	if (prosjek == 1) {
		printf("nedovoljan");
	}
	else if (prosjek == 2) {
		printf("dovoljan");
	}
	else if (prosjek == 3) {
		printf("dobar");
	}
	else if (prosjek == 4) {
		printf("vrlo dobar");
	}
	else if (prosjek == 5) {
		printf("odlican");
	}
	

	return 0;
}
