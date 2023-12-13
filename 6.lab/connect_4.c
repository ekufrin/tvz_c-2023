/*
TEKST ZADATKA
Radite software koji prepoznaje da li je neki od igrača pobjednik poznate i popularne igre connect 4. Kao prvu
komponentu, odabrali ste C kako bi napravili algoritam koji na temelju igraće ploče određuje da li je neki igrač pobjednik, ili
ako je stanje na ploči nemoguće. Stanje na ploči je nemoguće ako su oba igrača pobjednici. Ukoliko niti jedan igrač nije
pobjednik, potrebno je ispisati "Nema pobjednika".

TEST CASEOVI:
Test case #1
Ulaz:
5 8
......x.
......x.
......o.
...x..x.
xooxoox.
Izlaz:
Nema pobjednika


Test case #2
Ulaz:
6 8
........
........
....x...
x..xx.oo
x..xxxxx
xxoooxxx
Izlaz:
Pobjednik: x


Test case #3
Ulaz:
8 10
..........
..........
....x.....
....xx....
....xo....
..x.xo...x
.xxxxo..xx
xxxxxo.xxx
Izlaz:
Nemoguca situacija

Test case #4
Ulaz:
4 1
o
o
o
o
Izlaz:
Pobjednik: o


*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<stdlib.h>

void provjeri(char** polje, int n, int m) {
	int x = 0;
	int o = 0;
	int pobX = 0;
	int pobO = 0;
	int jednako = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (polje[j][i] == 'x') {
				x++;
				o = 0;
			}
			else if (polje[j][i] == 'o') {
				o++;
				x = 0;
			}
			if (x == 4) {
				pobX=1;
			}
			else if (o == 4) {
				pobO=1;
			}
		}
	}
	x = 0;
	o = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (polje[i][j] == 'x') {
				x++;
				o = 0;
			}
			else if (polje[i][j] == 'o') {
				o++;
				x = 0;
			}
			if (x == 4) {
				pobX = 1;
			}
			else if (o == 4) {
				pobO = 1;
			}
		}
	}

	if (pobX == 1 && pobO == 1) {
		printf("Nemoguca situacija");
	}
	else if (pobO == 1) {
		printf("Pobjednik: o");
	}
	else if (pobX==1) {
		printf("Pobjednik: x");
	}
	else {
		printf("Nema pobjednika");
	}

}

int main() {

	int n = 0, m = 0;


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

	provjeri(polje, n, m);

	for (int i = 0; i < n; i++) {
		free(polje[i]);
	}

	free(polje);

	return 0;
}
