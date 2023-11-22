/*
Preko tipkovnice učitati dimenzije i vrijednosti elemenata matrice koja može biti maksimalnih dimenzija 5x10. Ukoliko se unesu
krive dimenzije potrebno je ponoviti unos dimenzija.
Program treba ispisati pozicije onih stupaca za koje vrijedi da je suma elemenata tog stupca veća od vrijednosti najvećeg
elementa susjednog lijevog stupca.

Test case #1
Prvo se unose dimenzije matrice; u ovom slučaju 2x4.
Zatim se unose elementi.
Prvi stupac nema lijevog susjeda.
Stupac koji ne zadovoljava zadani kriterij je 2. stupac zato jer je suma stupca -3+4=1, a najveći el
ement u lijevom susjednom stupcu je 3.
Stupac koji ne zadovoljava zadani kriterij je 3. stupac zato jer je suma stupca 0+0=0, a najveći ele
ment u lijevom susjednom stupcu je 4.
Stupac koji zadovoljava zadani kriterij je 4. stupac zato jer je suma stupca 0+5=5, a najveći eleme
nt u lijevom susjednom stupcu je 0. 5 je veće od 0.
Primjer ulaza:
2 4
1 -3 0 0
3 4 0 5
Primjer izlaza:
Stupci koji zadovoljavaju kriterij:
4


Test case #2
Primjer ulaza:
5 5
3 -2 4 5 12
1 4 1 12 5
-1 6 -4 2 2
3 2 5 0 -20
0 -2 20 7 26
Primjer izlaza:
Stupci koji zadovoljavaju kriterij:
2 3 4 5


Test case #3
Prvo je unesen krivi unos dimenzija. Potrebno je ponoviti unos dimenzija matrice.
U ovom slučaju nema stupaca koji zadovoljavaju kriterij i ispisuje se poruka "Nema stupaca koji zado
voljavaju kriterij."
Primjer ulaza:
5 11
3 3
2 4 -20
12 2 4
20 -2 3
Primjer izlaza:
Stupci koji zadovoljavaju kriterij:
Nema stupaca koji zadovoljavaju kriterij.


Test case #4
Primjer ulaza:
5 5
3 -2 4 5 12
1 4 1 12 5
-1 6 -4 2 2
3 2 5 0 -20
0 -2 20 7 -26
Primjer izlaza:
Stupci koji zadovoljavaju kriterij:
2 3 4
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int n, m;
	int polje[50][50] = { 0 };
	int zbroj[50] = {0};
	int najveciElement[50] = {-99};
	int brojac = 0;

	do {
		scanf("%d %d", &n, &m);
	} while (n*m>50);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &polje[i][j]);
			if (polje[i][j] > najveciElement[j]) {
				najveciElement[j] = polje[i][j];
			}
		}
	}
	printf("Stupci koji zadovoljavaju kriterij:\n");
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < n; j++) {
			zbroj[i] += polje[j][i];
		}
		if (zbroj[i] > najveciElement[i - 1]) {
			printf("%d ", i+1);
		}
		else {
			brojac++;
		}
	}

	if (brojac == n-1) {
		printf("Nema stupaca koji zadovoljavaju kriterij.");
	}

	return 0;
}
