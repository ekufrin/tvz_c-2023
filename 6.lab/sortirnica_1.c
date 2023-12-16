/*TEKST ZADATAKA
Radite dinamičku sortirnicu u pošti.
Na početku je potrebno učitati koliko paketa je došlo u sortirnicu (0 <= n <= 100).
Onda je potrebno redom učitavati pakete. Za svaki paket je bitno samo koja mu je kategorija (1 <= k <= 50) i težina u
gramima (1 <= t <= 5000)..
Pošto je sortirnica dinamička, potrebno je dinamički alocirati memoriju po potrebi.
Algoritam je sljedeći: počinjemo sa praznim nizom paketnih nizova. Kada dođe kategorija X, ukoliko potrebno ga je staviti u
redak sa indeksom (X-1), na kraj.
Ukoliko ne postoji redak za kategoriju X, tada je potrebno proširiti originalni niz kategorija.
Ukoliko u retku ne stane paket, potrebno je povećati kapacitet retka za 5.
Na kraju je potrebno ispisati redak sa najviše paketa, te koliko mjesta još ima u tom retku.
Primjer:

dolazi paket K = 2, T = 10
alociramo prostor za 2 kategorije.
u retku s indexom 1 (za kategoriju K=2) nema ništa mjesta, alociramo 5 mjesta
dodajemo paket
dolazi paket K = 2, T = 11
postoji redak za K=2, i ima mjesta u njemu (ima još 4 mjesta). Dodajemo paket
dolazi paket K = 1, T = 15
redak za K=1 postoji, ali nema mjesta (trenutni kapacitet = 0), proširujemo za 5 i dodajemo paket
TEST CASEOVI:
Ulaz:
3
2 10
2 11
1 15

Izlaz:
Redak 2 ima najvise paketa (2).
10 11 _ _ _

Ulaz:
6
2 1
2 2
2 3
2 4
2 5
2 6

Izlaz:
Redak 2 ima najvise paketa (6).
1 2 3 4 5 6 _ _ _ _

Ulaz:
10
1 246
1 4527
3 553
1 3714
1 3398
3 3653
1 1483
2 3230
1 4820
2 4834

Izlaz:
Redak 1 ima najvise paketa (6).
246 4527 3714 3398 1483 4820 _ _ _ _

Ulaz:
25
3 275
4 1115
6 142
4 1992
6 3164
2 2836
3 1821
5 4338
2 853
2 1547
4 2119
3 3335
6 1051
5 1565
4 2425
6 4448
3 3903
6 278
3 1118
4 502
3 2399
4 3831
4 2760
1 2417
2 1802

Izlaz:
Redak 4 ima najvise paketa (7).
1115 1992 2119 2425 502 3831 2760 _ _ _

Ulaz:
44
1 3784
7 79
2 2937
4 849
2 3716
3 1631
4 4582
6 1775
8 3037
3 3558
8 4110
4 591
9 3237
6 1114
9 1830
8 3953
7 3513
7 3079
6 73
8 4804
4 188
2 206
5 4969
7 3382
6 3598
2 973
8 4535
4 896
8 2917
4 1349
6 396
3 3721
8 503
6 190
1 3739
4 3483
2 3545
3 1877
4 3828
8 3081
6 4423
7 1217
2 4128
8 1376

Izlaz:
Redak 8 ima najvise paketa (9).
3037 4110 3953 4804 4535 2917 503 3081 1376 _

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int najveciBroj = 0, redak;

void unos(int** niz, int brojPaketa);

int main()
{
int N;

scanf("%d", &N);

int** paketi = (int*)calloc(N, sizeof(int));
for (int i = 0; i < N; i++) {
	paketi[i] = (int*)calloc(1, sizeof(int));
}

unos(paketi, N);

printf("Redak %d ima najvise paketa (%d).\n", redak, najveciBroj);

for (int i = 0; i < najveciBroj; i++) {
	printf("%d ", paketi[redak - 1][i]);
}

int temp = 0;

while (temp < najveciBroj) {
	temp += 5;
}

for (int i = najveciBroj; i < temp; i++) {
	printf("_ ");
}
}

void unos(int** niz, int brojPaketa) {
int K, T;
int* counter = (int*)calloc(MAX, sizeof(int));

for (int i = 0; i < brojPaketa; i++) {
	scanf("%d %d", &K, &T);

	if ((int)counter[K - 1] % 5 == 0 || counter[K - 1] == 0) {
		niz[K - 1] = (int*)realloc(niz[K - 1], sizeof(int) * counter[(K)-1] + sizeof(int) * 5);
	}

	niz[K - 1][counter[K - 1]] = T;

	counter[K - 1] += 1;
}

for (int i = 0; i < MAX; i++) {
	if (najveciBroj < counter[i]) {
		najveciBroj = counter[i];
		redak = i + 1;
	}
}
}
