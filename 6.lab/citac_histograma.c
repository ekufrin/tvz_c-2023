/*
TEKST ZADATKA
Vaš partner studira ekonomiju, i nije baš vješt u čitanju histograma. Kako bi mu pomogli u tom dosta bitnom segmentu,
odlučili ste napisati program koji za uneseni histogram ispisuje koji stupac ima najveću vrijednost, i koja je to vrijednost.
Napomena: zadatak je potrebno riješiti pomoću funkcije, na način da se proslijedi matrica koja sadrži historgram, a funkcija
treba vratiti informaciju koji stupac ima najveću vrijednost i koja je to vrijednost. Dinamički alocirati matricu (tj. 2d polje) u
zasebnoj funkciji. Neće biti test primjera gdje više od jednog stupca sadrže najveće vrijednosti.

TEST CASEOVI:
Test case #1
Ulaz:
5 8
......x.
......x.
......x.
...x..x.
x..x..x.
Izlaz:
Najveca vrijednost (5) je u stupcu 7.

Test case #2
Ulaz:
6 8
........
........
....x...
x..xx.xx
x..xx.xx
xxxxx.xx
Izlaz:
Najveca vrijednost (4) je u stupcu 5.

Test case #3
Ulaz:
8 10
..........
..........
....x.....
....xx....
....xx....
..x.xx...x
.xxxxx..xx
xxxxxx.xxx
Izlaz:
Najveca vrijednost (6) je u stupcu 5.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<stdlib.h>

void provjeri(char** polje, int n, int m, int* stupac, int*vrijednost) {
	int tempZbroj = 0;
	int tempStupac = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (polje[j][i] == 'x') {
				tempStupac++;
			}
		}
		if (tempStupac > *vrijednost) {
			*vrijednost = tempStupac;
			*stupac = i+1;
		}
		tempStupac = 0;
	}
}

int main() {

	int n = 0, m = 0;
	int stupac=0, vrijednost = 0;


	scanf("%d %d", &n, &m);
	char** polje = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++) {
		polje[i] = (char*)malloc(m * sizeof(char));
	}

	for(int i=0;i<n;i++){
		for (int j = 0; j < m; j++) {
			scanf(" %c", &polje[i][j]);
		}
	}

	provjeri(polje, n, m,&stupac,&vrijednost);
	printf("Najveca vrijednost (%d) je u stupcu %d.", vrijednost, stupac);

	for (int i = 0; i < n; i++) {
		free(polje[i]);
	}

	free(polje);

	return 0;
}
