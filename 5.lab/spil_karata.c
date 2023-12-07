/*
Boza zvani pub je vrhunski kartas. Da bi bio vrhunski kartas , mora imati nekoliko vrlo vaznih sposobnosti, od kojih je jedna da neprimjetno moze poredati karte u dijelu spila tijekom mijesanja. Vas zadatak je da kao promatrac , napravite program koji ce predvidjeti kako su karte izmjesane uzimajuci u obzir boz inu sposobnost.

Potrebno je napraviti funkciju koja ce za zadani niz proslijeden kao parametar, te za dva indexa idx1 i idx2, poredati karte izmedu idx1 i idx2.

Karte su numerirane od 1 do n(n se ucitava), i inicijalno su poredane silazno. Nakon toga potrebno je ucitati k redaka, gdje svaki redak sadrzi idx1 i idx2, te poredati karte prema gore opisanom postupku.

test case #1:
Ulaz:
10 2
1 5
3 7
Izlaz:
6 7 4 5 8 9 10 3 2 1

test case #2:
Ulaz:
20 4
1 6
5 11
13 19
4 16

Izlaz:
15 16 17 2 3 4 5 9 10 11 12 13 14 18 19 20 6 7 8 1

test case #3:
Ulaz:
100 10
1 5
4 8
3 34
12 23
5 67
13 19
15 78
56 89
97 99
61 67

Izlaz:
96 97 67 68 34 35 36 37 38 39 40 41 42 43 23 24 25 26 27 28 29 30 31 32 33 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 69 70 71 72 73 74 75 12 13 14 15 16 17 18 19 20 21 22 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 98 99 100 11 10 9 8 7 6 5 2 3 4 1

*/
void poredakKarata(int niz[], int minKarte, int maxKarte) {

int x = 0;

for (int i = minKarte - 1; i < maxKarte - 1; i++) {
	for (int j = minKarte - 1; j < maxKarte - x - 1; j++) {
		if (niz[j] > niz[j + 1]) {
			int temp = niz[j];
			niz[j] = niz[j + 1];
			niz[j + 1] = temp;
		}

	}
	x++;
}
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX 200

int main() {

int brojKarata = 0;
int redak = 0;

scanf("%d %d", &brojKarata, &redak);

int niz[MAX] = { 0 };


for (int i = 0; i <= brojKarata; i++) {
	niz[i] = brojKarata - i;
}

int intervalMijesanjaKarata[2] = { 0 };

for (int i = 0; i < redak; i++) {
	scanf("%d %d", &intervalMijesanjaKarata[0], &intervalMijesanjaKarata[1]);

	poredakKarata(niz, intervalMijesanjaKarata[0], intervalMijesanjaKarata[1]);
}
printf("\n");

for (int i = 0; i <= brojKarata; i++) {
	printf("%d ", niz[i]);
}

return 0;
}
